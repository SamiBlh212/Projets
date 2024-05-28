#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// L'adresse IP que prendra le shield
byte ip[] = { 10, 194, 196, 35 };
// L'adresse IP de la passerelle
byte gateway[] = { 10, 194, 196, 254 };
// Attachement d'un objet "server" sur le port 2000
EthernetServer server(212);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Liaison Serie ok ...");
  // Configuration de la ethernet shield et du server
  Ethernet.begin(mac, ip, gateway);
  server.begin();
  // Donne une seconde au shield pour s'initialiser
  delay(1000);
  Serial.println("Serveur ok ...");
}

void loop() {
  // put your main code here, to run repeatedly:
  EthernetClient client = server.available();
  if (client && client.connected()) {
    //if (client.available() > 0) {
    Serial.println("Client connecté ...");

    //}
  }
  client.write("A");
  Serial.println("Envoyé...");
}
