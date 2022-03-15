#include "SR04.h"
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enA 10
#define enB 5
#define echopin 12 // echo pin
#define trigpin 11 // Trigger pin
 
 int Speed = 50;
 int M1_Speed = 120; // speed of motor 1 
 int M2_Speed = 120; // speed of motor 2
 int LeftRotationSpeed = 180; // Left Rotation Speed
 int RightRotationSpeed = 180; // Right Rotation Speed
 SR04 sr04 = SR04(echopin,trigpin);
 long distance;

 
 void setup() {
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
 
  pinMode(A0, INPUT); // initialize Left sensor as an input
  pinMode(A1, INPUT); // initialize Right sensor as an input
   
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
}
 
 void loop() {
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.print("cm ");
  int LEFT_SENSOR = digitalRead(A0);
  int RIGHT_SENSOR = digitalRead(A1);
  if(RIGHT_SENSOR==1 && distance>=10 && distance<=20 && LEFT_SENSOR==1) {
    forward(); //FORWARD
  }
 
  else if(RIGHT_SENSOR==0 && LEFT_SENSOR==1) {
    right(); //Move Right
  }
 
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==0) {
    left(); //Move Left
  }
 
  else if(RIGHT_SENSOR==1 && LEFT_SENSOR==1) {
    Stop(); //STOP
  }

  else if(distance > 20){
    Stop();
  }

  else if(distance < 10){
    backward();
  } 
  delay(50);
}

void forward()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
       
      analogWrite(enA, M1_Speed);
      analogWrite(enB, M2_Speed);
}
  
void backward()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
       
      analogWrite(enA, M1_Speed);
      analogWrite(enB, M2_Speed);
}
  
void right()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
       
      analogWrite(enA, LeftRotationSpeed);
      analogWrite(enB, 250);
}
  
void left()
{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
       
      analogWrite(enA, 250);
      analogWrite(enB, RightRotationSpeed);
}
  
void Stop()
{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
}
