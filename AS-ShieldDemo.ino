/*
  SparkFun + Qtechknow ArduSensor Shield
 
  Plug ArduSensor Button into A0, Force into A1, Magnet into A2, and Light into
  A3, and see what happens!!!
   
   created 30 May 13
   by Quin (Qtechknow)
 */

int lowVal = 0;          // declare the low value of your ArduSensor
int highVal = 1000;      // declare the high value of your ArduSensor

// these constants won't change:
const int ledCount = 10;    // the number of LEDs in the QBar Graph

int lowVal2 = 0;       // declare the lowVal of your ArduSensor 
int highVal2 = 900;  // declare the highVal of your ArduSensor

const int QBuzzPin = 9;  // the pin that your QBuzz is connected to
const int ArduSensorPin = A3;  // the pin that your ArduSensor is connected to

int ledPins[] = { 
13, 12, 11, 10, A4, 8, 7, 4, 2, A5 };   // an array of our LED pins


void setup() {
  // loop over the pin array and set them all to output:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT); 
  }
  Serial.begin(9600);    // start serial communication
}

void loop() {
  // read the ArduSensor:
  int sensor1 = analogRead(1);
  int sensor3 = analogRead(0);
  int sensor4 = analogRead(2);
  // map the result to a range from 0 to the number of LEDs:
  int ledLevel = map(sensor1, highVal, lowVal, 0, ledCount);

  // loop over the QBar Graph:
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    // if the array element's index is less than ledLevel,
    // turn the pin for this element on:
    if (thisLed < ledLevel) {
      digitalWrite(ledPins[thisLed], HIGH);
    } 
    // turn off all pins higher than the ledLevel:
    else {
      digitalWrite(ledPins[thisLed], LOW); 
    }
  } 
  // read the ArduSensor
  int sensor2=analogRead(ArduSensorPin);
  
  // convert the ArduSensor values to values that the QBuzz can use
  int val=map(sensor2, highVal2, lowVal2, 150, 1500);  
  
  // make the tone
  tone(QBuzzPin, val);
  
  if(sensor3 >= 1000) {
    analogWrite(3, 255);
  }else{
    analogWrite(3, 0);
  }
  
  if(sensor4 >= 1000) {
    analogWrite(5, 255);
  }else{
    analogWrite(5, 0);
}
}
