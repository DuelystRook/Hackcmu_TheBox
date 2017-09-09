#include <MIDI.h>

#include <SD.h>

#define  c     3830    // 261 Hz 
#define  d     3400    // 294 Hz 
#define  e     3038    // 329 Hz 
#define  f     2864    // 349 Hz 
#define  g     2550    // 392 Hz 
#define  a     2272    // 440 Hz 
#define  b     2028    // 493 Hz 
#define  C     1912    // 523 Hz 
#define  n     0
//n =no sound 
//put speaker on pin 9
int speakerOut = 12;
int speakerOut2= 8;
int DEBUG = 1; //debugs

void setup()
{ 
  pinMode(speakerOut, OUTPUT);//declares speaker
  pinMode(speakerOut2, OUTPUT);//declares speaker
  if (DEBUG) 
  { 
    Serial.begin(9600); //something about debugging
  } 
}
int oNotes[] = {  C,  b,  g,  C,  b,   e,  C,  C,  g,  g, a, C };//order of notes 
int xNotes[] = {  c,  c,  c,  c,  c,   c,  c,  c,  c,  c, c, c };//order of notes 
int lNotes[]  = { 160 }; //length of notes(only necessary when playing a prewritten song)
int MAX_COUNT = sizeof(oNotes) / 2; // Melody length, for looping.
int MAX_COUNT2 = sizeof(xNotes) / 2;
// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; 

int order = 0;// initializes variables
int note = 0;
int x =0;
long duration  = 0;

// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (order > 0)
  { // if this isn't a Rest beat, while the tone hasvplayed less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration)
      {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(order / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(order / 2);

      // Keep track of how long we pulsed
      elapsed_time += (order);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}
void playTone2() {
  long elapsed_time = 0;
  if (x > 0)
  { // if this isn't a Rest beat, while the tone hasvplayed less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration)
      {

      digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(x / 2);

      // DOWN
      digitalWrite(speakerOut2, LOW);
      delayMicroseconds(x / 2);

      // Keep track of how long we pulsed
      elapsed_time += (x);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}
void loop()
{
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++)
  {
    order = oNotes[2];//this number equals the note from oNotes so 3 is equal to C because 0123 
    note = lNotes[i];
   // x= xNotes[2];


    duration = note * tempo; // Set up timing

    playTone(); 
    playTone2();
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(note);
      Serial.print(" ");    
      Serial.print(order);
      Serial.print(" ");
      Serial.print(x);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}

