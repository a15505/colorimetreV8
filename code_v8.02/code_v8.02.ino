/*
 * Colorimètre V8
 * Le code nécessite l'ajout de la bibliothèque de l'écran ACL "LiquidCrystal_I2C"
 * La bibliothèque peut varier selon le type de convertisseur I2C.
 * https://github.com/johnrickman/LiquidCrystal_I2C
 * ou
 * https://www.mathertel.de/Arduino/LiquidCrystal_PCF8574.aspx si la puce est du type PCF8574
 * 
 * Créé par Yvon Quémener
 * 19 juin 2021
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // lcd(0x3F,16,2) utiliser la biblothèque I2C detect pour identifier l'adresse. https://github.com/mcauser/i2cdetect

int broche_del = 3;  
int puissance = 70; //valeur de puissance minimale de la del au démarrage
float sonde = 0;

void setup(){
  pinMode(broche_del, OUTPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Colorimetre");
  lcd.setCursor(0,1);
  lcd.print("V8.02");
  delay (2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Sonde : A0");
  lcd.setCursor(0,1);
  lcd.print("DEL : D3");
  delay (2000);
  lcd.clear();
  analogWrite (broche_del,puissance);

  while (sonde < 100){ //la puissance maximale définie de la del est 100
  analogWrite (broche_del,puissance);
  delay (100);
  sonde = analogRead (A0);
  sonde = sonde / 3.5;
  puissance++;
  puissance = constrain(puissance, 0, 255); 
  Serial.println(puissance);
  lcd.setCursor(0,0);
  lcd.print("Calibration");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(sonde,0);
  lcd.print(" %");
  }
  puissance--;
  lcd.setCursor(0,0);
  lcd.print("                ");
}

void loop(){
  analogWrite (broche_del,puissance);
  sonde = analogRead (A0);  // ajuster la del afin d'obtenir un signal de 512 
  sonde = sonde / 3.5; // division afin d'obtenir une valeur en pourcentage
  Serial.println (sonde);
  lcd.setCursor(0,0);
  lcd.print("Mesure");
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print(sonde,0);
  lcd.print(" %");
  delay (200);
}
