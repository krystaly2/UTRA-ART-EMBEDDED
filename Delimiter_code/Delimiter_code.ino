 #include <SoftwareSerial.h>
SoftwareSerial motorSerial(10, 11); //tx, rx (transmitting, receiving)
String command = "";
unsigned long lastTime = 0;
boolean on = false;
void setup()
{
  Serial.begin(9600);
  // put your setup code here, to run once:
  motorSerial.begin(38400);
}
void loop()
{
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    command += (char)inChar;
    
    
    if (inChar == '\n') {
       ProcessCommand(command);
       command = "";
    }
  }
  /*unsigned long currentTime = millis();
  if (currentTime > lastTime + 5000) {
    lastTime = currentTime;
    if (on == false) {
      ProcessCommand("75,75\n");
      on = true;
    } else {
      ProcessCommand("0\n");
      on = false;
    }
    Serial.println("Sent");
  }*/
}
void ProcessCommand(String command) {
  int data[5];
  int numArgs = 0;
  
  int beginIdx = 0;
  int idx = command.indexOf(",");
 // Serial.println(idx);
  
  while (idx != -1)
  {
      data[numArgs++] = command.substring(beginIdx, idx).toInt();//reads string from beginIdx to idx. toInt coverts string to int
      
      beginIdx = idx + 1;
      idx = command.indexOf(",", beginIdx);
      
      //Serial.println(numArgs);
  }
  Serial.println(data[0]);
  Serial.println(data[1]);
  Serial.println(data[2]);
  Serial.println(data[3]);
  data[numArgs] = command.substring(beginIdx).toInt(); 
  Serial.println(data[4]);
  int leftSpeed = data[0];
  int rightSpeed = data[1];
  
  Serial.println(leftSpeed);
  
  if (leftSpeed == 0) {
    motorSerial.write((byte)0); //moving the motor
  } else {
    motorSerial.write(leftSpeed);
    delay(42);
    motorSerial.write(rightSpeed + 127); //moving the right motor, for turning (or 127 is for adjusting?)
  }
}
