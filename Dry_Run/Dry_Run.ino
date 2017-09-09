#include <MIDI.h>

#include <SD.h>

const int button1Pin=2;
const int button2Pin=4;
const int button3Pin=5;
const int button4Pin=7;
const int button5Pin=9;
const int button6Pin=11;
const int button7Pin=10;
const int button8Pin=13;

const int LED1Pin=3;
const int LED2Pin=6;
const int LED3Pin=8;

/* pulse-width modulation (PWM) = vibration.
  pulse-width = half the period
 speaker = HIGH for 'pulse-width' microseconds
         = LOW for 'pulse-width' microseconds.
 *  This pulsing creates a vibration of the desired frequency.
 */

int  c   =  3830;    // 261 Hz 
int  d   =  3400;    // 294 Hz 
int  e   =  3038;    // 329 Hz 
int  f   =  2864;    // 349 Hz 
int  g   =  2550;   // 392 Hz 
int  a   =  2272;    // 440 Hz 
int  b   =  2028;    // 493 Hz  
int  n   =  0;
//n =no sound 
//put speaker on pin 9
int speakerOut = 8;
int speakerOut2 = 12;

int DEBUG = 1; //debugs

int button1State = 0;         // variable for reading the pushbutton status
int button2State=0;
int button3State=0;
int button4State=0;
int button5State=0;
int button6State=0;
int button7State=0;
int button8State=0;


int x = 1;

void setup()
{ 
  pinMode(speakerOut, OUTPUT);//declares speaker
  pinMode(speakerOut2, OUTPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(LED1Pin, OUTPUT);
  pinMode(LED2Pin, OUTPUT);
  pinMode(LED3Pin, OUTPUT);
  digitalWrite(LED1Pin, LOW);
  digitalWrite(LED2Pin, LOW);
  digitalWrite(LED3Pin, LOW);
   
  if (DEBUG) 
  { 
    Serial.begin(9600); //something about debugging
  } 
}

int aNotes[] = {  c};
int bNotes[] = {  d };
int cNotes[] = {  e };
int dNotes[] = {  f};
int eNotes[] = {  g};
int fNotes[] = {  a};
int gNotes[] = {  b};
//order of notes 
int lNotes[]  = { 160, 160, 160,  160,  160,  160, 160, 160, 160, 160, 160, 160 }; //length of notes(only necessary when playing a prewritten song)
//int MAX_COUNT = sizeof(oNotes) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; 

int order = 1;// initializes variables
int note = lNotes[3];
long duration  = note*tempo;

//  button1State = digitalRead(button1Pin);
 // button2State=digitalRead(button2Pin);
 // button3State=digitalRead(button3Pin);
  

  
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (order > 0)
  { // if this isn't a Rest beat, while the tone hasvplayed less long than 'duration', pulse speaker HIGH and LOW
    
  
    while(elapsed_time < duration)
      {
         button1State = digitalRead(button1Pin);
         button2State=digitalRead(button2Pin);
         button3State=digitalRead(button3Pin);
         button4State=digitalRead(button4Pin);
         button5State=digitalRead(button5Pin);
         button6State=digitalRead(button6Pin);
         button7State=digitalRead(button7Pin);
         button8State=digitalRead(button8Pin);
         

         if (button8State == HIGH) {
           x += 1;
          if (x%3 == 2) {
            c = 1912;
            d = 1704;
            e = 1518;
            f = 1433;
            g = 1276;
            a = 1136;
            b = 1012;
            aNotes[0] = {  c};
            bNotes[0] = {  d };
            cNotes[0] = {  e };
            dNotes[0] = {  f};
            eNotes[0] = {  g};
            fNotes[0] = {  a};
            gNotes[0] = {  b};
          }
          else if (x%3 == 0) {
            c = 7634;
            d = 6803;
            e = 6061;
            f = 5714;
            g = 5102;
            a = 4546;
            b = 4049;
             aNotes[0] = {  c};
            bNotes[0] = {  d };
            cNotes[0] = {  e };
            dNotes[0] = {  f};
            eNotes[0] = {  g};
            fNotes[0] = {  a};
            gNotes[0] = {  b};
          }
          else {
            c = 3830;
            d = 3400;
            e = 3038;
            f = 2864;
            g = 2550;
            a = 2272;
            b = 2028;
             aNotes[0] = {  c};
            bNotes[0] = {  d };
            cNotes[0] = {  e };
            dNotes[0] = {  f};
            eNotes[0] = {  g};
            fNotes[0] = {  a};
            gNotes[0] = {  b};
          }
          button8State=HIGH;
         }

    // digitalWrite(speakerOut,LOW);
      if (button1State == HIGH) {
        digitalWrite(speakerOut,HIGH);
        digitalWrite(speakerOut2, HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = aNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 
  
      //digitalWrite(speakerOut, LOW);
     // digitalWrite(speakerOut2, LOW);
      //delayMicroseconds(order/3);   
  

   //digitalWrite(speakerOut2,LOW);
   if(button2State==HIGH){
    digitalWrite(speakerOut,HIGH);
    digitalWrite(speakerOut2,HIGH);
    delayMicroseconds(order/2);
    order = bNotes[0];
   // note = lNotes[i];

     //duration = note * tempo; // Set up timing
  
   }

  
    
    //delayMicroseconds(order / 3);  

    if (button3State == HIGH) {
        digitalWrite(speakerOut,HIGH);
        digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = cNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 
  
      
      //delayMicroseconds(order/3);  

       if (button4State == HIGH) {
        digitalWrite(speakerOut,HIGH);
         digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = dNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 
  
      

       if (button5State == HIGH) {
        digitalWrite(speakerOut,HIGH);
         digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = eNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 

      //digitalWrite(speakerOut, LOW);
      //digitalWrite(speakerOut2, LOW);
      //delayMicroseconds(order );  
      //delayMicroseconds(order/3 );  

      if (button6State == HIGH) {
        digitalWrite(speakerOut,HIGH);
         digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = eNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 

      //digitalWrite(speakerOut, LOW);
      //digitalWrite(speakerOut2, LOW);
      //delayMicroseconds(order/10 );  

      if (button7State == HIGH) {
        digitalWrite(speakerOut,HIGH);
         digitalWrite(speakerOut2,HIGH);
      delayMicroseconds(order/2);
    // turn LED on:
      order = eNotes[0];
      //note = lNotes[i];
       //duration = note * tempo; // Set up timing  
  } 

      digitalWrite(speakerOut, LOW);
      digitalWrite(speakerOut2, LOW);
      delayMicroseconds(order/2 );  

      //delayMicroseconds(order/3 );
      //delayMicroseconds(order/3 );
      
      // DOWN
      //digitalWrite(speakerOut, LOW);
      //delayMicroseconds(order );

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

    //order = (oNotes[3] +nNotes[3]) ;//this number equals the note from oNotes so 3 is equal to C because 0123 
    //note = lNotes[i];
    //duration = note * tempo; // Set up timing
    //playTone(); 
    // A pause between notes...
   // delayMicroseconds(pause);
 doublePressTime++;
    playTone();

    
    if(doublePressTime>=doublePressTimer){
     if(button8State==LOW){
       //  octavePhase+=1;
         //octavePhase=octavePhase%3;
         //doublePressTime=0;
     }}
  


    if(octavePhase==0){
      octave=2;
      digitalWrite(LED1Pin, HIGH);
      digitalWrite(LED2Pin, LOW);
      digitalWrite(LED3Pin, LOW);
      }
     else if(octavePhase==1){
      octave=3;
      digitalWrite(LED1Pin, LOW);
      digitalWrite(LED2Pin, HIGH);
      digitalWrite(LED3Pin, LOW);
     }
     else{
      octave=4;
      digitalWrite(LED1Pin, LOW);
      digitalWrite(LED2Pin, LOW);
      digitalWrite(LED3Pin, HIGH);
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

