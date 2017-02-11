#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup()
{
  Serial.begin(115200);

    WiFi.disconnect();
  delay(1000);
   WiFi.begin("Mayank");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }Serial.println("Connected");
  Serial.println((WiFi.localIP()));

}


void loop()
{

  server.begin();

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("hiii");
    client.println("</html>");
    delay(1);

}
