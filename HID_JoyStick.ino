#define bluetoothRX 10
#define bluetoothTX 11
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(bluetoothRX, bluetoothTX);
void setup() {
  // put your main code here, to run repeatedly:
 
  //...

  // Command Mode
  // --------------
  bluetooth.begin(9600);
  delay(50);
  bluetooth.print("$$$");
  delay(50);
  bluetooth.print("SN,HIDJoystick\r\n");
  delay(50);
  bluetooth.print(" SU,57\r\n");
  delay(50);
  bluetooth.print("S~,6\r\n");
  delay(600);
  bluetooth.print("SH,0240\r\n");
  delay(200);
  bluetooth.print("R,1\r\n");
  delay(400);
}

void loop() {
  bluetooth.write((byte)0xFD); //Start HID Report
  bluetooth.write((byte)0x6);  //Length byte

  // 1. X/Y-Axis
  bluetooth.write(45);  //First X coordinate
  bluetooth.write(-33); //First Y coordinate

  // 2. X/Y-Axis
  bluetooth.write(45);  //Second X coordinate
  bluetooth.write(-33); //Second Y coordinate

  // Buttons
  bluetooth.write(B10000001); // Second Byte (Buttons 1-8)
  bluetooth.write(B10000000); // Second Byte (Buttons 9-16)
}
