#define ANALOG_IN_PIN A0
#include <SoftwareSerial.h> 
#include <TinyGPS.h> 
float lat = 0,lon = 0; // create variable for latitude and longitude object  
SoftwareSerial gpsSerial(3,4);//rx,tx 
 
TinyGPS gps; // create gps object
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
float current=0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
//+442000
float R2 = 7500.0; 
// Float for Reference Voltage
float ref_voltage = 5.0;
// Integer for ADC value
int adc_value = 0;


void setup()
{
   // Setup Serial Monitor
Serial.begin(9600);
   //Serial.println("DC Voltage Test");
    //ss.begin(GPSBaud);
    //Serial.println("The GPS Received Signal:"); 
gpsSerial.begin(9600); // connect gps sensor
}
 
void loop()
{
   // Read the Analog Input
   adc_value = analogRead(ANALOG_IN_PIN);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 
   
   // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage = ");
  Serial.println(in_voltage, 2);

  // Short delay
  delay(500);

// for measuring current
    float average = 0;
  for(int i = 0; i < 1000; i++) 
  {
    average = average + (.0264 * analogRead(A1) -13.51) / 1000;
    
  }
   

  // for GPS
   while(gpsSerial.available()){ // check for gps data 
  if(gps.encode(gpsSerial.read()))// encode gps data 
  {  
  gps.f_get_position(&lat,&lon); // get latitude and longitude 
  // display position 
  
  //Serial.print("Position: "); 
  //Serial.print("Latitude:"); 
  //Serial.print(lat,6); 
  //Serial.print(";"); 
  //Serial.print("Longitude:"); 
  //Serial.println(lon,6);  
  
  //Serial.print(lat); 
  //Serial.print(" "); 
 } 
} 
String latitude = String(lat,6); 
  String longitude = String(lon,6); 
Serial.println(latitude+";"+longitude); 
delay(100); 
Serial.print("DC Current = ");
Serial.println(average);
delay(100);
Serial.print("Input Voltage = ");
Serial.println(in_voltage, 2);
Serial.println();
}
