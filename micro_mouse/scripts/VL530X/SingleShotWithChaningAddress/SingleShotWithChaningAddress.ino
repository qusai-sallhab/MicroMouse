#include <Wire.h>
#include <VL53L0X.h> 

VL53L0X sensor; 

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  delay(20);
  sensor.setTimeout(500);
  if(!sensor.init())
  {
    Serial.println("can't communicate with the laser Sensor^-^");
    while(1);
  }

  Serial.print("address: ");
  Serial.println(sensor.getAddress());

  //sensor.setAddress(0x30);


  Serial.print("address: ");
  Serial.println(sensor.getAddress());


  delay(1000);
  
  Serial.println("laser sensor is up");

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance: ");
  uint16_t distance=sensor.readRangeSingleMillimeters();
  if(distance<5000)
  {
    Serial.println(distance);
  }
  else
    Serial.println("nothing in my range");
  if(sensor.timeoutOccurred())
  {
     Serial.print("failure");
  }


}


