#define ENCODER_A_PIN 16 
#define ENCODER_B_PIN 17

volatile long encoderCount = 0;

void IRAM_ATTR encoderISR_A() {
  bool a = digitalRead(ENCODER_A_PIN);
  bool b = digitalRead(ENCODER_B_PIN);
  if (a == b) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

void IRAM_ATTR encoderISR_B() {
  bool a = digitalRead(ENCODER_A_PIN);
  bool b = digitalRead(ENCODER_B_PIN);
  if (a != b) {
    encoderCount++;
  } else {
    encoderCount--;
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(ENCODER_A_PIN, INPUT_PULLUP);
  pinMode(ENCODER_B_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN), encoderISR_A, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B_PIN), encoderISR_B, CHANGE);
}

void loop() {
  static long lastCount = 0;
  long currentCount = encoderCount; // snapshot volatile var

  if (currentCount != lastCount) {
    Serial.print("Encoder Count: ");
    Serial.println(currentCount);
    lastCount = currentCount;
  }

  delay(50);
}