#include <esp_system.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("=== ESP32 Information ===");

  Serial.printf("Chip Model: %s\n", ESP.getChipModel());
  Serial.printf("Chip Revision: %d\n", ESP.getChipRevision());
  Serial.printf("CPU Frequency: %d MHz\n", ESP.getCpuFreqMHz());

  Serial.printf("Flash Size: %d MB\n",
                ESP.getFlashChipSize() / (1024 * 1024));

  Serial.printf("Flash Speed: %d MHz\n",
                ESP.getFlashChipSpeed() / 1000000);

  Serial.printf("Free Heap: %d bytes\n", ESP.getFreeHeap());

  Serial.printf("Sketch Size: %d bytes\n", ESP.getSketchSize());
  Serial.printf("Free Sketch Space: %d bytes\n",
                ESP.getFreeSketchSpace());

  Serial.printf("MAC Address: %s\n",
                WiFi.macAddress().c_str());
}

void loop() {
}
