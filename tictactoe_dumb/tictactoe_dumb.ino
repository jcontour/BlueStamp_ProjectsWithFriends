const int x1y1 = 2;
const int x2y1 = 3;
const int x3y1 = 4;

const int x1y2 = 5;
const int x2y2 = 6;
const int x3y2 = 7;

const int x1y3 = 8;
const int x2y3 = 9;
const int x3y3 = 10;

int leds[] = {x1y1, x2y1, x3y1, x1y2, x2y2, x3y2, x1y3, x2y3, x3y3};
int tokens[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

const int select = 12;
const int next = 13;

int nextState = 0;         // current state of the button
int lastNextState = 0;     // previous state of the button
int selectState = 0;
int lastSelectState = 0;

int selected = 0;
int whoseTurn = 1;
int numMoves = 0;

bool gameOver = false;
int win1, win2, win3;

unsigned long currentMillis;
unsigned long selectedBlinkMillis = 0;
const long selectedBlinkInterval = 100;
int selectedLedState = LOW;

unsigned long currTurnBlinkMillis = 0;
const long currTurnBlinkInterval = 250;
int currTurnLedState = LOW;


void setup() {
  pinMode(x1y1, OUTPUT);
  pinMode(x2y1, OUTPUT);
  pinMode(x3y1, OUTPUT);
  pinMode(x1y2, OUTPUT);
  pinMode(x2y2, OUTPUT);
  pinMode(x3y2, OUTPUT);
  pinMode(x1y3, OUTPUT);
  pinMode(x2y3, OUTPUT);
  pinMode(x3y3, OUTPUT);
  pinMode(select, INPUT);
  pinMode(next, INPUT);

  Serial.begin(9600);
  displaySelected();
}

void loop() {
  nextState = digitalRead(next);
  selectState = digitalRead(select);
  currentMillis = millis();

  if (!gameOver) {
    chooseSpot();
    makeSelection();
    displaySelected();
    showActiveTurn();
  } else {
    reset(win1, win2, win3);
  }
}

void chooseSpot() {
  // compare the buttonState to its previous state
  if (nextState != lastNextState) {
    // if the state has changed, increment the counter
    if (nextState == HIGH) {
      nextSpot();
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastNextState = nextState;
}

void makeSelection() {
  // compare the buttonState to its previous state
  if (selectState != lastSelectState) {
    // if the state has changed, increment the counter
    if (selectState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      tokens[selected] = whoseTurn;
      numMoves ++;
      checkForEndGame();
      
      // switchTurns
      if (whoseTurn == 1) {
        whoseTurn = 2;
      } else {
        whoseTurn = 1;
      }
      for (int i = 0; i < 9; i ++) {
        Serial.print(" ");
        Serial.print(tokens[i]);
        if (i == 2 || i == 5 || i == 8) {
          Serial.println("");
        }
        if (i == 8) {
          Serial.println ("------");
        }
      }
      nextSpot();
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastSelectState = selectState;
}

void nextSpot() {
  selected++;
  if (selected > 8) {
    selected = 0;
  }

  while (tokens[selected] != 0) {
    selected ++;
    if (selected > 8) {
      selected = 0;
    }
  }
}

void componentTest() {
  //check if all LEDs are working
  for (int i = 0; i < 9; i ++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
    delay(100);
  }
  // check if buttons are working
  Serial.print("select ");
  Serial.print(digitalRead(select));
  Serial.print(" next ");
  Serial.println(digitalRead(next));
}
