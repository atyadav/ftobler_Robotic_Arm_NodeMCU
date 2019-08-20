/*
 * Ftobler Robot Arm with NodeMCU
 *
 * Heramb MakerLab
 */
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

//ESP Web Server Library to host a web page
#include <ESP8266WebServer.h>

//---------------------------------------------------------------
//Our HTML webpage contents in program memory
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<center>
<h1>Ftobler Arm Mobile Operated using NodeMCU</h1><br>
Click to move arm <a href="ArmHome" target="myIframe">ARM HOME</a><br>
Click to move arm <a href="ArmRest" target="myIframe">ARM REST</a><br>
Click to move arm <a href="ArmBottom" target="myIframe">ARM BOTTOM</a><br>
Arm State:<iframe name="myIframe" width="200" height="25" frameBorder="0"><br>
<hr>
<a href="http://www.facebook.com/herambmakerlab">Heramb MakerLab</a>
</center>
</body>
</html>
)=====";
//---------------------------------------------------------------

//SSID and Password of your WiFi router
const char* ssid = "XXXXXX";
const char* password = "XXXXXXX";

//Declare a global object variable from the ESP8266WebServer class.
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 //Serial.println("You called root page");
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleArmHome() { 
 Serial.println("M17");
 Serial.println("G1 X0 Y100 Z0");
 
 server.send(200, "text/html", "Arm at Home"); //Send ADC value only to client ajax request
}

void handleArmRest() { 
 Serial.println("M17");
 Serial.println("G1 X0 Y40 Z70");
 server.send(200, "text/html", "Arm at Rest"); //Send ADC value only to client ajax request
}

void handleArmBottom() { 
 Serial.println("M17");
 Serial.println("G1 X0 Y120 Z120");
 server.send(200, "text/html", "Arm at Bottom"); //Send ADC value only to client ajax request
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router

  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);

  }
   
  server.on("/", handleRoot);      //Which routine to handle at root location. This is display page
  server.on("/ArmHome", handleArmHome); 
  server.on("/ArmRest", handleArmRest); 
  server.on("/ArmBottom", handleArmBottom); 

  server.begin();                  //Start server
  //Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
