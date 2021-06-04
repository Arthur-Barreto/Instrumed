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
  float umid; // Declara variáveis
  int bin; float tensao, temp; // Declara variáveis
  int b;float t,res,lum; // variáveis do ldr
  float press; // variável da pressão d sensor bmp 280
  // variavel aux
  float pressao = 1.00;
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

  byte cedilha[] = {
    B01110,
    B10000,
    B10000,
    B10001,
    B01110,
    B00100,
    B01000,
    B00100
    };

  byte oh[] = {
    B00010,
    B00100,
    B01110,
    B10001,
    B10001,
    B10001,
    B01110,
    B00000
    };
  // vamos criar um vetor de vetores, ponteiro, para imprimir os nomes dos alunos
  char *nome[] = {"Arthur","Augusto","Giovana","Giselle"};

void setup()
{
  bmp.begin(0x76); // Inicializa objeto BMP
  dht.begin(); // Inicializa objeto dht
  lcd.init(); // Inicializa LCD
  lcd.backlight(); // Liga luz do LCD
  lcd.createChar(0,tio); // cria o "ã" para usar no nome pressão
  lcd.createChar(2,grau); // cria o "º" para usar em ºC
  lcd.createChar(4,cedilha); // cria "ç"
  lcd.createChar(6,oh); // cria "ó"
  // percorre p nosso vetor de veotores para imprimir os nomes
  lcd.setCursor(0,0);
  lcd.print("Insper");
  lcd.setCursor(0,1);
  lcd.print("1B ENGENHARIA");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Disciplina");
  lcd.setCursor(0,1);
  lcd.print("Instrumed");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Esta");
  lcd.setCursor(4,0);
  lcd.write(4);
  lcd.setCursor(5,0);
  lcd.write(0);
  lcd.setCursor(6,0);
  lcd.print("o");
  lcd.setCursor(0,1);
  lcd.print("Metereol");
  lcd.setCursor(8,1);
  lcd.write(6);
  lcd.setCursor(9,1);
  lcd.print("gica");
  delay(2000);
  for (int i=0; i<=3; i++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alunos");
    lcd.setCursor(0,1);
    lcd.print(nome[i]);
    delay(2000);
  } // end for

}
void loop()
{
  // para o ldr
  b = analogRead(A1); // lê o binario do sensor de luminosidade
  delay(10);
  b = analogRead(A1);
  t = (b/1023.0)*5.0; // converte em tensão 
  res = t*100000.0/(5.0-t); // calcula resistencia
  lum = pow(10,6.5-1.25*log10(res)); // calcula a luminosidade
  // para o lm35
  bin = analogRead(A0); // Lê valor binário
  delay(10);
  bin = analogRead(A0);
  tensao = (bin/1023.0)*5.0; // Converte em tensão
  temp = 99.602*tensao-0.0677; // Converte em temp.e calibra
  /////////Para o dht22///////////////
  umid = dht.readHumidity(); // Lê umidade
  umid = 0.927*umid + 3.026; // Calibração de acordo com o excel
  // para o bmp 280
  press = bmp.readPressure(); // Lê pressão
  // converter a pressão para atm
  pressao = press/101300.25;
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
  lcd.print(tempdh);
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
  lcd.print("o [atm]:");
  lcd.setCursor(0,1);
  lcd.print(pressao);
  delay(2000);
}
