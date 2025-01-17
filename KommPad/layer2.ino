int const Lnum2 = 1;

void initiate_2() {
  layer_name[Lnum2]="--";

  actions[Lnum2][0][0]="--";
  actions[Lnum2][0][1]="--";
  actions[Lnum2][0][2]="--";
  actions[Lnum2][1][0]="--";
  actions[Lnum2][1][1]="--";
  actions[Lnum2][1][2]="Layer";
  actions[Lnum2][2][0]="--";
  actions[Lnum2][2][1]="--";
  actions[Lnum2][2][2]="--";
}

void butNo1_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][0]);
}

void butNo2_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][0][1]);
}

void butNo3_2(){
  Keyboard.releaseAll();  
  print_action(actions[Lnum2][0][2]);
}

void butNo4_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][1][0]);
}

void butNo5_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][1][1]);
}

void butNo6_2(){
  UpLayer();
}

//Encoder actions
void encClock_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][0]);
}

void encConter_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][2]);
}

void encBut_2(){
  Keyboard.releaseAll();
  print_action(actions[Lnum2][2][1]);
}


