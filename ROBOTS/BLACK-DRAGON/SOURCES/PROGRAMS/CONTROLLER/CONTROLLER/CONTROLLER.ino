#include <SPI.h> 
#include <nRF24L01.h> 
#include <RF24.h> 
RF24 radio(9, 10); 
int data[3]; 
void setup(){ 
 pinMode(A2, INPUT_PULLUP); 
 Serial.begin(9600); 
 radio.begin(); 
 radio.setChannel(5); 
 radio.setDataRate (RF24_1MBPS); 
 radio.setPALevel (RF24_PA_HIGH); 
 radio.openWritingPipe (0x1234567890LL); 
} 
void loop(){ 
 data[0] = analogRead(A0); 
 data[1] = analogRead(A1); 
 data[2] = digitalRead(A2); 
 Serial.println(data[0]); 
 Serial.println(data[1]); 
 Serial.println(data[2]); 
 radio.write(&data, sizeof(data)); 
}
