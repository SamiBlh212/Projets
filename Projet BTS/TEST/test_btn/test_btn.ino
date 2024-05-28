const int btn = 33;
int comptage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT);
  digitalWrite(btn, HIGH);
}

void loop() {
  int etatBtn = digitalRead(btn);

  if(etatBtn == LOW)
  {
    comptage++;
  }
  Serial.print("Nombre des véhicules : ");
  Serial.println(comptage);
}
