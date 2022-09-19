int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("program for counter");
  while(count<=1000){
  Serial.println(count);
   count +=1;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
}
