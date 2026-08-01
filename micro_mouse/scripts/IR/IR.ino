#define IR_PIN 34

void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  bool obstacle = (digitalRead(IR_PIN) == LOW); // LOW = obstacle detected (typical)

  Serial.println(obstacle ? "OBSTACLE" : "clear");

  delay(200);
}