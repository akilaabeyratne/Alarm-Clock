#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>

unsigned char k[4][3]={{0x01,0x02,0x03},{0x04,0x05,0x06},{0x07,0x08,0x09},{0x0e,0x00,0x0f}};
	
int main()
{
	unsigned char c,r;
	DDRB = 0X0f;
	DDRD = 0xf0;
	PORTD = 0xff;
	while(1)
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
			PORTD=0xef;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=0;
				break;
			}
			PORTD=0xdf;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=1;
				break;
			}
			PORTD=0xbf;
			r=PIND&0x0f;
			if(r!=0x0f)
			{
				c=2;
				break;
			}

		}

		if(r==0x0e)
		PORTB=k[0][c];
		else if(r==0x0d)
		PORTB=k[1][c];
		else if(r==0x0b)
		PORTB=k[2][c];
		else
		PORTB=k[3][c];
	}
	return 0;
}
