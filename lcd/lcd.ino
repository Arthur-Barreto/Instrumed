#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Define o endereço do LCD no barramento I2C e o
// número de colunas e linhas (16x2)
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
lcd.init(); // Inicializa LCD
lcd.backlight(); // Liga luz do LCD
lcd.print("HELLO WORLD!");// Escreve no LCD
}
void loop()
{
lcd.setCursor(0,1); // Move cursor no LCD
lcd.print(millis()/1000);// Escreve no LCD
} 
