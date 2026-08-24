#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include <Wire.h>

MPU6050 mpu;

bool DMPReady = false;
uint8_t devStatus;
uint8_t FIFOBuffer[64];

Quaternion q;
VectorFloat gravity;
float ypr[3];

void setup() {
  Serial.begin(115200);

  // Start I2C communication
  Wire.begin();
  Wire.setClock(400000);

  // Initialize MPU6050
  mpu.initialize();

  // Check MPU6050 connection
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  Serial.println("MPU6050 connected!");

  // Initialize DMP
  devStatus = mpu.dmpInitialize();

  if (devStatus == 0) {

    // Calibrate the sensors
    mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);

    // Enable DMP
    mpu.setDMPEnabled(true);

    DMPReady = true;

    Serial.println("DMP ready!");
  }
}

void loop() {

  if (!DMPReady) return;

  // Read the latest DMP data
  if (mpu.dmpGetCurrentFIFOPacket(FIFOBuffer)) {

    // Get orientation information
    mpu.dmpGetQuaternion(&q, FIFOBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    // Convert radians to degrees
    float yaw   = ypr[0] * 180 / M_PI;
    float pitch = ypr[1] * 180 / M_PI;
    float roll  = ypr[2] * 180 / M_PI;

    // Print results
    Serial.print("Yaw: ");
    Serial.print(yaw);

    Serial.print(" | Pitch: ");
    Serial.print(pitch);

    Serial.print(" | Roll: ");
    Serial.println(roll);
  }
}