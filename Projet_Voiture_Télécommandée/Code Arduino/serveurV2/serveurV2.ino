#include <ESP8266WiFi.h>

#define Enable_A D0 
#define IN1 D1
#define IN2 D2
#define Enable_B D3
#define IN3 D6
#define IN4 D5

// Replace with your network credentials
const char* ssid     = "seconde_ICN";
const char* password = "wifipourlesicn";

// Set web server port number to 80
WiFiServer server(212);

// Variable to store the request
String header;

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

// Assign output variables to GPIO pins
const int output5 = 5;
const int output4 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 30000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  
  pinMode(Enable_A, OUTPUT); 
  pinMode(Enable_B, OUTPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(Enable_A, HIGH);      
  digitalWrite(Enable_B, HIGH);       
  digitalWrite(IN1, HIGH);    
  digitalWrite(IN2, HIGH);    
  digitalWrite(IN3, HIGH);    
  digitalWrite(IN4, HIGH);   
  
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  // Set outputs to LOW
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        switch(c) 
         {
          case 'a' : Serial.print("Avancer ");
                    digitalWrite(IN1, LOW);
                    digitalWrite(IN2, HIGH);
                    digitalWrite(IN3, HIGH);    
                    digitalWrite(IN4, LOW);
          break; 
          case 'b' : Serial.println("Freiner");
                    digitalWrite(IN1, HIGH);
                    digitalWrite(IN2, HIGH);
                    digitalWrite(IN3, HIGH);    
                    digitalWrite(IN4, HIGH);
          break;
          case 'c' : Serial.println("Gauche");
                     digitalWrite(IN1, LOW);
                     digitalWrite(IN2, HIGH);
                     digitalWrite(IN3, HIGH);    
                     digitalWrite(IN4, HIGH);
          break;
          case 'd' : Serial.println("Droite");
                     digitalWrite(IN1, HIGH);
                     digitalWrite(IN2, HIGH);
                     digitalWrite(IN3, LOW);    
                     digitalWrite(IN4, LOW);
          break;
         }
        //Serial.write(c);  
        //header += c;// print it out the serial monitor
         }
    }
    // Close the connection
    header = "";
    //client.stop();
    Serial.println("");
 
 }
}
