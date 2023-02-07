/* US Sensor - Written by Wallace and Nazar
   This code is written to sense distance and sound a buzzer
   "tone" commands */

// declare variables for pins
int green_LED_pin =  4;
int red_LED_pin = 5;
int BUZZER_PIN = 6;
int TRIGGER_PIN = 3;
int ECHO_PIN = 2;
int hertz = 100;
int tune[] = {195, 0, 195, 0, 195, 0, 261, 261, 261, 261, 391, 391, 391, 391, 349, 329, 293, 523, 523, 523, 523, 391, 391, 349, 329, 293, 523, 523, 523, 523, 391, 391, 349, 329, 349, 293, 293, 293, 293};

float duration;
float distance;

void setup()
{
  // set pins 3 to 6 outputs
  for (int i = 3; i <= 6; i++)
  {
    pinMode(i, OUTPUT);
  }

  pinMode(2, INPUT); // set pin 2 as input
}

void loop()
{
  /************** Start US Measurement Section ***********/
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  /************** End US Measurement Section ***********/

  // if distance is less than 50cm
  if (distance < 50)
  {
    digitalWrite(red_LED_pin, HIGH);
    digitalWrite(green_LED_pin, LOW);
    //The playing of each notes for the tune
    for (int i = 0; i <= 38; i++)
    {
      //first five notes are faster
      if (i <= 4)
      {
        tone (BUZZER_PIN, tune[i]);
        delay(150);
      }
      //the other notes remains at another tempo
      else
      {
        tone (BUZZER_PIN, tune[i]);
        delay(225);
      }
    }
  }
  //else if distance is less than or equal to 110 cm and larger than 95 cm
  else if (distance <= 110 && distance > 95)
  {
    digitalWrite(green_LED_pin, HIGH);
    digitalWrite(red_LED_pin, LOW);
    tone(BUZZER_PIN, hertz);
  }
  //else if distance is less than or equal to 95 cm and larger than 80 cm
  else if (distance <= 95 && distance > 80)
  {
    digitalWrite(green_LED_pin, HIGH);
    digitalWrite(red_LED_pin, LOW);
    tone(BUZZER_PIN, hertz * 2);
  }
  //else if distance is less than or equal to 80 cm and larger than 65 cm
  else if (distance <= 80 && distance > 65)
  {
    digitalWrite(green_LED_pin, HIGH);
    digitalWrite(red_LED_pin, LOW);
    tone(BUZZER_PIN, hertz * 3);
  }
  //else if distance is less than or equal to 65 cm and larger than or equal to 50 cm
  else if (distance <= 65 && distance >= 50)
  {
    digitalWrite(green_LED_pin, HIGH);
    digitalWrite(red_LED_pin, LOW);
    tone(BUZZER_PIN, hertz * 4);
  }
  // distance is greater than 110 cm
  else
  {
    digitalWrite(green_LED_pin, HIGH);
    digitalWrite(red_LED_pin, LOW);
    noTone(BUZZER_PIN);
  }
  delay(10); // small delay to save system resources
}
