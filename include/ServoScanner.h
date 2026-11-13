#pragma once
#include <Arduino.h>
#include <Servo.h>
#include "UltrasonicSensor.h"

class ServoScanner
{
public:
    ServoScanner(UltrasonicSensor& sensor);
    void begin();

    void lookLeft();
    void lookRight();
    void backcenter();

    int measure();
private:
    Servo servo;
    UltrasonicSensor& ultrasonic;
};

