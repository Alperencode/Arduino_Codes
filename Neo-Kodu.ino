#include <Adafruit_NeoPixel.h>   // NeoPixel Kütüphanesi
#include <SoftwareSerial.h>     // Bluetooth Kütüphanesi
// Kütüphanelerin Tanıtılması //

// Haberleşme pinlerinin tanıtılması
SoftwareSerial mySerial(9, 10); // RX, TX

// NeoPixel Halkaların pinlerinin tanıtılması
#define PIN 6
#define NUMPIXELS 16

// Değişkenlerin tanıtılması
int kirmizi;
int yesil;
int mavi;

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);   // NeoPixel halkanın stabil değerini ayarlıyoruz 

int bekleme = 20;   // 20 milisaniye delay

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);     // Bluetooth sensör haberleşmesi
  mySerial.setTimeout(50);  // Bluetooth sensör haberleşmesi
  led.begin();              // NeoPixel Ledlerinin çalıştırılması
  led.show();               // NeoPixel lambayı kontrol'e hazır hale getirme
 
}
 
void loop() {                           // Bütün loop haberleşmeye bağlı
                                        // Haberleşme olmazsa while döngüsüne girmez
                                        // While döngüsüne girmezse loop boş geçiyor
 
  while (mySerial.available() > 0) {    // Haberleşme olduğu sürece
 
    kirmizi = mySerial.parseInt();      // Kırmızı değişkenine kırmızı rengin tanıtılması
 
    yesil = mySerial.parseInt();        // Yeşil değişkenine yeşil rengin tanıtılması
 
    mavi = mySerial.parseInt();         // Mavi değişkenine mavi rengin tanıtılması
 
    if (mySerial.read() == ')') {       // Eğer Haberleşme ')' okursa   // ?

      for(int i=0;i<NUMPIXELS;i++){                         // Numpixel sayısı kadar bir döngüye gir
    
      led.setPixelColor(i, led.Color(kirmizi,yesil,mavi));  // Led'e renkleri tanıtıyoruz
      led.show();                                           // Ledlerin çalıştırılması
      delay(bekleme);                                       // 20 milisaniye delay

  }
 
      Serial.print(kirmizi);       // Serial monitöre kırmızı değişkenini yazdır
      Serial.print(" ");           // Bir satır boşluk bırak
      Serial.print(yesil);         // Serial monitöre yeşil değişkenini yazdır
      Serial.print(" ");           // Bir satır boşluk bırak
      Serial.println(mavi);        // Serial monitöre mavi değişkenini yazdır ve alt satıra geç

    }
  }
}
