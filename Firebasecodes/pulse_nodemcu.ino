#include  <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include<Wire.h>


 
#define FIREBASE_HOST "ecgpulse-default-rtdb.firebaseio.com/"
#define WIFI_SSID "OPPO A16k" // Change the name of your WIFI
#define WIFI_PASSWORD "quiuu27h" // Change the password of your WIFI
#define FIREBASE_Authorization_key "P67KN1LRMmr6UrrPI8GJNjk1vk2YNEdWSe8r7jLm"
 
FirebaseData firebaseData;
FirebaseJson json;
              
void setup() {
 Serial.begin(115200);
 
   WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
   Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST,FIREBASE_Authorization_key);
}
 float pulse_rate;
 
void loop() {
  
  
   pulse_rate=analogRead(A0);
   
   
 
  Firebase.setFloat(firebaseData, "pulse_rate : in beats/min", pulse_rate);
  //Firebase.setFloat(firebaseData, "spo2 : in %", hum);
delay(3000);
}
