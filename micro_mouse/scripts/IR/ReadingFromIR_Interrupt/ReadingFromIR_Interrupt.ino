int ir_pin = 32;

volatile bool wallDetected = false;

void IRAM_ATTR wallINT(){
  wallDetected = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(ir_pin, INPUT);

  attachInterrupt(digitalPinToInterrupt(ir_pin), wallINT, FALLING);
}

void loop() {
  if(wallDetected){
    Serial.println("Wall In Front");

    wallDetected = false;

  }
  else{
    Serial.println("No Wall");
  }

  delay(5000);
}