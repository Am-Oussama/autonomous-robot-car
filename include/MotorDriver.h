#pragma once
#include<Arduino.h>

class MotorDriver{
public:
    MotorDriver();
    void begin();
    void forward();
    void backward();
    void stop();
    void turnLeft();
    void turnRight();

private:
    void setSpeed(uint8_t leftSpeed, uint8_t rightSpeed);    
};