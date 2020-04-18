#include "pitches.h"

unsigned long previousMillis = 0;
unsigned long currentMillis;
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
float noteDuration;
float pauseDuration;
bool isPlaying = true;
int whichNote = 0;
const int buzzer = 7;

void setup() {
  // set the initial values for note and pause duration
  noteDuration = 1000 / noteDurations[whichNote];
  pauseDuration = noteDuration * 1.30;
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (isPlaying) {
    // play the first note
    tone(buzzer, melody[whichNote], noteDuration);

    // when the note runs out, reset the prevMillis and
    // switch the bool to run the pause timer
    if (currentMillis - previousMillis >= noteDuration) {
      previousMillis = currentMillis;
      isPlaying = false;
    }

  } else {
    noTone(8);
    if (currentMillis - previousMillis >= pauseDuration) {
      // once the pause timer runs out, switch to the next note and recalculate the
      // play/pause durations for this note
      whichNote++;
      // if we reached the end of the song, start over
      if (whichNote > 7) {
        whichNote = 0;
      }
      noteDuration = 1000 / noteDurations[whichNote];
      pauseDuration = noteDuration * 1.30;

      // reset the prev millis and switch the bool back to playing
      previousMillis = currentMillis;
      isPlaying = true;
    }
  }
  currentMillis = millis();

}
