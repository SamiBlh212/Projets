#include <SPI.h>
#include <Ethernet.h>

const int pin = 37;
const int pin8 = 39; // Ventilateur Bas
const int pin7 = 41; // Ventilateur Haut
const int pin6 = 43; // Led en haut à gauche
const int pin5 = 45; // Led tunnel  gauche - HIGH = Rouge, LOW = Vert
const int pin4 = 47; // Led tunnel droite - HIGH = Rouge, LOW = Vert
const int pin3 = 49; // Lampadaires
const int pin2 = 51; // Lampadaires
const int pin1 = 53; // Lampadaires

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);

  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);
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

  float valFumee = map(potentiometerValueA0, 0, 1023, 0, 10);
  float valCo2 = map(potentiometerValueA1, 0, 1023, 0, 10);
  float valLumi = map(potentiometerValueA2, 0, 1023, 0, 10);


  Serial.print("Fumée : ");
  Serial.println(valFumee);
  Serial.print("CO2 : ");
  Serial.println(valCo2);
  Serial.print("Luminosité : ");
  Serial.println(valLumi);

  if (valLumi < 2.5) {
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
  }
  else if (2.5 <= valLumi && valLumi <= 5)
  {
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }
  else if (valLumi > 5)
  {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
  }
  delay(1000);

  if (valCo2 <= 3.3) {
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, HIGH);
  }
  else if (3.3 < valCo2 && valCo2 <= 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
  }
  else if (valCo2 > 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
  }

  if (valFumee <= 3.3) {
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, HIGH);
  }
  else if (3.3 < valFumee && valFumee <= 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
  }
  else if (valFumee > 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
  }

  if (valCo2 > 6.6 && valFumee > 6.6) {
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    //client.write("D");
  }
  else {
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    //client.write("E");
  }

  /*if (valCo2 <= 3.3 || valFumee <= 3.3) {
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, HIGH);
    }
    else if (3.3 < valCo2 && valCo2 <= 6.6 || 3.3 < valFumee && valFumee <= 6.6)
    {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
    }
    else if (valCo2 > 6.6 || valFumee > 6.6)
    {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
    }*/
}
