#include <TinyGPS++.h>
#include <SoftwareSerial.h>

int rxPin = 10, txPin = 11;
TinyGPSPlus gps;
SoftwareSerial serial_connection(rxPin, txPin);

//Basic Serial setup
void setup() {
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Status :");
}

//Checking for serial connection 
void loop() {
  while(serial_connection.available()){
    gps.encode(serial_connection.read());
  }

//Print out new value in serial for updated landitude and latitude 
  if(gps.location.isUpdated()){
    Serial.println("Total number of satalite found :");
    Serial.print(gps.satellites.value());

    Serial.println("Latitude :");
    Serial.print(gps.location.lat());
    
    Serial.println("Longitude :");
    Serial.print(gps.location.lng());

    Serial.println("GPS Speed :");
    Serial.print(gps.speed.kmph());

    Serial.println("Altitude Feed");
    Serial.println(gps.altitude.feet());
    Serial.println();
  }
}