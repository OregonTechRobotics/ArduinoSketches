#include <Servo.h>

Servo  ServoX;
Servo  ServoY;
Servo  ServoZ;


int READ_VALUE;
char READ_ADDRESS;
void setup() {
  // initialize serial:
  Serial.begin(115200);

  ServoX.attach(9);
  ServoY.attach(10);
  ServoZ.attach(11);
  ServoX.writeMicroseconds(2000);
  ServoY.writeMicroseconds(2000);
  ServoZ.writeMicroseconds(2000);
}

void loop() {
  // if there's any serial available, read it:
  if(Serial.available() >= 2) 
  {
    //Serial.print("Got ");
    //Serial.println(BYTES_READ);
    READ_ADDRESS = Serial.read();
    READ_VALUE   = (int)Serial.read();
    //Serial.print(READ_ADDRESS);
    //Serial.println(READ_VALUE);
       switch(READ_ADDRESS)
       {
         case 'a':ServoX.write(READ_VALUE);break;
         case 'b':ServoY.write(READ_VALUE);break;
         case 'c':ServoZ.write(READ_VALUE);break;
         case 13:break;
         default: Serial.println("Recieved incorrect address");break;
       }
       delay(12);
  }

}








