uint16_t hue = 0; // Hue value for rainbow cycling
int breath = 0; //Brightness for breath effect
bool breathUp = 1; //segment of breath effect

uint8_t brightness = 100;
uint32_t mainColor = 0xff00ff; 
uint32_t secColor = 0x00ffff; 

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

void breathingEffect(uint32_t color1, int speed) {
  // Adjust brightness to simulate the breathing effect
  if (breathUp) {
    breath++;  // Increase brightness
    if (breath >= brightness * speed) breathUp = false;  // Change direction
  } else {
    breath--;  // Decrease brightness
    if (breath <= 0) breathUp = true;  // Change direction
  }

  // Apply the dynamic breathing effect using color1 and dynamic brightness
  strip.setPixelColor(0, hexToRGB(color1, breath/speed)); 
  strip.setPixelColor(1, hexToRGB(color1, breath/speed)); 
  strip.show();
}

void rainbowCycle(int speed) {
  strip.setPixelColor(0, strip.ColorHSV(hue, 255, brightness));
  strip.setPixelColor(1, strip.ColorHSV(hue+5000, 255, brightness));
  strip.show();
  hue += speed;
}

void rgbLed(){
  rainbowCycle(2);
}
