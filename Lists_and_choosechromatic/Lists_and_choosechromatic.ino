void setup() {
}
  char CHROMATIC[] = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"};
  char STATE[] = { "None", "Major", "Minor", "Diminished", "Augmented", "Sustained2", "Sustained4"};
  char NUMBER[] = { "None", "Maj7", "6", "7", "add9", "9", "11", "13"};
  int c = 0;
  int s = 0;
  int n = 0;
  int b = 0;
  int buttonState = 0;
  int button1State = 0;
  int button2State = 0;
  int button3State = 0;
  
char choosechromatic() {
  // index root Chord (C, D, E, etc.)
  if (buttonState == HIGH) {
    int c ++;
    return CHROMATIC[c];
  } else {
    int choosechromatic();
  }
}

char choosestate() {
  // index state of chord (major, minor, etc.)
  if (button1State == HIGH) {
    int s ++;
    return STATE[s];
  } else {
    int choosestate();
  }
}

char choosenumber() {
  // index number of chord (7, 9, etc.)
  if (button2State == HIGH) {
    int n ++;
    return NUMBER[n];
  } else {
    int choosenumber();
  }
}

char choosebass() {
  // index bass note of chord (C, D, E, etc.)
  if (button3State == HIGH) {
    int b ++;
    return CHROMATIC[b];
  } else {
    int choosebass();
  }
}

char constructchord() {
  char CHORD[5] = {CHROMATIC[b]};
  if (n == 1) {
    CHORD[1] = CHROMATIC[c-1];
  }
  if (n == 3 or 5) {
    CHORD[1] = CHROMATIC[c-2]; 
  }
  if (n != 1 or 3 or 5) {
    CHORD[1] = CHROMATIC[c];
  }
  if (s == 5) {
    CHORD[2] = CHROMATIC[c+2];
  }
  if (s == 2 or 3) {
    CHORD[2] = CHROMATIC[c+3];
  }
  if (s == 6) {
    CHORD[2] = CHROMATIC[c+5];
  }
  if (s == 1 or 4) {
    CHORD[2] = CHROMATIC[c+4];
  }
  if (s == 3) {
    CHORD[3] = CHROMATIC[c+6];
  }
  if (s == 4) {
    CHORD[3] = CHROMATIC[c+8];
  }
  if (s != 3 or 4) {
    CHORD[3] = CHROMATIC[c+7]
  }
  if (n == 4 or 5) {
    CHORD[4] = CHROMATIC[c+2];
  }
  if (n == 2) {
    CHORD[4] = CHROMATIC[c+9];
  }
  if (n != 4 or 2) {
    CHORD[4] =CHROMATIC[c];
  }
  return CHORD;
}


