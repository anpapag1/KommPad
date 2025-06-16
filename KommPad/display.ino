extern float brightnessMod;
extern float idleBrightnessMod;

void print_display(int layer,bool help){
  brightnessMod= 1;
  display.clearDisplay();
  display.setCursor(30, 8);
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.println(layer_name[layer]);
  if (help){
    display.setTextSize(1);      // Set the text size for actions
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 3; col++) {
        display.setCursor(xPos[col], yPos[row]);
        display.print(actions[layer][row][col]);
      }
    }
  }
  display.display();
}

void print_action(char* Idid){
  print_display(layer,0);
  actionTaken = millis();
  display.setCursor(10,24);
  display.setTextSize(1);
  display.print(Idid);
  display.display();  
}

void UpLayer(){
  if (millis()-actionTaken < idleTime){ 
    layer=(layer+1)%num_layer;
  }
  print_display(layer,1);
  actionTaken = millis();
}

void idle(){
  brightnessMod= idleBrightnessMod;
  display.clearDisplay();
  display.display();
  layer = startLayer;
}

