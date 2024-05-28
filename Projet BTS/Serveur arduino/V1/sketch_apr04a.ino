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

const int potentiometerPin1 = A0; //Fumee
const int potentiometerPin2 = A1; //C02
const int potentiometerPin3 = A2; //Luminosité
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

void setup()
{

  // Initialisation liaison série
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

void loop()
{
  // Attente de la connexion d'un client
  EthernetClient client = server.available();

  /*int val1 = analogRead(potentiometerPin1);
  int val2 = analogRead(potentiometerPin2);
  int val3 = analogRead(potentiometerPin3);*/

  int val1 = 1;
  int val2 = 89;
  int val3 = 23;


  Serial.print("Capteur 1 : ");
  Serial.println(val1);
  Serial.print("Capteur 2 : ");
  Serial.println(val2);
  Serial.print("Capteur 3 : ");
  Serial.println(val3);
  
  requete = "GET 127.0.0.1::8888/ProjetCTR/insertion.php?valLum=";
  requete.concat(val1);
  requete += "&valFumee=";
  requete.concat(val2);
  requete += "&valCo2=";
  requete.concat(val3);
  //requete += " HTTP/1.1";
  Serial.println(requete);
  
  client.println(requete);


  if (client && client.connected()) {

    Serial.println("Client connecté ...");
    // si le client nous envoie quelque chose
    if (client.available() > 0) {
      // On regarde ce que le client nous demande
      switch (client.read()) {
         
        // Ventilateur Bas
        case 'A': // allumer le ventilateur
          Serial.println("Reception : ");
          //Serial.println(client.read());
          digitalWrite(pin1, LOW);
          Serial.println("Allumage du ventilateur");
          break;
        case 'B': // éteindre le ventilateur
          digitalWrite(pin1, HIGH);
          Serial.println("Eteindre le ventilateur ...");
          break;

        // Ventilateur Haut
        case 'C': // allumer le ventilateur
          digitalWrite(pin2, LOW);
          Serial.println("Allumage du ventilateur");
          break;
        case 'D': // éteindre le ventilateur
          digitalWrite(pin2, HIGH);
          Serial.println("Eteindre le ventilateur ...");
          break;

        // LED en haut à gauche
        case 'E': // allumer la led
          digitalWrite(pin3, LOW);
          Serial.println("Allumage de la LED");
          break;
        case 'F': // éteindre la led
          digitalWrite(pin3, HIGH);
          Serial.println("Eteindre la led ...");
          break;

        // Led Tunnel gauche
        case 'G': // LED Rouge
          digitalWrite(pin4, LOW);
          Serial.println("Allumage du ventilateur");
          break;
        case 'H': // LED Verte
          digitalWrite(pin4, HIGH);
          Serial.println("LED Verte ...");
          break; 

          // Led Tunnel Droite
        case 'I': // LED Rouge
          digitalWrite(pin5, LOW);
          Serial.println("Allumage du ventilateur");
          break;
        // Led Tunnel Droite
        case 'J': // LED Rouge
          digitalWrite(pin5, HIGH);
          Serial.println("Allumage du ventilateur");
          break;
        case 'K': // LED Verte
          digitalWrite(pin6, LOW);
          Serial.println("Eteindre la led ...");
          break; 
        case 'L': // LED Verte
          digitalWrite(pin6, HIGH);
          Serial.println("Eteindre la led ...");
          break;

        case 'M': // LED Verte
          digitalWrite(pin7, LOW);
          Serial.println("Eteindre la led ...");
          break;

        case 'N': // LED Verte
          digitalWrite(pin7, HIGH);
          Serial.println("Eteindre la led ...");
          break; 

        case 'O': // LED Verte
         Serial.println("E : ");
          digitalWrite(pin8, LOW);
          Serial.println("Eteindre la led ...");
          break; 

        case 'P': // LED Verte
        Serial.println("F : ");
          digitalWrite(pin8, HIGH);
          Serial.println("Eteindre la led ...");
          break; 
      }
    }
  }
}
