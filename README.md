# KommPad: Macro Pad Project

### Table of Contents

1. [Overview](#overview)
2. [Features](#features)
3. [Deej Configuration](#deej-configuration)
   - [Required Setup](#required-setup)
4. [Reference View](#reference-view)
5. [How to Customize](#how-to-customize)
   - [Core Files](#core-files)
   - [Configuration Files](#configuration-files)
   - [Changing Macros](#changing-macros)
   - [HID-Project Library](#hid-project-library)
6. [Special Features](#special-features)
   - [Help Display](#help-display)
   - [Locking the Start Layer](#locking-the-start-layer)
   - [RGB Functionality](#rgb-functionality)
7. [Getting Started](#getting-started)
8. [Hardware Information](#hardware-information)
9. [Support](#support)

## Overview

KommPad is a customizable macro pad designed for efficiency and ease of use. It features multiple layers, rotary encoder support, an OLED display for feedback, and analog sliders for additional controls. The hardware is predefined and sold as a complete unit, making it easy to set up and start using right away. One additional software needed to be downloaded ([deej](#deej-configuration)) by for the potential meter functionality to be available

## Features

- **OLED Display**: Provides real-time feedback on the current layer and actions.
- **Rotary Encoder**: Allows intuitive navigation and control, with a long-press function to lock the current layer.
- **Single Press Help**: A single press of the rotary encoder displays a help screen showing the macros assigned to the current layer.
- **Keypad**: Configurable buttons for custom macros.
- **Analog Potentiometers**: Great for volume control or other analog inputs.
- **Layer System**: Up to 4 customizable layers for different workflows.
- **HID Functionality**: Enables macro control using the [HID-Project library](https://github.com/NicoHood/HID).

## Deej Configuration

Deej is a library for controlling analog inputs such as potentiometers. KommPad integrates this library to enable smooth analog control over various functions, such as volume adjustments or any other custom analog inputs. This section will guide you through configuring Deej to work with your KommPad.

### Required Setup

**Install and configure Deej**:

- Run the [deej\_installer.bat](https://github.com/anpapag1/KommPad/blob/main/deej_installer.bat) that downloads the deej to program files and puts it in the startup folder
- After the .bat finishes is done, edit the config.yaml as you need
- Deej documentation is available on GitHub: [Deej Repository](https://github.com/omriharel/deej).

## Reference view

```
    [pot 0]      [pot 1]     [pot 2]        _____________________
+------------+------------+------------+   |   Rotary Encoder    |
| Prev Track | Next Track | Play/Pause |  | [  <<  ]  Volume Down |
+------------+------------+------------+  | [ PUSH ]  Press: Mute |
|  Spotify   |  YouTube   |  Layer Up  |  | [  >>  ]  Volume Up   |
+------------+------------+------------+   |_____________________|
```

## How to Customize

### Core Files

The following files implement the core functionality and generally do not need modification:

1. **`kommpad.ino`**:

   - Main program loop and general control logic.

2. **`deej.ino`**:

   - Handles the analog sliders and processes their input values.

3. **`display.ino`**:

   - Manages the OLED display and provides feedback to the user.

You are free to modify any part of the code, but changes to the core files are typically unnecessary unless you want to extend functionality.

### Configuration Files

The functionality of KommPad is defined in the following files:

1. **`config.ino`**:

   - Central configuration file where you can define global settings such as layer names and other initialization parameters.

2. **Layer Files** (`layer1.ino`, `layer2.ino`, `layer3.ino`, `layer4.ino`):

   - Each file corresponds to a specific layer.
   - You can customize the button actions, encoder functions, and other layer-specific behavior in these files.
   - Layer names and actions are defined here. For instance, you can assign unique names to each layer (e.g., "Editing", "Gaming", "Productivity") and specify what each button or encoder action does within that context.

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
   Here is a comprehensive list of actions you can do [HID-Prodject Functions Example](Function_Example.md)
4. Make sure that there is at least an UpLayer() function on the keyboard for changing layers
   ```cpp
   void butNo6_1(){ UpLayer(); }
   ```
5. Assign descriptive actions to each button for clarity (e.g., "Copy", "Paste", "Increase Volume").
6. Upload the updated code to your KommPad.

> [!IMPORTANT]\
> When you upload you need to exit the Deej application because it uses the serial ports that are needed to upload

### HID-Project Library

KommPad uses the HID-Project library to emulate keyboard and mouse inputs. This library allows you to create powerful macros, such as:

- Key combinations (e.g., `Ctrl + C`, `Alt + Tab`)
- Mouse movements and clicks
- Media control (e.g., volume up, play/pause)

For more details on the HID-Project library, refer to its [official documentation](https://github.com/NicoHood/HID).

## Special Features

### Help Display

A single press using the UpLayer() function will display a help screen on the OLED when the help screen is disabled, showing the current layer and the macros assigned to each button. This feature allows for quick reference without disrupting your workflow.

### Locking the Start Layer

The rotary encoder includes a long-press function to lock the current layer. To activate this feature:

1. Press and hold the rotary encoder button.
2. After the specified duration (.5 sec), the current layer will be locked as the start layer.
3. This ensures that even after idle or reset, the device will revert to your preferred layer.

This functionality is especially useful for maintaining a consistent workflow across sessions.

### RGB Functionality

KommPad includes RGB LED support, allowing you to customize lighting effects for enhanced aesthetics and functionality. The RGB features are controlled using the `rgb.ino` file, which provides several predefined effects.

#### Available Effects

1. **Static Effect**:
   - Displays a single static color.
   - Configurable via the `Colors` array in `config.ino`.

2. **Breathing Effect**:
   - Smoothly fades the brightness of the LEDs in and out.
   - Cycles through the colors defined in the `Colors` array.

3. **Rainbow Cycle**:
   - Displays a continuous rainbow effect that cycles through all hues.

#### Configuration

You can configure the RGB settings in the `config.ino` file:
```cpp
brightness = 100; // Set brightness (0-255)
effect = 1;       // Choose effect: 0 - Static, 1 - Breathing, 2 - Rainbow
Colors[0] = 0xff00ff; // Define colors in hexadecimal (e.g., magenta)
Colors[1] = 0x36d06d; // Add more colors as needed
```

## Getting Started

1. Connect your KommPad to your computer via USB.
2. The default configuration will be loaded and ready to use.
3. To customize:
   - Edit `config.ino` and the layer files as described [above](#changing-macros).
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

For questions or assistance, feel free to contact me through discord [https://discordapp.com/users/kommwtria](https://discordapp.com/users/kommwtria).

Enjoy using KommPad to streamline your workflows!

