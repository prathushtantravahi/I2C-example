#include <Wire.h>

int x = 0;
char c;
 
void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  Serial.begin(9600);
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  Wire.requestFrom(9, 7); // request 1 bytes from slave device #2
   while (Wire.available()) { // slave may send less than requested {
     c = Wire.read(); // receive a byte as character
      Serial.print(c); // print the character     
}
  Serial.println();
  x++; // Increment x
  if (x > 5) x = 0; // `reset x once it gets 6
  delay(500);
}
