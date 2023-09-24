#include<Wire.h>
#include  <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#define FIREBASE_HOST "nodemcuiot-6fcf3-default-rtdb.firebaseio.com/"
#define WIFI_SSID "OPPO A16k" // Change the name of your WIFI
#define WIFI_PASSWORD "quiuu27h" // Change the password of your WIFI
#define FIREBASE_Authorization_key "2RjQhBX8aX6PqqeCpNNgzGdruKHqhbtqFyk5K8Pl"
 
FirebaseData firebaseData;
FirebaseJson json;
              
void setup() {
   Serial.begin(9600);
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
  Wire.begin(D1, D2);
}
 int temp;
void loop() {

  Serial.print(Wire.available());
  while(Wire.available())
  {
  int temp = Wire.read();
  Serial.print(temp);
  }
 
  Firebase.setFloat(firebaseData, "OBJECT TEMP", temp);
   delay(3000);
}
