#define Enable_A D0 
#define IN1 D1
#define IN2 D2
#define Enable_B D3
#define IN3 D6
#define IN4 D5

/*const int LED  = 13;
const int Enable_A =  0;    // A low-to-high transition on the STEP input sequences the translator and advances the motor one increment.
const int IN1 = 1;          // Direction of rotation
const int IN2 = 2;          // Mode of operation: Active/Sleep
const int Enable_B = 3;      // Enable/Disable the Driver operation
const int IN3 = 6;          // Reset when active turns off all of the FET outputs
const int IN4 = 5;          // Microstep Select
const int Threshold = 20;*/

/* #define IN1_L    digitalWrite(IN1, LOW);
#define IN1_H    digitalWrite(IN1, HIGH);
#define IN2_L    digitalWrite(IN2, LOW);
#define IN2_H    digitalWrite(IN2, HIGH);
#define IN3_L    digitalWrite(IN3, LOW);
#define IN3_H    digitalWrite(IN3, HIGH);
#define IN4_L    digitalWrite(IN4, LOW);
#define IN4_H    digitalWrite(IN4, HIGH);  */


void setup() {
  Serial.begin(115200);
  //Serial.print("Serial ok ... ");
  // set the digital pin as output:
  pinMode(Enable_A, OUTPUT); 
  pinMode(Enable_B, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //Set the state
  digitalWrite(Enable_A, HIGH);      
  digitalWrite(Enable_B, HIGH);       
  digitalWrite(IN1, LOW);    
  digitalWrite(IN2, LOW);    
  digitalWrite(IN3, LOW);    
  digitalWrite(IN4, LOW);    

}

void loop()
{
  /*Serial.print("Sens 1 ... ");
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, HIGH);
  delay(1000);
  Serial.print("Sens 2 ... ");
  digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
  delay(1000);
  Serial.print("Sens 3 ... ");
  digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
  delay(1000);*/

  Serial.print("Avancer ");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);    
  digitalWrite(IN4, LOW);

  
  
}
