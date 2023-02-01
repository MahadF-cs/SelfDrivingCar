int middleDistancePp, topDistancePp, leftDistancePp, rightDistancePp, backDistancePp;

bool parkingFound = false;
bool inSpot = false;
bool object = false;

void  parallelPark (unsigned long int time){

  topDistancePp = scanTop(0);
  rightDistancePp = scanRight();

  if(!inSpot){
    backDistancePp = scanBack(180);
  }
  else{
    backDistancePp = scanBack(90);
   
  }
  if (topDistancePp < 25 && rightDistancePp < 25){
    object = true;
  }
  if ((rightDistancePp < 30 && backDistancePp < 30 && topDistancePp < 30) && object || parkingFound){
    parkingFound = true;
    if ((topDistancePp < 30 && rightDistancePp < 30 && backDistancePp > 30) || inSpot){
      if(!inSpot){
        left45();
        inSpot = true;
      }
      else if(backDistancePp < 15){
        right45();
        stopMovement();
        delay(1000000);
      }
      else{
        goBack();
      }
    }
    else{
      slowForward(time);
    }
  }
  else{
    slowForward(time);
  }
}
