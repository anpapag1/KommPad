int const Lnum3 = 2;

void initiate_3() {
  layer_name[Lnum3]="--";

  actions[Lnum3][0][0]="--";
  actions[Lnum3][0][1]="--";
  actions[Lnum3][0][2]="--";
  actions[Lnum3][1][0]="--";
  actions[Lnum3][1][1]="--";
  actions[Lnum3][1][2]="Layer";
  actions[Lnum3][2][0]="--";
  actions[Lnum3][2][1]="--";
  actions[Lnum3][2][2]="--";
}

void butNo1_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][0][0]);
}

void butNo2_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][0][1]);
}

void butNo3_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][0][2]);
}

void butNo4_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][1][0]);
}

void butNo5_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][1][1]);
}

void butNo6_3(){
  UpLayer();
}

void encClock_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][2][0]);
}

void encConter_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][2][2]);
}

void encBut_3(){
  Keyboard.releaseAll();
  print_action(actions[Lnum3][2][1]);
}

// ------------------EXAMPLES FOR FUNCTIONS-------------------------
// https://github.com/anpapag1/KommPad/blob/main/Function_Example.md

