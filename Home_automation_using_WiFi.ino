#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD ""
#define REMOTEXY_SERVER_PORT 6377
#include <RemoteXY.h>
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,29,0,17,0,0,0,31,1,106,200,1,1,1,0,2,
  31,86,44,22,0,2,26,31,31,79,78,0,79,70,70,0 };
struct {
  uint8_t switch_01;
  uint8_t connect_flag;  
} RemoteXY;  
#pragma pack(pop)
#define PIN_SWITCH_01 D4
void setup()
{
  RemoteXY_Init ();
  pinMode (PIN_SWITCH_01, OUTPUT);
}
void loop()
{
  RemoteXY_Handler ();
  digitalWrite(PIN_SWITCH_01, (RemoteXY.switch_01==0)?LOW:HIGH);
}