/*
 * IncFile1.h
 *
 * Created: 8/9/2021 1:31:43 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef Set_Time_H_
#define Set_Time_H_
#include "TWI.h"
int Current_Time[6];







void Time_insert()
{
	DDRD = 0xf0;
	PORTD = 0x7f;
	unsigned char c,r;
	int pos = 0 ;
    unsigned char k[4][3]={{14,0,15},{7,8,9},{4,5,6},{1,2,3}};	
    int input=0;
	LCD_Init();
	char fog[10]={0};
	int Set_Time[8];
	
while(1)
{
	if (pos<8 && pos!=2 && pos!=5)  // key pad input loop
	{
		do
		{
			PORTD&=0x0f;
			r=PIND&0x0f;
		} while(r!=0x0f);
	
		do
		{
			r=PIND&0x0f;
		}	  while(r==0x0f);
	
		while(1)
		{
			PORTD=0x6f;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=0;
				break;
			}
			PORTD=0x5f;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=1;
				break;
			}
			PORTD=0x3f;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=2;
				
				break;
			}
			
		}
	

		if(r==0x0e)
		{
			input=k[0][c];
			itoa(input,fog,10);
		}	
		else if(r==0x0d)
		{
			input=k[1][c];
			itoa(input,fog,10);
		}
		else if(r==0x0b)
		{
			input=k[2][c];
			itoa(input,fog,10);
		}
		else {
			input=k[3][c];
			itoa(input,fog,10);
		}
	
		if ((input!=14) && (input !=15)){
		Set_Time[pos]=input;
		LCD_String_xy(0,pos,fog);
		LCD_Command(0xC0);
		LCD_String_xy(1,pos,"^");
		
		if (pos<8 & pos!=3 & pos!=6)
		{
			LCD_String_xy(1,pos-1," ");
		}
	
	    else if(pos==3 | pos ==6)
		{
			LCD_String_xy(1,pos-2," ");
		}
		
		pos++;}
	
	} else if (pos==2 | pos==5){
			pos++;
	}
	else  
	{
		pos=0;
		
	}
	
	
	
	
	
	if(input==14)
	{      // checking valid inputs for time settings
		if ((Set_Time[0]*10+Set_Time[1]<24)&&(Set_Time[3]*10+Set_Time[4]<60) && (Set_Time[6]*10+Set_Time[7]<60)){
			
			Current_Time[3]=Set_Time[0]*10+Set_Time[1];
			Current_Time[4]=Set_Time[3]*10+Set_Time[4];
			Current_Time[5]=Set_Time[6]*10+Set_Time[7];
			//Setdate(Current_Time[0],Current_Time[1],Current_Time[2],Current_Time[3],Current_Time[4],Current_Time[5]);
			LCD_Clear();
			LCD_String("TIME SET DONE");
			_delay_ms(500);
			update_Clock_Menu();
			_delay_ms(1000);
			break;
			}else{
			LCD_Clear();
			LCD_String("INVALID INPUT");
			
			_delay_ms(1000);
			LCD_Clear();
			LCD_Time_Print(Current_Time[3],Current_Time[4],Current_Time[5]);
			
		}
		
	}
	else if (input==15)
	{   
		DDRD=0x0f;
		PORTD&=0x7e;
		update_Clock_Menu();
		_delay_ms(1000);
		break;
		
	}
	}
	
}



#endif /* INCFILE1_H_ */

