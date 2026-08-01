// ---- Motor A pin definitions ----
#define IN1 14
#define IN2 27
#define ENA 25  // PWM speed control

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Setup PWM on ENA pin (ESP32 core 3.x syntax)
  ledcAttach(ENA, 5000, 8); // pin, freq Hz, resolution bits

  stopMotor();
}

void loop() {
  Serial.println("Forward");
  motorForward(200);   // 0-255 speed
  delay(2000);

  Serial.println("Stop");
  stopMotor();
  delay(1000);

  Serial.println("Backward");
  motorBackward(200);
  delay(2000);

  Serial.println("Stop");
  stopMotor();
  delay(1000);
}

// ---- Motor control functions ----

void motorForward(int speed) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  ledcWrite(ENA, speed);
}

void motorBackward(int speed) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  ledcWrite(ENA, speed);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  ledcWrite(ENA, 0);
}