#include <Ultrasonic.h> //import ultrosonic library
#include <LiquidCrystal.h> //import LCD library

Ultrasonic ultrasonic(2,3); //Register ultrasonic sensor with interface pins trig:2, echo:3
LiquidCrystal lcd(0,1,8,9,10,11); //Register the LCD with interface pins RS:0, E:1, D4:8, D5:9, D6:10, D7:11

void setup() {
  //setup the LCD's number of columns and rows
  lcd.begin(16,2);
}

void loop() {
  //take a measurement and display it on the LCD
  lcd.clear(); //Clears the screen in preparation of new measurement
  lcd.print("Distance in cm:"); //Prints the first line of the display
  lcd.setCursor(0,1); //Takes measurement from US and prints it to LCD
  lcd.print(ultrasonic.distanceRead()); //waits half a second
  delay(500);
}

