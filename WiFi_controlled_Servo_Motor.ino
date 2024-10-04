#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377
#include <RemoteXY.h>
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 27 bytes
  { 255,1,0,0,0,20,0,17,0,0,0,31,1,106,200,1,1,1,0,4,
  24,80,63,21,128,2,26 };
struct {
  int8_t slider_01;
  uint8_t connect_flag;
} RemoteXY;  
#pragma pack(pop)
 #include <Servo.h>
Servo myservo;
void setup()
{
  RemoteXY_Init ();
  myservo.attach(2);//CONNECT ON D4;
}
void loop()
{
  RemoteXY_Handler ();
  int sliderValue = RemoteXY.slider_01;
  int servoAngle = map(sliderValue, 0, 100, 0, 180);
  myservo.write(servoAngle);
  RemoteXY_delay(20);
}
