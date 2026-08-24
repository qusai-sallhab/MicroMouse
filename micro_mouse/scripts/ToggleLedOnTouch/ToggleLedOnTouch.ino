//pins
int onBoardLed=2;
int touchPin=4;

//variables
bool ledOn;
bool touched;

void setup() {
    Serial.begin(115200);
    pinMode(onBoardLed,OUTPUT);

    digitalWrite(onBoardLed,LOW);
    ledOn=false;
    touched=false;
}   


void loop() {
  // put your main code here, to run repeatedly:
  touched=touchRead(touchPin)<800;
  Serial.println(touchRead(touchPin));
  if(touched)
  {
    ToggleLed();
    delay(300);
  }
}

void ToggleLed()
{
  ledOn=!ledOn;
  digitalWrite(onBoardLed,ledOn);
}
