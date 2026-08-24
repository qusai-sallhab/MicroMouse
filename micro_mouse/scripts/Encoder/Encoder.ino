//pins
int c1Pin=18;
int c2Pin=19;

volatile long encoderCount=0;

void IRAM_ATTR EncoderISR_C1()
{
    bool a= digitalRead(c1Pin);
    bool b= digitalRead(c2Pin);

    if(a!=b)
    {
      encoderCount++;
    }
    else
    {
      encoderCount--;
    }
}

void IRAM_ATTR EncoderISR_C2()
{
    bool a= digitalRead(c1Pin);
    bool b= digitalRead(c2Pin);

    if(a==b)
    {
      encoderCount++;
    }
    else
    {
      encoderCount--;
    }

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(c1Pin),EncoderISR_C1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(c2Pin),EncoderISR_C2,CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Count: ");
  Serial.println(encoderCount);

}
