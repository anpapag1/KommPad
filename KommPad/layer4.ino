int const Lnum4 = 3;

void initiate_4() {
  layer_name[Lnum4]="--";

  actions[Lnum4][0][0]="--";
  actions[Lnum4][0][1]="--";
  actions[Lnum4][0][2]="--";
  actions[Lnum4][1][0]="--";
  actions[Lnum4][1][1]="--";
  actions[Lnum4][1][2]="--";
  actions[Lnum4][2][0]="--";
  actions[Lnum4][2][1]="--";
  actions[Lnum4][2][2]="--";
}

void butNo1_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][0][0]);
}

void butNo2_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][0][1]);
}

void butNo3_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][0][2]);
}

void butNo4_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][1][0]);
}

void butNo5_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][1][1]);
}

void butNo6_4(){
  UpLayer();
}

void encClock_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][2][0]);
}

void encConter_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][2][2]);
}

void encBut_4(){
  Keyboard.releaseAll();
  print_action(actions[Lnum4][2][1]);
}


