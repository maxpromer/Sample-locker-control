#define MOTOR_A_PIN A0
#define MOTOR_B_PIN A1

void MotorSetup() {
  pinMode(MOTOR_A_PIN, OUTPUT);
  pinMode(MOTOR_B_PIN, OUTPUT);
}

void MotorSet(int stats) {
  if (stats == MOTER_FORWARD) {
    digitalWrite(MOTOR_A_PIN, 0);
    digitalWrite(MOTOR_B_PIN, 1);
  } else if (stats == MOTER_BACKWARD) {
    digitalWrite(MOTOR_A_PIN, 1);
    digitalWrite(MOTOR_B_PIN, 1);
  } else {
    digitalWrite(MOTOR_A_PIN, 0);
    digitalWrite(MOTOR_B_PIN, 0);
  }
}

