#include <VL53L0X.h>
#include <Wire.h>

VL53L0X firstSensor;
VL53L0X secondSensor;

int xshut=4;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(xshut,OUTPUT);
  digitalWrite(xshut, LOW);
  delay(20);

  if(!firstSensor.init())
  {
    Serial.println("first sensor failed");
    while(1);
  }
    Serial.println("first sensor initialized");
    firstSensor.setAddress(0x30);
    
    delay(20);
    digitalWrite(xshut, HIGH);
      
    if(!secondSensor.init())
    {
      Serial.println("second sensor failed");
      while(1);
    }
    Serial.println("second sensor initialized");

    firstSensor.startContinuous();
    secondSensor.startContinuous();
  // put your setup code here, to run once:

}

void loop() {
  Serial.print("firstSensor distance: ");
  Serial.println(firstSensor.readRangeContinuousMillimeters());

  Serial.print("secondSensor distance: ");
  Serial.println(secondSensor.readRangeContinuousMillimeters());

}