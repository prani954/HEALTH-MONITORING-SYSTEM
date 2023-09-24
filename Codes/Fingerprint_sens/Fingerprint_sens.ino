#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;
String IDname;

void setup(){
  //Fingerprint sensor module setup
  Serial.begin(9600);
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } 
  else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  //OLED display setup
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  //displays main screen
  displayMainScreen();
}

void loop(){
  displayMainScreen();
  fingerprintID = getFingerprintIDez();
  delay(50);
  if(fingerprintID == 1 || fingerprintID == 3 || fingerprintID == 4 || fingerprintID == 5){
    IDname = "Sara";
    displayUserGreeting(IDname);            
  }  
  else if(fingerprintID == 2){
    IDname = "Rui";  
    displayUserGreeting(IDname);            
  }
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  return finger.fingerID; 
}

void displayMainScreen(){
  // display.clearDisplay();
  // Serial.setTextSize(1);
  // Serial.setTextColor(WHITE);
  // Serial.setCursor(7,5);
  Serial.println("Waiting fingerprint");
  // Serial.setTextSize(1);
  // Serial.setTextColor(WHITE);
  // Serial.setCursor(52,20);
  Serial.println("...");  
  Serial.display();
  delay(2000);
}

void displayUserGreeting(String Name){
  Serial.setTextColor(WHITE);
  Serial.setTextSize(2);
  Serial.clearDisplay();
  Serial.setCursor(0,0);
  Serial.print("Hello");
  Serial.setCursor(0,15);
  Serial.print(Name); 
  Serial.display();
  delay(5000);
  fingerprintID = 0; 
}
