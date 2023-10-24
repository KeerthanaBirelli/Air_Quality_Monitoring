//#include <IFTTTMaker.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#include "TRIGGER_WIFI.h"  
#include "TRIGGER_GOOGLESHEETS.h" 

char column_name_in_sheets[ ][6] = {"ppm"};                        
String Sheets_GAS_ID = "AKfycbzEuj7nY2nAYEG4quW9ARxc_ZY_2HL0uYTzWXP943TtSNhDVZhwUJ49vpr-PI9QxAas";                                         
int No_of_Parameters = 1;    

const int aqsensor=A0;
int threshold=250;
void setup()
{
pinMode (aqsensor, INPUT);
Serial.begin(9600);
WIFI_Connect("rohith mi5pro","987654321"); 
Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters );
}
void loop()
{
float ppm= analogRead (aqsensor);
Data_to_Sheets(No_of_Parameters, ppm); 
Serial.println (ppm);
Serial.print(" ");
delay(10000);
}