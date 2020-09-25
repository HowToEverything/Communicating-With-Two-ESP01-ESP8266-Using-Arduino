/*
 * Starts WiFi client 
 * Connects to server network
 * Sends recieves data from server
 * 
 * Made by: How To Everything
 * https://www.youtube.com/channel/UCJVtkE-cJj3g-KKhZuSMe1w
 */
#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[] = "********";  //Name of your WiFi network        
char pass[] = "********";  //Password of your WiFi network
         
IPAddress server(192,168,1,4);  //connect to reserved Ip address for your server      
WiFiClient client;

void setup() {
  Serial.begin(115200);               
  WiFi.begin(ssid, pass);     //Connects to network       
  while (WiFi.status() != WL_CONNECTED) { //If not connected to network
    Serial.println("Not Connected!");     //Print this
    delay(500);
  }
  Serial.println("Connected!");  //When connected print this
}

void loop () {
  client.connect(server, 80);    //Connects to server host 
  client.println("Hello\r");  //sends message for debugging
  String answer = client.readStringUntil('\r'); //recieves and reads server data
  answer = answer.toInt();
  if(answer != "-1"){     //same as if(Serial.available())
    Serial.println(answer);  //Prints answer for Arduino to recieve
  }
  client.flush();         
}
