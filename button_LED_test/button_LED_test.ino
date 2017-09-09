// Jaiden was here
// constants won't change. They're used here to set pin numbers:
const int button1Pin = 2;     // the number of the pushbutton pin
const int button2Pin=4;
const int led1Pin =  13;// the number of the LED pin
const int led2Pin=12;
const int led3Pin=11;

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int button2State=0;

//comment

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  button1State = digitalRead(button1Pin);
  button2State=digitalRead(button2Pin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    // turn LED on:
    digitalWrite(led1Pin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led1Pin, LOW);
  }
  if(button2State==HIGH){
    digitalWrite(led2Pin,HIGH);
    }
   else{
      digitalWrite(led2Pin,LOW);
    }
}
