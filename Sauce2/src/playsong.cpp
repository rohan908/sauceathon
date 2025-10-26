#include <Arduino.h>
#include "../lib/playsong.h"

// subway surfers!

playsong::playsong(uint8_t buzzerPin) {
  //start song
  this->BUZZER_PIN = buzzerPin;
  pinMode(BUZZER_PIN, OUTPUT);
  lastNoteTime = millis();
  currentNote = 0;
  uint8_t noteDuration = 1000 / durations[currentNote];
  tone(BUZZER_PIN, melody[currentNote], noteDuration);
  lastNoteDuration = noteDuration;
  currentNote++;
};

void playsong::stepSong(unsigned long currentTime)
{
    if (currentNote < songSize && currentTime - lastNoteTime >= lastNoteDuration) {
      int noteDuration = 1000 / durations[currentNote];
      tone(BUZZER_PIN, melody[currentNote], noteDuration);
      currentNote++;
      if (currentNote >= songSize) {
        currentNote = 0;
      }
      lastNoteDuration = noteDuration;
      lastNoteTime = currentTime;
    }
}

playsong::~playsong()
{
}
