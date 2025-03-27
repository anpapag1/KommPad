extern uint8_t brightness;
extern uint8_t effect;
extern uint32_t Colors[4];

void initiate_conf() {
  // layers
  num_layer = 2; // How many layers to enable
  
  // timings
  idleTime = 9000; // 20 seconds
  longPress = 500; // 0.5 seconds

  // rgb 
  brightness = 100; // max 255
  effect = 0; // 0 - static(multicolor*), 1 - breathing(*multicolor), 2 - rainbow
  Colors[0] = 0xff00ff; // colors set in hex
  Colors[1] = 0x00d5ff; 
  // Colors[2] = 0xFF0000; // uncomend for more colors in suported effects
  // Colors[3] = 0xFF0000;  
  // *multicolor means that it can take multiple colors from the array Colors[4]
}
