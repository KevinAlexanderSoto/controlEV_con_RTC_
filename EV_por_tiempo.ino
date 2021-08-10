#include "RTC_EXPORT.h"

#define valve1 8 
#define valve2 7
#define h_anterior GET_HOUR()// intervlao de riego , 1 es por hora , 2 es media hora etc...

void setup() {
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
 INICIAR_MODULO ();
}

void loop() {
  
ControlValve();


delay(10000);
}

void ControlValve(){
int h_actual = GET_HOUR();

if(h_actual != h_anterior)
// TODO: encender valvular por un intervalo de tiempo 
h_anterior=h_actual;
}

