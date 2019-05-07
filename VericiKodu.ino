#include <SPI.h>    //nRF24L01 ile haberleşmek için standart SPI kütüphanesini ekliyoruz.
#include "RF24.h"   //nRF24L01'in ana kütüphanesini ekliyoruz.
#include "nRF24L01.h"

#define Pot A0
int digitalPin = 3;
int analogPin = A0;

int data[1];           //Data isminde bir dizi tanımlıyoruz ve gönderilecek datayı belirtiyoruz.

RF24 radio(9,10);     //RF24 kütüphanesinin kullanacağı CE ve CSN pinlerini tanımlıyoruz.

const uint64_t pipe = 0xE8E8F0F0E1LL; //Alıcıyla iletişim için bir pipe adresi tanımlıyoruz.

void setup(void) {    
Serial.begin(9600);             // Seri monitörü başlatıyorum
pinMode (digitalPin, INPUT);    
pinMode (Pot, INPUT);           // Sensörü input olarak tanıttım
radio.begin();                  // İletişimi başlatıyorum.
radio.openWritingPipe(pipe);    // Pipe adresi tanımlıyorum

}
void loop(void) {
data [0] = (digitalRead(digitalPin));       // Gönderilecek veri'nin, pot'un okunması olduğunu belirttim.
Serial.println(data [0]);     // Gönderilen veriyi monitöre yansıttım.
delay(500);
Serial.println(digitalRead(digitalPin));
delay(500);
Serial.println(analogRead(analogPin));
delay(500);
radio.write(data, sizeof(data));  // Veri, bütün hali ile yazılsın ve gönderilsin.
}
