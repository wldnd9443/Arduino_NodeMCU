#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <Hash.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include <BH1750.h>

Adafruit_BMP085 bmp;
BH1750 bh;

const int LED = D0;

const char* ssid = "Riatech2GA";
const char* password = "12345678";

AsyncWebServer server(80);

String readBMPTemperature() {
  float t = bmp.readTemperature();
  Serial.println(t);
  return String(t);
}

String readBMPPressure() {
  float h = bmp.readPressure()/100.0;
  Serial.println(h);
  return String(h);
}
String readBHLightLevel(){
  float l = bh.readLightLevel();
  Serial.println(l);
  return String(l);
}

void setup(){

  pinMode(LED, OUTPUT);
  // Serial port for debugging purposes
  Serial.begin(115200);
  // Initialize SPIFFS 
  
  if (!bmp.begin()) 
  {
    Serial.println("Could not find BMP180 or BMP085 sensor at 0x77");
    while (1) {}
  }
  
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }


  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  bh.begin();
  
  Serial.println(WiFi.localIP());

   
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index_select.html","text/html");
    //request->send(SPIFFS, "/index_button.html","text/html");
  });
  
  server.on("/gauge", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/gauge.html","text/html");
  });
  
  server.on("/real_time_chart", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/real_time_chart.html","text/html");
  });
  
  server.on("/bar_chart", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/bar_chart.html","text/html");
  });

  server.on("/pie_chart", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/pie_chart.html","text/html");
  });
  
  
  
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style.css","text/css");
  });
  
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBMPTemperature().c_str());
  });
 
  server.on("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBMPPressure().c_str());
  });

  server.on("/lightlevel", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBHLightLevel().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
}
