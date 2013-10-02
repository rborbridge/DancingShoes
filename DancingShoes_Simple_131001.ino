//DancingShoes_Simple
/*
when force is applied to the sensor, brighten the LED's accordingly (presumably as you tap to the beat)
*/

int forcesensorPin = A2; //force sensor is connected to this
int peakLED = 10; //LED showing listening is 'on'
int blinkingLED = 9; //LED blinking output
int forceReading; //what is the output from the force sensor
int pulseBrightness;

void setup ( ) {
  Serial.begin(9600);
  pinMode(peakLED, OUTPUT);
}

void loop( ) {
  Serial.println(forceReading);
  forceReading = analogRead(forcesensorPin);  
  pulseBrightness = map(forceReading, 0, 1023, 0, 255);
  analogWrite(blinkingLED, pulseBrightness);
  
  delay(20);

  if (forceReading > 800) {
  digitalWrite(peakLED, HIGH);
  delay(200);
  } else {
  digitalWrite(peakLED, LOW);
 //digitalWrite(peakLED, HIGH);
 
  }

}
