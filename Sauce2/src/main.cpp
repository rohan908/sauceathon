#include <Arduino.h>

#include "../lib/hbridge.h"
#include "../lib/playsong.h"
#include "../lib/receiver.h"

#define BUZZER_PIN 9
#define INFO_PIN A1

playsong song(BUZZER_PIN);
Receiver receiver(A1, A2);

static unsigned long currentTime;

HBridge hbridge(3, 5, NULL, NULL);


void setup() {
  // enable serial communication for debugging
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INFO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  song.stepSong(currentTime);

  hbridge.setMotor1(100, false);
  

  // if(receiver.isUp()) {
  //   Serial.print("Up ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isDiagonalUpRight()) {
  //   Serial.print("Diagonal Up Right ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isRight()) {
  //   Serial.print("Right ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isDiagonalDownRight()) {
  //   Serial.print("Diagonal Down Right ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isDown()) {
  //   Serial.print("Down ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isDiagonalDownLeft()) {
  //   Serial.print("Diagonal Down Left ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

  // if(receiver.isLeft()) {
  //   Serial.print("Left ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }
  // if(receiver.isDiagonalUpLeft()) {
  //   Serial.print("Diagonal Up Left ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }
  // if(receiver.isDefault()) {
  //   Serial.print("Default ");
  //   Serial.print(receiver.getChannel1Value());
  //   Serial.print(" ");
  //   Serial.println(receiver.getChannel2Value());
  // }

}
