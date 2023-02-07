/* Pushbuttons - Written by Wallace and Nazar
   This code is written to display the state of a pushbutton
   digitalRead */

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // initialize the LCD with pin numbers

int button1Pin = 8; //set pin where button 1 is wired
int button2Pin = 9; //set pin where button 2 is wired

int button1State; //create variable for the state of button 1
int button2State; // create variable for the state of button 2

void setup() 
{
  lcd.begin(16, 2); // set up the LCD's number of columns and rows
}

void loop() 
{
  button1State = digitalRead(button1Pin); //read state of pushbutton
  button2State = digitalRead(button2Pin); //read state of pushbutton

  if (button1State == LOW && button2State == LOW) 
   //button 1 and 2 not pressed
  {
    lcd.setCursor(0, 0);
    lcd.print("PB1 and PB2 not");
    lcd.setCursor(0, 1);
    lcd.print("pressed ");
  }
  else if (button1State == HIGH && button2State == LOW) 
   //button 1 pressed, button 2 not pressed
  {
    lcd.setCursor(0, 0);
    lcd.print("PB1 pressed       "); 
    lcd.setCursor(0, 1);
    lcd.print(“UvU                "); 
  }
   else if (button1State == LOW && button2State == HIGH) 
   //button 1 not pressed, button 2 pressed
  {
    lcd.setCursor(0, 0);
    lcd.print("PB2 pressed       "); 
    lcd.setCursor(0, 1);
    lcd.print("OwO                "); 
  }
   else 
   //both button pressed
  {
    lcd.setCursor(0, 0);
    lcd.print("PB1 and PB2 are      "); 
    lcd.setCursor(0, 1);
    lcd.print("pressed UwU        "); 
  }

  delay(100); //delay to allow screen to update
}
