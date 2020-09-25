/*
 * Connects to WiFi network
 * Starts WiFi server with fixed IP
 * Sends data to client
 * 
 * Made by: How To Everything
 * https://www.youtube.com/channel/UCJVtkE-cJj3g-KKhZuSMe1w
 */
#include <SPI.h>
#include <ESP8266WiFi.h>

char ssid[] = "********";  //Name of your WiFi network              
char pass[] = "********";  //Password of your WiFi network               
WiFiServer server(80);
                    
IPAddress ip(192, 168, 1, 4);  //Reserved Ip address for your server            
IPAddress gateway(192,168,0,1);  //Gateway of your network          
IPAddress subnet(255,255,255,0);  //Subnet mask of your network         

void setup() {
  Serial.begin(115200);                   
  WiFi.config(ip, gateway, subnet);  //Sets configuration for WiFi network       
  WiFi.begin(ssid, pass);            //Connects to network     
  while (WiFi.status() != WL_CONNECTED) {  //If not connected to network
    Serial.println("Not Connected!");      //Print this
    delay(500);
  }
  Serial.println("Connected!"); //When connected print this
  server.begin();                   //Starts server      
}

void loop () {
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      String request = client.readStringUntil('\r');    
      client.flush();
      client.println(Serial.read()); //Sends data recieved from Arduino
    }
    client.stop();   //Terminates the connection with the client             
  }
}
