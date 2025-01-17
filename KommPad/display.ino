// Function to update the display based on the current layer and help status
void print_display(int layer, bool help) {
  display.clearDisplay();  // Clear the previous display
  display.setCursor(30, 8); // Set cursor position to display the layer name
  display.setTextColor(SSD1306_WHITE); // Set text color to white
  display.setTextSize(2);  // Set the text size for the layer name
  display.println(layer_name[layer]); // Print the current layer name

  // If help is enabled, display the actions for the current layer
  if (help) {
    display.setTextSize(1);  // Set smaller text size for actions
    // Loop through each row and column to display actions
    for (int row = 0; row < 2; row++) {
      for (int col = 0; col < 3; col++) {
        display.setCursor(xPos[col], yPos[row]);  // Set cursor for each action's position
        display.print(actions[layer][row][col]);   // Print the corresponding action
      }
    }
  }
  display.display();  // Update the display to show the changes
}

// Function to print an action message on the display (e.g., "locked" or other feedback)
void print_action(String Idid) {
  print_display(layer, 0);  // Update the display with the current layer without help
  actionTaken = millis();  // Record the time of the action
  display.setCursor(10, 24);  // Set cursor for action message
  display.setTextSize(1);  // Set text size for the action message
  display.print(Idid);  // Print the action message
  display.display();  // Update the display
}

// Function to switch to the next layer (circular transition)
void UpLayer() {
  // Check if the idle time has passed, if not, prevent changing the layer
  if (millis() - actionTaken < idleTime) {
    layer = (layer + 1) % num_layer;  // Increment the layer and wrap around using modulo
  }
  print_display(layer, 1);  // Update the display with the new layer and actions
  actionTaken = millis();  // Record the time of the action
}

// Function to reset to the starting layer and clear the display
void idle() {
  display.clearDisplay();  // Clear the display
  display.display();  // Update the display to show the cleared screen
  layer = startLayer;  // Reset the layer to the starting layer
}
