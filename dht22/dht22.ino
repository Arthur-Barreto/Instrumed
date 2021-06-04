#include <DHT.h>
DHT dht(2,DHT22); // Declara objeto do tipo DHT
float umid, temp; // Declara variáveis
void setup()
{
Serial.begin(9600);// Inicializa serial
dht.begin(); // Inicializa objeto dht
}
void loop()
{
umid = dht.readHumidity(); // Lê umidade
temp = dht.readTemperature(); // Lê temperatura
umid = 0.927*umid + 3.026; // Calibração
Serial.print("\n\nUmidade [%]: ");
Serial.print(umid); // Exibe umidade
Serial.print("\nTemperatura [ºC]: ");
Serial.print(temp); // Exibe temp.
delay(2000);
}
