const int pin3 = 49; // Lampadaires
const int pin2 = 51; // Lampadaires
const int pin1 = 53; // Lampadaires

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
}

void loop() {

  /*digitalWrite(pin1, LOW);
    digitalWrite(pin3, HIGH);
    delay(2000);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    delay(2000);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    delay(2000);*/

  int potentiometerValueA0 = analogRead(A0);
  int potentiometerValueA1 = analogRead(A1);
  int potentiometerValueA2 = analogRead(A2);

  float valFumee = map(potentiometerValueA0, 0, 1023, 0, 0.2);
  float valCo2 = map(potentiometerValueA1, 0, 1023, 0, 3000);
  float valLumi = map(potentiometerValueA2, 0, 1023, 0, 10);


  Serial.print("Fumée : ");
  Serial.println(valFumee);
  Serial.print("CO2 : ");
  Serial.println(valCo2);
  Serial.print("Luminosité : ");
  Serial.println(valLumi);

  if (valLumi < 2.5) {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }
  else if (2.5 <= valLumi <= 5)
  {
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }
  else if (5 < valLumi <= 7.5)
  {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }
  else if (valLumi > 7.5)
  {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }

  
  delay(1000);
  //digitalWrite(pin1, LOW);
  //digitalWrite(pin2, LOW);
  //digitalWrite(pin3, LOW);
}
