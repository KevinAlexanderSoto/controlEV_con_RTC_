#include<Arduino.h> // si el archivo es .ino , no hya que colocar esto
#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

String daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void INICIAR_MODULO () {
 
 if (! rtc.begin()) {       // si falla la inicializacion del modulo
 Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
 Serial.flush();
        abort();
 }
 Serial.println("Modulo RTC inicializado!");
 if(rtc.lostPower()) {
        // this will adjust to the date and time at compilation
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }  
    //we don't need the 32K Pin, so disable it
    rtc.disable32K();       
}

int GET_HOUR() {
 DateTime fecha = rtc.now();      // funcion que devuelve fecha y horario en formato
 return fecha.hour();
 
}

int GET_MINUTE() {
 DateTime fecha = rtc.now();      
 return fecha.minute();

}

String GET_DAY(){
  DateTime fecha = rtc.now(); 
  Serial.println(daysOfTheWeek[fecha.dayOfTheWeek()]);
  
  }

int GET_RTCTEMPERATURE(){// mide temperatura =O
  
return rtc.getTemperature();
}

////////////////////////DHT11 sensor///////////////////////////////7

#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void INICIAR_MODULO_DHT(){
    
    dht.begin();
    Serial.println(F("DHTxx test!"));

}

float GET_HUMIDITY(){
    return dht.readHumidity();
}

float GET_TEMPERATURE(){
    return dht.readTemperature();
}
