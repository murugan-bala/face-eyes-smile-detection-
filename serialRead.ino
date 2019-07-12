#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX  (arduino 10pin ---GSM TXpin) (arduino 11th pin ----GSM RX pin)
void gsm();
char phone_no[]="98*******";

void gsm()  // dengue found
  {
    
  mySerial.println("AT+CMGF=1");    
delay(2000);
mySerial.print("AT+CMGS=\"");
mySerial.print(phone_no); 
mySerial.write(0x22);
mySerial.write(0x0D);  // hex equivalent of Carraige return    
mySerial.write(0x0A);  // hex equivalent of newline
delay(2000);
mySerial.print("Dengue found  ");
#mySerial.print("location : 11.9206° N, 79.6109° E ");
delay(500);
mySerial.println (char(26));//the ASCII code of the ctrl+z is 26

}
void setup()
{
  
Serial.begin(9600);
 mySerial.begin(9600);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() 
{
 while (Serial.available()>0) 
 {
char  serIn=Serial.read();
  if (serIn=='a') 
  { 
    gsm();
    Serial.print("YES....");
  digitalWrite(7,HIGH);
  delay(1000);
  }
  else 
  
   digitalWrite(7,LOW);
}
}
