#include <SoftwareSerial.h>// import the serial library
SoftwareSerial blueToothSerial(10, 11); // RX, TX
int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  blueToothSerial.begin(9600);
  blueToothSerial.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
   if (blueToothSerial.available()){
BluetoothData=blueToothSerial.read();
   if(BluetoothData=='1'){   // if number 1 pressed ....
   digitalWrite(ledpin,1);
   Serial.println("LED  On D13 ON ! ");
   }
  if (BluetoothData=='0'){// if number 0 pressed ....
  digitalWrite(ledpin,0);
   Serial.println("LED  On D13 Off ! ");
  }
}
delay(100);// prepare for next data ...
}
