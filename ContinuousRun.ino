#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s(3,1);

void setup() {
  //Serial S Begin at 9600 Baud
  s.begin(9600);
}

void loop() {
  //Write '123' to Serial
  s.println("M17");
  s.println("G1 X0 Y120 Z120");
  s.println("G1 X10 Y100 Z0");
  s.println("G1 X142 Y108 Z80");
  s.println("G1 X62 Y-14 Z0");
  s.println("G1 X10 Y100 Z0");
  s.println("G1 X0 Y120 Z120");
  s.println("G1 X10 Y100 Z0");
  s.println("G1 X142 Y108 Z80");
  s.println("G1 X62 Y-14 Z0");
  s.println("G1 X10 Y100 Z0");
  s.println("G1 X-180 Y100 Z100");
  delay(10000);
}
