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

String requete;

/* Connexion ethernet */
// L'adresse MAC du shield
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// L'adresse IP que prendra le shield
byte ip[] = { 10, 194, 196, 35 };
// L'adresse IP de la passerelle
byte gateway[] = { 10, 194, 196, 254 };
// Attachement d'un objet "server" sur le port 2000
EthernetServer server(212);

void setup() {
  Serial.begin(9600);

  pinMode(pin, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);

  digitalWrite(pin, HIGH);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);

  Serial.println("Liaison Serie ok ...");
  // Configuration de la ethernet shield et du server
  Ethernet.begin(mac, ip, gateway);
  server.begin();
  // Donne une seconde au shield pour s'initialiser
  delay(1000);
  Serial.println("Serveur ok ...");
}

void loop() {

    EthernetClient client = server.available();
    
  /*digitalWrite(pin1, LOW);
    digitalWrite(pin3, HIGH);
    delay(2000);
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    delay(2000);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    delay(2000);*/

  if (client && client.connected()) {
    Serial.println("Client connecté ...");
  }
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

  requete = "GET http://127.0.0.1:8888/ProjetCTR/insertion.php?valLum=";
  requete.concat(valFumee);
  requete += "&valFumee=";
  requete.concat(valCo2);
  requete += "&valCo2=";
  requete.concat(valLumi);
  //requete += " HTTP/1.1";
  Serial.println(requete);
  client.println(requete);

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
    client.write("A");
  }
  else if (3.3 < valCo2 && valCo2 <= 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
    client.write("B");
  }
  else if (valCo2 > 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
    client.write("C");
  }

  if (valFumee <= 3.3) {
    digitalWrite(pin7, HIGH);
    digitalWrite(pin8, HIGH);
    client.write("A");
  }
  else if (3.3 < valFumee && valFumee <= 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, HIGH);
    client.write("B");
  }
  else if (valFumee > 6.6)
  {
    digitalWrite(pin7, LOW);
    digitalWrite(pin8, LOW);
    client.write("C");
  }

  if (valCo2 > 6.6 && valFumee > 6.6) {
    digitalWrite(pin5, HIGH);
    digitalWrite(pin4, HIGH);
    client.write("D");
  }
  else {
    digitalWrite(pin5, LOW);
    digitalWrite(pin4, LOW);
    client.write("E");
  }

/* COMMANDES :
 *  "A" = Ventilateurs éteints
 *  "B" = Ventilateur Haut allumé et l'autre éteint
 *  "C" = Les deux ventilateurs allumés
 *  "D" = Tunnels Fermé
 *  "E" = Tunnels Ouverts
 *  "F" = Lampadaires allumés
 *  "G" = 1/2 Allumé
 *  "H" = Lampadaires éteints
 */
}
