#include <Wire.h>
#include <Adafruit_MLX90614.h>
char *Object_Type[]={"Object","Ambient"};

Adafruit_MLX90614 MLX_Sensor = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Serial.println("MLX90614 Sensor MicroLab");  
  MLX_Sensor.begin();  
  Wire.begin();
}
float temp_value;
void loop() {
    float Object_Temperature = MLX_Sensor.readObjectTempF();
    float Ambient_Temperature = MLX_Sensor.readAmbientTempF();
    Wire.beginTransmission(8);
    int obj = round(Object_Temperature);
    int amb = round(Ambient_Temperature);
    Wire.write(obj);
    Wire.write(amb);
    Wire.endTransmission();
    Serial.print(" "); 
    Serial.println("object temp");   
    Serial.print(obj);
    Serial.print("°");      
    Serial.println("F");
    Serial.print(" ");
    Serial.println("ambient temp"); 
    Serial.print(amb);
    Serial.print("°");      
    Serial.println("F");
    
    
    
  
  
  
  
  
  Serial.println("########");

  delay(2000);

  
}
