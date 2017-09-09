#include <MIDI.h>

#include <SD.h>

/* pulse-width modulation (PWM) = vibration.
  pulse-width = half the period
 speaker = HIGH for 'pulse-width' microseconds
         = LOW for 'pulse-width' microseconds.
 *  This pulsing creates a vibration of the desired frequency.
 */

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
int oNotes[] = {  C,  b,  g,  C,  b,   e,  C,  C,  c,  g, a, C };//order of notes 
int xNotes[] = {  c,  c,  c,  c,  c,   c,  c,  c,  c,  c, c, c };//order of notes 
int lNotes[]  = { 160, 160, 160,  160,  160,  160, 160, 160, 160, 160, 160, 160 }; //length of notes(only necessary when playing a prewritten song)
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
      digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order / 2);

      digitalWrite(speakerOut, LOW);
      digitalWrite(speakerOut2, LOW);
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

void loop() {
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++)
  {
    order = oNotes[2];//this number equals the note from oNotes so 3 is equal to C because 0123 
    note = lNotes[i];
    x= xNotes[2];


    duration = note * tempo; // Set up timing

    playTone(); 
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

/*
 * NOTES
 * The program purports to hold a tone for 'duration' microseconds.
 *  Lies lies lies! It holds for at least 'duration' microseconds, _plus_
 *  any overhead created by incremeting elapsed_time (could be in excess of 
 *  3K microseconds) _plus_ overhead of looping and two digitalWrites()
 *  
 * As a result, a tone of 'duration' plays much more slowly than a rest
 *  of 'duration.' rest_count creates a loop variable to bring 'rest' beats 
 *  in line with 'tone' beats of the same length. 
 * 
 * rest_count will be affected by chip architecture and speed, as well as 
 *  overhead from anyprogram mods. Past behavior is no guarantee of future 
 *  performance. Your mileage may vary. Light fuse and get away.
 *  
 * RE-WRITE to include volume, using analogWrite, as with the second program at
 *          http://www.arduino.cc/en/Tutorial/PlayMelody
 * ADD code to make the tempo settable by pot or other input device
 * ADD code to take tempo or volume settable by serial communication 
 *          (Requires 0005 or higher.)
 * ADD code to create a tone offset (higer or lower) through pot etc
 */

