#include <DHT.h>
DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, tempdh; // Declara variáveis
int bin; float tensao, temp; // Declara variáveis
void setup()
{
Serial.begin(9600);// Inicializa serial
dht.begin(); // Inicializa objeto dht
}
void loop()
{
bin = analogRead(A0); // Lê valor binário
tensao = (bin/1023.0)*5.0; // Converte em tensão
temp = 100.00*tensao+0.00; // Converte em temp.
/////////------------------///////////////
umid = dht.readHumidity(); // Lê umidade
tempdh = dht.readTemperature(); // Lê temperatura
umid = 1.21*umid + 4.90; // Calibração
/////////// ------------- //////////////
Serial.print("\n\nUmidade [%]: ");
Serial.print(umid); // Exibe umidade
Serial.print("\nTemperatura [ºC]: ");
Serial.print(tempdh); // Exibe temp.
Serial.print("\nTemperatura [ºC] com lm35: ");
Serial.print(temp); // Exibe temperatura
delay(2000);
}
