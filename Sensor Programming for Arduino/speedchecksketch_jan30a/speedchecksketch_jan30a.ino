#include <avr/io.h>
#include <avr/interrupt.h>
 

 int counts = 0;
 int pin = 13;
void setup()
{
    
     pinMode(pin, OUTPUT);
    // initialize Timer1
    cli();             // disable global interrupts
    TCCR1A = 0;        // set entire TCCR1A register to 0
    TCCR1B = 0;
 
    // enable Timer1 overflow interrupt:
    TIMSK1 = (1 << TOIE1);
    // Set CS10 bit so timer runs at clock speed:
    TCCR1B |= (1 << CS10);
    // enable global interrupts:
    sei();
    
}
void loop()
{
}
ISR(TIMER1_OVF_vect)
{
    counts++;
    if (counts > 1000)
   {
     digitalWrite(pin, HIGH);
     Serial.println(counts);
   } 
   if (counts > 1200)
   {
   digitalWrite(pin, LOW);
   counts = 0;
   }
   
   
 
}
