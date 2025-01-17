#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <HID-Project.h>
#include <Keypad.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define encPin1 10
#define encPin2 16
#define SW 9

// Define the keymap
#define numRows 2 // number of rows in the keypad
#define numCols 3 // number of columns in the keypad
char keymap[numRows][numCols] = 
{ {'1', '2', '3'},
  {'4', '5', '6'} };

// Define the row and column pins connected to the keypad
byte colPins[numCols] = {8, 7, 6}; // Rows 1 to 3
byte rowPins[numRows] = {4, 5};    // Columns 1 to 2

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

int currentStateencPin1;
int lastStateencPin1;
unsigned long AltTabMill = 0;
unsigned long actionTaken = 0;
unsigned long lockLayer = 0;
int idleTime;
int longPress;


int layer=0;
int num_layer;
const int max_layers=4;
String layer_name[max_layers];
String actions[max_layers][3][3];

int startLayer = 0;
bool help = 1;
int yPos[] = {0, 24};        // Y positions for the two rows
int xPos[] = {0, 48, 92};   // X positions for the columns

const int NUM_SLIDERS = 3;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2};
int analogSliderValues[NUM_SLIDERS];

void setup() {

  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }

  Serial.begin(9600);
  initiate_conf();
  initiate_1();
  initiate_2();
  initiate_3();
  initiate_4();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  print_display(layer,help);
   
  pinMode(encPin1, INPUT_PULLUP);
  pinMode(encPin2, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  lastStateencPin1 = digitalRead(encPin1); //encPin1 value
}

void  loop() {
  deej();
    
  currentStateencPin1 = digitalRead(encPin1); //encPin1 current value
  if (currentStateencPin1 != lastStateencPin1  && currentStateencPin1 == 1){  //encPin1 change  && encPin1 only 1state change
    if (digitalRead(encPin2) != currentStateencPin1) { //Encoder  CCW Rotation
    enc_func(layer,0);
    delay(2);

    } else {            // Encoder CW Rotation
    enc_func(layer,1);
    delay(2);
    }
  }
  lastStateencPin1  = currentStateencPin1; // Last encPin1 Value
  
  // Enc Switch pushed  
  if (digitalRead(SW) == LOW) { 
    lockLayer = millis();
    while (digitalRead(SW) == LOW && millis()-lockLayer<=longPress){}
    if (millis()-lockLayer>longPress) { // Lock the layer
      startLayer = layer;
      print_action("locked " + layer_name[layer]);
    } else enc_func(layer,2);
    while (digitalRead(SW) == LOW){}
  }

  char key = keypad.getKey();

  // Check if a key is pressed
  if (key != NO_KEY) {
    butt_func(layer,key);
  }
  
  // Release Alt after 700 millis
  if (millis()-AltTabMill>700 && millis()-AltTabMill<800){
    Keyboard.release(KEY_LEFT_ALT);
  }
  // Hide help and put to idle
  if (millis()-actionTaken>5000 && millis()-actionTaken<5050){
    print_display(layer,0);
  }else if (millis()-actionTaken> idleTime-50 && millis()-actionTaken< idleTime){
    idle();
  }

  delay(1);
}

void enc_func(int layer,int enc_state){
  switch (enc_state){
    case 0:
      if (layer==0) encConter_1();
      else if (layer==1) encConter_2();
      else if (layer==2) encConter_3();
      else if (layer==3) encConter_4();
      break;
    case 1:
      if (layer==0) encClock_1();
      else if (layer==1) encClock_2();
      else if (layer==2) encClock_3();
      else if (layer==3) encClock_4();
      break;
    case 2:
      if (layer==0) encBut_1();
      else if (layer==1) encBut_2();
      else if (layer==2) encBut_3();
      else if (layer==3) encBut_4();
      break;
  }
}

void butt_func(int layer,char button){
  switch (button) {
    case '1':
      if (layer==0) butNo1_1();
      else if (layer==1) butNo1_2();
      else if (layer==2) butNo1_3();
      else if (layer==3) butNo1_4();
      break;
    case '2':
      if (layer==0) butNo2_1();
      else if (layer==1) butNo2_2();
      else if (layer==2) butNo2_3();
      else if (layer==3) butNo2_4();
      break;
    case '3':
      if (layer==0) butNo3_1();
      else if (layer==1) butNo3_2();
      else if (layer==2) butNo3_3();
      else if (layer==3) butNo3_4();
      break;
    case '4':
      if (layer==0) butNo4_1();
      else if (layer==1) butNo4_2();
      else if (layer==2) butNo4_3();
      else if (layer==3) butNo4_4();
      break;
    case '5':
      if (layer==0) butNo5_1();
      else if (layer==1) butNo5_2();
      else if (layer==2) butNo5_3();
      else if (layer==3) butNo5_4();
      break;
    default:
      if (layer==0) butNo6_1();
      else if (layer==1) butNo6_2();
      else if (layer==2) butNo6_3();
      else if (layer==3) butNo6_4();
      break;
  }
}



