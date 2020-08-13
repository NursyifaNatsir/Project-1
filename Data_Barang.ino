#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
unsigned int masuk=0,keluar=0;
void setup() {
lcd.begin(16,2);
Serial.begin(9600);
pinMode(A0,INPUT_PULLUP);
pinMode(A1,INPUT_PULLUP);
}

void loop() {
if (digitalRead(A0)==LOW){while(digitalRead(A0)==LOW){}
masuk++;
}
if (digitalRead(A1)==LOW){while(digitalRead(A1)==LOW){}
masuk--;
keluar++;
}
if (masuk==0){
  delay(500);keluar=0;
}
lcd.setCursor(0,0);
lcd.print("Barang Masuk = ");lcd.print(masuk);
Serial.print(masuk);
Serial.print(" -- ");
lcd.setCursor(1,1);
lcd.println("Keluar =");lcd.print(keluar);
Serial.println(keluar);
}
