#include <Arduino.h>
#include "Config.h"

#include "RobotController.h"

MotorDriver motors;
UltrasonicSensor ultrasonic;
ServoScanner scanner(ultrasonic);
RobotController robot(motors,scanner);

void setup() {
  Serial.begin(Config::SERIAL_BAUD);
  robot.begin();
}

void loop() {
  
  robot.update();

}

