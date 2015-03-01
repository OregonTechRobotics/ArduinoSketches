#include <Servo.h>

Servo  ServoX;
Servo  ServoY;
Servo  ServoZ;

int BYTES_READ;
int PARSE_INDEX;
char DATA_BUFFER[601];
int process_count;
int READ_VALUE;
char READ_ADDRESS;
const int ADDRESS_WIDTH = sizeof(unsigned int);
void setup() {
  // initialize serial:
  Serial.begin(921600);

  BYTES_READ = 0;
  PARSE_INDEX = 0;
  ServoX.attach(9);
  ServoY.attach(10);
  ServoZ.attach(11);
  ServoX.writeMicroseconds(2000);
  ServoY.writeMicroseconds(2000);
  ServoZ.writeMicroseconds(2000);
}

void loop() {
  // if there's any serial available, read it:
  if(Serial.available() > 0) 
  {
    BYTES_READ = Serial.readBytes(DATA_BUFFER,600);
    //Serial.print("Got ");
    //Serial.println(BYTES_READ);
  }
  process_count = 0;
  while(process_count < (BYTES_READ/2))
  {
       READ_ADDRESS = DATA_BUFFER[PARSE_INDEX++];
       READ_VALUE   = DATA_BUFFER[PARSE_INDEX++];
       switch(READ_ADDRESS)
       {
         case 'a':ServoX.write(READ_VALUE);break;
         case 'b':ServoY.write(READ_VALUE);break;
         case 'c':ServoZ.write(READ_VALUE);break;
         case 13:break;
         default: Serial.println("Recieved incorrect address");break;
       }
       process_count++;
  }

  BYTES_READ = 0;
  PARSE_INDEX = 0;
}








