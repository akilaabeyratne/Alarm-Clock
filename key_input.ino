#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char keys[ROWS][COLS] = {
  {'1', '2', '3',},
  {'4', '5', '6',},
  {'7', '8', '9',},
  {'*', '0', '#',}
};

byte rowPins[ROWS] = {8, 7, 6, 5}; 
byte colPins[COLS] = {4, 3, 2}; 

Keypad numberKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  for (int j=10; j<=13; j++){
    pinMode(j, OUTPUT);
    }
}
  
void loop(){
  char customKey = numberKeypad.getKey();
  
  if (customKey=='1'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    
  }
  if (customKey=='2'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (customKey=='3'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (customKey=='4'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if (customKey=='5'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if (customKey=='6'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if (customKey=='7'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  if (customKey=='8'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if (customKey=='9'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }
  if (customKey=='*'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }
  if (customKey=='0'){
    //Serial.println(customKey);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  if (customKey=='#'){
    //Serial.println(customKey);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }

}
