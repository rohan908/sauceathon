#include <Arduino.h>

#include "../lib/playsong.h"

#define BUZZER_PIN 9
#define INFO_PIN A0

playsong song(BUZZER_PIN);

static unsigned long currentTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INFO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  song.stepSong(currentTime);


}
