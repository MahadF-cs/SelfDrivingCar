// motor
#define ENA 5
#define ENB 6
// wheels
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 150

void slowForward(unsigned long time){
  if ((time - staggeredMovement) <= stopInterval){
    goForward();
  }
  if ((time - staggeredMovement) > stopInterval){
    stopMovement();
    if ((time -  staggeredMovement) >= resetStaggeredMovement){
      staggeredMovement = time;
    }
  }
}


void goForward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void goBack(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
} 


void stopMovement(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
} 