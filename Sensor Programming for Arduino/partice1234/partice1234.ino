#include <SPI.h>
#include <SD.h>
int count = 0; 
File file;

void setup()

{
  Serial.begin(9600);
  SD.begin(10);
  
  pinMode (8, OUTPUT);
  noInterrupts();           // disable all interrupts

  TCCR1A = 0;

  TCCR1B = 0;

  TCNT1  = 0;


  OCR1A = 1;            // compare match register 16MHz/256/2Hz

  TCCR1B |= (1 << WGM12);   // CTC mode

  TCCR1B |= (1 << CS10);    // 256 prescaler 

  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  if (count < 255){
  interrupts();  }           // enable all interrupts
//  Serial.println("Analog value     Voltage Value    Frequency        current value    ");
 file = SD.open("Ajwad.txt", FILE_WRITE);

}


ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine

{
   
   digitalWrite(8, !digitalRead(8));
   if ( count < 255){
    file.println(count++);
    Serial.println(count);}
   else{
    file.close(); }
  //int number = analogRead(A0); // generate value from analog
  //  file.println(count++); // write number to file
   // if (count == 1000){
     // file.close(); }// close file
   // Serial.print("FARHAN JAN : "); // debug output: show written number in serial monitor
   
   
}


void loop()

{

  // your program here…

}
