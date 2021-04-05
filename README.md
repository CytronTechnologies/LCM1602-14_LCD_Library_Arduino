# LCM1602-14 LCD Arduino Library for NodeMCU, Official Arduino and Maker
These libraries support LCM1602A-14 LCD module I2C and SPI communication with NodeMCU ESP8266, official Arduino and Maker (Cytron Product).

# Disclaimer
> These libraries were built with fundamental function. So, there a lot of features that we can update together! You are encouraged to improve the code for your purposed and better application by pulling request from me or modify by yourself. Cheers!


![106861113-4928be80-6700-11eb-9203-9196ff394f06](https://user-images.githubusercontent.com/80098610/111902161-f2403400-8a76-11eb-9730-570ecfd3ff88.PNG)

The library file must be downloaded and saved inside Arduino library file before uploading user's code

# Add Library 
STEP 1 : Download the library file (Arduino_LCD-I2C_Library and Arduino_LCD-SPI_Library)

![Screenshot (5)](https://user-images.githubusercontent.com/12636070/113525920-4f48f780-95ea-11eb-82e0-6d1501d35b4a.png)

STEP 2 : Put the downloaded files in Arduino library folder separately [Documents > Arduino > libraries]

![lib1](https://user-images.githubusercontent.com/80098610/111907497-91255a00-8a90-11eb-8677-df6ff2abc415.PNG)

STEP 3 : Check both files if its already got into the libraries by opening the Arduino IDE then got to sketch [Arduino IDE > sketch > Include Library]

![Screenshot (2)](https://user-images.githubusercontent.com/80098610/111908016-92578680-8a92-11eb-9e39-bbd0aeb02756.png)

If the libraries are there, then you are ready to use it but if the libraries does not appear, you need to restart Arduino IDE by closing the IDE and open back.

# Import LCD I2C
- Import lcd_i2c library

```
#include <lcd_i2c.h>
```

# Import LCD SPI
- Import lcd_spi library

```
#include <lcd_spi.h>
```

# Create Object for I2C
- Create object using class
- Set the communication address, setup the columns and rows required for LCD
- The I2C communication for this LCD is 0x3e (HEX) or 62 (DEC), 16 is the number of the columns, 2 is the number of the rows

```
lcd_i2c lcd(0x3E,16,2);
```

# Create Object for SPI
- Create object using class
- Set the Chip Selected Pin
- D8 for NodeMCU V3 ESP8266, 10 for any Arduino and Maker

```
lcd_spi lcd(D8);
```

# Initialize
- LCD intiallization function
- For SPI need to initialize the column and row here, (16,2)

```
lcd.begin();
```

# Set Cursor
- Set the cursor to a specific position
- First parameter sets to the column, second parameter set the row
- Set the cursor to column 0 (first column) and row 0 (first row)

```
lcd.setCursor(0,0);
```

# Scroll Text from Left to Right
- Function to move the text by scrolling from left to right.

```
lcd.scrollDisplayRight();
```

# Scroll Text from Right to Left
- Function to move the text by scrolling from right to left.

```
lcd.scrollDisplayLeft();
```

# Write to LCD Display
- Write string to the LCD

```
lcd.print("Hello World");
```

# Clear LCD Display
- Clear the data on the display

```
lcd.clear();
``` 
