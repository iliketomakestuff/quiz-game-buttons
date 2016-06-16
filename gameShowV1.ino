//This code was written by Bob Clagett for I Like To Make Stuff - 2016
//It accompanies the project at http://www.iliketomakestuff.com/make-quiz-game-buttons
//This is for a simple 4 player quiz game setup.
//Only one button will light at a time, until the reset button is pressed.
//The reset button turns off all LEDs and sets everything up for the next "round".

int resetButtonPin = 2;

int button1Pin = 13;
int led1Pin = 12;
int button1State = 0; 

int button2Pin = 11;
int led2Pin = 10;
int button2State = 0; 

int button3Pin = 9;
int led3Pin = 8;
int button3State = 0; 

int button4Pin = 7;
int led4Pin = 6;
int button4State = 0; 

int resetButtonState = 0;
boolean pollingForPresses = 1;

int lastbutton1State = LOW;
int lastbutton2State = LOW;
int lastbutton3State = LOW;
int lastbutton4State = LOW;
int lastResetState = LOW;

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(resetButtonPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
}

void loop() {

  int reading1 = digitalRead(button1Pin);
  int reading2 = digitalRead(button2Pin);
  int reading3 = digitalRead(button3Pin);
  int reading4 = digitalRead(button4Pin);
  int readingReset = digitalRead(resetButtonPin);

    if(pollingForPresses==1){
      //Button 1
      if (reading1 != button1State && reading1 != lastbutton1State) {
        button1State = reading1;
        button1State = digitalRead(button1Pin);
          
              if (button1State == HIGH) {
                // turn LED on:
                  Serial.print("Button 1 ON");
                digitalWrite(led1Pin, HIGH);
                pollingForPresses = 0;
              }
         button1State = 0;
      }
   
      //Button 2
      if (reading2 != button2State && reading2 != lastbutton2State) {
        button2State = reading2;
        button2State = digitalRead(button2Pin);
          
              if (button2State == HIGH) {
                // turn LED on:
                  Serial.print("Button 2 ON");
                digitalWrite(led2Pin, HIGH);
                pollingForPresses = 0;
              }
         button2State = 0;
      }

      //Button 3
      if (reading3 != button3State && reading3 != lastbutton3State) {
        button3State = reading3;
        button3State = digitalRead(button3Pin);
          
              if (button3State == HIGH) {
                // turn LED on:
                  Serial.print("Button 3 ON");
                digitalWrite(led3Pin, HIGH);
                pollingForPresses = 0;
              }
         button3State = 0;
      }

      //Button 4
      if (reading4 != button4State && reading4 != lastbutton4State) {
        button4State = reading4;
        button4State = digitalRead(button4Pin);
          
              if (button4State == HIGH) {
                // turn LED on:
                  Serial.print("Button 4 ON");
                digitalWrite(led4Pin, HIGH);
                pollingForPresses = 0;
              }
         button4State = 0;
      }
      
    }
   //Check reset button
   
    if (pollingForPresses==0) {
    
      if (readingReset != resetButtonState && readingReset != lastResetState) {
              resetButtonState = digitalRead(resetButtonPin);
          
              if (resetButtonState == HIGH) {
                Serial.print("Reset button HIGH");
                resetButtons();
              }
         
         resetButtonState = 0;
      }
    }
  lastResetState = readingReset;
  lastbutton1State = reading1;  
  lastbutton2State = reading2;
  lastbutton3State = reading3;  
  lastbutton4State = reading4;
}


void resetButtons() {
  lastbutton1State = 0;
  lastbutton2State = 0;
  lastbutton3State = 0;
  lastbutton4State = 0;
  resetButtonState = 0;
  lastResetState = 0;
  button1State = 0;
  button2State = 0;
  button3State = 0;
  button4State = 0;
  Serial.print("reset all Buttons");
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(resetButtonPin, LOW);
  pollingForPresses = 1;
}
