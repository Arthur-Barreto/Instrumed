//biblioteca do bmp280
#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp; // Declara objeto do tipo BMP
// biblioteca do lcd
#include <LiquidCrystal_I2C.h>
// biblioteca i2c
#include <Wire.h>
// biblioteca do sensor de umidade
#include <DHT.h>
DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, tempdh; // Declara variáveis
int bin; float tensao, temp; // Declara variáveis
int b;float t,res,lum; // variáveis do ldr
float press; // variável da pressão d sensor bmp 280
// chama o lcd na biblioteca
LiquidCrystal_I2C lcd(0x27,16,2);
// criar o caracter especial para a com acento tio e o grau
  byte grau[] = {
    B00111,
    B00101,
    B00111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };
  byte tio[] = {
    B00101,
    B01010,
    B01110,
    B00001,
    B01111,
    B10001,
    B01111,
    B00000
    };
void setup()
{
  Serial.begin(9600);// Inicializa serial
  bmp.begin(0x76); // Inicializa objeto BMP
  dht.begin(); // Inicializa objeto dht
  lcd.init(); // Inicializa LCD
  lcd.backlight(); // Liga luz do LCD
  lcd.createChar(0,tio);
  lcd.createChar(2,grau);

}
void loop()
{
// para o ldr
b = analogRead(A1); // lê o binario do sensor de luminosidade
delay(10);
t = (b/1023.0)*5.0; // converte em tensão 
res = t*100000.0/(5.0-t); // calcula resistencia
lum = pow(10,6.5-1.25*log10(res)); // calcula a luminosidade
// para o lm35
bin = analogRead(A0); // Lê valor binário
delay(10);
tensao = (bin/1023.0)*5.0; // Converte em tensão
temp = 99.602*tensao-0.0677; // Converte em temp.e calibra
/////////Para o dht22///////////////
umid = dht.readHumidity(); // Lê umidade
umid = 0.927*umid + 3.026; // Calibração de acordo com o excel
// para o bmp 280
press = bmp.readPressure(); // Lê pressão
/////////// ------------- //////////////
// o lcd é trocado a referenica, não é como matriz
// primeiro vem a coluna e depois a linha
lcd.clear(); // limpa a tela se não buga tudo
lcd.setCursor(0,0);
lcd.print("Umidade [%]:");
lcd.setCursor(0,1);
lcd.print(umid);
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Temp. - [");
lcd.setCursor(9,0);
lcd.write(2);
lcd.setCursor(10,0);
lcd.print("C]: ");
lcd.setCursor(0,1);
lcd.print(temp);
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Lumin. [Lux]:");
lcd.setCursor(0,1);
lcd.print(lum);
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Press"); 
lcd.setCursor(5,0);
lcd.write(0);
lcd.setCursor(6,0);
lcd.print("o [hPa]:");
lcd.setCursor(0,1);
lcd.print(press/100);
delay(2000);
}
