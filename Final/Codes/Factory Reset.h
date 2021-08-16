/*
 * Factory_Reset.h
 *
 * Created: 8/12/2021 5:23:12 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef FACTORY RESET_H_
#define FACTORY RESET_H_
#include "rtc.h"

int Factory_Menu=1;



void update_Factory_Menu(){
	switch(Factory_Menu){
		case 0:
		Factory_Menu = 1;
		break;
		case 1:							//initial display state
		LCD_Init();
		LCD_Clear();
		LCD_String("Sure ?");
		LCD_Command(0xC0);
		LCD_String("<YES>        NO ");
		break;
		case 2:							//2nd display state
		LCD_Init();
		LCD_Clear();
		LCD_String("Sure ?");
		LCD_Command(0xC0);
		LCD_String(" YES        <NO>");
		break;
		case 3:
		Factory_Menu = 1;
	}
}

int Factory_Menu_Buttons()   // Navigaring Between yes and no of are u sure question
{
	
	while(1)
	{
		DDRD=0x0f;
		PORTD&=0xfe;
		
		if (~PINC & (1<<PINC0)){
			_delay_ms(1000);
			LCD_Clear();
			execute_factory_action();
			break;
		}
		else if (~PINC & (1<<PINC1)){
			updateMenu();
			_delay_ms(1000);
			break;
		}
		else if (~PIND & (1<<PIND4)){
			
			Factory_Menu--;
			update_Factory_Menu();
			_delay_ms(1000);
			
			
		}
		else if (~PIND & (1<<PIND6)){
			
			Factory_Menu++;
			update_Factory_Menu();
			_delay_ms(1000);
			
			
		}
		
		
		
	}


}


int execute_factory_action(){
	
	switch (Factory_Menu) {
		case 1:
		Set_Factory_Action1();
		return 1;
		break;
		case 2:
		Set_Factory_Action2();
		break;
	}
}


void Set_Factory_Action1(){ //reset the clock to the following settings and deletes all the alarms
	Setdate(00,01,01,00,00,00);
	Alarm[0][0]=00;
	Alarm[0][1]=00;
	Alarm_status[0]=false;
	Alarm[1][0]=00;
	Alarm[1][1]=00;
	Alarm_status[1]=false;
	Alarm[2][0]=00;
	Alarm[2][1]=00;
	Alarm_status[2]=false;
	Alarm[3][0]=00;
	Alarm[3][1]=00;
	Alarm_status[3]=false;
	Alarm[4][0]=00;
	Alarm[4][1]=00;
	Alarm_status[4]=false;
	LCD_Clear();
	LCD_String("RESET COMPLETE");
	_delay_ms(1000);
	LCD_Clear();
	LCD_String("EXIT THE MENU");
	_delay_ms(1000);
	updateMenu();
	_delay_ms(1000);	
}


void Set_Factory_Action2(){
	updateMenu();
	_delay_ms(1000);
}









#endif /* FACTORY RESET_H_ */