int lightSensorL = A7;

// lowest and highest sensor readings:
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum


bool detectLight() {
  // read the sensor on analog A0:
    int sensorReading = analogRead(lightSensorL);
    // Serial.println(sensorReading);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
    int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close Fire **");
    return true;
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("** Distant Fire **");
    return true; 
    break;
  case 2:    // No fire detected.
    Serial.println("No Fire");
    return false;
    break;
  }
  delay(1);  // delay between reads
} 