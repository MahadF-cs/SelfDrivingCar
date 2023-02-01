//Line Tracking IO define
#define LT_L !digitalRead(2)
#define LT_M !digitalRead(4)
#define LT_R !digitalRead(10)

void followLine(unsigned long time){
  char buffer[40];
  sprintf(buffer, "Left: %d, Middle: %d, Right: %d", LT_L, LT_M, LT_R);
  Serial.println(buffer);

  if (LT_M && LT_R && LT_L){
    goBack();
    delay(100);
    turnRight();
    delay(300);
  }
  else if(LT_R || (LT_R && LT_M)) { 
    turnRight();
    while(!LT_M);
    
  }   
  else if(LT_L || (LT_L && LT_M)) {
    turnLeft();
    while(!LT_M);
  }
}