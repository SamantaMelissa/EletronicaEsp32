#include <Arduino.h>
#include <Adafruit_BMP280.h>
#include <LiquidCrystal_I2C.h>

Adafruit_BMP280 bmp;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  Serial.begin(9600);

  if (!bmp.begin(0x76))
  {
    Serial.print("Deu ruim :(");
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_FORCED,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("OLA MUNDO!");
}

void mozinho(int tempo)
{
  delay(tempo);
}

void loop()
{
  if (bmp.takeForcedMeasurement())
  {
    // can now print out the new measurements
    // F -> ARMAZENA NA MEMÓRIA FLASH E NAO RAM
    
    float temperatura = bmp.readTemperature();
    float pressao = bmp.readPressure();
    float altitude = bmp.readAltitude(1870);
    
    Serial.printf("Temperatura = %.2f", temperatura, "*C \n");
    
    Serial.printf("Pressão = %.0f", pressao, "*PA \n");
    
    Serial.printf("Altitude = %.2f", altitude, "m \n");
    
    
    
    lcd.setCursor(0, 2);
    lcd.printf("Temp = %.2f*C", temperatura);
    
    lcd.setCursor(0, 3);
    lcd.printf("Pressão = %.2f*PA", pressao);
    
    lcd.setCursor(0, 4);
    lcd.printf("Altitude = %.2fm", altitude);
  }
  mozinho(3000);
}
