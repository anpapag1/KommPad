int const Lnum3 = 2;


void initiate_3() {
  layer_name[Lnum3]="Screen";

  actions[Lnum3][0][0]="1 Sc";
  actions[Lnum3][0][1]="Cln";
  actions[Lnum3][0][2]="Extd";
  actions[Lnum3][1][0]="Desk";
  actions[Lnum3][1][1]="Lock";
  actions[Lnum3][1][2]="Layer";
  actions[Lnum3][2][0]="Alt Tab";
  actions[Lnum3][2][1]="Win Tab";
  actions[Lnum3][2][2]="Alt Shift Tab";
}

void butNo1_3(){
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("%windir%\\System32\\DisplaySwitch.exe /internal");
  Keyboard.write(KEY_RETURN);
  print_action(actions[Lnum3][0][0]);
}

void butNo2_3(){
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("%windir%\\System32\\DisplaySwitch.exe /clone");
  Keyboard.write(KEY_RETURN);
  print_action(actions[Lnum3][0][1]);
}

void butNo3_3(){
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("%windir%\\System32\\DisplaySwitch.exe /extend");
  Keyboard.write(KEY_RETURN);
  print_action(actions[Lnum3][0][2]);
}

void butNo4_3(){
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.press('d');
  Keyboard.releaseAll();
  print_action(actions[Lnum3][1][0]);
}

void butNo5_3(){
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.press('l');
  Keyboard.releaseAll();
  print_action(actions[Lnum3][1][1]);
}

void butNo6_3(){
  UpLayer();
}

void encClock_3(){
  AltTabMill=millis();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(KEY_TAB);  
  print_action(actions[Lnum3][2][0]);
}

void encConter_3(){
  AltTabMill=millis();
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_TAB);
  Keyboard.release(KEY_LEFT_SHIFT);
  print_action(actions[Lnum3][2][2]);
}

void encBut_3(){
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_WINDOWS);
  Keyboard.write(KEY_TAB);
  Keyboard.releaseAll();
  print_action(actions[Lnum3][2][1]);
}


