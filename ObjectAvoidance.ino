int middleStop = 20;
int sideStop = 15;

unsigned long previousTime = 0;
unsigned long avoidInteval = 750;
unsigned long resetTime = 0;

// Debug Sensors
// char buffer[40];
// sprintf(buffer, "Left: %d, Middle: %d, Right: %d", leftDistance, middleDistance, rightDistance);
// Serial.println(buffer);

//Ultrasonic distance measurement Sub function
int findDistance(int SonicSensorTrig, int SonicSensorEcho) {
  digitalWrite(SonicSensorTrig, LOW);   
  delayMicroseconds(2);
  digitalWrite(SonicSensorTrig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(SonicSensorTrig, LOW);   
  float Fdistance = pulseIn(SonicSensorEcho, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
}

void avoidObject(unsigned long time){
  int leftDistance = findDistance(TrigL, EchoL);
  int middleDistance = findDistance(TrigM, EchoM);
  int rightDistance = findDistance(TrigR, EchoR);

  unsigned long avoidTime = millis();

  // char buffer[40];
  // sprintf(buffer, "Left: %d, Middle: %d, Right: %d", leftDistance, middleDistance, rightDistance);
  // Serial.println(buffer);

  if (middleDistance <= middleStop && leftDistance <= sideStop && rightDistance <= sideStop){
    stopMovement();
    goBack();
   delay(500);
  }
  else if (middleDistance <= middleStop && leftDistance <= sideStop){
    stopMovement();
    turnRight();
    delay(500);
  }
  else if (middleDistance <= middleStop && rightDistance <= sideStop){
    stopMovement();
    turnLeft();
    delay(500);
  }
  else if (middleDistance <= middleStop){
    stopMovement();    
    turnRight();
    delay(500);
  }
  else if (leftDistance <= sideStop){
    stopMovement();
    turnRight();
      delay(500);
  }
  else if (rightDistance <= sideStop){
    stopMovement();
    turnLeft();
     delay(500);
  }
}


// void avoidIntervalHasPassed(unsigned long time, bool turnSide){
//   if ((time - previousTime) <= avoidInterval){
//     if (turnSide){
//       turnRight();
//     }
//     else{
//       turnLeft();
//     }
//   }
//   if ((time - staggeredMovement) > stopInterval){
//     stopMovement();
//     if ((time - previousTime) >= resetTime){
//       previousTime = time;
//     }
//   }
// }
// bool intervalPassed(timex, prev){
//   if (timex - prev >= avoidInterval){
//     prev = timex;
//     Serial.println("AVOIDING");
//     return true;
//   }
//   Serial.println("NOT");
//   return false;
// }