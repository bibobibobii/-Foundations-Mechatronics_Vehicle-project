#include "SR04.h"
// Motor A connections
int enA = 2;
int in1 = 3;
int in2 = 4;
int enB = 7;
int in3 = 5;
int in4 = 6;
#define TRIG_PIN 12
#define ECHO_PIN 13

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
  Serial.begin(9600); //Initialization of Serial Port
     
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {

  a = sr04.Distance();
   Serial.print(a);
   Serial.println("cm");//The difference between "Serial.print" and "Serial.println" 
                        //is that "Serial.println" can change lines.
   delay(100);
  // set speed to 50%
  analogWrite(enA, 255); 
  analogWrite(enB, 255); 

  // Turn on motor - forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(200);

}
