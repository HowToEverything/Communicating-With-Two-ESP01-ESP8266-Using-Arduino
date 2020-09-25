/*
 * Reads data from ESP8266
 * Translates data
 * Operates on given functions
 * 
 * Made By: How To Everything
 * https://www.youtube.com/channel/UCJVtkE-cJj3g-KKhZuSMe1w
 */
String myString="";

void setup() {
 Serial.begin(115200);
}

void loop() {
  if(Serial.available() > 0){
    String rawData = Serial.readStringUntil('\n'); //Reads data from ESP8266
    int data = rawData.toInt();  //Turns data to integer
    if(data>31){  //Filters none needed data
      char c = data;  //Converts data to readable string
      myString+=c; //Combines string to form one command
    }
    if(data==13){  //When done recieving data
      Serial.println(myString); //Print recieved data
                    //
                    //  ADD YOUR CODE HERE
                    //
      myString="";  //Erases old data
    }  
  }
}
