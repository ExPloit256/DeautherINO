# DeautherINO

A simple and lightweight yet effective ESP32 Deauther

**DeautherINO** is a no-nonsense, straightforward tool based on the ESP32 that can send deauthentication packets to any WiFi network around you. It utilizes the capability of ESP32 for sending raw 802.11 frames, making it suitable for testing network security and learning about WiFi vulnerabilities.

## Features:

- **Easy Setup**: Get started using just the Arduino IDE—no complex frameworks or extra hardware required.
- **Lean & Mean**: The code is kept lean but powerful enough to send deauth packets for disrupting client connections on surrounding networks.
- **Customizable**: Easily change variables such as the channel, packet timing, or target networks.

## Why Use DeautherINO?

- **Security Testing**: Helpful for ethical hackers, security professionals, or anyone who wants to test the security of their WiFi networks.
- **Learning Tool**: Great for exploring how WiFi works and understanding possible vulnerabilities in wireless networks.

> **Reminder**: Please only run this tool on networks you have permission to test. Deauthing devices without consent is illegal and unethical.

## Installation Instructions:

You will need to use **ESP Arduino 2.0.0** for DeautherINO to work properly.

1. Install the Arduino IDE and add to the boards manager ESP32 version 2.0.0.
2. Open `platform.txt`:
   - **Windows**: It should be at `C:\\Users\\<USERNAME>\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\2.0.0\\platform.txt`
   - **Linux**: It should be at `~/.arduino15/packages/esp32/hardware/esp32/2.0.0/platform.txt`
3. Open the file using any text editor.
4. Add `-w` to the following compiler settings:
   ```txt
   build.extra_flags.esp32
   build.extra_flags.esp32s2
   build.extra_flags.esp32s3
   build.extra_flags.esp32c3
5.Add `-zmuldefs` to the following compiler settings
   ```txt
    compiler.c.elf.libs.esp32
    compiler.c.elf.libs.esp32s2
    compiler.c.elf.libs.esp32s3
    compiler.c.elf.libs.esp32c3
