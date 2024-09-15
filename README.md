# DeautherINO

A simple and lightweight yet effective ESP32 Deauther

**DeautherINO** is a no-nonsense, straightforward tool based on the ESP32 that can send deauthentication packets to any WiFi network around you. It utilizes the capability of ESP32 for sending raw 802.11 frames, making it suitable for testing network security and learning about WiFi vulnerabilities.

## Features:

- **Easy Setup**: Get started using just the Arduino IDE—no complex frameworks or extra hardware required.
- **Lean & Mean**: The code is kept lean but powerful enough to send deauth packets for disrupting client connections on surrounding networks.
- **Customizable**: Fine-tune parameters like channel selection, packet timing, and retransmission settings to match your specific needs and scenarios.


## Why Use DeautherINO?

- **Security Testing**: Helpful for ethical hackers, security professionals, or anyone who wants to test the security of their WiFi networks.
- **Learning Tool**: Great for exploring how WiFi works and understanding possible vulnerabilities in wireless networks.

> **Reminder**: Please only run this tool on networks you have permission to test. Deauthing devices without consent is illegal and unethical.

## Installation Instructions:

You will need to use **ESP32 for Arduino version 2.0.0** for DeautherINO to work properly.

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
5. Add `-zmuldefs` to the following compiler settings.
   ```txt
    compiler.c.elf.libs.esp32
    compiler.c.elf.libs.esp32s2
    compiler.c.elf.libs.esp32s3
    compiler.c.elf.libs.esp32c3
6. Open the Serial Monitor at a baud rate of `115200`.

## Configuration and Usage

**DeautherINO** is designed to be straightforward yet powerful. To get the most out of it, you need to tweak a few settings. Here’s a detailed guide on what each parameter does and how to adjust them based on your scenario.

### `scan_delay`
- **Purpose**: Controls how often the tool scans for new networks.
- **Default**: `10` milliseconds
- **Range**: `10` to `5000` milliseconds (5 seconds)
- **In Practice**: Adjust this based on how quickly you need to detect networks.
  - **Fast Detection**: `10-50 ms` – Best for high-speed scenarios like walking fast or driving.
  - **Balanced Approach**: `100-500 ms` – Ideal for general use where you want a good balance between speed and power usage.
  - **Slow and Steady**: `1000+ ms` – Suitable for stationary setups or reducing power consumption.

### `send_delay`
- **Purpose**: Sets the delay between sending each deauth packet.
- **Default**: `10` milliseconds
- **Range**: `10` to `500` milliseconds
- **In Practice**: Adjust this to manage the rate at which packets are sent.
  - **High Frequency**: `10-30 ms` – Useful for maximum impact but watch out for potential overheating.
  - **Moderate Frequency**: `50-100 ms` – Good for effective deauth while managing power and thermal load.
  - **Low Frequency**: `200+ ms` – Best for reducing stress on the ESP32, especially for prolonged use.

### `deauthPacketRetransmissions`
- **Purpose**: Number of deauth packets to send in each burst.
- **Default**: `20` packets
- **Range**: `5` to `100+` packets
- **In Practice**: Adjust based on how persistent you want the deauth attacks to be.
  - **Low Impact**: `5-10` packets – For a subtle effect or when testing in controlled environments.
  - **Medium Impact**: `20-50` packets – Balanced for general usage with noticeable impact.
  - **High Impact**: `50+` packets – Use with proper cooling for extreme scenarios where maximum disruption is needed.

### `retransmissionSessions`
- **Purpose**: Number of times to repeat the burst of deauth packets.
- **Default**: `3` sessions
- **Range**: `1` to `10` sessions
- **In Practice**: Controls how many times you repeat the deauth burst for thoroughness.
  - **Few Sessions**: `1-3` – For quick tests or less intensive scenarios.
  - **Moderate Sessions**: `4-6` – Good for sustained impact while keeping the load manageable.
  - **Many Sessions**: `7+` – For comprehensive coverage, suitable for scenarios with high network activity or where persistent disruption is needed.

## Recommended Settings for Various Scenarios

To help you get started, here are some recommended settings for different use cases:

**Walking Around (Dynamic Environment)**:
  ```cpp
  int scan_delay = 10;    // Quick scans for rapid changes
  int send_delay = 30;    // Moderate packet sending rate
  int deauthPacketRetransmissions = 20; // Balanced impact
  int retransmissionSessions = 3; // Adequate for mobile use
```

**Mall or Busy Area (High Density)**:
```cpp
   int scan_delay = 50;    // Slightly slower scans to handle high traffic
   int send_delay = 50;    // Balanced sending rate to avoid overwhelming the ESP32
   int deauthPacketRetransmissions = 30; // Medium impact for crowded areas
   int retransmissionSessions = 5; // More sessions for effective coverage
```

**Static Setup (Stationary Environment)**:
```cpp
   int scan_delay = 100;   // Slower scans, less frequent updates
   int send_delay = 100;   // Slower sending to reduce thermal stress
   int deauthPacketRetransmissions = 50; // High impact for thorough testing
   int retransmissionSessions = 7; // Extended sessions for sustained testing
```

**Mobile Setup (On the Move)**:
```cpp
    int scan_delay = 20;    // Fast scans to keep up with movement
    int send_delay = 40;    // Moderate sending rate to balance impact and stability
    int deauthPacketRetransmissions = 20; // Balanced packet count
    int retransmissionSessions = 3; // Adequate for mobile scenarios
```

Adjust these settings based on your specific needs and environment to optimize the performance of DeautherINO.
