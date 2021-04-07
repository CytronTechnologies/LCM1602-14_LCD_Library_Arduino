/* ******************************************************************************
#  * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
#  * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
#  * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
#  * DAMAGES, FOR ANY REASON WHATSOEVER.
#  ********************************************************************************
#  * DESCRIPTION:
#  *
#  * This example show how to connect LCD module with NodeMCU V3 and Arduino using I2C protocol
#  * 
#  * 
#  * 
#  * CONNECTIONS:
#  * 
#  * NodeMCU V3  D2    - LCD SDA
#  * NodeMCU V3  D1    - LCD SCK
#  * NodeMCU V3 3V3(OUT) - LCD VDD
#  * NodeMCU V3 GND      - LCD VSS
#  *
#  * Arduino/Maker Uno/Mega SDA      - LCD SDA
#  * Arduino/Maker Uno/Mega SCL      - LCD SCK
#  * Arduino/Maker Uno/Mega 3V3(OUT) - LCD VDD
#  * Arduino/Maker Uno/Mega GND      - LCD VSS
#  * 
#  * Arduino Nano A4      - LCD SDA
#  * Arduino Nano A5      - LCD SCK
#  * Arduino Nano 3V3(OUT)- LCD VDD
#  * Arduino Nano GND     - LCD VSS
#  *
#  *
#  * AUTHOR   : Arif Haikal
#  * COMPANY  : Cytron Technologies Sdn Bhd
#  * WEBSITE  : www.cytron.io
#  * EMAIL    : support@cytron.io
#  *
#  ****************************************************************************** */

#include <lcd_i2c.h> //Import lcd_i2c library


lcd_i2c lcd(0x3E,16,2); //The I2C communication for this LCD is 0x3E (HEX) or 62 (DEC), 16 is the number of the columns, 2 is the number of the rows

void setup()
{
  lcd.begin(); //LCD initialization function  
  lcd.setCursor(0, 0); //cursor setting function start with column followed by row
  lcd.print("Hello World!"); //Print text
}

void loop() 
{
  // Do nothing here
}
