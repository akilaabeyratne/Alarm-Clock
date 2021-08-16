/*
 * GccApplication1.c
 *
 * Created: 8/10/2021 4:48:11 PM
 * Author : ALPHAXANDER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include "LCD.h"
#include <util/delay.h>
#include "Main_Menu.h"
#include <stdbool.h>
#include "Set_Time.h"
#include "rtc.h"
#include "String.h"
#include <stdio.h>
#define SPEAKER PORTD7
#include "Alarm_Ring.h"

int Current_Time[6];
int Alarm[5][2]={{10,05},{10,11},{10,8},{10,12},{10,13}};   // Alarm Times set for demonstration
bool Alarm_status[5]={true,true,true,false,false};     // Alarm status set for demonstration


int main(void)
{   DDRB = 0X0f;
	DDRD = 0xf0;
	PORTD = 0b01111111;
	DDRC = 0b11000100;
	PORTC= 0b01111011;
	
	
	
	uint8_t year = 0;
	uint8_t month = 0;
	uint8_t day = 0;
	uint8_t hour = 0;
	uint8_t minute = 0;
	uint8_t second = 0;
	
	

	Setdate(21, 07, 05, 10, 04, 55);  // Time is setted for demonstartions purpose
	LCD_Init();
	LCD_Clear();
	LCD_String_xy(0,4,"WELCOME");
	LCD_Command(0xC0);
	LCD_String_xy(1,2,"-TEAM LOCUS-");
	_delay_ms(1000);
	LCD_Clear();
	

  
  
    while (1) 
    {
		
		Getdate(&year,&month,&day,&hour,&minute,&second);
		
		if (~PINC & (1<<PINC0))
		{   
			menu_can_access = false;
			Menu = 1;
			updateMenu();
			_delay_ms(1000);
			Main_Menu_Buttons();
		} else if(menu_can_access){
			
			LCD_Print(year,month,day,hour,minute,second);
			Current_Time[0]=year;	
			Current_Time[1]=month;
			Current_Time[2]=day;
			Current_Time[3]=hour;
			Current_Time[4]=minute;
			Current_Time[5]=second;	
			Alarm_Ring(Alarm_tone,hour,minute,second);
		}
		
		
    }
}

