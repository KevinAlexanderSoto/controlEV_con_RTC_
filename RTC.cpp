#include<Arduino.h> // si el archivo es .ino , no hya que colocar esto
#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

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
            // DateTime y asigna a variable fecha
   
 return fecha.minute();
 delay(1000);         // demora de 1 segundo
}
