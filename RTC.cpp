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

int GET_TEMPERATURE(){// mide temperatura =O
  
return rtc.getTemperature();
}
