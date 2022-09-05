
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24           radio(9,  10);
int            data[3];
int i = 0;
void setup(){
    //delay(1000);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    //Для теста удержания мотора
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    Serial.begin(9600);
    radio.begin();
    radio.setChannel(12);
    radio.setDataRate     (RF24_250KBPS);
    radio.setPALevel      (RF24_PA_HIGH);
    radio.openReadingPipe (1, 0x1234567890LL);
    radio.startListening  ();
    //  radio.stopListening   ();
    }
void loop(){
    if(radio.available()){
     radio.read(&data, sizeof(data));
     Serial.println(data[0]);
     Serial.println(data[1]);
     Serial.println(data[2]);
     //analogWrite(6, 50);
     //if(data[2]==0)digitalWrite(6, 1);
    // motion(data[0], data[1]);
    delay(500);
    }
}
