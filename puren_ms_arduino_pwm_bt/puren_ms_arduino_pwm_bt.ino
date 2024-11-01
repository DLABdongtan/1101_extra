#include <SoftwareSerial.h>

#define Lmotor_A1A  6
#define Lmotor_A1B  5
#define Rmotor_B1A  11
#define Rmotor_B1B  10
#define BT_TX   7
#define BT_RX   8

SoftwareSerial myBT(BT_TX, BT_RX);
byte car_speed = 255;

void setup() {
  // put your setup code here, to run once:
  myBT.begin(9600);
  Serial.begin(9600);
  pinMode(Lmotor_A1A, OUTPUT);
  pinMode(Lmotor_A1B, OUTPUT);
  pinMode(Rmotor_B1A, OUTPUT);
  pinMode(Rmotor_B1B, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(myBT.available() > 1) {
    char buf[2];
    myBT.readBytes(buf, 2);
    if(buf[0] == 'c') {
      if(buf[1] == 1) forward();
      else if(buf[1] == 2)  backward();
      else if(buf[1] == 3)  left();
      else if(buf[1] == 4)  right();
      else  stop_car();
    }
    else if(buf[0] == 's'){
      car_speed = buf[1];
    }
    delay(5);
  }
}

void forward() {
  digitalWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, car_speed);
  digitalWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, car_speed);
}

void backward() {
  analogWrite(Lmotor_A1A, car_speed);
  digitalWrite(Lmotor_A1B, LOW);
  analogWrite(Rmotor_B1A, car_speed);
  digitalWrite(Rmotor_B1B, LOW);
}

void left() {
  analogWrite(Lmotor_A1A, LOW);
  digitalWrite(Lmotor_A1B, LOW);
  digitalWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, car_speed);
}

void right() {
  digitalWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, car_speed);
  analogWrite(Rmotor_B1A, LOW);
  digitalWrite(Rmotor_B1B, LOW);
}

void stop_car() {
  digitalWrite(Lmotor_A1A, LOW);
  digitalWrite(Lmotor_A1B, LOW);
  digitalWrite(Rmotor_B1A, LOW);
  digitalWrite(Rmotor_B1B, LOW);
}