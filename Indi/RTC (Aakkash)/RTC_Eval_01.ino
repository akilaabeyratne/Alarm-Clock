#include <Wire.h>        //to communicate with i2c devices like ds1307
#include "RTClib.h"     //communicate and control ds1307
int ledPin = 13;       //  pin for the LED
int inPin = 4;        // input of the switch
int val = 0;         // variable for reading the pin status

DS1307 rtc;
int _day, _month, _year, _hour24, _hour12, _minute, _second, _dtw;
int hr24;
String st;
char nameoftheday[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  // 2d array

void setup() {
  Serial.begin(9600);       // get arduino to get ready to exchange messages with the serial moniter at 9600 bits per second
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare switch as input
  Serial.println("Arduino RTC DS1307");  // to print the arduino type in the start
  delay(500);
  
  if (! rtc.begin()) { // to check the connectivity of rtc to arduino
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // if the chip has lost track of time. If the function returns false, we can then set the date & time.
  }
   rtc.adjust(DateTime(2021, 4, 15, 18, 34, 0));
  // if this is not done then the time and date will return to the beginning when it was set when arduino is reset or restarted.
}
void GetDateTime() {
  DateTime now = rtc.now();
  _day=now.day();
  _month=now.month();
  _year=now.year();
  _hour24=now.hour();
  _minute=now.minute();
  _second=now.second();
  _dtw=now.dayOfWeek();

  hr24=_hour24;
  if (hr24>12) {
    _hour12=hr24-12;
  }
  else if (hr24==0) {
    _hour12=12;
  }
  else {
    _hour12=hr24;
  }

  if (hr24<12) {
    st="AM";
  }
  else {
    st="PM"; 
  }  
}
void Alarm(){ // if alarm time is equal to the current time
  val = digitalRead(inPin);  
  int alarm_hour24=18;
  int alarm_minute=35;
  if (alarm_hour24==_hour24 && alarm_minute==_minute  ) {
    if (val==LOW){
      digitalWrite(ledPin, HIGH);
    } else{
      digitalWrite(ledPin, LOW);  // turn LED OFF
    }
  }
}

void loop() {
  GetDateTime();
  Alarm();
  Serial.print(nameoftheday[_dtw]);
  Serial.print(',');    
  Serial.print(_day, DEC);
  Serial.print('/');
  Serial.print(_month, DEC);
  Serial.print('/');
  Serial.print(_year, DEC);
  Serial.print(" ");   
  Serial.print(_hour24, DEC);
  Serial.print(':');
  Serial.print(_minute, DEC);
  Serial.print(':');
  Serial.print(_second, DEC);
  Serial.print(' ');
  Serial.print(_hour12, DEC);
  Serial.print(':');
  Serial.print(_minute, DEC);
  Serial.print(':');
  Serial.print(_second, DEC);
  Serial.print(' ');
  Serial.print(st);
  Serial.println();
  delay(1000);
}
