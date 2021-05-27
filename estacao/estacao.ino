// bibliotecas do lcd
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// bibliotecas do sensor de umidade
#include <DHT.h>
DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, tempdh; // Declara variáveis
int bin; float tensao, temp; // Declara variáveis
int b;float t,res,lum; // variáveis do ldr
// chama o lcd na biblioteca
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
Serial.begin(9600);// Inicializa serial
dht.begin(); // Inicializa objeto dht
lcd.init(); // Inicializa LCD
lcd.backlight(); // Liga luz do LCD
}
void loop()
{
// para o ldr
b = analogRead(A1); // lê o binario do sensor de luminosidade
t = (b/1023.0)*5.0; // converte em tensão 
res = t*10000.0/(5.0-t); // calcula resistencia
lum = pow(10,6.5-1.25*log10(res)); // calcula a luminosidade
bin = analogRead(A0); // Lê valor binário
// para o lm35
tensao = (bin/1023.0)*5.0; // Converte em tensão
temp = 100.00*tensao+0.00; // Converte em temp.
/////////Para o dht22///////////////
umid = dht.readHumidity(); // Lê umidade
tempdh = dht.readTemperature(); // Lê temperatura
umid = 1.21*umid + 4.90; // Calibração
/////////// ------------- //////////////
// o lcd é trocado a referenica, não é como matriz
// primeiro vem a coluna e depois a linha
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Umidade [%]:");
lcd.setCursor(0,1);
lcd.print(umid);
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp. - [oC]:");
lcd.setCursor(0,1);
lcd.print(temp);
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Lumin. [Lux]:");
lcd.setCursor(0,1);
lcd.print(lum);
delay(2000);
}
