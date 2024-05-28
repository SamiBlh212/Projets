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

/*const int potentiometerPin1 = A0; //Fumee
  const int potentiometerPin2 = A1; //C02
  const int potentiometerPin3 = A2; //Luminosité*/

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
    int val3 = analogRead(potentiometerPin3);

    float realval1 = val1/1000;
    float realval2 = val2/1000;
    float realval3 = val3/1000;*/

  int potentiometerValueA0 = analogRead(A0);
  int potentiometerValueA1 = analogRead(A1);
  int potentiometerValueA2 = analogRead(A2);

  int valFumee = map(potentiometerValueA0, 0, 1023, 0, 10);
  int valCo2 = map(potentiometerValueA1, 0, 1023, 0, 10);
  int valLumi = map(potentiometerValueA2, 0, 1023, 0, 10);


  Serial.print("Fumée : ");
  Serial.println(valFumee);
  Serial.print("CO2 : ");
  Serial.println(valCo2);
  Serial.print("Luminosité : ");
  Serial.println(valLumi);

  /*requete = "GET http://127.0.0.1:8888/ProjetCTR/insertion.php?valLum=";
  requete.concat(valFumee);
  requete += "&valFumee=";
  requete.concat(valCo2);
  requete += "&valCo2=";
  requete.concat(valLumi);
  //requete += " HTTP/1.1";
  Serial.println(requete);
  client.println(requete);
  delay(2000);*/

  //if (client && client.connected()) {

    Serial.println("Client connecté ...");
    //////////////////////////////////////////////////////////////////////////
    ///////////////////////   LAMPADAIRES 1/3   /////////////////////////////
    if (valLumi < 2.5) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH); // Obligé de ne pas l'allumer à cause d'un problème d'alimentation
    }
    else if (2.5 <= valLumi <= 5)
    {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
    }

    else if (5 < valLumi <= 7.5)
    {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
    }
    else if (valLumi > 7.5)
    {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, HIGH);
    }


    /*        case 'F': // éteindre la led
              digitalWrite(pin3, HIGH);
              Serial.println("Eteindre lampadaires 3/3");
              break;

      //////////////////////////////////////////////////////////////////////////
      ///////////////////////   LED TUNNEL DROITE   ///////////////////////////

            case 'G': // LED Verte
              digitalWrite(pin4, LOW);
              Serial.println("LED Verte");
              break;

            case 'H': // LED Rouge
              digitalWrite(pin4, HIGH);
              Serial.println("LED Rouge");
              break;

      //////////////////////////////////////////////////////////////////////////
      ///////////////////////   LED TUNNEL GAUCHE   ///////////////////////////

            case 'I': // LED Verte
              digitalWrite(pin5, LOW);
              Serial.println("LED Verte");
              break;

            case 'J': // LED Rouge
              digitalWrite(pin5, HIGH);
              Serial.println("LED Rouge");
              break;

      //////////////////////////////////////////////////////////////////////////
      ///////////////////////   LED EN HAUT A GAUCHE   ////////////////////////

            case 'K': // LED Allumée
              digitalWrite(pin6, LOW);
              Serial.println("Allumage de la led");
              break;

            case 'L': // LED éteinte
              digitalWrite(pin6, HIGH);
              Serial.println("Eteindre la led");
              break;

      //////////////////////////////////////////////////////////////////////////
      ///////////////////////   VENTILATEUR HAUT   ////////////////////////////

            case 'M': // Allumage Ventilateur
              digitalWrite(pin7, LOW);
              Serial.println("Allumage Ventilateur");
              break;

            case 'N': // Eteindre Ventilateur
              digitalWrite(pin7, HIGH);
              Serial.println("Eteindre la led ...");
              break;

      //////////////////////////////////////////////////////////////////////////
      ///////////////////////   VENTILATEUR BAS   /////////////////////////////

            case 'O': // Allumage Ventilateur
             Serial.println("E : ");
              digitalWrite(pin8, LOW);
              Serial.println("Allumage Ventilateur");
              break;

            case 'P': // Eteindre Ventilateur
            Serial.println("F : ");
              digitalWrite(pin8, HIGH);
              Serial.println("Eteindre Ventilateur");
              break; */

  //}
}
