// Line Tracking Modules
#define LT_L !digitalRead(9)
#define LT_M !digitalRead(10)
#define LT_R !digitalRead(8)

int motorAdjustment =  20;

// Servo Motors
#include <Servo.h>
Servo frontServo; 
Servo backServo;

int TrigB = 53;
int EchoB = 52;
int TrigL = 51;
int EchoL = 50;
int TrigM = 48;
int EchoM = 49;
int TrigR = 46; 
int EchoR = 47; 
int TrigT = 44;
int EchoT = 45;

int foundLight = 0;

bool rightLane = true;

bool isSetUp  = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // set up servos
  frontServo.attach(11);
  backServo.attach(12);
  // set up all US sensors
  pinMode(EchoL, INPUT);    
  pinMode(TrigL, OUTPUT);
  pinMode(EchoM, INPUT);    
  pinMode(TrigM, OUTPUT);
  pinMode(EchoR, INPUT);    
  pinMode(TrigR, OUTPUT);
  pinMode(EchoB, INPUT);
  pinMode(TrigB, OUTPUT);
  pinMode(EchoT, INPUT);
  pinMode(TrigT, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis(); //current time in miliseconds


  if (!foundLight){
    foundLight = detectLight();
  }
  if (!foundLight){
    cruiseControl(currentTime);
  }
  else{

      parallelPark(currentTime);
    
  }

}