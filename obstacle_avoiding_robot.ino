#include <Servo.h>
Servo s = Servo();

#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(7,4);  //Trig , Echo

int ENA = 11;
int IN1 = 10;
int IN2 = 9;

int ENB = 6;
int IN4 = 5;
int IN3 = 3;

void setup() {
  // put your setup code here, to run once:
  s.attach(2);

  //Motor A
  pinMode(ENA,OUTPUT);   
  pinMode(IN1,OUTPUT);   
  pinMode(IN2,OUTPUT);
  analogWrite(ENA,250);

  //Motor B
  pinMode(ENB,OUTPUT);    
  pinMode(IN4,OUTPUT);    
  pinMode(IN3,OUTPUT);    
  analogWrite(ENB,250);

  //Red Light
  pinMode(8,OUTPUT);

  //Yellow Light
  pinMode(12,OUTPUT);

  //Blue Light
  pinMode(13,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = Serial.read();
  //Serial.println(x);

  digitalWrite(13,HIGH);
  
  //Forword
  if (x == '1') {
    s.write(90);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(12,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
    }

    if (d <= 20) {
      digitalWrite(8,HIGH);
      digitalWrite(12,LOW);
    }
  }

  //Reverse
  if (x == '2') {
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(12,LOW);
    delay(500);
    digitalWrite(8,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }

  //Stop
  if (x == '3') {
    digitalWrite(8,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }

  //Turn Right
  if(x == '4') {
    s.write(45);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(8,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      delay(250);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    }
    s.write(90);
  }

  //Turn Left
  if(x == '5') {
    s.write(135);
    delay(300);
    int d = u.read();
    if (d > 20) {
      digitalWrite(12,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      delay(250);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    }
    s.write(90);
  }
}