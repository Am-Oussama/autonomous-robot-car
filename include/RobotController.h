#pragma once
#include <Arduino.h>
#include "MotorDriver.h"
#include "ServoScanner.h"

class RobotController
{
public:
    RobotController(MotorDriver& motors , ServoScanner& scanner);

    void begin();
    void update();

private:
    MotorDriver& motorDriver;
    ServoScanner& servoScanner;

    enum class State {
        FORWARD,
        STOPPING,
        REVERSING,
        STOP_AFTER_REVERSE,
        SCAN_LEFT,
        SCAN_RIGHT,
        CENTERING,
        DECIDING,
        TURNING,
        RECOVERY
    };


    State currentState;

    unsigned long stateStartTime;

    int leftDistance;
    int rightDistance;

    void changeState(State newState);

};
