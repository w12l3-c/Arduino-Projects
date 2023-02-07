// 8 LEDs - Written by Wallace Nazar 21.10.27
// This code is to make 8 LEDs light on and off one in order and different
// delays in a continuous loop using for loops and variables.
// variables, arrays, for loop

int pins[] = {1, 2, 3, 4, 5, 6, 7, 8}; // array to hold pin numbers
int delayTime;  //variable to hold a number for millisecond

void setup()
{
  // set LED pin 1 to 8 as outputs.
  for (int i = 0; i <= 7; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  /*setting the time delay to 500 ms and each loop of LEDs lighting
    on and off will be delaying 100 ms less until 100 ms*/
  for (int delayTime = 500; delayTime >= 100; delayTime = delayTime - 100)
  {
    // turn LEDs on then by the order with a delay
    for (int i = 0; i <= 3; i++)
    {
      digitalWrite(pins[i], HIGH);
      delay(delayTime);
      digitalWrite(pins[i + 4], HIGH);
      delay(delayTime);
    }
    // turn LEDs off in reverse order with a delay
    for (int i = 7; i >= 4; i--)
    {
      digitalWrite(pins[i], LOW);
      delay(delayTime);
      digitalWrite(pins[i - 4], LOW);
      delay(delayTime);
    }
  }
  /*setting the time delay to 200 ms and each loop of LEDs lighting
    on and off will be delaying 100 ms more until 400 ms */
  for (int delayTime = 200; delayTime <= 400; delayTime = delayTime + 100)
  {
    // turn LEDs on then by the order with a delay
    for (int i = 0; i <= 3; i++)
    {
      digitalWrite(pins[i], HIGH);
      delay(delayTime);
      digitalWrite(pins[i + 4], HIGH);
      delay(delayTime);
    }
    // turn LEDs off in reverse order with a delay
    for (int i = 7; i >= 4; i--)
    {
      digitalWrite(pins[i], LOW);
      delay(delayTime);
      digitalWrite(pins[i - 4], LOW);
      delay(delayTime);
    }
  }
}
