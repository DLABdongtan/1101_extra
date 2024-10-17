#define Lmotor_A1A    6
#define Lmotor_A1B    5
#define Rmotor_B1A    11
#define Rmotor_B1B    10

byte car_speed = 130;

void setup() {
  Serial.begin(9600);
  pinMode(Lmotor_A1A, OUTPUT);
  pinMode(Lmotor_A1B, OUTPUT);
  pinMode(Rmotor_B1A, OUTPUT);
  pinMode(Rmotor_B1B, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    char data = Serial.read();
    if(data == '1') forward();
    else if(data == '2')  backward();
    else if(data == '3')  left();
    else if(data == '4')  right();
    else  stop_car();
  }
}


void forward() {
  analogWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, car_speed);
  analogWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, car_speed);
}

void backward() {
  analogWrite(Lmotor_A1A, car_speed);
  analogWrite(Lmotor_A1B, LOW);
  analogWrite(Rmotor_B1A, car_speed);
  analogWrite(Rmotor_B1B, LOW);
}

void left() {
  analogWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, LOW);
  analogWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, car_speed);
}

void right() {
  analogWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, car_speed);
  analogWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, LOW);
}

void stop_car() {
  analogWrite(Lmotor_A1A, LOW);
  analogWrite(Lmotor_A1B, LOW);
  analogWrite(Rmotor_B1A, LOW);
  analogWrite(Rmotor_B1B, LOW);
}

