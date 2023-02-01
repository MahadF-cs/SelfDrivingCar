int topDistanceSPp, sideDistanceSPp, backDistanceSPp;

bool foundCar = false;
bool isBeside = false;
bool isParallel = false;

int counter = 0;


void setupParallelPark(unsigned long int time){
  topDistanceSPp = scanTop(0);
  sideDistanceSPp = scanRight();
  backDistanceSPp = scanBack(180);

  if ((backDistanceSPp < 25) || foundCar){

    foundCar = true;
    if (!isBeside){
      goForward();
      delay(280);
      // turnRight();
      // delay(batteryLevel / 1.4);
      right90();
      isBeside = true;
    }
    if ((sideDistanceSPp < 20 && backDistanceSPp < 20) || isParallel){
     isParallel = true;
      if ((sideDistanceSPp < 20 && backDistanceSPp < 20)){
      goForward();
      delay(200);
      stopMovement();
      isSetUp = true;
      
    }
    else{
      slowForward(time);
    }
      
    }
    else{
      slowForward(time);
    }
  }
  else{
    if (counter < 1){
      left45();
      goForward();
      delay(500);
      right45();
      counter += 1;

    }
    goBack();
  }
}


