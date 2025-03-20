# HID-Project Basic Examples

## Keyboard Functions

```cpp
Keyboard.print("Hello, world!");            // Type "Hello, world!"
Keyboard.println("Hello, world!");          // Type "Hello, world!" + Enter
Keyboard.write('A');                        // Type the letter 'A'
Keyboard.write(KEY_RETURN);                 // Press Enter
Keyboard.press(KEY_LEFT_CTRL);              // Hold Left Ctrl
Keyboard.press('c');                        // Hold 'C' (for Ctrl+C)
Keyboard.releaseAll();                      // Release all keys
Keyboard.press(KEY_ESC);                    // Press Escape key
Keyboard.release(KEY_ESC);                  // Release Escape key
Keyboard.press(KEY_F5);                     // Press F5 (refresh page)
Keyboard.release(KEY_F5);                   // Release F5
```

## Consumer Control (Media Keys)

```cpp
Consumer.write(MEDIA_PLAY_PAUSE);           // Play/Pause media
Consumer.write(MEDIA_STOP);                 // Stop media playback
Consumer.write(MEDIA_NEXT);                 // Next track
Consumer.write(MEDIA_PREVIOUS);             // Previous track
Consumer.write(MEDIA_VOLUME_UP);            // Increase volume
Consumer.write(MEDIA_VOLUME_DOWN);          // Decrease volume
Consumer.write(MEDIA_MUTE);                 // Mute/unmute audio
```

## System Control (Power & Sleep)

```cpp
System.write(SYSTEM_SLEEP);                 // Put PC to sleep
System.write(SYSTEM_WAKE_UP);               // Wake up PC
System.write(SYSTEM_POWER_DOWN);            // Shut down PC
System.write(SYSTEM_RESET);                 // Restart PC
```

## Mouse Functions

```cpp
Mouse.move(10, 10);                         // Move cursor 10px right & 10px down
Mouse.click(MOUSE_LEFT);                    // Left-click
Mouse.click(MOUSE_RIGHT);                   // Right-click
Mouse.press(MOUSE_LEFT);                    // Hold left mouse button
Mouse.release(MOUSE_LEFT);                  // Release left mouse button
Mouse.scroll(1);                             // Scroll up
Mouse.scroll(-1);                            // Scroll down
```

## Gamepad Functions

```cpp
Gamepad.press(1);                           // Press button 1
Gamepad.release(1);                         // Release button 1
Gamepad.xAxis(127);                         // Move X-axis joystick to the middle
Gamepad.yAxis(-127);                        // Move Y-axis joystick to the top
Gamepad.dPad1(HAT_UP);                      // Set D-Pad up
```
# HID-Project Advanced Examples

## Raw HID (Advanced USB HID Communication)

```cpp
uint8_t buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
RawHID.send(buffer, 8);                     // Send raw HID data over USB
RawHID.available();                          // Check if data is available
RawHID.recv(buffer, 8);                      // Receive raw HID data
```

## Absolute Mouse (Graphics Tablets & Special Devices)

```cpp
AbsoluteMouse.moveTo(800, 600);             // Move mouse to absolute position (800,600)
AbsoluteMouse.click(MOUSE_RIGHT);           // Right-click at current position
```

## Boot Keyboard (BIOS-Level Keyboard Emulation)

```cpp
BootKeyboard.press(KEY_ENTER);              // Press Enter key
BootKeyboard.releaseAll();                  // Release all keys
BootKeyboard.print("admin");                // Type "admin"
```

## NKRO Keyboard (Full N-Key Rollover Support)

```cpp
NKROKeyboard.press(KEY_A);                  // Press 'A' with NKRO
NKROKeyboard.press(KEY_S);                  // Press 'S' with NKRO
NKROKeyboard.press(KEY_D);                  // Press 'D' with NKRO
NKROKeyboard.releaseAll();                  // Release all keys
```

## USB Device Management

```cpp
USBDevice.detach();                         // Disconnect USB device
USBDevice.attach();                         // Reconnect USB device
USBDevice.restart();                        // Restart USB device
```

