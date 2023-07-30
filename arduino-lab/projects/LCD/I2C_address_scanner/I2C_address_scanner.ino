#include <Wire.h> // For communication purposes of I2C

void setup()
{
  Wire.begin();

  Serial.begin(9600); // Initialize serial and wait for port to open
  delay(1500); // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  Serial.println("Setting up done.");
  

}

void loop() 
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      Serial.println("  !");
      nDevices++;
   
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) Serial.println("No. I2C found\n");
  else Serial.println("done\n");

  delay(5000);
}
