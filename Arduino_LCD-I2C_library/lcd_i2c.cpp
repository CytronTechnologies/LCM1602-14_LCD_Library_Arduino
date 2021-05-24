#include "lcd_i2c.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>



lcd_i2c::lcd_i2c(uint8_t _addr, uint8_t _cols, uint8_t _rows, uint8_t _charsize)
{
	addr = _addr;
	cols = _cols;
	rows = _rows;
	charsize = _charsize;
}

void lcd_i2c::begin()
{
	Wire.begin();

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

void lcd_i2c::display() 
{
	command(DISPLAYCONTROL | DISPLAYON | CURSOROFF | BLINKOFF);
}

void lcd_i2c::noDisplay()
{
	command(DISPLAYCONTROL | DISPLAYOFF | CURSOROFF | BLINKOFF);
}

void lcd_i2c::clear()
{
	command(CLEARDISPLAY);
	delayMicroseconds(2000);
	setCursor(0,0);
}

void lcd_i2c::setCursor(uint8_t col, uint8_t row)
{
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if (row > rows) 
	{
		row = rows-1;    // we count rows starting w/0k
	}
	command(SETDDRAMADDR | (col + row_offsets[row]));
}

void lcd_i2c::scrollDisplayRight(void) 
{
	command(CURSORSHIFT | DISPLAYMOVE | MOVERIGHT);
}

void lcd_i2c::scrollDisplayLeft(void) 
{
	command(CURSORSHIFT | DISPLAYMOVE | MOVELEFT);
}

inline void lcd_i2c::command(uint8_t value)
{
	Wire.beginTransmission(addr);
	Wire.write(0x80);
	Wire.write(value);
	Wire.endTransmission();
	delayMicroseconds(1000);	
}

inline void lcd_i2c::write(uint8_t value)
{
	Wire.beginTransmission(addr);
	Wire.write(0x40);
	Wire.write(value);
	Wire.endTransmission();
	delayMicroseconds(1000);
}

void lcd_i2c::print(const char c[])
{
	for(int i =0; i < strlen(c); i++ ) 
	{
		char x = c[i];
		write((int)x);
	}	
}
