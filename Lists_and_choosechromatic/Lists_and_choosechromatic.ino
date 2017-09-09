void setup() {
  // put your setup code here, to run once:
char CHROMATIC = { "C", "C#/Db", "D", "D#/Eb", "E", "F", "F#/Gb", "G", "G#/Ab", "A", "A#/Bb", "B"}
char STATE = { "Major", "Minor", "Diminished", "Augmented", "Sustained2", "Sustained4", "5"}
char NUMBER = { "6", "7", "add9", "9", "11", "13" }
}

char choosechromatic() {
  // put your main code here, to run repeatedly:
  int r = 0
  char chrom = CHROMATIC[r]
  int buttonState = 0
  if (buttonState == HIGH) {
    char r ++
    return CHROMATIC[r];
  } else {
    int choosechromatic();
  }
}
}
