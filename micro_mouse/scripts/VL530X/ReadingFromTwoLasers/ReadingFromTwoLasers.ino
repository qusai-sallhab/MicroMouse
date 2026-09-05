#include <VL53L0X.h>
#include <Wire.h>

VL53L0X firstSensor;
VL53L0X secondSensor;

int secondXshut=4;
int firstXshut=5;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  pinMode(secondXshut,OUTPUT);
  digitalWrite(secondXshut, LOW);
  delay(20);

  pinMode(firstXshut,OUTPUT);
  digitalWrite(firstXshut, LOW);
  delay(20);
  digitalWrite(firstXshut, HIGH);

  if(!firstSensor.init())
  {
    Serial.println("first sensor failed");
    while(1);
  }
    Serial.println("first sensor initialized");
    firstSensor.setAddress(0x30);
    
    delay(20);
    digitalWrite(secondXshut, HIGH);
      
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
