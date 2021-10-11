#include <LiquidCrystal.h>
LiquidCrystal lcd(4,6,10,11,12,13);
int input,R1=990;
float R2=0,Vout=0,Vin =4.95;
String ohm;
void setup() {
  lcd.begin(16,2);
}

void loop() {
  delay(250);
  lcd.clear();
  lcd.print("Qarshilik Test");
  input=analogRead(A0);
  Vout=Vin*input/1023.00;
  R2=R1*(Vout/(Vin-Vout));
  if(R2>=1000){R2=R2/1000.00;
  ohm="kOm.";
  }else if(R2>=1000000)
  {
    R2=R2/1000000.00;
    ohm="MOm.";
    }else ohm = "Ohm";
    lcd.setCursor(0,1);
    lcd.print(R2);
    lcd.print(ohm);
}
