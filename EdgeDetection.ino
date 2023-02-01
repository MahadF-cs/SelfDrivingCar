#define irEdgeL A1
#define irEdgeR A0

int edge = 900;

int stuckCounter = 0;

void avoidEdge(unsigned long time){
  int valueR = analogRead(irEdgeR);
  int valueL = analogRead(irEdgeL);
  // char buffer[40];
  // sprintf(buffer, "Left: %d, Right: %d",valueL, valueR);
  // Serial.println(buffer);
  if (((valueR > edge) and (valueL > edge)) or stuckCounter >= 1000){
    stopMovement();
    goBack();
    delay(400);
    turnLeft();
    delay(1000);
    stuckCounter = 0;
  }
  else if (valueL > edge){
    stopMovement();
    goBack();
    delay(400);
    if (!irEdgeR){
      turnRight();
      delay(2000);
    }
    else{
      turnRight();
      delay(1000);
    }
    stuckCounter += 100; 
  }
  else if(valueR > edge){
    stopMovement();
    goBack();
    delay(400);
    if (!irEdgeL){
      turnLeft();
      delay(2000);
    }
    else{
      turnLeft();
      delay(1000);
    }
    stuckCounter +=100; 
  }
  else{
    if (stuckCounter > 0) {
        stuckCounter -= 1;
    }
  }
}