
const int btn = 39; // Capteur de Luminosité
const int btn1 = 41;  // Capteur de Fumée
const int btn2 = 43;  // Capteur de CO2
int val1, val2, val3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(btn, OUTPUT);
  pinMode(btn1, OUTPUT);
  pinMode(btn2, OUTPUT);

  pinMode(btn, HIGH);
  pinMode(btn1, HIGH);
  pinMode(btn2, HIGH);
}

void loop() {

digitalWrite(btn, LOW);
 digitalWrite(btn2, HIGH);
 delay(2000);
 digitalWrite(btn, HIGH);
 digitalWrite(btn1, LOW);
 delay(2000);
 digitalWrite(btn1, HIGH);
 digitalWrite(btn2, LOW);
 delay(2000);
}
