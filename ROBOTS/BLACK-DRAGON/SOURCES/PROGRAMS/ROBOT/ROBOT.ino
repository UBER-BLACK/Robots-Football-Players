#include <SPI.h>//library  
#include <nRF24L01.h>//library  
#include <RF24.h>//library  
RF24           radio(7, 8);//radio ports
int            data[3];//data package
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);//port monitor speed
  radio.begin();     //???
  radio.setChannel(64); //chennel
  radio.setDataRate     (RF24_250KBPS);//sending speed
  radio.setPALevel      (RF24_PA_HIGH);//power
  radio.openReadingPipe (1, 0x1234567890LL);//key
  radio.startListening  ();//listening channel
}
void loop() {
  if (radio.available()) { //find
    radio.read(&data, sizeof(data));//read
    Serial.println(data[0]);//print in com-port: x
    Serial.println(data[1]);//print in com-port: y
    Serial.println(data[2]);//print in com-port: button
    analogWrite(6, 0 );// 0/255 !!!_ATTENTION_!!!, do not
    if (data[2] == 0)digitalWrite(6, 255); //set more then 90 - there is a danger of OVERHEATING
    if (data[1] < 300) {
      if (data[2] == 1) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        analogWrite(8, LOW);
      }
      else {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);Ы
        digitalWrite(8, HIGH);
      }
    }
    else if (data[1] > 700) {
      if (data[2] == 1) {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(8, LOW);
      }
      else {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
      }
    8
    else if (data[0] > 700) {
      if (data[2] == 1) {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
      }
      else {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
      }
    }
    else if (data[0] < 300) {
      if (data[2] == 1) {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
      }
      else {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
      }
    }
    else {
      if (data[1] == 1) {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
      }
      else {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
      }
    }
  }
  else {
    Serial.println("ERROR");
  }
}
