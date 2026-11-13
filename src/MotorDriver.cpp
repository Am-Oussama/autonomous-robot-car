#include "MotorDriver.h"
#include "Config.h"

MotorDriver::MotorDriver(){
                            }

void MotorDriver::setSpeed(uint8_t leftSpeed, uint8_t rightSpeed){
    analogWrite(Config::ENA, leftSpeed);
    analogWrite(Config::ENB, rightSpeed);
}

void MotorDriver::begin(){
    pinMode(Config::ENA,OUTPUT);
    pinMode(Config::ENB,OUTPUT);
    
    pinMode(Config::IN1,OUTPUT);
    pinMode(Config::IN2,OUTPUT);
    pinMode(Config::IN3,OUTPUT);
    pinMode(Config::IN4,OUTPUT);
    stop();
}

void MotorDriver::stop(){
    setSpeed(0,0);
    
    digitalWrite(Config::IN1,LOW);
    digitalWrite(Config::IN2,LOW);
    digitalWrite(Config::IN3,LOW);
    digitalWrite(Config::IN4,LOW);
    
}

void MotorDriver::forward(){
    setSpeed(Config::LEFT_MOTOR_SPEED , Config::RIGHT_MOTOR_SPEED);
    
    digitalWrite(Config::IN1,LOW);
    digitalWrite(Config::IN2,HIGH);
    digitalWrite(Config::IN3,LOW);
    digitalWrite(Config::IN4,HIGH);
    
}
void MotorDriver::backward(){
    setSpeed(Config::LEFT_MOTOR_SPEED , Config::RIGHT_MOTOR_SPEED);
    
    digitalWrite(Config::IN1,HIGH);
    digitalWrite(Config::IN2,LOW);
    digitalWrite(Config::IN3,HIGH);
    digitalWrite(Config::IN4,LOW);
    
}

void MotorDriver::turnLeft(){
    setSpeed(Config::LEFT_MOTOR_SPEED,Config::RIGHT_MOTOR_SPEED);

    digitalWrite(Config::IN1,LOW);
    digitalWrite(Config::IN2,LOW);
    digitalWrite(Config::IN3,LOW);
    digitalWrite(Config::IN4,HIGH);

}
void MotorDriver::turnRight(){
    setSpeed(Config::LEFT_MOTOR_SPEED,Config::RIGHT_MOTOR_SPEED);

    digitalWrite(Config::IN1,LOW);
    digitalWrite(Config::IN2,HIGH);
    digitalWrite(Config::IN3,LOW);
    digitalWrite(Config::IN4,LOW);
}

