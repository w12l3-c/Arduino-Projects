/* Elavator by Wallace Lee
   
*/
#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(6, 5, 4, 3, 2, 1);  //LCD pins
Servo servo;

//LED pins
const int motorR_pin = 13;
const int motorL_pin = 12;
const int servo_pin = 9;

//push button pins
const int first_pb = 11;
const int second_pb = 10;
const int third_pb = 8;
const int stop_pb = 7;

//value for case
int mode = 0;

//State for each pushbutton and switch
bool first_pb_state;
bool second_pb_state;
bool third_pb_state;
bool stop_pb_state;

//the beep sound as audible warning sound
int beep = 440;

//the condition of some cases for changing mode
bool condition2 = true;
bool condition3 = true;
bool condition5 = true;

//unsigned long variables for the millis() function
//intervals for each mode
unsigned long door_close = 5000;
//time variables
unsigned long previous_time = 0;
unsigned long current_time = 0;
unsigned long delta_time = 0;
unsigned long number = 0;

void setup() {
  //setting up each output pins
  pinMode(READY_LED_PIN, OUTPUT);
  pinMode(WASH_LED_PIN, OUTPUT);
  pinMode(RINSE_LED_PIN, OUTPUT);
  pinMode(DONE_LED_PIN, OUTPUT);
  pinMode(HEAVY_LED_PIN, OUTPUT);
  pinMode(buzzer_PIN, OUTPUT);

  //starting up each input pins
  pinMode(doorSwitch_PIN, INPUT);
  pinMode(stopPB_PIN, INPUT);
  pinMode(rinsePB_PIN, INPUT);
  pinMode(washPB_PIN, INPUT);
  pinMode(heavyPB_PIN, INPUT);

  //start servo
  servo.attach(servo_pin);

  //starting the lcd
  lcd.begin(16, 2);
}

void loop() {
  //read button states
  1pbState = digitalRead(doorSwitch_PIN);
  2pbState = digitalRead(stopPB_PIN);
  3pbState = digitalRead(rinsePB_PIN);
  stopPBState = digitalRead(washPB_PIN);

  //compare each value
  switch (mode) {
    case 0: //standby
      //every LED off
      digitalWrite(READY_LED_PIN, LOW);
      digitalWrite(WASH_LED_PIN, LOW);
      digitalWrite(RINSE_LED_PIN, LOW);
      digitalWrite(HEAVY_LED_PIN, LOW);
      digitalWrite(DONE_LED_PIN, LOW);

      //if door closed
      if (doorState == HIGH)
      {
        //if each button is pushed
        if (washPBState == LOW)
        {
          //beep
          tone(buzzer_PIN, beep);
          delay(100);
          noTone(buzzer_PIN);
          mode = 2;
        }
        if (rinsePBState == LOW)
        {
          //beep
          tone(buzzer_PIN, beep);
          delay(100);
          noTone(buzzer_PIN);
          mode = 3;
        }
        if (heavyPBState == LOW)
        {
          //beep
          tone(buzzer_PIN, beep);
          delay(100);
          noTone(buzzer_PIN);
          mode = 5;
        }
        //no button is pushed
        if (washPBState == HIGH && rinsePBState == HIGH && heavyPBState == HIGH)
        {
          mode = 1;
        }
      }
      //if door open
      else
      {
        mode = 0;
        //print text on lcd
        lcd.setCursor(0, 0);
        lcd.print("Mode:Standby    ");
        lcd.setCursor(0, 1);
        lcd.print("           ");

      }
      break;

    case 1: //ready
      //ready led on others off
      digitalWrite(READY_LED_PIN, HIGH);
      digitalWrite(WASH_LED_PIN, LOW);
      digitalWrite(RINSE_LED_PIN, LOW);
      digitalWrite(DONE_LED_PIN, LOW);
      digitalWrite(HEAVY_LED_PIN, LOW);

      //print text on lcd first row
      lcd.setCursor(0, 0);
      lcd.print("Mode:Ready      ");

      mode = 0;
      break;

    case 2: //Wash
      //reset current_time
      current_time = 0;
      //reset the condition for mode
      condition2 = true;

      //Wash LED on other LED off
      digitalWrite(READY_LED_PIN, LOW);
      digitalWrite(WASH_LED_PIN, HIGH);
      digitalWrite(RINSE_LED_PIN, LOW);
      digitalWrite(DONE_LED_PIN, LOW);
      digitalWrite(HEAVY_LED_PIN, LOW);

      //print text on lcd
      lcd.setCursor(0, 0);
      lcd.print("Mode:Wash       ");

      //take the time of arduino running as before the loop
      previous_time = millis();
      //current time must bigger than previous time as unsigned cannot be negative
      current_time = previous_time + 10;
      //while the difference of two times is still under 5 seconds
      while ((current_time - previous_time) < interval_wash)
      {
        //update the current time
        current_time = millis();
        //update the state for stop button and door
        doorState = digitalRead(doorSwitch_PIN);
        stopPBState = digitalRead(stopPB_PIN);
        //run only when stop button is not pressed and door not open
        if (stopPBState == HIGH && doorState == HIGH)
        {
          //calculate time to display on lcd
          delta_time = current_time - previous_time;
          number = ((interval_wash - delta_time) / 1000) + 1;

          //print text on lcd
          lcd.setCursor(0, 1);
          lcd.print(number);
        }
        //when door is open or stop button is pressed
        else
        {
          //check whether is door open or stop button pressed
          if (stopPBState == LOW && doorState != LOW)
          {
            //beep
            tone(buzzer_PIN, beep);
            delay(100);
            noTone(buzzer_PIN);
            mode = 4;
          }
          //door open
          else
          {
            mode = 0;
          }
          //condition to fail the next if after while loop
          condition2  = false;
          break;
        }
      }
      //when the while loop does not break out
      if (condition2 == true)
      {
        mode = 3;
      }
      break;

    case 3: //Rinse
      //reset current_time
      current_time = 0;
      //reset the condition for mode
      condition3 = true;

      //Rinse LED on other LED off
      digitalWrite(READY_LED_PIN, LOW);
      digitalWrite(WASH_LED_PIN, LOW);
      digitalWrite(RINSE_LED_PIN, HIGH);
      digitalWrite(DONE_LED_PIN, LOW);
      digitalWrite(HEAVY_LED_PIN, LOW);

      //print text on lcd
      lcd.setCursor(0, 0);
      lcd.print("Mode:Rinse      ");

      //take the time of arduino running as before the loop
      previous_time = millis();
      //current time must bigger than previous time as unsigned cannot be negative
      current_time = previous_time + 10;
      //reset the number as other mode will pass a value to this
      number = 0;
      //while the difference of two times is still under 3 seconds
      while ((current_time - previous_time) < interval_rinse)
      {
        //update the current time
        current_time = millis();
        //update the state for stop button and door
        doorState = digitalRead(doorSwitch_PIN);
        stopPBState = digitalRead(stopPB_PIN);
        //run only when stop button is not pressed and door not open
        if (stopPBState == HIGH && doorState == HIGH)
        {
          //calculate time to display on lcd
          delta_time = current_time - previous_time;
          number = ((interval_rinse - delta_time) / 1000) + 1;

          //print text on lcd
          lcd.setCursor(0, 1);
          lcd.print(number);
        }
        //when door is open or stop button is pressed
        else
        {
          //check whether is door open or stop button pressed
          if (stopPBState == LOW)
          {
            //beep
            tone(buzzer_PIN, beep);
            delay(100);
            noTone(buzzer_PIN);
            mode = 4;
          }
          //door open
          else
          {
            mode = 0;
          }
          //condition to fail the next if after while loop
          condition3  = false;
          break;
        }
      }
      //when the while loop does not break out
      if (condition3 == true)
      {
        mode = 4;
      }
      break;

    case 4: //Done
      //Done led on other led off
      digitalWrite(READY_LED_PIN, LOW);
      digitalWrite(WASH_LED_PIN, LOW);
      digitalWrite(RINSE_LED_PIN, LOW);
      digitalWrite(DONE_LED_PIN, HIGH);
      digitalWrite(HEAVY_LED_PIN, LOW);

      //print text in lcd
      lcd.setCursor(0, 0);
      lcd.print("Done :)         ");
      lcd.setCursor(0, 1);
      lcd.print("                ");

      //play music from list
      for (int i = 0; i < 29; i++)
      {
        tone(buzzer_PIN, music[i]);
        delay(100);
      }
      noTone(buzzer_PIN);
      mode = 0;

      //will not exit until either door is open or stop button pressed
      while (stopPBState == HIGH && doorState == HIGH)
      {
        //update the state of door and stop button
        doorState = digitalRead(doorSwitch_PIN);
        stopPBState = digitalRead(stopPB_PIN);
      }
      break;

    case 5: //Heavy Duty
      //reset current time
      current_time = 0;
      //reset the condition for mode
      condition5 = true;

      //heavy duty led on other led off
      digitalWrite(READY_LED_PIN, LOW);
      digitalWrite(WASH_LED_PIN, LOW);
      digitalWrite(RINSE_LED_PIN, LOW);
      digitalWrite(DONE_LED_PIN, LOW);
      digitalWrite(HEAVY_LED_PIN, HIGH);

      //print text on lcd
      lcd.setCursor(0, 0);
      lcd.print("Mode:Heavy Duty ");

      //take the time of arduino running as before the loop
      previous_time = millis();
      //current time must bigger than previous time as unsigned cannot be negative
      current_time = previous_time + 10;
      //while the difference of two times is still under 10 seconds
      while ((current_time - previous_time) < interval_heavy)
      {
        //update the current time
        current_time = millis();
        //update the state for stop button and door
        doorState = digitalRead(doorSwitch_PIN);
        stopPBState = digitalRead(stopPB_PIN);
        //run only when stop button is not pressed and door not open
        if (stopPBState == HIGH && doorState == HIGH)
        {
          //calculate time to display on lcd
          delta_time = current_time - previous_time;
          number = ((interval_heavy - delta_time) / 1000) + 1;

          //print text on lcd
          lcd.setCursor(0, 1);
          if (number == 9)
          {
            //print "9 " to cancel the 0 on 10 and lcd.clear is too slow
            lcd.print("9 ");
          }
          else
          {
            lcd.print(number);
          }
        }
        //when door is open or stop button is pressed
        else
        {
          //check whether is door open or stop button pressed
          if (stopPBState == LOW)
          {
            //beep
            tone(buzzer_PIN, beep);
            delay(100);
            noTone(buzzer_PIN);
            mode = 4;
          }
          //door open
          else
          {
            mode = 0;
          }
          //condition to fail the next if after while loop
          condition5  = false;
          break;
        }
      }
      //when the while loop does not break out
      if (condition5 == true)
      {
        mode = 3;
      }
      break;
  }
}
