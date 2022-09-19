const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
long starttime,interval;
void setup()
{
   ADCSRA &= ~PS_128;
   ADCSRA |= PS_16;
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop()
{
  starttime = micros();
  for (int i = 0; i < 100; i++) {
    analogRead(A0);
  }
  interval = micros() - starttime;

  Serial.print("Time per sample: ");
  Serial.print((float)interval / 100);
  Serial.println(" µs");
  Serial.print("Sample Rate: ");
  Serial.print((float)100 * 1000000 / interval);
  Serial.println(" S/s");
  Serial.println();
  delay(2000);
}
