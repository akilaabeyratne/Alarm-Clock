

#include <LiquidCrystal.h>  // get LCD library code
#include <Wire.h>           // get wire library code
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//define buttons
int upButton = 11;
int downButton = 12;
int selectButton = 13;

int menu = 1;
int count=0;  //to control button8 action

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
  Wire.begin();
  // Print a welcome message to the LCD.
  lcd.print("  ---WELCOME--- ");
  lcd.setCursor(6,1);
  lcd.print("MENU");
  delay(3000);
  
  pinMode(upButton, INPUT_PULLUP);        //buttons are connected to the pins
  pinMode(downButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  updateMenu();
}

char Time[] = "TIME:  :  :  ";
char Calendar[] = "DATE:  /  /20  ";
byte i, second, minute, hour, date, month, year;

void DS1307() {                                 //convert BCD to decimal
  second = (second >>4) *10 + (second & 0x0F);
  minute = (minute >>4) *10 + (minute & 0x0F);
  hour   = (hour >>4) *10 + (hour & 0x0F);
  date   = (date >>4) *10 + (date & 0x0F);
  month  = (month >>4) *10 + (month & 0x0F);
  year   = (year >>4) *10 + (year & 0x0F);

  Time[12] = second  %10 +48;
  Time[11] = second  /10 +48;
  Time[9] = minute  %10 +48;
  Time[8] = minute  /10 +48;
  Time[6] = hour  %10 +48;
  Time[5] = hour  /10 +48;
  Calendar[14]= year %10+48;
  Calendar[13]= year /10+48;
  Calendar[9]= month %10+48;
  Calendar[8]= month /10+48;
  Calendar[6]= date %10+48;
  Calendar[5]= date /10+48;  

  lcd.setCursor(0,0);
  lcd.print(Time);
  lcd.setCursor(0,1);
  lcd.print(Calendar);
}
void blinkParameter(){
  byte j=0;
  while(j<10 && digitalRead(8) && digitalRead(9)){
    j++;
    delay(25);
  }
}
byte edit(byte x, byte y, byte parameter){
  char text[3];
  while (!digitalRead(8));
  while(true){
    while(!digitalRead(9)){
      parameter++;
      if (i==0 && parameter>23)       //if hours>23 then hours =0
        parameter=0;
      if (i==1 && parameter>59)       //if minutes>59 then minutes =0
        parameter=0;
      if (i==2 && parameter>31)       //if date>31 then date =1
        parameter=1;
      if (i==3 && parameter>12)       //if month>12 then month =1
        parameter=1;
      if (i==4 && parameter>99)       //if year>99 then year =0
        parameter=0;

      sprintf(text,"%02u",parameter);
      lcd.setCursor(x,y);
      lcd.print(text);
      delay(200);
      }
      lcd.setCursor(x,y);
      lcd.print("  ");
      blinkParameter();
      sprintf(text,"%02u",parameter);
      lcd.setCursor(x,y);
      lcd.print(text);
      blinkParameter();
      if (!digitalRead(8)){
        i++;
        return parameter;
      }
  } 
}

void updateMenu() { // update the menu and define objects shown in the screen
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">>Date & Time");
      lcd.setCursor(0, 1);
      lcd.print("  Set Date & Time");
      break;
    case 2:
      lcd.clear();
      lcd.print("  Date & Time");
      lcd.setCursor(0, 1);
      lcd.print(">>Set Date & Time");
      break;
    case 3:
      lcd.clear();
      lcd.print(">>Set alarm");
      lcd.setCursor(0, 1);
      lcd.print("  alarm ringtone");
      break;
    case 4:
      lcd.clear();
      lcd.print("  Set alarm");
      lcd.setCursor(0, 1);
      lcd.print(">>alarm ringtone");
      break;
    case 5:
      menu = 4;
      break;
  }
}


void executeAction() {        //process, after select an option
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}
 // set the objects shown in the screen when press select
void action1() { 
  lcd.clear();
  DS1307();         // go to the time and date
  delay(2500);      //display date n time 2500ms
}
void action2() {
  lcd.clear();
  DS1307();     // go to the time
  count=0;
  while(count<5){
    if(!digitalRead(8)){                           // If button (pin #8) is pressed
      i = 0;
      hour   = edit(5, 0, hour);
      minute = edit(8, 0, minute);
      date   = edit(5, 1, date);
      month  = edit(8, 1, month);
      year   = edit(13, 1, year);
      // Convert decimal to BCD
      minute = ((minute / 10) << 4) + (minute % 10);    // ((val/10)*16) + (val%10))
      hour = ((hour / 10) << 4) + (hour % 10);
      date = ((date / 10) << 4) + (date % 10);
      month = ((month / 10) << 4) + (month % 10);
      year = ((year / 10) << 4) + (year % 10);
      // End conversion
      // Write data to DS1307 RTC
      Wire.beginTransmission(0x68);               // Start I2C protocol with DS1307 address
      Wire.write(0);                              // Send register address
      Wire.write(0);                              // Reset sesonds and start oscillator
      Wire.write(minute);                         // Write minute
      Wire.write(hour);                           // Write hour
      Wire.write(1);                              // Write day (not used)
      Wire.write(date);                           // Write date
      Wire.write(month);                          // Write month
      Wire.write(year);                           // Write year
      Wire.endTransmission();                     // Stop transmission and release the I2C bus
      delay(200);  
      count++  ;                            
    }
    if (count==5){
      break;
    }
  }
}

void action3() {
  lcd.clear();
  lcd.print(" >alarmTime<");
   lcd.setCursor(0, 1);
  lcd.print(" >alarmDate<");
  delay(1500);
}
void action4() {
  lcd.clear();
  lcd.print("  > ringtones <");
   lcd.setCursor(0, 1);
  lcd.print("Song1");
   lcd.setCursor(6, 1);
  lcd.print("Song2");
   lcd.setCursor(12, 1);
  lcd.print("Song3");
  delay(3000);
}


void loop(){
  if (!digitalRead(downButton)){      //scroll down
    menu++;
    updateMenu();                     //call updateMenu definition
    delay(100);
    while (!digitalRead(downButton));   //until press the down button
  }
  if (!digitalRead(upButton)){      // scroll up
    menu--;
    updateMenu();
    delay(100);
    while(!digitalRead(upButton));
  }
  if (!digitalRead(selectButton)){    //select option
    executeAction();
    updateMenu();
    delay(100);
    while (!digitalRead(selectButton)); 
  } 
  Wire.beginTransmission(0x68);                 // Start I2C protocol with DS1307 address
  Wire.write(0);                                // Send register address
  Wire.endTransmission(false);                  // I2C restart
  Wire.requestFrom(0x68, 7);                    // Request 7 bytes from DS1307 and release I2C bus at end of reading
  second = Wire.read();                         // Read seconds from register 0
  minute = Wire.read();                         // Read minuts from register 1
  hour   = Wire.read();                         // Read hour from register 2
  Wire.read();                                  // Read day from register 3 (not used)
  date   = Wire.read();                         // Read date from register 4
  month  = Wire.read();                         // Read month from register 5
  year   = Wire.read();                         // Read year from register 6

  delay(50);                    
                  
 }

 //lowerbyte = decval & 0x0F
 //upperbyte=x<<4
  
