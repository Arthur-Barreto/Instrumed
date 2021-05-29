#include <Adafruit_BMP280.h>
#include <Wire.h>
Adafruit_BMP280 bmp; // Declara objeto do tipo BMP
float press, temp; // Declara variáveis
void setup()
{
Serial.begin(9600); // Inicializa serial
bmp.begin(0x76); // Inicializa objeto BMP
}
void loop()
{
press = bmp.readPressure(); // Lê pressão
temp = bmp.readTemperature();// Lê temperatura
Serial.print("\n\nPressão [hPa]: ");
Serial.print(press/100); // Exibe pressão
Serial.print("\nTemperatura [ºC]: ");
Serial.print(temp); // Exibe temperatura
delay(2000);
}
