#include "lcd_spi.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include <SPI.h>

lcd_spi::lcd_spi(uint8_t ssPin)
{
	initSPI(ssPin);
}

void lcd_spi::initSPI(uint8_t ssPin)
{
	cs = ssPin;
	pinMode(cs,OUTPUT);
	digitalWrite(cs,HIGH);
	SPI.begin();
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void lcd_spi::begin(uint8_t _cols, uint8_t _rows, uint8_t _charsize)
{
	cols = _cols;
	rows = _rows;
	charsize = _charsize;
	
	delayMicroseconds(50000);

	command(FUNCTIONSET | _2LINE);
	delayMicroseconds(10000);
	
	display();
	delayMicroseconds(40);
	clear();
	delayMicroseconds(2000);
	command(ENTRYMODESET | ENTRYLEFT | ENTRYSHIFTDECREMENT);

	setCursor(0,0);
}

void lcd_spi::display() 
{
	command(DISPLAYCONTROL | DISPLAYON | CURSOROFF | BLINKOFF);
}

void lcd_spi::noDisplay()
{
	command(DISPLAYCONTROL | DISPLAYOFF | CURSOROFF | BLINKOFF);
}

void lcd_spi::clear()
{
	command(CLEARDISPLAY);
	delayMicroseconds(2000);
	setCursor(0,0);
}

void lcd_spi::setCursor(uint8_t col, uint8_t row)
{
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > rows) 
	{
		row = rows-1;    // we count rows starting w/0k
	}
	command(SETDDRAMADDR | (col + row_offsets[row]));
}

void lcd_spi::scrollDisplayLeft(void) 
{
  command(CURSORSHIFT | DISPLAYMOVE | MOVELEFT);
}
void lcd_spi::scrollDisplayRight(void) 
{
  command(CURSORSHIFT | DISPLAYMOVE | MOVERIGHT);
}

inline void lcd_spi::command(uint8_t value)
{
	int buff[2];
	buff[0] = 0;
	buff[0] |= value >> 1;
	buff[1] = (value & 1) << 7;
	delayMicroseconds(10000); 
	
	digitalWrite(cs,LOW);
	SPI.transfer(buff[0]);
	SPI.transfer(buff[1]);
	digitalWrite(cs,HIGH);
	delayMicroseconds(1);
}

inline void lcd_spi::write(uint8_t value)
{
	int buffs[2];
	buffs[0] = 0x80;
	buffs[0] |= value >> 1;
	buffs[1] = (value & 1) << 7;
	delayMicroseconds(10000);
	
	digitalWrite(cs,LOW);
	SPI.transfer(buffs[0]);
	SPI.transfer(buffs[1]);
	digitalWrite(cs,HIGH);
	delayMicroseconds(1);   
}

void lcd_spi::print(const char c[])
{
	for(int i =0; i < strlen(c); i++ ) 
	{
		char x = c[i];
		write((int)x);
	}
}
