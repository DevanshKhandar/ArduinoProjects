#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#define REMOTEXY_SERIAL_RX 0
#define REMOTEXY_SERIAL_TX 1
#define REMOTEXY_SERIAL_SPEED 9600
#include <RemoteXY.h>
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 36 bytes
  { 255,1,0,0,0,29,0,17,0,0,0,31,1,106,200,1,1,1,0,10,
  39,85,27,27,48,4,26,31,79,78,0,31,79,70,70,0 };
 struct {
  uint8_t pushSwitch_01; 
  uint8_t connect_flag; 

} RemoteXY;  
#pragma pack(pop)
#define PIN_PUSHSWITCH_01 13
void setup()
{
  RemoteXY_Init ();
 pinMode (PIN_PUSHSWITCH_01, OUTPUT);
}
void loop()
{
  RemoteXY_Handler ();
  digitalWrite(PIN_PUSHSWITCH_01, (RemoteXY.pushSwitch_01==0)?LOW:HIGH);
}