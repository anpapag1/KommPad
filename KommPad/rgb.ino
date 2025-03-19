uint16_t hue = 0; // Hue value for rainbow cycling
int breath = 0; //Brightness for breath effect
bool breathUp = 1; //segment of breath effect

uint8_t brightness;
float brightnessMod = .5;
uint32_t mainColors[8]; 
uint8_t effect;


uint32_t hexToRGB(uint32_t hex, uint8_t brightness) {
  byte r = ((hex >> 16) & 0xFF) * brightness / 255;
  byte g = ((hex >> 8) & 0xFF) * brightness / 255;
  byte b = (hex & 0xFF) * brightness / 255;
  return strip.Color(r, g, b);
}

void staticEffect(uint32_t color1){
  strip.setPixelColor(0, hexToRGB(color1, brightness));
  strip.setPixelColor(1, hexToRGB(color1, brightness));
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
      } while (mainColors[colorIndex] == 0); // Skip empty spaces
    }
  }

  // Apply the dynamic breathing effect using the current color and dynamic brightness
  float modulatedBrightness = (breath / speed ) * brightnessMod; // Modify brightness by brightness mode
  strip.setPixelColor(0, hexToRGB(mainColors[colorIndex], modulatedBrightness)); 
  strip.setPixelColor(1, hexToRGB(mainColors[colorIndex], modulatedBrightness)); 
  strip.show();
}

void rainbowCycle(int speed) {
  strip.setPixelColor(0, strip.ColorHSV(hue, 255, brightness));
  strip.setPixelColor(1, strip.ColorHSV(hue+5000, 255, brightness));
  strip.show();
  hue += speed;
}

void rgbLed(){
  switch (effect) {
      case 0:
        staticEffect(mainColors[0]);
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