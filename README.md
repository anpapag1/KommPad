# KommPad: Macro Pad Project

## Overview
KommPad is a customizable macro pad designed for efficiency and ease of use. It features multiple layers, rotary encoder support, an OLED display for feedback, and analog sliders for additional controls. The hardware is predefined and sold as a complete unit, making it easy to set up and start using right away.

## Features
- **OLED Display**: Provides real-time feedback on the current layer and actions.
- **Rotary Encoder**: Allows intuitive navigation and control.
- **Keypad**: Configurable buttons for custom macros.
- **Analog Sliders**: Great for volume control or other analog inputs.
- **Layer System**: Up to 4 customizable layers for different workflows.
- **HID Functionality**: Enables macro control using the HID-Project library.

## How to Customize
### Configuration Files
The functionality of KommPad is defined in the following files:

1. **`config.ino`**:
   - Central configuration file where you can define global settings such as layer names and other initialization parameters.

2. **Layer Files** (`layer1.ino`, `layer2.ino`, `layer3.ino`, `layer4.ino`):
   - Each file corresponds to a specific layer.
   - You can customize the button actions, encoder functions, and other layer-specific behavior in these files.

### Core Files
The following files implement the core functionality and generally do not need modification:

1. **`kommpad.ino`**:
   - Main program loop and general control logic.

2. **`deej.ino`**:
   - Handles the analog sliders and processes their input values.

3. **`display.ino`**:
   - Manages the OLED display and provides feedback to the user.

You are free to modify any part of the code, but changes to the core files are typically unnecessary unless you want to extend functionality.

## HID-Project Library
KommPad uses the HID-Project library to emulate keyboard and mouse inputs. This library allows you to create powerful macros, such as:

- Key combinations (e.g., `Ctrl + C`, `Alt + Tab`)
- Mouse movements and clicks
- Media control (e.g., volume up, play/pause)

### Changing Macros
To modify macros:
1. Open the appropriate layer file (`layer1.ino`, `layer2.ino`, etc.).
2. Locate the button or encoder function you want to change.
3. Use HID commands provided by the library, such as:
   ```cpp
   Keyboard.press(KEY_LEFT_CTRL);
   Keyboard.press('C');
   Keyboard.releaseAll();
   ```
   or
   ```cpp
   Consumer.write(MEDIA_VOLUME_UP);
   ```
4. Upload the updated code to your KommPad.

For more details on the HID-Project library, refer to its [official documentation](https://github.com/NicoHood/HID).

## Getting Started
1. Connect your KommPad to your computer via USB.
2. The default configuration will be loaded and ready to use.
3. To customize:
   - Edit `config.ino` and the layer files as described above.
   - Compile and upload the code using the Arduino IDE.

## Hardware Information
KommPad is sold as a complete hardware unit and includes:
- A 2x3 button matrix keypad
- Rotary encoder with a push button
- 2.8-inch OLED display (128x32 resolution)
- 3 analog potentiometers for custom controls
- Arduino-compatible microcontroller (Arduino Pro Micro)

All components are preassembled and tested for optimal performance.

## Support
For questions or assistance, feel free to contact me through discord https://discordapp.com/users/kommwtria.

Enjoy using KommPad to streamline your workflows!

