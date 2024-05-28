const int pin = 36;
const int pin1 = 38; // Ventilateur Bas
const int pin2 = 40; // Ventilateur Haut
const int pin3 = 42; // Led en haut à gauche
const int pin4 = 44; // Led tunnel  gauche - HIGH = Rouge, LOW = Vert
const int pin5 = 46; // Led tunnel droite - HIGH = Rouge, LOW = Vert 
const int pin6 = 48; // Lampadaires
const int pin7 = 50; // Lampadaires
const int pin8 = 52; // Lampadaires

const int capteur = A0; // Capteur de Luminosité
const int capteur1 = A1;  // Capteur de Fumée
const int capteur2 = A2;  // Capteur de CO2
int val1, val2, val3; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Liaison série : ");
  pinMode(pin,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  pinMode(capteur, OUTPUT);
  pinMode(capteur1, OUTPUT);
  pinMode(capteur2, OUTPUT);
 // pinMode(pin9,OUTPUT);

  digitalWrite(pin,HIGH);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,HIGH);
  digitalWrite(pin5,HIGH);
  digitalWrite(pin6,HIGH);
  digitalWrite(pin7,HIGH);
  digitalWrite(pin8,HIGH);
  //digitalWrite(pin9,LOW);
}

void loop() {

  /* val1 = analogRead(capteur);
   val2 = analogRead(capteur1);
   val3 = analogRead(capteur2);*/

   
  /* Serial.print("Capteur 1 : ");
   Serial.println(val1);
   Serial.print("Capteur 2 : ");
   Serial.println(val2);
   Serial.print("Capteur 3 : ");
   Serial.println(val3);
   Serial.println("  ");
   delay(2000);          //delay 1000 milliseconds */
   
   digitalWrite(pin6,HIGH);   //set pin 8 HIGH, turning on LED
   digitalWrite(pin7,HIGH);   //set pin 8 HIGH, turning on LED
   digitalWrite(pin8,HIGH);   //set pin 8 HIGH, turning on LED
}
