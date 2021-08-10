  #include "RTC_EXPORT.h"
  
  #define valve1 8 
  #define valve2 7
  
  int h_anterior = 1;//GET_HOUR();
  int h_actual ;
  
  void setup() {
      Serial.begin(9600); 
      Serial.println("serial init");// inicializa comunicacion serie a 9600 bps
      pinMode(valve1,OUTPUT);
      pinMode(valve2,OUTPUT);
      INICIAR_MODULO ();
  }
  
  void loop() {
      Serial.println("estoy en loop2");
    //ControlValve();
    
    
    delay(1000);
  }
  
  void ControlValve(){
     h_actual = GET_HOUR();
     
    if(h_actual != h_anterior){
    // TODO: encender valvular por un intervalo de tiempo 
    h_anterior = h_actual;
    }
    
  }
