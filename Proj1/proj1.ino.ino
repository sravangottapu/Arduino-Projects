
// These constants won't change.  They're used to give names to the pins used:
const int analogInPin1 = A0;  // Analog input pin 1 - s1
const int analogInPin2 = A7; //  Analog input pin 2 - s2
const int analogOutPin1 = 9; // Analog output pin used to display s2+s1
const int analogOutPin2 = 5; // Analog output pin used to display s1-s2 

int sensor1Value = 0; // s1       
int add = 0;          // s2+s1
int sub = 0;          // s1-s2
int sensor2Value=0;   // s2
void setup() {
  //We can Use Serial Communication for Debugging.
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensor1Value = analogRead(analogInPin1);
  sensor2Value = analogRead(analogInPin2);
  // map it to the range of the analog out:
  add= map(sensor1Value+sensor2Value, 0, 1023, 0, 255);
  sub= map(sensor1Value-sensor2Value, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin1, add);
  analogWrite(analogOutPin2, sub);
  
  // print the results to the serial monitor:
  Serial.print("\nInput 1 = ");
  Serial.print(sensor1Value);
  Serial.print("\t Input 2 = ");
  Serial.print(sensor2Value);
  Serial.print("\nOutput 1 = ");
  Serial.print(add);
  Serial.print("\t Output 2 = ");
  Serial.print(sub);
  Serial.println();
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}
