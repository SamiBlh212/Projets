void setup() {
  // Démarre la communication série avec une vitesse de 9600 bauds
  Serial.begin(9600);
}

void loop() {
  // Lit les valeurs des potentiomètres
  int potentiometerValueA0 = analogRead(A0);
  int potentiometerValueA1 = analogRead(A1);
  int potentiometerValueA2 = analogRead(A2);

  // Convertit les valeurs analogiques en valeurs décimales
  float decimalValueA0 = map(potentiometerValueA0, 0, 1023, 0, 10);
  float decimalValueA1 = map(potentiometerValueA1, 0, 1023, 0, 10);
  float decimalValueA2 = map(potentiometerValueA2, 0, 1023, 0, 10);

  // Affiche les valeurs dans la console série avec 2 décimales
  Serial.print("Potentiometer A0: ");
  Serial.println(decimalValueA0, 2);
  Serial.print("Potentiometer A1: ");
  Serial.println(decimalValueA1, 2);
  Serial.print("Potentiometer A2: ");
  Serial.println(decimalValueA2, 2);

  // Délai d'attente entre chaque lecture (facultatif)
  delay(1000);
}
