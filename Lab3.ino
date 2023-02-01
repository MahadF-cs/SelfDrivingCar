#define irEdgeL A4
#define irEdgeR A5


// US sensors 
int EchoL = 12;  
int TrigL = 13;
int EchoM = A3;
int TrigM = A2; 
int EchoR = A4;
int TrigR = A5;

// intervals for movement
unsigned long staggeredMovement = 0;
unsigned long stopInterval = 300;
unsigned long resetStaggeredMovement= 400;

// intervals for different actions
unsigned long edgeDetectionTime = 0, objectDetectionTime = 0, lineTrackingTime = 0; //previous time
unsigned long edgeDetectionInterval = 200, objectDetectionInterval = 200, lineTrackingInterval = 200;   // time for intervals

void setup() {
  Serial.begin(9600);
  pinMode(EchoL, INPUT);    
  pinMode(TrigL, OUTPUT);
  pinMode(EchoM, INPUT);    
  pinMode(TrigM, OUTPUT);
  pinMode(EchoR, INPUT);    
  pinMode(TrigR, OUTPUT);
  // pinMode(irEdgeR,INPUT);
  // pinMode(irEdgeL,INPUT);
}


/// @brief new additiong ends 
void loop() {
  unsigned long currentTime = millis();   //current time in miliseconds

  // Line Tracking
  if (currentTime - lineTrackingTime >= lineTrackingInterval){
    followLine(currentTime);
    lineTrackingTime = currentTime;
  }

  // // Edge detection loop
  // if (currentTime - edgeDetectionTime >= edgeDetectionInterval){
  //   avoidEdge(currentTime);
  //   edgeDetectionTime  = currentTime;
  // }
  
  // // Object avoidance loop
  // if (currentTime - objectDetectionTime >= objectDetectionInterval){
  //   avoidObject(currentTime);
  //   objectDetectionTime = currentTime;
  // }

  // // Line Tracking
  // if (currentTime - lineTrackingTime >= lineTrackingInterval){
  //   followLine(currentTime);
  //   lineTrackingTime = currentTime;
  // }
  // followLine(currentTime);
  // // avoidEdge(currentTime);
  // // avoidObject(currentTime);
  // slowForward(currentTime);
  

}