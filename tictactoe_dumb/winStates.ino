void checkForEndGame() {
  if (tokens[0] != 0 && tokens[0] == tokens[1] && tokens[1] == tokens[2]) {
    win1 = 0;
    win2 = 1;
    win3 = 2;
    gameOver = true;
  } else if (tokens[3] != 0 && tokens[3] == tokens[4] && tokens[4] == tokens[5]) {
    win1 = 3;
    win2 = 4;
    win3 = 5;
    gameOver = true;
  } else if (tokens[6] != 0 && tokens[6] == tokens[7] && tokens[7] == tokens[8]) {
    win1 = 6;
    win2 = 7;
    win3 = 8;
    gameOver = true;
  } else if (tokens[0] != 0 && tokens[0] == tokens[3] && tokens[3] == tokens[6]) {
    win1 = 0;
    win2 = 3;
    win3 = 6;
    gameOver = true;
  } else if (tokens[1] != 0 && tokens[1] == tokens[4] && tokens[4] == tokens[7]) {
    win1 = 1;
    win2 = 4;
    win3 = 7;
    gameOver = true;
  } else if (tokens[2] != 0 && tokens[2] == tokens[5] && tokens[5] == tokens[8]) {
    win1 = 2;
    win2 = 5;
    win3 = 8;
    gameOver = true;
  } else if (tokens[0] != 0 && tokens[0] == tokens[4] && tokens[4] == tokens[8]) {
    win1 = 0;
    win2 = 4;
    win3 = 8;
    gameOver = true;
  } else if (tokens[2] != 0 && tokens[2] == tokens[4] && tokens[4] == tokens[6]) {
    win1 = 2;
    win2 = 4;
    win3 = 6;
    gameOver = true;
  } else if (numMoves == 9){
    win1 = 0;
    win2 = 4;
    win3 = 6;
    gameOver = true;
  }
}

void reset(int a, int b, int c) {
  Serial.print("resetting...");

  for (int i = 0; i < 5; i ++) {
    digitalWrite(leds[a], HIGH);
    digitalWrite(leds[b], HIGH);
    digitalWrite(leds[c], HIGH);
    delay (500);
    digitalWrite(leds[a], LOW);
    digitalWrite(leds[b], LOW);
    digitalWrite(leds[c], LOW);
    delay (500);
  }

  for (int i = 0; i < 9; i ++) {
    tokens[i] = 0;
  }
  selected = 0;
  gameOver = false;

}
