/*
Header file for checking if certain inputs are received from the 2 outputs of the receiver

Will read PWM signals from both inputs of the receiver and convert them to integer values between -100 and 100
Depending on the values of both channels determine if a certain stick position is reached
stick positions:
    position: up
        ch1: 100
        ch2: 0
    position: diagonal up right
        ch1: 100
        ch2: 100
    position: right
        ch1: 0
        ch2: 100
    position: diagonal down right
        ch1: -100
        ch2: 100
    position: down
        ch1: -100
        ch2: 0
    position: diagonal down left
        ch1: -100
        ch2: -100
    position: left
        ch1: 0
        ch2: -100
    position: diagonal up left
        ch1: 100
        ch2: -100
    position: default
        ch1: 0
        ch2: 0 
*/

#include <Arduino.h>

class Receiver {

  private:
    uint8_t CH1_PIN;
    uint8_t CH2_PIN;

  public:

    Receiver(uint8_t ch1Pin, uint8_t ch2Pin);
    int16_t getChannel1Value();
    int16_t getChannel2Value();
    bool isUp();
    bool isDiagonalUpRight();
    bool isRight();
    bool isDiagonalDownRight();
    bool isDown();
    bool isDiagonalDownLeft();
    bool isLeft();
    bool isDiagonalUpLeft();
    bool isDefault();
};