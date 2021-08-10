#include<Arduino.h> // si el archivo es .ino , no hya que colocar esto
#include <Wire.h>    // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

void INICIAR_MODULO () {
 

 if (! rtc.begin()) {       // si falla la inicializacion del modulo
 Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
 while (1);         // bucle infinito que detiene ejecucion del programa
 }
 rtc.adjust(DateTime(__DATE__, __TIME__));  // funcion que permite establecer fecha y horario
            // al momento de la compilacion. Comentar esta linea
}           // y volver a subir para normal operacion

int GET_HOUR() {
 DateTime fecha = rtc.now();      // funcion que devuelve fecha y horario en formato
            // DateTime y asigna a variable fecha
   
 Serial.print(fecha.hour());      // funcion que obtiene la hora de la fecha completa
 Serial.print(":");       // caracter dos puntos como separador

 delay(1000);         // demora de 1 segundo
}
