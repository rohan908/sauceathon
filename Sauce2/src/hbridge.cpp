#include <Arduino.h>
#include "../lib/hbridge.h"

HBridge::HBridge(uint8_t in1Pin, uint8_t in2Pin, uint8_t in3Pin, uint8_t in4Pin)
{
    this->IN1_PIN = in1Pin;
    this->IN2_PIN = in2Pin;
    this->IN3_PIN = in3Pin;
    this->IN4_PIN = in4Pin;

    pinMode(IN1_PIN, OUTPUT);
    pinMode(IN2_PIN, OUTPUT);
    pinMode(IN3_PIN, OUTPUT);
    pinMode(IN4_PIN, OUTPUT);
}

/* 
function to set motor 1 speed and direction
if direction is true, motor spins forward
if direction is false, motor spins backward

*/
void HBridge::setMotor1(int8_t speed, bool direction)
{
    // constrain speed to 0-100
    if (speed < 0) speed = 0;
    if (speed > 100) speed = 100;

    uint8_t pwmValue = map(speed, 0, 100, 0, 255);

    if (direction) {
        analogWrite(IN1_PIN, pwmValue);
        analogWrite(IN2_PIN, 0);
    } else {
        analogWrite(IN1_PIN, 0);
        analogWrite(IN2_PIN, pwmValue);
    }
}

/*
function to set motor 2 speed and direction
if direction is true, motor spins forward
if direction is false, motor spins backward

*/
void HBridge::setMotor2(int8_t speed, bool direction)
{
    // constrain speed to 0-100
    if (speed < 0) speed = 0;
    if (speed > 100) speed = 100;

    uint8_t pwmValue = map(speed, 0, 100, 0, 255);

    if (direction) {
        analogWrite(IN3_PIN, pwmValue);
        analogWrite(IN4_PIN, 0);
    } else {
        analogWrite(IN3_PIN, 0);
        analogWrite(IN4_PIN, pwmValue);
    }
}   


