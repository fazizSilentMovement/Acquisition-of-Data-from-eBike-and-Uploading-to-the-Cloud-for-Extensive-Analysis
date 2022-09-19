#include <SPI.h>
#include <SD.h>
int c =0;
File myfile;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
myfile = SD.open("simple test.txt", FILE_WRITE);
   if ( c < 255){
    myfile.write(c++);
    Serial.println(c);}
   else{
    myfile.close();}
}
