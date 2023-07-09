#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>
#include <FS.h>

// Replace with your network credentials
const char* ssid = "Curry";
const char* password = "Yuzihao0923";
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);


String file_name = "/index.html";
String txt;


void initFS() {
  if (!LittleFS.begin()) {
    Serial.println("An error has occurred while mounting LittleFS");
  }
  else {
    Serial.println("LittleFS mounted successfully");
  }
}
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}
void setup() {
  Serial.begin(115200);

while(!Serial){
    ;
}





   initWiFi();
    initFS();
  //
   server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
     request->send(LittleFS, "/index.html", "text/html");
    });
    server.serveStatic("/", LittleFS, "/");
    server.begin();
}

void loop() {

}
