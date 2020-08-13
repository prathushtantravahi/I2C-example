#include <Wire.h>


int x = 0;
char a[7] = "ON200ms";
char b[7] = "ON400ms";
char c[6] = "OTHERS";
void setup() {
  // Define the LED pin as Output
  pinMode (LED_BUILTIN, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void requestEvent() {  
  if( x == 0)
  {
   Wire.write(a); // respond with message of 1 bytes as expected by master  
  }
  if( x == 3)
  {
    Wire.write (b);  
  }
  else 
  {
    Wire.write(c);
  }
}
void loop() {
  //If value received is 0 blink LED for 200 ms
  if (x == 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    Wire.write("Off 200ms");
    delay(200);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 3) {
    digitalWrite(LED_BUILTIN, HIGH);
    Wire.write("ON 400ms");
    delay(400);
    Wire.write("off 400ms");
    digitalWrite(LED_BUILTIN, LOW);
    delay(400);
  }
}
