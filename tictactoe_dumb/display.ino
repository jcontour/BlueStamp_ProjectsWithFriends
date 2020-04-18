void displaySelected() {
  if (currentMillis - selectedBlinkMillis > selectedBlinkInterval) {
    selectedBlinkMillis = currentMillis;
    if (selectedLedState == LOW) {
      selectedLedState = HIGH;
    } else {
      selectedLedState = LOW;
    }
    digitalWrite(leds[selected], selectedLedState);
  }
}

void showActiveTurn () {
  if (currentMillis - currTurnBlinkMillis > currTurnBlinkInterval) {
    currTurnBlinkMillis = currentMillis;
    if (currTurnLedState == LOW) {
      currTurnLedState = HIGH;
    } else {
      currTurnLedState = LOW;
    }
    for (int i = 0; i < 9; i ++) {
      if (tokens[i] == whoseTurn){
        digitalWrite(leds[i], currTurnLedState);
      } else if (tokens[i] != 0){
        digitalWrite(leds[i], HIGH);
      } else if (i != selected) {
        digitalWrite(leds[i], LOW);
      }
    }
  }
}
