/*
 * IncFile1.h
 *
 * Created: 5/28/2021 12:36:31 AM
 *  Author: ALPHAXANDER
 */ 


#ifndef rtc_H_
#define rtc_H_

#include <avr/io.h>
#include "avr/pgmspace.h"
#include "util/delay.h"
#include "TWI.h"

// days per month

const uint8_t Days_month [] PROGMEM = { 31,28,31,30,31,30,31,31,30,31,30,31 };

//get number of days 

static uint16_t Date2Day(uint8_t y, uint8_t m, uint8_t d) {
	uint16_t days = d;
	for (uint8_t i = 1; i < m; ++i)
		days += pgm_read_byte(Days_month + i - 1);
	if (m > 2 && y % 4 == 0)
		++days;
	return days + 365 * y + (y + 3) / 4 - 1;

}


//get day of a week

uint8_t Get_Days_Week(uint8_t y, uint8_t m, uint8_t d) {
	uint16_t day = Date2Day(y, m, d);
	return (day + 6) % 7;
}
	
//set date

uint8_t Setdate(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
	//sanitize data
	if (second < 0 || second > 59 ||
		minute < 0 || minute > 59 ||
		hour < 0 || hour > 23 ||
		day < 1 || day > 31 ||
		month < 1 || month > 12 ||
		year < 0 || year > 99)
		return 8;

	//sanitize day based on month
	if(day > pgm_read_byte(Days_month + month - 1))
		return 0;
		
	//get day of week
	uint8_t Dayofweek = Get_Days_Week(year, month, day);

	//write date
	TWI_Initial();
	TWI_Start();
	TWI_Slave_Write();
	TWI_Write(0x00);//stop oscillator
	TWI_Write(DEC_2_BCD(second));
	TWI_Write(DEC_2_BCD(minute));
	TWI_Write(DEC_2_BCD(hour));
	TWI_Write(DEC_2_BCD(Dayofweek));
	TWI_Write(DEC_2_BCD(day));
	TWI_Write(DEC_2_BCD(month));
	TWI_Write(DEC_2_BCD(year));
	TWI_Write(0x00); //start oscillator
	TWI_Write();

	return 1;
}


 
void Getdate(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *minute, uint8_t *second) {
	TWI_Initial();
	TWI_Start();
	TWI_Slave_Write();
	TWI_Write(0x00);
	TWI_Stop();
	
	TWI_Start();
	TWI_Slave_Read();
	*second = BCD_2_DEC(TWI_ReadMore() & 0x7F);
	*minute = BCD_2_DEC(TWI_ReadMore());
	*hour = BCD_2_DEC(TWI_ReadMore());
	TWI_ReadMore();
	*day = BCD_2_DEC(TWI_ReadMore());
	*month = BCD_2_DEC(TWI_ReadMore());
	*year = BCD_2_DEC(TWI_ReadStop());
}







#endif /* INCFILE1_H_ */