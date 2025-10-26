/*

*/

#include <Arduino.h>
#include "../lib/receiver.h"

Receiver::Receiver(uint8_t ch1Pin, uint8_t ch2Pin) {
    this->CH1_PIN = ch1Pin;
    this->CH2_PIN = ch2Pin;
    pinMode(CH1_PIN, INPUT);
    pinMode(CH2_PIN, INPUT);
}

// Need to add debounce to make sure readings are stable, non blocking
int16_t Receiver::getChannel1Value() {
    int pulseWidth = pulseIn(CH1_PIN, HIGH); // timeout after 25ms
    int16_t value = map(pulseWidth, 1010, 2000, -100, 100);

    // unsigned long highTime = pulseIn(CH1_PIN, HIGH);
    // unsigned long lowTime = pulseIn(CH1_PIN, LOW);
    // unsigned long cycleTime = highTime + lowTime;
    // float dutyCycle = (float)highTime / float(cycleTime);

    return value;

}

int16_t Receiver::getChannel2Value() {
    int pulseWidth = pulseIn(CH2_PIN, HIGH); // timeout after 25ms
    int16_t value = map(pulseWidth, 960, 1990, -100, 100);
    return value;
}

bool Receiver::isUp() {
    return (getChannel1Value() >= 80 && abs(getChannel2Value()) < 10);
}

bool Receiver::isDiagonalUpRight() {
    return (getChannel1Value() >= 80 && getChannel2Value() >= 80);
}

bool Receiver::isRight() {
    return (abs(getChannel1Value()) < 20 && getChannel2Value() >= 80);
}

bool Receiver::isDiagonalDownRight() {
    return (getChannel1Value() <= -80 && getChannel2Value() >= 80);
}

bool Receiver::isDown() {
    return (getChannel1Value() <= -80 && abs(getChannel2Value()) < 10);
}

bool Receiver::isDiagonalDownLeft() {
    return (getChannel1Value() <= -80 && getChannel2Value() <= -80);
}

bool Receiver::isLeft() {
    return (abs(getChannel1Value()) < 20 && getChannel2Value() <= -80);
}

bool Receiver::isDiagonalUpLeft() {
    return (getChannel1Value() >= 80 && getChannel2Value() <= -80);
}

bool Receiver::isDefault(){
    return (abs(getChannel1Value()) < 20 && abs(getChannel2Value()) < 20);
}