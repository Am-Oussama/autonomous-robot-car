#include "RobotController.h"
#include "Config.h"


RobotController::RobotController(MotorDriver& motors, ServoScanner& scanner)
:motorDriver(motors),servoScanner(scanner),currentState(State::FORWARD),
stateStartTime(0),leftDistance(0),rightDistance(0){}


void RobotController::begin(){
    randomSeed(analogRead(A0));//assumes that A0 is not being used by another sensor

    motorDriver.begin();
    servoScanner.begin();

    motorDriver.stop();
    changeState(State::FORWARD);
}

void RobotController::changeState(State newState){
    currentState=newState;
    stateStartTime = millis(); //the exact transition time
    if(newState == State::FORWARD){
        motorDriver.forward();
    }else if(newState == State::REVERSING){
        motorDriver.backward();
    }
}

void RobotController::update(){
    switch (currentState)
    {
    case State::FORWARD:
    {
        int frontDistance = servoScanner.measure();
        if (frontDistance <= Config::OBSTACLE_THRESHOLD_CM){
            motorDriver.stop();
            changeState(State::STOPPING);
        }
        break;
    }//beacuse she has a local variable

    case State::STOPPING:
        if(millis()-stateStartTime >= Config::STOP_BEFORE_REVERSE_MS){
            changeState(State::REVERSING);
        }
        break;

    case State::REVERSING:
        if(millis()-stateStartTime >= Config::REVERSE_DURATION_MS){
            motorDriver.stop();
            changeState(State::STOP_AFTER_REVERSE);
        }
        break;
    
    case State::STOP_AFTER_REVERSE:
        if(millis()-stateStartTime >= Config::STOP_AFTER_REVERSE_MS){
            servoScanner.lookLeft();
            changeState(State::SCAN_LEFT);
        }
        break;
    
    case State::SCAN_LEFT:
        if(millis()-stateStartTime >= Config::SERVO_SIDE_SETTLE_MS){
            leftDistance = servoScanner.measure();
            Serial.print("\nLEFT: ");Serial.print(leftDistance);Serial.println(" cm");
            
            servoScanner.lookRight();
            changeState(State::SCAN_RIGHT);
        }
        break;

    case State::SCAN_RIGHT:
        if(millis()-stateStartTime >= Config::SERVO_SIDE_TO_SIDE_MS){
            rightDistance = servoScanner.measure();
            Serial.print("RIGHT: ");Serial.print(rightDistance);Serial.println(" cm");
            
            servoScanner.backcenter();
            changeState(State::CENTERING);
        }
        break;


    case State::CENTERING:
        if(millis()-stateStartTime >= Config::SERVO_RETURN_CENTER_MS){
            changeState(State::DECIDING);
        }
        break;

    case State::DECIDING:
        if(leftDistance<=Config::OBSTACLE_THRESHOLD_CM && rightDistance<=Config::OBSTACLE_THRESHOLD_CM){
            Serial.println("BOTH SIDES BLOCKED");
            int x = random(2);
            Serial.print("X = ");Serial.println(x);
            if(x==0){
                motorDriver.turnLeft();Serial.println("RANDOM TO THE LEFT");
            }else{
                motorDriver.turnRight();Serial.println("RANDOM TO THE RIGHT");
            }

            changeState(State::RECOVERY);
        }else if(leftDistance>rightDistance){
            Serial.println("DECISION LEFT");
            motorDriver.turnLeft();
            changeState(State::TURNING);
        }else{
            Serial.println("DECISION RIGHT");
            motorDriver.turnRight();
            changeState(State::TURNING);
        }
        break;

    case State::TURNING:
        if (millis() - stateStartTime >= Config::TURN_DURATION_MS){
            motorDriver.stop();
            changeState(State::FORWARD);
        }
        break;

    case State::RECOVERY:
        if(millis()-stateStartTime>=Config::RECOVERY_TURN_DURATION_MS){
            motorDriver.stop();
            changeState(State::FORWARD);
        }
        break;
    
    default:
        break;
    }
}
