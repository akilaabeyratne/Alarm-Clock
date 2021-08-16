/*
 * IncFile1.h
 *
 * Created: 5/27/2021 10:14:57 PM
 *  Author: ALPHAXANDER
 */ 


#ifndef TWI_H_
#define TWI_H_


#include <avr/io.h>

#define F_CPU 16000000UL
#define SCL_frequency 100000
#define prescaler 1


//Initialization of the TWI

void TWI_Initial(){
	TWBR = (F_CPU/SCL_frequency-16)/prescaler*2;   //setting the value of bit rate generator unit   // page 180
	TWCR = (1<<TWEN); //enable TWI
	TWSR = (0x01); // sets prescaler value to 1
}

// Sending the TWI start condition

void TWI_Start(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // initiating the start condition
	while (!(TWCR & (1<<TWINT)));  // Wait for TWINT flag set. This indicates that the START condition has been transmitted	
}

//Sending a write command to slave address

void TWI_Slave_Write(){
	//Here Master is micro controller
	//Slave is DS1307
	//slave Address 1101000
	//last bit is 0 to write
	
	TWDR = 0b11010000; //  sending write signal to slave
	TWCR = (1<<TWINT) | (1<<TWEN); // clear TWINT to start transmission
	while(!((TWCR) & (1<<TWINT))); // Wait for transmission
	
}

//Sending a reading request to slave address

void TWI_Slave_Read(){
	//Here Master is micro controller
	//Slave is DS1307
	//slave Address 11010000
	//last bit is 1 to read
	TWDR= 0b11010001; //sending read signal to slave
	TWCR = (1<<TWINT) | (1<<TWEN);	//clear TWINT to start transmission
	while(!((TWCR) & (1<<TWINT)));	////wait for transition
}

// Transforming decimal value to Binary Coded Decimal

uint8_t DEC_2_BCD(uint8_t val) {
	return val + 6 * (val / 10);
}

//Transforming binary coded value to decimal

static uint8_t BCD_2_DEC(uint8_t val) {
	return val - 6 * (val >> 4);
}

//TWI Writing to Slave register

void TWI_Write(x){
	TWDR = x;	//data  to be written to the slave
	TWCR = (1<<TWINT) | (1<<TWEN);	//clear TWINT to start transmission
	while(!((TWCR) & (1<<TWINT)));	//wait for data byte to transmit
}




//TWI Stop

void TWI_Stop(){
	//stops the transmission 
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}



 //Read one byte from the slave, request more data from device 
 //Automatically acknowleges shits to the next register
 
unsigned char TWI_ReadMore(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));    
    return TWDR;

}

 //Read one byte from the slave, read is followed by a stop condition
  // Automatically acknowledges and ends 
  
unsigned char TWI_ReadStop(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
    return TWDR;

}
#endif