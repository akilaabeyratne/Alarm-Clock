/*
 * IncFile1.h
 *
 * Created: 10-Aug-21 10:33:43 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include "LCD.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "Alarm_Menu.h"
#include "Status_Menu.h"
#include "Tone_Menu.h"
#include "Clock_Menu.h"
#include "Factory Reset.h"

bool menu_can_access = true;
int Menu=1;

void updateMenu(){
	switch(Menu){
		case 0:
		Menu = 1;
		break;
		case 1:							
		LCD_Init();                     //1st display
		LCD_Clear();
		LCD_String(">> Set Clock");
		LCD_Command(0xC0);
		LCD_String(" > Set Alarm");
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_String(" > Set Clock");
		LCD_Command(0xC0);
		LCD_String(">> Set Alarm");
		break;
		case 3:							//Third display state
		LCD_Init();
		LCD_Clear();
		LCD_String(">> Alarm Status");
		LCD_Command(0xC0);
		LCD_String(" > Alarm Tone");
		break;
		case 4:							
		LCD_Init();
		LCD_Clear();                      //4th display
		LCD_String(" > Alarm Status");
		LCD_Command(0xC0);
		LCD_String(">> Alarm Tone");
		break;
		case 5:
		LCD_Init();
		LCD_Clear();                          //5th display
		LCD_String(">> Factory Reset");
		LCD_Command(0xC0);
		LCD_String(" > About Us");
		break;
		case 6:
		LCD_Init();
		LCD_Clear();
		LCD_String(" > Factory Reset");          //6th display
		LCD_Command(0xC0);
		LCD_String(">> About Us");
		break;
		case 7:
		Menu = 6;
		break;
	}
}

void Action1(){
	Clock_Menu = 1;
	update_Clock_Menu();
	Clock_Menu_Buttons();
	
	
}

void Action2(){
	Alarm_Menu = 1;
	update_Alarm_Menu();
	Alarm_Menu_Buttons();
	
}

void Action3(){
	Status_Menu = 1;
	update_Status_Menu();
	Status_Menu_Buttons();
}

void Action4(){
	Tone_Menu = 1;
	update_Tone_Menu();
	Tone_Menu_Buttons();
}

void Action5(){
	Factory_Menu = 1;
	update_Factory_Menu();
	Factory_Menu_Buttons();
}

void Action6(){                        //About US monologue
	LCD_Clear();
	LCD_String("PROJECT LOCUS");
	LCD_Command(0xC0);
	LCD_String("Ver 1.0.0");
	_delay_ms(2000);
	LCD_Clear();
	LCD_String("PROJECT BY:");
	LCD_Command(0xC0);
	LCD_String("SYAMAL");
	_delay_ms(2000);;
	LCD_Command(0xC0);
	LCD_String("AAKKASH");
	_delay_ms(2000);
	LCD_Command(0xC0);
	LCD_String("CHALINDU");
	_delay_ms(2000);
	LCD_Command(0xC0);
	LCD_String("AKILA     ");
	_delay_ms(2000);
	LCD_Clear();
	LCD_String_xy(0,4,"THANK");
	LCD_Command(0xC0);
	LCD_String_xy(1,5,"YOU:)");
	_delay_ms(3000);
	updateMenu();
}

void executeAction()
{			
	switch (Menu) {
		case 1:
		Action1();
		break;
		case 2:
		Action2();
		break;
		case 3:
		Action3();
		break;
		case 4:
		Action4();
		break;
		case 5:
		Action5();
		break;
		case 6:
		Action6();
		break;
		
	}
	
}

void Main_Menu_Buttons()
{
	
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0b01111110;
		
		if (~PINC & (1<<PINC0))
       {
		   _delay_ms(1000);
            executeAction();
			

		} 
            
	    else if (~PINC & (1<<PINC1)){
			
			menu_can_access=true;
			LCD_Clear();
			DDRD=0xf0;
			PORTD=0b01111111;
			break;
			
		}
		else if (~PIND & (1<<PIND4)){
			
			Menu--;
			updateMenu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Menu++;
			updateMenu();
			_delay_ms(1000);
			
			
		}
	
	}
 }





#endif /* MAIN_MENU_H_ */