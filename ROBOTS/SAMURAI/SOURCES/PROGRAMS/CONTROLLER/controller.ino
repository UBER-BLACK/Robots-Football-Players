#include <SPI.h>           //library
#include <nRF24L01.h>      //library
#include <RF24.h>          //library
RF24           radio(7, 8);//radio ports
int            data[3];    //data package
void setup(){              //auto boot
    pinMode(2, INPUT_PULLUP);//button
    Serial.begin(9600);    //port monitor speed
    radio.begin();         //radio speed
    radio.setChannel(100); //channel
    radio.setDataRate     (RF24_250KBPS); //transmission speed
    radio.setPALevel      (RF24_PA_LOW);  //power
    radio.openWritingPipe (0x1234567890LL);//key
}
void loop(){//basic
  data[0] = analogRead(A0);//x
  data[1] = analogRead(A1);//y
  data[2] = digitalRead(2);//button
  Serial.println(data[0]); //DATA + X
  Serial.println(data[1]); //DATA + Y
  Serial.println(data[2]); //DATA + B
  radio.write(&data, sizeof(data)); //send
}
