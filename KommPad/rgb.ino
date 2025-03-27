uint16_t hue = 0; // Hue value for rainbow cycling
int breath = 0; //Brightness for breath effect
bool breathUp = 1; //segment of breath effect

uint8_t brightness;
float brightnessMod = .5;
uint32_t Colors[4]; 
uint8_t effect;
uint8_t num_Colors = 0 ; // Variable to store the count of non-empty colors


uint32_t hexToRGB(uint32_t color, uint8_t brightness) {
  // Extract the red, green, and blue components from the 24-bit color
  byte r = (color >> 16) & 0xFF; // Extract red (8 bits)
  byte g = (color >> 8) & 0xFF;  // Extract green (8 bits)
  byte b = color & 0xFF;         // Extract blue (8 bits)

  // Apply brightness scaling
  r = r * brightness / 255;
  g = g * brightness / 255;
  b = b * brightness / 255;

  // Return the color in the format expected by the LED strip library
  return strip.Color(r, g, b);
}

void staticEffect(uint32_t color1){
  strip.setPixelColor(0, hexToRGB(color1, brightness * brightnessMod));
  strip.setPixelColor(1, hexToRGB(color1, brightness * brightnessMod));
  strip.show();

}

void breathingEffect(int speed) {
  static int colorIndex = 0; // Index to track the current color

  // Adjust brightness to simulate the breathing effect
  if (breathUp) {
    breath++;  // Increase brightness
    if (breath >= brightness * speed) breathUp = false;  // Change direction
  } else {
    breath--;  // Decrease brightness
    if (breath <= 0) {
      breathUp = true;  // Change direction
      do {
        colorIndex = (colorIndex + 1) % 8; // Move to the next color
      } while (Colors[colorIndex] == 0); // Skip empty spaces
    }
  }

  // Apply the dynamic breathing effect using the current color and dynamic brightness 
  // float modulatedBrightness = (breath / speed ) * brightnessMod; // Modify brightness by brightness mode
  float modulatedBrightness = map(breath, 0, brightness * speed, 0, brightness * brightnessMod); // Modify brightness by brightness mode
  strip.setPixelColor(0, hexToRGB(Colors[colorIndex], brightness * brightnessMod)); 
  strip.setPixelColor(1, hexToRGB(Colors[colorIndex], brightness * brightnessMod)); 
  strip.show();
}

void rainbowCycle(int speed) {
  strip.setPixelColor(0, strip.ColorHSV(hue, 255, brightness * brightnessMod));
  strip.setPixelColor(1, strip.ColorHSV(hue+500, 255, brightness * brightnessMod));
  strip.show();
  hue += speed;
}

void rgbLed(){
  switch (effect) {
      case 0:
        staticEffect(Colors[layer % num_Colors]);
        break;
      case 1:
        breathingEffect(10);
        break;
      case 2:
        rainbowCycle(2);
        break;
      case 3:
        // add an effect
        break;
      default:
        break;
  }
}