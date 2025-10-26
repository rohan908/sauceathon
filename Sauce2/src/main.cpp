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
  //   digitalWrite(LED_BUILTIN, HIGH);
  //   Serial.println("Up");
  // } else {
  //   digitalWrite(LED_BUILTIN, LOW);
  // }

  // print raw analog value of A1
  unsigned long highTime = pulseIn(INFO_PIN, HIGH);
    unsigned long lowTime = pulseIn(INFO_PIN, LOW);
    unsigned long cycleTime = highTime + lowTime;
    float dutyCycle = (float)highTime / float(cycleTime);
  Serial.print("INFO_PIN:");
  Serial.println(dutyCycle);
}
