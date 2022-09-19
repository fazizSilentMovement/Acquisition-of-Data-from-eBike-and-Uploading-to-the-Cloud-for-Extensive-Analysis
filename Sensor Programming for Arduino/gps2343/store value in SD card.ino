#include <SPI.h>
#include <SD.h>
File file;
int countC = 1;
float Lat = 100;
float Long = 200;
short int Ia = 300;
short int Ib = 400;
short int Ic = 500;
short int Vdc = 600;
short int Idc = 700;
void setup()

{
  Serial.begin(9600);
  SD.begin(10);
  pinMode(8, OUTPUT);


  noInterrupts();           // disable all interrupts

  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1  = 0;


  OCR1A = 1;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS10);    // 62 prescaler 

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  file = SD.open("store.txt", FILE_WRITE);
  interrupts();             // enable all interrupts
  
}


ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine

{
  digitalWrite(8, !digitalRead(8));
  if (countC <= 1000){
  countC++;
  file.println(Lat);

  }
  else{
  file.close();
  }
    

}


void loop()

{

  // your program here…

}
