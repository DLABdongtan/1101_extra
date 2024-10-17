#define Lmotor_A1A    6
#define Lmotor_A1B    5
#define Rmotor_B1A    11
#define Rmotor_B1B    10

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
  digitalWrite(Lmotor_A1A, LOW);
  digitalWrite(Lmotor_A1B, HIGH);
  digitalWrite(Rmotor_B1A, LOW);
  digitalWrite(Rmotor_B1B, HIGH);
}

void backward() {
  digitalWrite(Lmotor_A1A, HIGH);
  digitalWrite(Lmotor_A1B, LOW);
  digitalWrite(Rmotor_B1A, HIGH);
  digitalWrite(Rmotor_B1B, LOW);
}

void left() {
  digitalWrite(Lmotor_A1A, HIGH);
  digitalWrite(Lmotor_A1B, LOW);
  digitalWrite(Rmotor_B1A, LOW);
  digitalWrite(Rmotor_B1B, HIGH);
}

void right() {
  digitalWrite(Lmotor_A1A, LOW);
  digitalWrite(Lmotor_A1B, HIGH);
  digitalWrite(Rmotor_B1A, HIGH);
  digitalWrite(Rmotor_B1B, LOW);
}

void stop_car() {
  digitalWrite(Lmotor_A1A, LOW);
  digitalWrite(Lmotor_A1B, LOW);
  digitalWrite(Rmotor_B1A, LOW);
  digitalWrite(Rmotor_B1B, LOW);
}