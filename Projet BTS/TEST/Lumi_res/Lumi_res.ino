const int pin3 = 49; // Lampadaires
const int pin2 = 51; // Lampadaires
const int pin1 = 53; // Lampadaires
const int pin8 = 39; // Ventilateur Bas
const int pin7 = 41; // Ventilateur Haut

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
  digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);

}
