
#include <Servo.h>

Servo topServo;
Servo midServo;
Servo bottomServo;

int positions[3] = {0, 90, 180};  // 3 discrete positions

void setup() {
  Serial.begin(9600);
  Serial.println("Please enter a character:");

  topServo.attach(9);
  midServo.attach(10);
  bottomServo.attach(11);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();

    if (incomingChar < 'a' || incomingChar > 'z') {
      return;  // ignore any non a-z
    }

    int index = incomingChar - 'a';  // 0 to 25

    Serial.print("Character received: ");
    Serial.println(incomingChar);

    Serial.print("Index: ");
    Serial.println(index);

    // calculate base-3 digits
    int t = (index / 9) % 3;  // top servo
    int m = (index / 3) % 3;  // middle servo
    int b = (index / 1) % 3;  // bottom servo

    Serial.print("Positions: ");
    Serial.print(t); Serial.print(", ");
    Serial.print(m); Serial.print(", ");
    Serial.println(b);

    // write servo positions
    topServo.write(positions[t]);
    midServo.write(positions[m]);
    bottomServo.write(positions[b]);
  }
}

