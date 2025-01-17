# Macro Pad Project

## Overview
This project implements a feature-rich macro pad using an Arduino-compatible board. The macro pad includes the following features:

- **OLED Display**: Provides visual feedback for current layers and actions.
- **Rotary Encoder with Switch**: Allows for navigation and action triggering.
- **Keypad Input**: Supports multi-key configurations for various functionalities.
- **Analog Sliders**: Controls volume or other app-specific parameters.
- **Layer System**: Offers up to 4 layers for different sets of actions.
- **Idle and Help States**: Automatically displays help or transitions to idle mode after inactivity.

## Hardware Requirements
1. Arduino-compatible board (e.g., Arduino Pro Micro).
2. 128x32 OLED display (I2C, SSD1306).
3. Rotary encoder with push-button functionality.
4. 2x3 matrix keypad.
5. 3 potentiometers for analog sliders.
6. Miscellaneous components: resistors, wires, and breadboard/PCB for assembly.

## Software Dependencies
- Arduino IDE
- Adafruit SSD1306 library
- Keypad library
- HID-Project library

## File Descriptions
1. **main.ino**: The main program file that initializes hardware, manages the loop, and integrates all functionality.
2. **deej.ino**: Handles the analog slider inputs and serial output for slider values.
3. **display.ino**: Manages the OLED display, showing layer information, actions, and idle state.
4. **config.ino**: Contains initialization and configuration functions for the macro pad.
5. **layer1.ino, layer2.ino, layer3.ino, layer4.ino**: Defines specific behaviors for each layer, including button and encoder actions.

## Features
### OLED Display
- Displays the current layer name and associated actions.
- Shows dynamic feedback when an action is performed.

### Rotary Encoder
- Supports clockwise (CW) and counterclockwise (CCW) rotations.
- Push-button functionality to trigger actions or lock the current layer.

### Keypad
- Maps 2x3 buttons to layer-specific actions.
- Customizable button actions for each layer.

### Analog Sliders
- Reads values from potentiometers and outputs them as a `|`-delimited string.
- Can be used for volume control or app-specific parameters.

### Layers
- Up to 4 customizable layers.
- Each layer can define unique actions for buttons and the rotary encoder.

## Usage
1. Upload the code to your Arduino board using the Arduino IDE.
2. Assemble the hardware according to the specified pin mappings in the code.
3. Use the rotary encoder to navigate and select actions.
4. Press keys on the keypad to trigger layer-specific actions.
5. Adjust sliders to control analog values.

## Customization
- Edit the `actions` array in the main file to define layer-specific behaviors.
- Update `layer_name` to assign meaningful names to each layer.
- Modify `deej.ino` to normalize or map slider values as needed.

## Troubleshooting
1. **OLED Display Not Working**:
   - Check I2C address and connections.
   - Ensure the Adafruit SSD1306 library is installed.
2. **Keypad Issues**:
   - Verify row and column pin connections.
   - Test with a simple keypad sketch to rule out hardware faults.
3. **Rotary Encoder Misbehaving**:
   - Check for proper debouncing in the code.
   - Ensure encoder pins are correctly mapped and stable.
4. **Analog Sliders Not Reading**:
   - Confirm potentiometer connections and analog input pins.

## Future Improvements
- Add graphical feedback on the OLED (e.g., bar graphs for sliders).
- Implement EEPROM storage for persistent layer settings.
- Expand to support more layers or actions.

---
For questions or contributions, feel free to reach out!

