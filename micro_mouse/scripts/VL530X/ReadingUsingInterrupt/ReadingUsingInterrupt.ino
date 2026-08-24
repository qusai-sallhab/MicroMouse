#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

int INT_PIN = 4;
volatile bool dataReady = false;

void IRAM_ATTR dataReadyISR() { dataReady = true; }

void setup() {
  Serial.begin(115200);
  Wire.begin();
  sensor.setTimeout(500);
  if(!sensor.init())
  {
    Serial.println("sensor didn't work");
    while(1);
  }   

  Serial.println("sensor started ^--^");

  sensor.startContinuous();
  pinMode(INT_PIN,INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), dataReadyISR, FALLING);
  

}

void loop() {
  if (dataReady) {
    dataReady = false;
    Serial.println(sensor.readRangeContinuousMillimeters()); 
    if (sensor.timeoutOccurred()) {  Serial.println("Time out occured"); }
  }

}
