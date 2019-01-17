#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;

// The serial connection to the GPS device RX=4, TX=3
SoftwareSerial ss(4, 3);

void setup(){
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);

      Serial.print("Date DDMMYY = ");
      Serial.println(gps.date.value()); 

      Serial.print("Year = "); 
      Serial.println(gps.date.year()); 
      
      Serial.print("Month = "); 
      Serial.println(gps.date.month()); 
      Serial.print("Day = "); 
      Serial.println(gps.date.day()); 

      Serial.print("Time in HHMMSSCC = "); 
      Serial.println(gps.time.value()); 

      Serial.print("Hour = "); 
      Serial.println(gps.time.hour()); 

      Serial.print("Minute = "); 
      Serial.println(gps.time.minute()); 

      Serial.print("Second = "); 
      Serial.println(gps.time.second()); 
    }
  }
}
