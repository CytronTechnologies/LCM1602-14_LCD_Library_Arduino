#ifndef lcd_i2c_h
#define lcd_i2c_h

#include <inttypes.h>
#include <Arduino.h>
#include <Wire.h>

//Instruction Set
#define CLEARDISPLAY 0X01
#define CURSORSHIFT 0x10

//display entry mode
#define ENTRYMODESET 0X04
#define ENTRYLEFT 0X02
#define ENTRYRIGHT 0X00
#define ENTRYSHIFTINCREMENT 0X01
#define ENTRYSHIFTDECREMENT 0X00

// flags for display/cursor shift
#define DISPLAYMOVE 0x08
#define CURSORMOVE 0x00
#define MOVERIGHT 0x04
#define MOVELEFT 0x00

//display control
#define DISPLAYCONTROL 0X08
#define DISPLAYON 0X04
#define DISPLAYOFF 0X00
#define CURSORON 0X02
#define CURSOROFF 0X00
#define BLINKON 0X01
#define BLINKOFF 0X00
#define SETCGRAMADDR 0x40 
#define SETDDRAMADDR 0x80

//for functionset

#define FUNCTIONSET 0x20
#define _5x10DOTS 0x04
#define _5x8DOTS 0x00
#define _1LINE 0x00
#define _2LINE 0x08
#define _8BITMODE 0x10
#define _4BITMODE 0x00

class lcd_i2c{
public:
  lcd_i2c(uint8_t _addr, uint8_t _cols, uint8_t _rows, uint8_t _charsize = _5x8DOTS);

  void begin();
  void clear();
  void noDisplay();
  void display();
  void scrollDisplayRight();
  void scrollDisplayLeft();  
  
  void setCursor(uint8_t, uint8_t);
  void write(uint8_t);
  void command(uint8_t);

  void print(const char[]);
  
private:

  uint8_t addr;
  uint8_t cols;
  uint8_t rows;
  uint8_t col;
  uint8_t row;
  uint8_t charsize;
  uint8_t _command;
  uint8_t _displaymode;
  int buff;
  int buffs;
  uint8_t _displayfunction;  
  
};

#endif
