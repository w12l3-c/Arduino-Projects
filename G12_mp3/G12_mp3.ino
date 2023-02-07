/* IR mp3 - Written by Wallace
   This code is written to make a music player that play
   different song with different button using an infrared remote*/

//IR remote library
#include <IRremote.h>
//AVR libraries
#include <avr/io.h>
#include <avr/wdt.h>
//Define the reset function for later codes
#define Reset_AVR() wdt_enable(WDTO_30MS); while(1) {}

#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 9, 2);

//declare constant pin for IR receiver
const int IR_pin = 12;

//declare variable to store the key value
unsigned long key_value = 0;

//define the receiver and the results
IRrecv irrecv(IR_pin);
decode_results results;

//declare buzzer pin
const int BUZZER_PIN = 3;

//arrays for five different tunes
int tune1[] = {587, 0, 587, 0, 1174, 1174, 880, 880, 0, 830, 0, 783, 0, 698, 698, 587, 698, 783};
int tune2[] = {523, 0, 523, 0, 1174, 1174, 880, 880, 0, 830, 0, 783, 0, 698, 698, 587, 698, 783};
int tune3[] = {493, 0, 493, 0, 1174, 1174, 880, 880, 0, 830, 0, 783, 0, 698, 698, 587, 698, 783};
int tune4[] = {466, 0, 466, 0, 1174, 1174, 880, 880, 0, 830, 0, 783, 0, 698, 698, 587, 698, 783};
int tune5[] = {783, 783, 1046, 1046, 1174, 1174, 1244, 1244, 1244, 1244, 1174, 1174, 1046, 1174, 1244, 1174, 1046, 1046, 987, 1046, 1046, 1046, 1046};
int tune6[] = {880, 880, 1046, 1046, 1567, 1567, 1567, 1760, 1567, 1567, 880, 1046, 1318, 1318, 1318, 1396, 0, 1396, 1396, 1046, 1046, 1567, 1567, 1567, 1760, 1567, 1567, 1046, 2093, 1864, 1864, 1864, 2093, 1760, 1760, 1760, 1760, 1567, 1567, 1760, 1567, 1567, 880, 1046, 1318, 1318, 1567, 1567, 1396, 1396, 1318, 1318, 1396, 1396, 1769, 1767, 1567, 1567, 2093, 2093, 2349, 2349, 2349, 2349};
int tune7[] = {554, 659, 622, 659, 554, 554, 0, 554, 554, 622, 659, 987, 830, 830, 0, 554, 659, 622, 659, 554, 554, 0, 554, 554, 622, 659, 987, 830, 830, 0, 554, 659, 622, 659, 554, 554, 0, 554, 554, 622, 659, 987, 830, 830, 0, 493, 493, 493, 739, 739, 739, 659, 659, 622, 554, 493, 493, 622, 622, 622};
int tune8[] = {};

void setup() {
  Serial.begin(9600); //Begin the serial communication with a baud of 9600
  irrecv.enableIRIn(); // Enable the receiver
  pinMode(BUZZER_PIN, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Welcome to mp3");
  //This if function checks whether there is a signal from the remote
  if (irrecv.decode(&results))
  {
    //if the button is pressed constantly, set the value to original
    if (results.value == 0xFFFFFFFF)
    {
      results.value = key_value; //set value to key value
    }
    switch (results.value) //checks the value to each individual cases
    {

      case 0xFF30CF: //Keypad button "1
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 1");

        Serial.println("1");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 17; i++)
        {
          //first four notes are faster
          if (i <= 3)
          {
            tone (BUZZER_PIN, tune1[i]);
            delay(150);
          }
          //the other notes remains at another tempo
          else
          {
            tone (BUZZER_PIN, tune1[i]);
            delay(200);
          }
        }
        Reset_AVR(); //reset the arduino
        break;

      case 0xFF18E7: //Keypad button "2"
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 2");

        Serial.println("2");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 17; i++)
        {
          //first four notes are faster
          if (i <= 3)
          {
            tone (BUZZER_PIN, tune2[i]);
            delay(150);
          }
          //the other notes remains at another tempo
          else
          {
            tone (BUZZER_PIN, tune2[i]);
            delay(200);
          }
        }
        Reset_AVR(); //reset the arduino
        break;

      case 0xFF7A85: //Keypad button "3"
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 3");
        Serial.println("3");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 17; i++)
        {
          //first four notes are faster
          if (i <= 3)
          {
            tone (BUZZER_PIN, tune3[i]);
            delay(150);
          }
          //the other notes remains at another tempo
          else
          {
            tone (BUZZER_PIN, tune3[i]);
            delay(200);
          }
        }
        Reset_AVR(); //reset the arduino
        break;

      case 0xFF10EF: //Keypad button "4"
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 4");
        Serial.println("4");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 17; i++)
        {
          //first four notes are faster
          if (i <= 3)
          {
            tone (BUZZER_PIN, tune4[i]);
            delay(150);
          }
          //the other notes remains at another tempo
          else
          {
            tone (BUZZER_PIN, tune4[i]);
            delay(200);
          }
        }
        Reset_AVR(); //reset the arduino
        break;

      case 0xFF38C7: //Keypad button "5"
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 5");
        Serial.println("5");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 22; i++)
        {
          //some notes are faster
          if (i >= 12 && i <= 16)
          {
            tone (BUZZER_PIN, tune5[i]);
            delay(100);
          }
          //the other notes remains at another tempo
          else
          {
            tone (BUZZER_PIN, tune5[i]);
            delay(500);
          }
        }
        Reset_AVR(); //reset the arduino
        break;

      case 0xFF5AA5:
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 6");
        Serial.println("6");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 61; i++)
        {
          tone (BUZZER_PIN, tune6[i]);
          delay(400);
        }
        Reset_AVR();
        break;

      case 0xFF42BD:
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 7");
        Serial.println("7");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 58; i++)
        {
          tone (BUZZER_PIN, tune7[i]);
          delay(200);
        }
        Reset_AVR();
        break;

      case 0xFF4AB5:
        lcd.clear();
        delay(100);
        lcd.setCursor(0, 0);
        lcd.print("Now playing:");
        lcd.setCursor(0, 1);
        lcd.print("Track 8");
        Serial.println("8");  //to see if the sensor sense a signal
        //The playing of each notes for the tune
        for (int i = 0; i <= 10; i++)
        {
          tone (BUZZER_PIN, tune8[i]);
          delay(200);
        }
        Reset_AVR();
        break;

    }
    key_value = results.value; //store the value as key value
    irrecv.resume(); //Reset the receiver for the next value
  }
  delay(100); //delay for 100 ms
}
