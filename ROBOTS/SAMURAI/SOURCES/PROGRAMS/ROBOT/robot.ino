#include <SPI.h>//library  
#include <nRF24L01.h>//library  
#include <RF24.h>//library  
RF24           radio(7, 8);//radio ports  
int            data[3];//data package
void setup(){// auto boot
    pinMode(2,OUTPUT);//digital port connection
    pinMode(3,OUTPUT);//digital port connection
    pinMode(4,OUTPUT);//digital port connection
    pinMode(9,OUTPUT);//digital port connection
    pinMode(10,OUTPUT);//digital port connectionzz
    pinMode(A0,OUTPUT);//analog port connection
    pinMode(A1,OUTPUT);//analog port connection
    pinMode(A2,OUTPUT);//analog port connection
    pinMode(A3,OUTPUT);//analog port connection
    Serial.begin(9600);//port monitor speed
    radio.begin();     //???
    radio.setChannel(100); //chennel
    radio.setDataRate     (RF24_250KBPS);//sending speed
    radio.setPALevel      (RF24_PA_HIGH);//power
    radio.openReadingPipe (1, 0x1234567890LL);//key
    radio.startListening  ();//listening channel
    }
void loop(){ //basic
    if(radio.available()){//find
     radio.read(&data, sizeof(data));//read
     Serial.println(data[0]);//print in com-port: x
     Serial.println(data[1]);//print in com-port: y
     Serial.println(data[2]);//print in com-port: button
     analogWrite(6, 0 );// 0/255 !!!_ATTENTION_!!!, do not
     if(data[2]==0)digitalWrite(6, 255); //set more then 90 - there is a danger of OVERHEATING
     motion(data[0], data[1]); //DON'T TOUCH IT
    }
}
