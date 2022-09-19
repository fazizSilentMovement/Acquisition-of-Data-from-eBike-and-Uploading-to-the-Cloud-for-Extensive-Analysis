#define CS 4
#define DATAPIN 3
#define CLOCK 2
boolean adcvalue[12];
int decimalvalue;

void setup()
{
  Serial.begin(9600);
  pinMode(CS, OUTPUT);
  pinMode(DATAPIN, INPUT);
  pinMode(CLOCK, OUTPUT);
  digitalWrite(CS, HIGH);
  digitalWrite(CLOCK, LOW);
}

void loop(){
  decimalvalue = 0;
  digitalWrite(CS, LOW);
  clockchange ();
  clockchange ();
  for (int i = 11; i >= 0; i--)
  {
    clockchange ();
    adcvalue[i] = digitalRead(DATAPIN);
    decimalvalue+=digitalRead(DATAPIN)<<i;
  }
  digitalWrite(CS, HIGH);
  for (int i = 11; i >= 0; i--) {
    Serial.print(adcvalue[i]);
  }
  Serial. print(" ");
  Serial.print(decimalvalue);
  Serial.println();
  delay(100);  
}

void clockchange (void)
{
  digitalWrite(CLOCK, HIGH);
  digitalWrite(CLOCK, LOW);
}
