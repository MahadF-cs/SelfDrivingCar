int slowDistance = 30;
int stopDistanceCc = 15;

int blockedCounter = 0;

int topDistanceCc, sideDistanceCc, backDistanceCc, currObj;

void cruiseControl (unsigned long int time){

  followLine();

  currObj = scanMiddle();

  if (rightLane == true){
    topDistanceCc = scanTop(180);
    sideDistanceCc = scanLeft();
    backDistanceCc = scanBack(45);
  }
  else if (rightLane == false){
    topDistanceCc = scanTop(0);
    sideDistanceCc = scanRight();
    backDistanceCc = scanBack(135);
  }

  if (blockedCounter > 30){
    if (rightLane){
      if (topDistanceCc > 15 && sideDistanceCc > 15 && backDistanceCc > 15){
        left70();
        stopMovement();
        goForward();
        while(!LT_M);
        rightLane = false;
        blockedCounter = 0;
      }
    }
    else{
      if (topDistanceCc > 15 && sideDistanceCc > 15 && backDistanceCc > 15){
        right70();
        stopMovement();
        goForward();
        while(!LT_M);
        rightLane = true;
        blockedCounter = 0;
      }
    }
  }

  if (currObj <= stopDistanceCc){
    blockedCounter +=1;
    stopMovement();
  }
  else if (stopDistanceCc < currObj <= slowDistance){
    blockedCounter = 0;
    slowForward(time);
  }
  else{
    blockedCounter = 0;
    slowForward(time);
  }
}
