// Tachometer using a QRD114
// QRD1114 reads the colour of the spinning object. 
// Assume spinning object is black, with a white spot or area 
// painted on to count a rotation

//Pin reading the analog output from the QRD1114 
#define sensorPin A0
// Value between 0 and 1023 at which the QRD1114 is looking at something white. Any value lower is treated as black.
#define whiteBoundary 875
//Time between reading the QRD1114's output
#define delayTime 10

boolean determineColour(void);
void countOneRev(void);

int RPM;
int RPS;

int revolutions;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Sensor value: ");

 
}
 
void loop() {
  long startTime; // the value returned from millis when the switch is pressed
  long duration;  // variable to store the duration
  
  // Time how long the revolution took
  startTime = micros();
  countOneRev();
  duration = micros() - startTime;
  
  RPM = 60 / (duration / 1000000);

//  revolutions++;
}

boolean determineColour( void ) {
  //Get value read from sensor
  int readVal = (analogRead(sensorPin));
  
  //Determine if the colour is white or black
  if( readVal > whiteBoundary ){
    //Serial.println("White");
    return true;
  }
  else{
    //Serial.println("Black");
    return false;
  }
}

void countOneRev( void ){
   //default colour read to black
  boolean isWhite = false;
  //How to read the acual colour 
  //isWhite = determineColour()
 
  // Wait for the white spot to come around
  while( determineColour() == false ){
    delay(delayTime);
  }
  //White spot has come around, now wait for it to pass
  while( determineColour() == true ){
    delay(delayTime);
  }
}




