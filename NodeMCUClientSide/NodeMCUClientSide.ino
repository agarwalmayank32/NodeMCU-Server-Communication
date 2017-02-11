#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiServer server(80);

int i,j;
String  httpurl;
HTTPClient http;


void setup()
{
  i = 0;
  j = 0;

  Serial.begin(9600);

  WiFi.disconnect();
  delay(1000);
  WiFi.begin("IOT_Akash","megaunodl5");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
  }Serial.println("Connected");
}


void loop()
{
  server.begin();
  if(i==20)
  {
    i=0;
    j=0;
  }
  httpurl = "http://104.223.31.180/IOT/put.php?d1=";
  httpurl+=String(i);
  httpurl+="&d2=";
  httpurl+=String(j);
  i++;
  j++;
  http.begin(httpurl);
  http.GET();
  String reply=http.getString();
  http.end();
  Serial.println(reply);
  delay(500);

}
