// motor
#define LeftMotor 7
#define RightMotor 2
// wheels
#define IN1 6
#define IN2 5
#define IN3 4
#define IN4 3
int carSpeed =  140;
#define batteryLevel 1550

// intervals for movement
unsigned long staggeredMovement = 0;
unsigned long stopInterval = 200;
unsigned long resetStaggeredMovement= 400;

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
  analogWrite(LeftMotor, carSpeed - motorAdjustment);
  analogWrite(RightMotor, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void goBack(){
  analogWrite(LeftMotor, carSpeed - motorAdjustment);
  analogWrite(RightMotor, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft(){
  analogWrite(LeftMotor, carSpeed - motorAdjustment);
  analogWrite(RightMotor, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight(){
  analogWrite(LeftMotor, carSpeed - motorAdjustment);
  analogWrite(RightMotor, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right45(){
  turnRight();
  delay(batteryLevel / 4);
}

void right70(){
  turnRight();
  delay(((3 * batteryLevel) / 8));
}

void right90(){
  turnRight();
  delay(batteryLevel / 2);
}

void left45(){
  turnLeft();
  delay(batteryLevel / 4);
}

void left70(){
  turnLeft();
  delay((3 * batteryLevel) / 8);

}

void left90(){
  turnLeft();
  delay(batteryLevel / 2);
}

void turn180(){
  turnRight();
  delay(batteryLevel);
}

void stopMovement(){
   digitalWrite(LeftMotor, LOW);
   digitalWrite(RightMotor, LOW);
} 