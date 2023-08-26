#include <Wire.h>

#define I2C_SDA_2            21
#define I2C_SCL_2            22

#define I2C_SDA_1            18
#define I2C_SCL_1            19

TwoWire I2CBME_a = TwoWire(1);
TwoWire I2CBME_b = TwoWire(1);
void setup()
{
  I2CBME_a.begin(I2C_SDA_2, I2C_SCL_2, 400000);
  I2CBME_b.begin(I2C_SDA_2, I2C_SCL_2, 400000);
 
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}
 
 
void loop()
{
  byte error, address;
  int nDevices;
 
  Serial.println("Scanning_a...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    I2CBME_a.beginTransmission(address);
    error = I2CBME_a.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(1000);           // wait 5 seconds for next scan

  byte error, address;
  int nDevices;
 
  Serial.println("Scanning_b...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    I2CBME_b.beginTransmission(address);
    error = I2CBME_b.endTransmission();
 
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");
 
  delay(1000);           // wait 5 seconds for next scan
}
