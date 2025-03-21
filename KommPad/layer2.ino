int const Lnum2 = 1;

void initiate_2() {
  layer_name[Lnum2] = "Windows";

  actions[Lnum2][0][0] = "Task Mngr";
  actions[Lnum2][0][1] = "Minimize";
  actions[Lnum2][0][2] = "Lock";
  actions[Lnum2][1][0] = "Alt F4";
  actions[Lnum2][1][1] = "Find";
  actions[Lnum2][1][2] = "Layer";
  actions[Lnum2][2][0] = "Alt -TAB";
  actions[Lnum2][2][1] = "WIN TAB";
  actions[Lnum2][2][2] = "Alt +TAB";
}

void butNo1_2() {
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][0]);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
}

void butNo2_2() {
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][1]);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  Keyboard.releaseAll();
}

void butNo3_2() {
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][2]);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  Keyboard.releaseAll();
}

void butNo4_2() {
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(KEY_F4);
  Keyboard.releaseAll();        
  print_action(actions[Lnum2][1][0]);
}

void butNo5_2() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(KEY_F);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][1][1]);
}

void butNo6_2() {
  UpLayer();
}

// Encoder actions
void encClock_2() {
  AltTabMill=millis();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(KEY_TAB);
  print_action(actions[Lnum2][2][0]);
}

void encConter_2() {
  AltTabMill=millis();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_TAB);
  Keyboard.release(KEY_LEFT_SHIFT);
  print_action(actions[Lnum2][2][2]);
}

void encBut_2() {
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.write(KEY_TAB);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][1]);
}


// ------------------EXAMPLES FOR FUNCTIONS-------------------------
// https://github.com/anpapag1/KommPad/blob/main/Function_Example.md