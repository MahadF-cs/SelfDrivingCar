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

void debugScanners(){

  int leftDistance = findDistance(TrigL, EchoL);
  int middleDistance = findDistance(TrigM, EchoM);
  int rightDistance = findDistance(TrigR, EchoR);
  int topDistance = findDistance(TrigT, EchoT);
  int backDistance = findDistance(TrigB, EchoB);

  // Debug Sensor
  char buffer[60];
  sprintf(buffer, "Left: %d, Middle: %d, Right: %d, Top: %d , Back: %d", 
                  leftDistance, middleDistance, rightDistance, topDistance, backDistance);
  Serial.println(buffer);
}

int scanLeft(){
  return findDistance(TrigL, EchoL);
}

int scanMiddle(){
  return findDistance(TrigM, EchoM);
}

int scanRight(){
  return findDistance(TrigR, EchoR);
}

int scanTop(int angle){
  moveFrontServo(angle);
  return findDistance(TrigT, EchoT);
}



int scanBack(int angle){
  moveBackServo(angle);
  return findDistance(TrigB, EchoB);
}
