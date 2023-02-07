/* IR sensor fan - Written by Wallace
   This code is written to make the fan turn on and off with
   different speed with a Infrared Remote  */

//IR remote library
#include <IRremote.h>

//declare constant pin for IR receiver
const int IR_pin = 2;

//declare variable to store the key value
unsigned long key_value = 0;

//define the receiver and the results
IRrecv irrecv(IR_pin);
decode_results results;

//declare constant pins for motors
const int LMotor_pin1 = 9;
const int LMotor_pin2 = 11;
const int RMotor_pin1 = 5;
const int RMotor_pin2 = 6;


void setup() {
  Serial.begin(9600); //Begin the serial communication with a baud of 9600
  irrecv.enableIRIn(); // Enable the receiver

  //Set the motor pins as output
  pinMode(LMotor_pin1, OUTPUT);
  pinMode(LMotor_pin2, OUTPUT);
  pinMode(RMotor_pin1, OUTPUT);
  pinMode(RMotor_pin2, OUTPUT);
}

//function to pause the fans after spinning for 7 seconds
void pause() {
  delay(7000);  //delay for 7 seconds
  //Left motor off
  analogWrite(LMotor_pin1, 0);
  analogWrite(LMotor_pin2, 0);
  //Right motor off
  analogWrite(RMotor_pin1, 0);
  analogWrite(RMotor_pin2, 0);
}

void loop() {
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

      case 0xFF30CF: //Keypad button "1"
        //Left motor very slow speed
        analogWrite(LMotor_pin1, 75);
        analogWrite(LMotor_pin2, 0);
        //Right motor very slow speed
        analogWrite(RMotor_pin1, 75);
        analogWrite(RMotor_pin2, 0);
        pause();
        break;

      case 0xFF18E7: //Keypad button "2"
        //Left motor slow speed
        analogWrite(LMotor_pin1, 100);
        analogWrite(LMotor_pin2, 0);
        //Right motor medium speed
        analogWrite(RMotor_pin1, 100);
        analogWrite(RMotor_pin2, 0);
        pause();
        break;

      case 0xFF7A85: //Keypad button "3"
        //Left motor medium speed
        analogWrite(LMotor_pin1, 150);
        analogWrite(LMotor_pin2, 0);
        //Right motor medium speed
        analogWrite(RMotor_pin1, 150);
        analogWrite(RMotor_pin2, 0);
        pause();
        break;

      case 0xFF10EF: //Keypad button "4"
        //Left motor high speed
        analogWrite(LMotor_pin1, 200);
        analogWrite(LMotor_pin2, 0);
        //Right motor high speed
        analogWrite(RMotor_pin1, 200);
        analogWrite(RMotor_pin2, 0);
        pause();
        break;

      case 0xFF38C7: //Keypad button "5"
        //Left motor very high speed
        analogWrite(LMotor_pin1, 255);
        analogWrite(LMotor_pin2, 0);
        //Right motor very high speed
        analogWrite(RMotor_pin1, 255);
        analogWrite(RMotor_pin2, 0);
        pause();
        break;
    }
    key_value = results.value; //store the value as key value
    irrecv.resume(); //Reset the receiver for the next value
  }
  delay(100);
}
