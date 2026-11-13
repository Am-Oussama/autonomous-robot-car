#include "Config.h"
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(){ 
                                        }

void UltrasonicSensor::begin(){
    pinMode(Config::TRIG,OUTPUT);
    pinMode(Config::ECHO,INPUT);
}

int UltrasonicSensor::getDistance(){
    digitalWrite(Config::TRIG,LOW);
    delayMicroseconds(2);

    digitalWrite(Config::TRIG,HIGH);
    delayMicroseconds(10);

    digitalWrite(Config::TRIG,LOW);


    unsigned long duration = pulseIn(Config::ECHO,HIGH,30000);
    
    if (duration==0)
        return Config::NO_ECHO_DISTANCE_CM;

    int distance = duration * 0.0343 / 2;
    return distance;
}
                                    