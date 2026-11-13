#pragma once
#include<Arduino.h>

namespace Config 
{
    //Motor
    constexpr uint8_t ENA = 5;
    constexpr uint8_t ENB = 6;
    constexpr uint8_t IN1 = 7;
    constexpr uint8_t IN2 = 8;
    constexpr uint8_t IN3 = 9;
    constexpr uint8_t IN4 = 10;
    
    constexpr uint8_t LEFT_MOTOR_SPEED  = 180;
    constexpr uint8_t RIGHT_MOTOR_SPEED = 185;
    constexpr unsigned long TURN_DURATION_MS = 500; //duration for the car to turn left/right
    
    //Ultrasonic sensor
    constexpr uint8_t TRIG = 12;
    constexpr uint8_t ECHO = 13;
    constexpr uint16_t MAX_DISTANCE = 200;
    constexpr uint16_t NO_ECHO_DISTANCE_CM = MAX_DISTANCE + 40;
    constexpr int OBSTACLE_THRESHOLD_CM = 20; //int not uint16_t because we will compare it with an int

    //Servo
    constexpr uint8_t PIN_SERVO = 3;
    constexpr int SERVO_CENTER_ANGLE = 53;
    constexpr int SERVO_LEFT_ANGLE   = SERVO_CENTER_ANGLE + 40;
    constexpr int SERVO_RIGHT_ANGLE  = SERVO_CENTER_ANGLE - 40;
    constexpr unsigned long SERVO_SIDE_SETTLE_MS = 500;
    constexpr unsigned long SERVO_RETURN_CENTER_MS = 500;
    constexpr unsigned long SERVO_SIDE_TO_SIDE_MS = 800;


    constexpr uint32_t SERIAL_BAUD = 9600;
    
    
    // ...
    constexpr unsigned long STOP_BEFORE_REVERSE_MS = 300;
    constexpr unsigned long STOP_AFTER_REVERSE_MS = 300;
    constexpr unsigned long REVERSE_DURATION_MS = 400;

    //RECOVERY
    constexpr unsigned long RECOVERY_TURN_DURATION_MS = 850;
}