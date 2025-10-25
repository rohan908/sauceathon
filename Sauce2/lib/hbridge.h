/*
Library for cotrolling an DRV8833 H-Bridge Motor Driver
*/

#include <Arduino.h>

class HBridge
{
private:
    uint8_t IN1_PIN;
    uint8_t IN2_PIN;
    uint8_t IN3_PIN;
    uint8_t IN4_PIN;

public:

    HBridge(uint8_t in1Pin, uint8_t in2Pin, uint8_t in3Pin, uint8_t in4Pin);
    void setMotor1(int8_t speed, bool direction);
    void setMotor2(int8_t speed, bool direction);

};