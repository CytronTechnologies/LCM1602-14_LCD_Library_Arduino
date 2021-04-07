#include <lcd_i2c.h>


lcd_i2c lcd(0x3E,16,2); //The I2C communication for this LCD is 0x3E (HEX) or 62 (DEC), 16 is the number of the columns, 2 is the number of the rows

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin();
  // Print a message to the LCD.
  lcd.print("Hello World!");
  delay(1000);
}

void loop() 
{
  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 15; positionCounter++) 
  {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }

  // delay at the end of the full loop:
  delay(1000);

}
