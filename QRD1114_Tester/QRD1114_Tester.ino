// Tachometer using a QRD114
// QRD1114 reads the colour of the spinning object. 
// Assume spinning object is black, with a white spot or area 
// painted on to count a rotation
 
#define sensorPin A0

boolean determineColour(void);

int revolutions;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Sensor value: ");
  int RPM;
  int RPS;
 
}
 
void loop() {
  determineColour();
  //Serial.println(analogRead(A0));
  delay(1000);
}

boolean determineColour( void ) {
  //Get value read from sensor
  int readVal = (analogRead(sensorPin));
  
  //Determine if the colour is white or black
  if( readVal > 850 ){
    Serial.println("White");
    return true;
  }
  else{
    Serial.println("Black"); 
    return false;
   
  }
}
