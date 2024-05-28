const int buttonPin = 2;  
volatile int variable = 0; 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  attachInterrupt(digitalPinToInterrupt(buttonPin), incrementVariable, FALLING);  
  Serial.begin(9600);
}

void loop() {
  /*Serial.print("Variable : ");
  Serial.println(variable);
  delay(1000);*/
 
}

void incrementVariable() {
  variable++;  
  Serial.println("Nombre de véhicules : ");
  Serial.println(variable);
 
}
