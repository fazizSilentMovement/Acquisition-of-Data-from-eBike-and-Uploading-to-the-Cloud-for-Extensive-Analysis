#include <SPI.h>
#include <SD.h>
#define ANALOG_IN_PIN A0
#include <SoftwareSerial.h> 
#include <TinyGPS.h>
File file;
int countC = 1;
float lat = 0,lon = 0; // create variable for latitude and longitude object  

SoftwareSerial gpsSerial(3,4);//rx,tx 
 
TinyGPS gps; // create gps object
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
//float current=0.0;
 float average = 0;
//Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
//+442000
float R2 = 7500.0; 
// Float for Reference Voltage
float ref_voltage = 5.0;
// Integer for ADC value
int adc_value = 0;

//float Lat = 100;
//float Long = 200;
//short int Ia = 300;
//short int Ib = 400;
//short int Ic = 500;
//short int Vdc = 600;
//short int Idc = 700;
void setup()

{
  Serial.begin(9600);
  gpsSerial.begin(9600);
  SD.begin(10);
  pinMode(8, OUTPUT);


  noInterrupts();           // disable all interrupts

  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1  = 0;


  OCR1A = 1;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS10);    // no prescaler 

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  file = SD.open("IV34343434.txt", FILE_WRITE);
  interrupts();             // enable all interrupts
  
}


ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine

{
  digitalWrite(8, !digitalRead(8));
  
  if (countC <= 1000){
  countC++;
  // Read the Analog Input
   adc_value = analogRead(A0);
   
   // Determine voltage at ADC input
   adc_voltage  = (adc_value * ref_voltage) / 1024.0; 
   
   // Calculate voltage at divider input
   in_voltage = adc_voltage / (R2/(R1+R2)) ; 

 //  average = average + (.0264 * analogRead(A1) -13.51) / 1000;

   // for GPS
  // while(gpsSerial.available()){ // check for gps data 
  //if(gps.encode(gpsSerial.read()))// encode gps data 
 // {  
 // gps.f_get_position(&lat,&lon);
 // } 
//} 
//Serial.println("Input Voltage:");
//Serial.print(in_voltage,2);
file.print("Input Voltage = ");
file.print(in_voltage);
file.println();
file.println("DC Current = ");
file.print(average);

file.print("Input Voltage = ");
file.print(in_voltage);
file.println();
file.println("DC Current = ");
file.print(average);

file.print("Input Voltage = ");
file.print(in_voltage);
file.println();
file.println("DC Current = ");
file.print(average);

file.print("Input Voltage = ");
file.print(in_voltage);
file.println();
file.println("DC Current = ");
file.print(average);

file.print("Input Voltage = ");
file.print(in_voltage);
file.println();
file.println("DC Current = ");
file.print(average);
//file.println("latitude :"); 
//file.print(lat);
//file.print(";longitude: ");
//file.print(lon);
   
  //file.print(Lat);
  //file.print(Long);
  //file.print(Ia);
  //file.print(Ib);
  //file.print(Ic);
  //file.print(Vdc);
  //file.print(Idc);
  //file.println();
  }
  else{
  file.close();
  }
    

}


void loop()

{

  // your program here…

}
