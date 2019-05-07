#include <SPI.h>
#include <LiquidCrystal.h>     
#include "RF24.h"      
#include "nRF24L01.h"
// Gerekli Kütüphaneleri tanıttım  //
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define buzzer 8   // Buzzer'ı tanıttım

int data[1];          //Data isminde bir dizi tanımlıyoruz ve gönderilecek datayı belirtiyoruz.


RF24 radio (9,10);   //nRF24L sensörünün haberleşme pinlerini tanıttım


const uint64_t pipe = 0xE8E8F0F0E1LL;  // Yakalanıcak pipe adresini tanıttım

void setup() {
  Serial.begin(9600);             // Seri Monitörü başlattım
  lcd.begin(16, 2);
  radio.begin();                  // İletişimi başlattım
  radio.openReadingPipe(1, pipe); // Yakalanıcak pipe adresini okumasını söyledim
  radio.startListening();         // Devre alıcı devresi olduğu için dinlemeyi başlattım

}

void loop() {
  if (radio.available () ) {         // İletişim başladığında ;
    radio.read(data, sizeof(data));  // Gelen verinin hepsini oku
    Serial.println(data[0]);         // Gelen veriyi seri monitörde göster

    if(data[0] == HIGH) {             // Eğer gelen veri 500'den büyükse;     /* Şu an pot. devresi olduğu için bu kontrol var ileride değiştirilebilir */
      tone(buzzer, 440);            // Buzzer'ı çalıştır
      delay(400);
      lcd.clear(); 
      lcd.print("Guvenlik ihlali!");
      lcd.setCursor(0,1);
      lcd.print("Evde biri var!");
      delay(1000);                  // Bekleme süresi tanıttım
      noTone(buzzer);               // Buzzer'ı kapat
      delay(50);                    // Bekleme süresi tanıttım
    }
    else {                          // Gelen veri eşik değere ulaşmıyorsa
      lcd.clear();
      lcd.print("Guvenlik Devrede");
      lcd.setCursor(0,1);
      lcd.print("Tehdit Yok");
      noTone (buzzer);              // Buzzer'ı kapat.
      // digitalWrite(led1, LOW);   // Led'i kapat.
    }
  }
    }
