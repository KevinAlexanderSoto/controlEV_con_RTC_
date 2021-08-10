#include "RTC_EXPORT.h"

#define valve1 8 
#define valve2 7
#define interval 2 // intervlao de riego , 1 es por hora , 2 es media hora etc...

void setup() {
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
  pinMode(valve1,OUTPUT);
  pinMode(valve2,OUTPUT);
 INICIAR_MODULO ();
}

void loop() {
  // put your main code here, to run repeatedly:
int Hour = GET_HOUR();



}

void ControlValve(hour){
float timeA = hour + (1/interval);


}
}
