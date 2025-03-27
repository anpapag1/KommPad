#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <HID-Project.h>
#include <Keypad.h>
#include <Adafruit_NeoPixel.h>

// RgbLed
#define PIN 15
#define NUM_LEDS 2  // Change to the number of LEDs you have
Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
extern uint8_t num_Colors;  // Variable to store the count of non-empty colors
extern uint32_t Colors[4];

// OLED display settings
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 32     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Rotary encoder pins
#define encPin1 10
#define encPin2 16
#define SW 14

// Keypad configuration
#define numRows 2  // Number of rows in the keypad
#define numCols 3  // Number of columns in the keypad
char keymap[numRows][numCols] = { { '1', '2', '3' },
                                  { '4', '5', '6' } };

// Define the row and column pins connected to the keypad
byte colPins[numCols] = { 6, 7, 8 };  // Columns 1 to 3
byte rowPins[numRows] = { 5, 4 };     // Rows 1 to 2

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

// Encoder state variables
int currentStateencPin1;
int lastStateencPin1;
uint32_t  AltTabMill = 0;
uint32_t  actionTaken = 0;
uint32_t  lockLayer = 0;
uint16_t idleTime;
uint16_t longPress;

// Layer settings
int layer = 0;
int num_layer;
const int max_layers = 4;
const char* layer_name[max_layers];
const char* actions[max_layers][3][3];

// Start layer for locking
int startLayer = 0;
bool help = 1;
int yPos[] = { 0, 24 };      // Y positions for the two rows
int xPos[] = { 0, 48, 92 };  // X positions for the columns

// Analog slider input
const int NUM_SLIDERS = 3;
const int analogInputs[NUM_SLIDERS] = { A0, A1, A2 };
int analogSliderValues[NUM_SLIDERS];

// Setup function to initialize components
void setup() {

  // Set pin mode for analog inputs (sliders)
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  Serial.begin(9600);
  initiate_conf();
  initiate_1();
  initiate_2();
  initiate_3();
  initiate_4();

  // Count non-empty colors in Colors
  for (int i = 0; i < 15; i++) {
    if (Colors[i] != 0) {
      num_Colors++;
    }
  }

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Stay in an infinite loop if display fails
  }

  print_display(layer, help);

  // Set pin modes for encoder and switch
  pinMode(encPin1, INPUT_PULLUP);
  pinMode(encPin2, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  // Initialize encoder state
  lastStateencPin1 = digitalRead(encPin1);  // Encoder 1 initial state

  strip.begin();
}

// Main loop function
void loop() {
  deej();  // Call function to manage the macro pad operations
  rgbLed();
  currentStateencPin1 = digitalRead(encPin1);                                 // Read the current state of the encoder pin
  if (currentStateencPin1 != lastStateencPin1 && currentStateencPin1 == 1) {  // Encoder pin change detection
    if (digitalRead(encPin2) != currentStateencPin1) {                        // Counter-clockwise rotation
      enc_func(layer, 0);
    } else {  // Clockwise rotation
      enc_func(layer, 1);
    }
  }
  lastStateencPin1 = currentStateencPin1;  // Store the last encoder pin state

  // Check if encoder switch (SW) is pressed
  if (digitalRead(SW) == LOW) {
    lockLayer = millis();
    while (digitalRead(SW) == LOW && millis() - lockLayer <= longPress) {}  // Wait for switch release or long press time
    if (millis() - lockLayer > longPress) {                                 // If long press, lock the layer
      startLayer = layer;
      String message = "locked " + String(layer_name[layer]);
      print_action(message.c_str());
      // print_action("locked");
      delay(500);   
    } else {
      enc_func(layer, 2);  // Short press action
    }
    while (digitalRead(SW) == LOW) {}  // Wait for switch release or long press time
  }
  // Get pressed key from the keypad
  char key = keypad.getKey();

  // If a key is pressed, execute the corresponding action
  if (key != NO_KEY) {
    butt_func(layer, key);
    // Serial.println(key);
  }

  // Release Alt key after 700 milliseconds
  if (millis() - AltTabMill > 700 && millis() - AltTabMill < 800) {
    Keyboard.release(KEY_LEFT_ALT);
  }

  // If no action has been taken for 5 seconds, hide help and go to idle state
  if (millis() - actionTaken > 5000 && millis() - actionTaken < 5050) {
    print_display(layer, 0);
  } else if (millis() - actionTaken > idleTime - 50 && millis() - actionTaken < idleTime) {
    idle();  // Idle function (to be defined elsewhere)
  }

  delay(1);  // Small delay to ensure the loop runs smoothly
}

// Encoder function for different actions based on rotation direction
void enc_func(int layer, int enc_state) {
  switch (enc_state) {
    case 0:
      // Counter-clockwise rotation
      if (layer == 0) encConter_1();
      else if (layer == 1) encConter_2();
      else if (layer == 2) encConter_3();
      else if (layer == 3) encConter_4();
      break;
    case 1:
      // Clockwise rotation
      if (layer == 0) encClock_1();
      else if (layer == 1) encClock_2();
      else if (layer == 2) encClock_3();
      else if (layer == 3) encClock_4();
      break;
    case 2:
      // Switch pressed
      if (layer == 0) encBut_1();
      else if (layer == 1) encBut_2();
      else if (layer == 2) encBut_3();
      else if (layer == 3) encBut_4();
      break;
  }
}

// Function to handle button press actions based on the layer
void butt_func(int layer, char button) {
  switch (button) {
    case '1':
      if (layer == 0) butNo1_1();
      else if (layer == 1) butNo1_2();
      else if (layer == 2) butNo1_3();
      else if (layer == 3) butNo1_4();
      break;
    case '2':
      if (layer == 0) butNo2_1();
      else if (layer == 1) butNo2_2();
      else if (layer == 2) butNo2_3();
      else if (layer == 3) butNo2_4();
      break;
    case '3':
      if (layer == 0) butNo3_1();
      else if (layer == 1) butNo3_2();
      else if (layer == 2) butNo3_3();
      else if (layer == 3) butNo3_4();
      break;
    case '4':
      if (layer == 0) butNo4_1();
      else if (layer == 1) butNo4_2();
      else if (layer == 2) butNo4_3();
      else if (layer == 3) butNo4_4();
      break;
    case '5':
      if (layer == 0) butNo5_1();
      else if (layer == 1) butNo5_2();
      else if (layer == 2) butNo5_3();
      else if (layer == 3) butNo5_4();
      break;
    default:
      if (layer == 0) butNo6_1();
      else if (layer == 1) butNo6_2();
      else if (layer == 2) butNo6_3();
      else if (layer == 3) butNo6_4();
      break;
  }
}
