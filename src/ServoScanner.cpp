#include "ServoScanner.h"
#include "Config.h"


ServoScanner::ServoScanner(UltrasonicSensor& sensor):ultrasonic(sensor){
                                                                        }

void ServoScanner::begin(){
    ultrasonic.begin();

    servo.attach(Config::PIN_SERVO);
    servo.write(Config::SERVO_CENTER_ANGLE);
    delay(500);
}


void ServoScanner::lookLeft(){
    servo.write(Config::SERVO_LEFT_ANGLE);
}
void ServoScanner::lookRight(){
    servo.write(Config::SERVO_RIGHT_ANGLE);
}

void ServoScanner::backcenter(){
    servo.write(Config::SERVO_CENTER_ANGLE);
}


int ServoScanner::measure(){
    return ultrasonic.getDistance();
}