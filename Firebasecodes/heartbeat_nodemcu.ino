#include  <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#include<Wire.h>


 
#define FIREBASE_HOST "oximeter-ac509-default-rtdb.firebaseio.com/"
#define WIFI_SSID "OPPO A16k" // Change the name of your WIFI
#define WIFI_PASSWORD "quiuu27h" // Change the password of your WIFI
#define FIREBASE_Authorization_key "NkIJEevIc6cyNCESoswcQL7vrwFnomrXwZueBFNp"
 
FirebaseData firebaseData;
FirebaseJson json;
              
void setup() {
 Serial.begin(115200);
 Wire.begin(D1,D2);
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
 int heart_rate;
 int spo2;
void loop() {
  
  
   while(Wire.available())
   {
    int heart_rate=Wire.read();
    Serial.print(heart_rate);
   }
 
   
 
  Firebase.setFloat(firebaseData, "heart_rate : in beats/min", heart_rate);
  //Firebase.setFloat(firebaseData, "spo2 : in %", hum);
delay(3000);
}
