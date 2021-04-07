/* ******************************************************************************
#  * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
#  * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
#  * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
#  * DAMAGES, FOR ANY REASON WHATSOEVER.
#  ********************************************************************************
#  * DESCRIPTION:
#  *
#  * This example show how to connect LCD module with NodeMCU V3 ESP8266, Arduino and Maker using SPI protocol
#  * 
#  * 
#  * 
#  * CONNECTIONS:
#  * 
#  * NodeMCU V3 HMOSI D7      - LCD SDA
#  * NodeMCU V3 HSCLK D5      - LCD SCK
#  * NodeMCU V3 3V3(OUT)      - LCD VDD
#  * NodeMCU V3 GND           - LCD VSS
#  * NodeMCU V3 HCS D8        - LCD CS
#  * NodeMCU V3 GND           - LCD PSB
#  *
#  * Arduino/Maker Uno MOSI 11      - LCD SDA
#  * Arduino/Maker Uno SCK 13       - LCD SCK
#  * Arduino/Maker Uno 3V3(OUT)     - LCD VDD
#  * Arduino/Maker Uno GND          - LCD VSS
#  * Arduino/Maker Uno SS 10        - LCD CS
#  * Arduino/Maker Uno GND          - LCD PSB
#  *
#  *
#  *
#  * AUTHOR   : Arif Haikal
#  * COMPANY  : Cytron Technologies Sdn Bhd
#  * WEBSITE  : www.cytron.io
#  * EMAIL    : support@cytron.io
#  *
#  ****************************************************************************** */

#include <lcd_spi.h> //Import lcd_spi library

lcd_spi lcd(D8); // Chip Selected Pin (CS), D8 for NodeMCU V3 ESP8266, 10 for any Arduino and Maker

void setup() 
{
  // put your setup code here, to run once:
  
  lcd.begin(16,2); //LCD intialization, column and row setup setting  
  lcd.setCursor(0, 0); //cursor setting function start with column followed by row
  lcd.print("Hello World!"); //Print text

}

void loop() 
{
  // Do nothing here
}
