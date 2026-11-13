#pragma once
#include <Arduino.h>

class UltrasonicSensor{
public:
    UltrasonicSensor();
    void begin();
    int getDistance();

};
