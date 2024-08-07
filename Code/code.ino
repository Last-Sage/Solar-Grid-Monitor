#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "index.h" //Web page header file
#define ksebMeterPin 22
#define solarMeterPin 23

//variables
int kseb_count =0;
int ksebMeter_state =0;
int ksebMeter_prev_state =0;
int solar_count =0;
int solarMeter_state =0;
int solarMeter_prev_state =0;
int solarLdr = analogRead(35);
int ksebLdr = analogRead(32);

WebServer server(80);

//AccesPoint SSID and PASSWORD
const char* ssid = "test";
const char* password = "123456789";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
String s = MAIN_page; //Read HTML contents
server.send(200, "text/html", s); //Send web page
}
void handleADC() {
String ksebPulse = String(kseb_count);
String solarPulse = String(solar_count);
server.send(200, "text/plane", ksebPulse+"|"+solarPulse); //Send ADC value only to client ajax request
}

//===============================================================
// Setup
//===============================================================
void setup(void){
    Serial.begin(115200);

//ESP32 As access point
WiFi.mode(WIFI_AP); //Access Point mode
WiFi.softAP(ssid);
server.on("/", handleRoot); //This is display page
server.on("/readADC", handleADC);//To get update of ADC Value only
server.begin(); //Start server
Serial.println("HTTP server started");
delay(100);
pinMode(ksebMeterPin,INPUT_PULLUP);
pinMode(34,OUTPUT);
Serial.println("kseb:");
pinMode(solarMeterPin,INPUT_PULLUP);
pinMode(33,OUTPUT);
Serial.println("solar:");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
server.handleClient();
delay(1);
if (analogRead(32) > 400){
ksebMeter_state++;
Serial.println(analogRead(32));
Serial.println(ksebMeter_state);
delay(80);
}
if (analogRead(35)> 3500){
solarMeter_state++;
Serial.println(analogRead(35));
delay(80);
}
if(ksebMeter_state!=ksebMeter_prev_state)
{
if(ksebMeter_state==HIGH){
digitalWrite(34,LOW);
}
else
{
digitalWrite(34,HIGH);
kseb_count++;
Serial.println(String("Kseb unit: ")+float(kseb_count*.35));
}
delay(50);
}
if(solarMeter_state!=solarMeter_prev_state)
{
if(solarMeter_state==HIGH){
digitalWrite(35,LOW);
}
else
{
digitalWrite(35,HIGH);
solar_count++;
Serial.println(String("Solar unit: ")+float(solar_count*.28));
}
delay(50);
}
ksebMeter_prev_state=ksebMeter_state;
solarMeter_prev_state=solarMeter_state;
}