int const Lnum1 = 0;

void initiate_1() {
  layer_name[Lnum1]="Media";

  actions[Lnum1][0][0]="Prev";
  actions[Lnum1][0][1]="Next";
  actions[Lnum1][0][2]="Pl/Ps";
  actions[Lnum1][1][0]="Spotf";
  actions[Lnum1][1][1]="ytb";
  actions[Lnum1][1][2]="Layer";
  actions[Lnum1][2][0]="Volume ++";
  actions[Lnum1][2][1]="Mute";
  actions[Lnum1][2][2]="Volume --";
}

void butNo1_1(){
  Consumer.write(MEDIA_PREV);
  print_action(actions[Lnum1][0][0]);
}

void butNo2_1(){
  Consumer.write(MEDIA_NEXT);
  print_action(actions[Lnum1][0][1]);
}

void butNo3_1(){
  Consumer.write(MEDIA_PLAY_PAUSE);
  print_action(actions[Lnum1][0][2]);
}

void butNo4_1(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.print("spotify");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();  
  print_action(actions[Lnum1][1][0]);
}

void butNo5_1(){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("https://www.youtube.com");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(2000);
  Keyboard.press('/');
  Keyboard.releaseAll();
  print_action(actions[Lnum1][1][1]);
}

void butNo6_1(){
  UpLayer();
}

//Encoder actions
void encClock_1(){
  Consumer.write(MEDIA_VOLUME_UP);
  print_action(actions[Lnum1][2][0]);
}

void encConter_1(){
  Consumer.write(MEDIA_VOLUME_DOWN);
  print_action(actions[Lnum1][2][2]);
}

void encBut_1(){
  Consumer.write(MEDIA_VOLUME_MUTE);
  print_action(actions[Lnum1][2][1]);
}


