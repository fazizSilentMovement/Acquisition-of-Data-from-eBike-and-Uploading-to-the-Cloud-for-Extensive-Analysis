#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
//#define RXpin 2
//#define TXpin 3

TinyGPSPlus gps;
SoftwareSerial ss(0,1);
String GPS_nmea;

void setup() {
  Serial.begin(9600);
  ss.begin(9600);
  Serial.println("begin script");
}


void loop()
{

    while (ss.available())
    {
      gps.encode(ss.read());
      if (gps.location.isUpdated())
      {
        Serial.print("Latitude:");
        Serial.println((gps.location.lat()));
        Serial.print("Longitude:");
        Serial.println((gps.location.lng()));
      }

     // else
     // {
        //GPS_nmea = ss.readStringUntil(13);
       // if(GPS_nmea.startsWith("$GPRMC"))
      //  {
        //  Serial.println(GPS_nmea);
      //  }
    //  }

    }
}
