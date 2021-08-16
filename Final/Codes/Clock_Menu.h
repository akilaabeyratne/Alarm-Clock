/*
 * Clock_Menu.h
 *
 * Created: 8/12/2021 4:55:25 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef CLOCK_MENU_H_
#define CLOCK_MENU_H_
#include "String.h"
#include "rtc.h"
#include "Set_Time.h"
#include "Set_Date.h"
#include <stdio.h>


int Clock_Menu=1;
int Set_Time_Menu=1;
int Set_Date_Menu=1;
int Current_Time[6];




void update_Clock_Menu(){
	switch(Clock_Menu){
		case 0:
		Clock_Menu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_String(">> Set Time");
		LCD_Command(0xC0);
		LCD_String("   Set Date");
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_String("   Set Time");
		LCD_Command(0xC0);
		LCD_String(">> Set Date");
		break;
		case 3:
		Clock_Menu = 1;
	}
}


void Clock_Menu_Buttons()   //Navigating through Clock Menu
{
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
		   _delay_ms(1000);
		   LCD_Clear();
		   execute_clockAction();
		}
		else if (~PINC & (1<<PINC1)){
			updateMenu();
			_delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Clock_Menu--;
			update_Clock_Menu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Clock_Menu++;
			update_Clock_Menu();
			_delay_ms(1000);
			
			
		}
		
		
		
	}


}

void execute_clockAction()
{
	switch (Clock_Menu) {
		case 1:
		Set_Time_Action();
		break;
		case 2:
		Set_Date_Action();
		break;
		
	}
	
}

void Set_Time_Action(){  // When go inside the last time in storage will be displayed for setting like usual phone clocks
	LCD_Init();
	LCD_Clear();
	LCD_Time_Print(Current_Time[3],Current_Time[4],Current_Time[5]);
	Time_insert();
}

void Set_Date_Action(){  // When go inside the last date in storage will be displayed for setting like usual phone clocks
	LCD_Init();
	LCD_Clear();
	LCD_Date_Print(Current_Time[0],Current_Time[1],Current_Time[2]);
	Date_insert();
}









#endif /* CLOCK_MENU_H_ */