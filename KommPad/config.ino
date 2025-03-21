extern uint8_t brightness;
extern uint8_t effect;
extern uint32_t mainColors[8];

void initiate_conf() {
  // layers
  num_layer = 1; // How many layers to enable
  
  // timings
  idleTime = 25000; // 20 seconds
  longPress = 500; // 0.5 seconds

  // rgb 
  brightness = 100; // max 255
  effect = 1; // 0 - static, 1 - breathing(multicolor), 2 - rainbow
  mainColors[0] = 0xff00ff; // colors set in hex
  mainColors[1] = 0x36d06d; // uncomend for more colors in suported effects
  // mainColors[2] = 0xff644d;
  // mainColors[3] = 0x5b3cc7;
}
