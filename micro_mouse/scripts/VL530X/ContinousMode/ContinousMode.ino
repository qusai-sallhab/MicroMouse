#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;
void setup() {
  Serial.begin(115200);

  sensor.setTimeout(500);
  if(!sensor.init())
  {
    Serial.println("failed to start the sensor ^;^");
  }

    Serial.println("sensor started ^-^");

  
  
  sensor.startContinuous();
}

void loop() {
   
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }


}
