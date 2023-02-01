void followLine(){
  // char buffer[40];
  // sprintf(buffer, "Left: %d, Middle: %d, Right: %d", LT_L, LT_M, LT_R);
  // Serial.println(buffer);

  if (LT_M && LT_R && LT_L){
    if (rightLane){
      goBack();
      delay(150);
      turnLeft();
      delay(300);
    }
    else{
      goBack();
      delay(150);
      turnRight();
      delay(300);
    }
  }
  else if(LT_R || (LT_R && LT_M)) { 
    // Serial.println("I am here");
    turnRight();
    while(!LT_M);

  }   
  else if(LT_L || (LT_L && LT_M)) {
    turnLeft();
    while(!LT_M);
  }
}