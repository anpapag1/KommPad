int const Lnum2 = 1;

void initiate_2() {
  layer_name[Lnum2]="Home";

  actions[Lnum2][0][0]="Tv";
  actions[Lnum2][0][1]="3D Pr";
  actions[Lnum2][0][2]="Cam";
  actions[Lnum2][1][0]="Norm";
  actions[Lnum2][1][1]="Sec";
  actions[Lnum2][1][2]="Layer";
  actions[Lnum2][2][0]="Main up";
  actions[Lnum2][2][1]="Main on/off";
  actions[Lnum2][2][2]="Main down";
}

void butNo1_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F17);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][0]);
}

void butNo2_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F18);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][1]);
}

void butNo3_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F19);
  Keyboard.releaseAll();  
  print_action(actions[Lnum2][0][2]);
}

void butNo4_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F20);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][1][0]);
}

void butNo5_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F21);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][1][1]);
}

void butNo6_2(){
  UpLayer();
}

//Encoder actions
void encClock_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F22);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][0]);
}

void encConter_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F23);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][2]);
}

void encBut_2(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write(HID_KEYBOARD_F24);
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][1]);
}


