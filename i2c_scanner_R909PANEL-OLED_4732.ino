// i2c_scanner informing on serial, parallel LCD, 
// PCF8574 i2c LCD, & OLED   can work @3.3V with OLED
// Si4732 testing
//
// For OLED adafruits LIB; @20240522 OK 3.3V operation!
//
// For R909OLED PCB with lcd(8,9,10,11,12.13); @20231029
// LCD&i2c connection OK  serial OK
//
// Expecting address Si5351a:0x60, Si4732:0x63(0x11), i2c LCD:0x27
//   OLED:0x3C
//
// Version 5, March 28, 2013
// Cover over 7-bit(127d), not handle extention address
//
 
#include <Wire.h>
 
// PCF8574 i2c lcd instance
//  Thanks for giving information about i2c LCD adapter
//  https://github.com/marcoschwartz/LiquidCrystal_I2C
 #include <LiquidCrystal_I2C.h>
 LiquidCrystal_I2C lcdi2c(0x27,16,2);

// Parallel LCD for Adru5351 PCB
// instanciate the library and pass pins for (RS, Enable, D4, D5, D6, D7)
 #include <LiquidCrystal.h>              // Sure 8x2 LCD works with this lib
 LiquidCrystal    lcd(8,9,10,11,12,13);

//////// OLED SSD1306 //// 
// Thanks Adafruit for providing the library of OLED SSD1306
//Adafruit  GFX https://github.com/adafruit/Adafruit-GFX-Library
//Adafruit SSD1306 https://github.com/adafruit/Adafruit_SSD1306
#include <Adafruit_GFX.h>     
#include <Adafruit_SSD1306.h> 
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

#define led_pin 15
#define lcd_backlight 7

  byte error, address;
  int nDevices;
  boolean led_status;
  char charbuf[6];

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\ni2c Scanner");
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  pinMode(led_pin, OUTPUT);
  pinMode(lcd_backlight, OUTPUT);
  digitalWrite( lcd_backlight, 1);
  
// PCF8574 i2c lcd
// Iniatilize i2c LCD
  lcdi2c.init(); 
  lcdi2c.backlight();

// 4 bits parallel LCD
  lcd.begin(16,2);                    // set lib for display size (2x16)
  lcd.clear();                       // clear the screen   

// OLED banner
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("i2c scan");
  display.setCursor(55, 15);
  display.print("kpa");
  display.display();
  
}
 
void loop()
{
  Serial.println("i2c Scanning start");
  digitalWrite(led_pin, led_status);  
  led_status = !led_status;
  delay(1000);   

  lcdi2c.setCursor( 0, 0) ;            // Set position
  lcdi2c.print( "i2c Scan test" ) ;    // Let to display

  lcd.setCursor(0,0);
  lcd.print("i2c Scan test   ") ;   

  display.setCursor(0, 15);
  display.print("i2c scan");  
  display.display();
  
  lcdi2c.setCursor( 0, 1) ;            // Set column position
  lcdi2c.print( "ADR:" ) ;             // Let to display
  
  lcd.setCursor(0,1);
  lcd.print("ADR:") ;  

  display.setCursor(0, 30);
  display.print("AD:"); 
  display.display();
    
  nDevices = 0;
  int cnt = 0;
  for(address = 1; address < 127; address++ )
  {
    // Check WIRE function return back result
    // The value of Write.endTransmisstion
    // Is there ACK response (yes:0） or no
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)         // Got response
    {
      Serial.print("i2c device found at address 0x");
      if (address<16) Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      sprintf(charbuf, "%02X", address );
 
      lcdi2c.print(charbuf) ;  
      lcdi2c.print(",") ;        

      lcd.print(charbuf) ;  
      lcd.print(",") ;  

      cnt++;
      display.setCursor(cnt*36, 32);
      display.print(charbuf); 
      display.print(",");
      display.display(); 
      
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  
  if (nDevices == 0)
  {
    Serial.println("No i2c devices found\n");
    lcdi2c.print("No devices found") ;     
    lcd.print("No devices found") ;  
    display.setCursor(0, 49);
    display.print("No devices"); 
    display.display();
  }
  else{
    Serial.println("done\n");
    lcdi2c.print("done           ") ;     
    lcd.print("done           ") ; 
    display.setCursor(cnt*15, 49);
    display.print("Done"); 
    display.display();
  } 

  delay(2000);                  // Wait 2 sec
  lcd.clear();                  // clear the screen 
  lcdi2c.clear();               // clear the screen 
  display.clearDisplay(); 
  display.display();
}
