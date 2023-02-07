/* Motors - Written by Wallace
   This code is written to drive two motors forward, then reverse in a loop
   constant, motor control */

// declare constants for motor pins
const int LMotor_pin1 = 5; 
const int LMotor_pin2 = 6;
const int RMotor_pin1 = 10;
const int RMotor_pin2 = 11;

void setup()
{
  //set pins as OUTPUTS
  pinMode(LMotor_pin1, OUTPUT);
  pinMode(LMotor_pin2, OUTPUT);
  pinMode(RMotor_pin1, OUTPUT);
  pinMode(RMotor_pin2, OUTPUT);
}

void forward()
{
  //Left motor forward
  analogWrite(LMotor_pin1, 255);  
  analogWrite(LMotor_pin2, 0);  
  //Right motor forward
  analogWrite(RMotor_pin1, 255);
  analogWrite(RMotor_pin2, 0);
}

void reverse()
{
  //Left motor reverse
  analogWrite(LMotor_pin1, 0); 
  analogWrite(LMotor_pin2, 255);
  //Right motor reverse
  analogWrite(RMotor_pin1, 0);
  analogWrite(RMotor_pin2, 255);
}

void turnLeft()
{
  //Left motor reverse
  analogWrite(LMotor_pin1, 0); 
  analogWrite(LMotor_pin2, 225);
  //Right motor forward
  analogWrite(RMotor_pin1, 255);
  analogWrite(RMotor_pin2, 0);
}

void turnRight()
{
  //Left motor forward
  analogWrite(LMotor_pin1, 255); 
  analogWrite(LMotor_pin2, 0);
  //Right motor reverse
  analogWrite(RMotor_pin1, 0);
  analogWrite(RMotor_pin2, 225);
}


void spin()
{
  //Left motor forward
  analogWrite(LMotor_pin1, 255); 
  analogWrite(LMotor_pin2, 0);
  //Right motor reverse
  analogWrite(RMotor_pin1, 0);
  analogWrite(RMotor_pin2, 225);
}




void loop()
{
  forward();
  delay(2000); //for  seconds
  reverse();
  delay(2000); //for  seconds
  forward();
  delay(2000); //for  seconds
  turnLeft();
  delay(4000); //for  seconds
  forward();
  delay(2000); //for  seconds
  turnRight();
  delay(4000); //for  seconds
  while (true)
  {
    spin();
    }
}
