#include <ESP8266WiFi.h>
#include "NTPTimeClient.h"

// WIFI
const char* WIFI_SSID = "baobab"; 
const char* WIFI_PWD = "";

// TimeClient settings
const float UTC_OFFSET = 9;

NTPTimeClient timeClient(UTC_OFFSET);

void updateData();

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PWD);
  Serial.println("Connecting to WiFi");
 
  int counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
    counter++;
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  delay(10000); //3 sec
}

void updateData(){
  Serial.println("Updating time...");
  timeClient.updateTime();
  Serial.println(timeClient.getFormattedDate("."));
  Serial.println(timeClient.getFormattedTime());
}

