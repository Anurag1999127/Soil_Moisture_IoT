int sensor_pin = A0;
int output_value ;
#include <ESP8266WiFi.h> // ESP8266WiFi.h library
const char* ssid     = "Hehe";
const char* password = "haha1999";
const char* host = "api.thingspeak.com";
const char* writeAPIKey = "WPMLRCX7987EZ265";
void setup() {
Serial.begin(9600);
Serial.println("Reading From the Sensor ...");
delay(2000);
  // Initialize sensor
  Serial.begin(115200);
//  Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");}
}   
void loop() {
output_value= analogRead(sensor_pin);
output_value = map(output_value,550,0,0,100);
// make TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }
  String url = "/update?key=";
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(output_value);
                            Serial.print(output_value);
                             Serial.print(" Moisture of the Soil ");
                             Serial.println("%. Send to Thingspeak.");
  
  // Request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    delay(6000);
}
