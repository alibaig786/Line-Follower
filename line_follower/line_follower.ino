#define left 6 // left sensor pin at arduino
#define center 7 // centre sensor pin at arduino
#define right 8 // right sensor pin at arduino

//motor one
#define ENA 9 //Enable A of L298 pin at ardunio
#define IN1 2 // IN1 of L298
#define IN2 3 // IN2 of L298

//motor two
#define ENB 10  // Enable B of L298
#define IN3 4 // IN3 of L298
#define IN4 5 // IN4 of L298

int Speed = 200; // Speed of robot on straight path
int Speedt = 150;// speed of this robot at turn

void setup() {
  Serial.begin(9600);
  pinMode(left, INPUT);
  pinMode(center, INPUT);
  pinMode(right, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  int leftV = digitalRead(left);
  int centerV = digitalRead(center);
  int rightV = digitalRead(right);

 // Serial.println(rightV);

  if (leftV == 0 && centerV == 1 && rightV == 0) {
    carforward();
    //Serial.println("forward");
  } else if (leftV == 0 && centerV == 0 && rightV == 0) {
    carStop();
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    carStop();
  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    carturnleft();
  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    carturnleft();
  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    carturnright();
  } else if (leftV == 1 && centerV == 1 && rightV == 0) {
    carturnright();
  }
}

void carforward() {
  analogWrite(ENA, Speedt);
  analogWrite(ENB, Speedt);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
