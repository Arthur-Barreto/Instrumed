#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Define o endereço do LCD no barramento I2C e o
// número de colunas e linhas (16x2)
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
lcd.init(); // Inicializa LCD
lcd.backlight(); // Liga luz do LCD
lcd.print("Muito obrigado");// Escreve no LCD
}
void loop()
{

} 
