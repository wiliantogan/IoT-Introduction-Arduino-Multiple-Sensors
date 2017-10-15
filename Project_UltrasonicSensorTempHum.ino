#include <DHT.h>
#include <Wire.h>

#include <Ultrasonic.h> //import ultrosonic library
#include <LiquidCrystal.h> //import LCD library

#define DHTPIN A0

Ultrasonic ultrasonic(2,3); //Register ultrasonic sensor with interface pins trig:2, echo:3
LiquidCrystal lcd(0,1,8,9,10,11); //Register the LCD with interface pins RS:0, E:1, D4:8, D5:9, D6:10, D7:11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //setup the LCD's number of columns and rows
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  //take a measurement and display it on the LCD
  delay(500);
  
  lcd.clear(); //Clears the screen in preparation of new measurement
  lcd.setCursor(0,0);
  lcd.print("H:");
  float h = dht.readHumidity();
  lcd.setCursor(0,1);
  lcd.print("T:");
  float f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
  }
  lcd.setCursor(2,0);
  lcd.print(h);
  lcd.setCursor(7,0);
  lcd.print("%");
  lcd.setCursor(2,1);
  lcd.print(f);
  lcd.setCursor(7,1);
  lcd.print("F");
  lcd.setCursor(9,0);
  lcd.print("D:"); //Prints the first line of the display
  lcd.setCursor(11,0); //Takes measurement from US and prints it to LCD
  lcd.print(ultrasonic.distanceRead()); //waits half a second
  lcd.setCursor(14,0);
  lcd.print("cm");
  
  return; 
}

