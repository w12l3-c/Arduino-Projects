// 3X3X3 LED Cube Test Code
/* To turn on a single LED i.e. LED in the first layer-1st column, we need to power the
  CP1 pin and ground the CN1.
  To turn on all LEDs we power all CP pins and ground all CN layers
*/
void setup() {
  for (int i = 2; i <= 10; i++) {
    pinMode(i, OUTPUT); // PINS 2-10 are set as output
  }
  pinMode(A0, OUTPUT); // PIN A0 set as output
  pinMode(A1, OUTPUT); // PIN A1 set as output
  pinMode(A2, OUTPUT); // PIN A2 set as output
}
void loop() {
  //Layer 1 test
  digitalWrite(A0, LOW); // layer 1 of cube is enabled
  digitalWrite(A1, HIGH); // layer 2 of cube is disabled
  digitalWrite(A2, HIGH); // layer 3 of cube is disabled
  for (int i = 2; i <= 10; i++) { // turn ON each LED one after another in layer1
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
  //Layer 2 test
  digitalWrite(A0, HIGH); // layer 1 of cube is disabled
  digitalWrite(A1, LOW); // layer 2 of cube is enabled
  digitalWrite(A2, HIGH); // layer 3 of cube is disabled
  for (int i = 2; i <= 10; i++) { // turn ON each LED one after another in layer2
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
  //Layer 3 test
  digitalWrite(A0, HIGH); // layer 1 of cube is disabled
  digitalWrite(A1, HIGH); // layer 2 of cube is disabled
  digitalWrite(A2, LOW); // layer 3 of cube is enabled
  for (int i = 2; i <= 10; i++) { // turn ON each LED one after another in layer3
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
  }
}
