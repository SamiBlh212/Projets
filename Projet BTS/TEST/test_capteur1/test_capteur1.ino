const int potentiometerPin1 = A0;
const int potentiometerPin2 = A1;
const int potentiometerPin3 = A2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val1 = analogRead(potentiometerPin1);
  int val2 = analogRead(potentiometerPin2);
  int val3 = analogRead(potentiometerPin3);

  float realval1 = val1/1000;
  float realval2 = val2/1000;
  float realval3 = val3/1000;

  Serial.print("Potentiometer 1: ");
  Serial.println(realval1);

  Serial.print("Potentiometer 2: ");
  Serial.println(realval2);

  Serial.print("Potentiometer 3: ");
  Serial.println(realval3);

  delay(500); // Délai entre les lectures pour éviter une lecture trop rapide
}
