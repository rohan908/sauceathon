#include <Arduino.h>
#include "pitches.h"

class playsong
{
private:
    /* data */
    uint8_t currentNote = 0;
    uint8_t BUZZER_PIN;

    // subway surfers!
    
    uint8_t songSize = 94;
    uint16_t melody[100] = {
      NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,
      NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,
      NOTE_C4, REST, NOTE_G4, REST, NOTE_AS4, NOTE_C5, NOTE_AS4, REST, NOTE_F4, NOTE_DS4, REST,
    
      NOTE_C4, REST, NOTE_E4, REST, NOTE_G4, NOTE_A4, NOTE_AS4,
      NOTE_C5, REST, NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST,
      NOTE_AS4, REST, NOTE_AS4, NOTE_C5, REST, NOTE_AS4, NOTE_A4, REST,
      REST,
      NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST, NOTE_AS4, REST, NOTE_E5,
      REST,
    
      NOTE_C5, REST, NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST,
      NOTE_AS4, REST, NOTE_AS4, NOTE_C5, REST, NOTE_AS4, NOTE_A4, REST,
      REST,
      NOTE_C5, REST, NOTE_AS4, REST, NOTE_A4, REST, NOTE_AS4, REST, NOTE_E4,
      REST,
    };
    
    uint8_t durations[100] = {
      4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,
      4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,
      4, 8, 4, 8, 4, 8, 8, 16, 8, 8, 16,
    
      4, 8, 4, 8, 4, 4, 4,
      8, 16, 8, 16, 8, 16, 8, 16,
      8, 16, 8, 8, 16, 8, 8, 16,
      4,
      8, 16, 8, 16, 8, 16, 8, 4, 8,
      4,
    
      8, 16, 8, 16, 8, 16, 8, 16,
      8, 16, 8, 8, 16, 8, 8, 16,
      4,
      8, 16, 8, 16, 8, 16, 8, 4, 8,
      1
    };
    

    // pirates of the carribean
    /*
    uint8_t songSize = 187;
    uint16_t melody[250] = {
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
        NOTE_A4, NOTE_G4, NOTE_A4, REST,
        
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
        NOTE_A4, NOTE_G4, NOTE_A4, REST,
        
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
        NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
        NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
        NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
        
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_D5, NOTE_E5, NOTE_A4, REST,
        NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
        NOTE_C5, NOTE_A4, NOTE_B4, REST,
        
        NOTE_A4, NOTE_A4,
        //Repeat of first part
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
        NOTE_A4, NOTE_G4, NOTE_A4, REST,
        
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
        NOTE_A4, NOTE_G4, NOTE_A4, REST,
        
        NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
        NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
        NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
        NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,
        
        NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
        NOTE_D5, NOTE_E5, NOTE_A4, REST,
        NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
        NOTE_C5, NOTE_A4, NOTE_B4, REST,
        //End of Repeat
        
        NOTE_E5, REST, REST, NOTE_F5, REST, REST,
        NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
        NOTE_D5, REST, REST, NOTE_C5, REST, REST,
        NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,
        
        NOTE_E5, REST, REST, NOTE_F5, REST, REST,
        NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
        NOTE_D5, REST, REST, NOTE_C5, REST, REST,
        NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4
      };
      
      uint8_t durations[250] = {
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        4, 8, 4, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 4,
        
        4, 8,
        //Repeat of First Part
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 8, 8,
        8, 8, 8, 4, 8,
        
        8, 8, 4, 8, 8,
        4, 8, 4, 8,
        8, 8, 4, 8, 8,
        8, 8, 4, 4,
        //End of Repeat
        
        4, 8, 4, 4, 8, 4,
        8, 8, 8, 8, 8, 8, 8, 8, 4,
        4, 8, 4, 4, 8, 4,
        8, 8, 8, 8, 8, 2,
        
        4, 8, 4, 4, 8, 4,
        8, 8, 8, 8, 8, 8, 8, 8, 4,
        4, 8, 4, 4, 8, 4,
        8, 8, 8, 8, 8, 2
      };
    */

    unsigned long lastNoteTime = 0;
    uint8_t lastNoteDuration = 0;

public:

    void stepSong(unsigned long currentTime);
    playsong(uint8_t buzzerPin);
    ~playsong();
};