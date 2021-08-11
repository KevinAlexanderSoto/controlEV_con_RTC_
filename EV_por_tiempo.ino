  #include "RTC_EXPORT.h"
  
  #define valve1 8 
  #define valve2 7

  int h_anterior ;
  int h_actual ;
  
  void setup() {
      Serial.begin(9600); 
      Serial.println("serial init");// inicializa comunicacion serie a 9600 bps
      pinMode(valve1,OUTPUT);
      pinMode(valve2,OUTPUT);
      INICIAR_MODULO ();
       h_anterior = GET_HOUR();
  }
  
  void loop() {
    ControlValve();

    delay(2000);
  }
  
  void ControlValve(){
     h_actual = GET_HOUR();
     
    if(h_actual != h_anterior){
    Serial.println("bomba  ENCENDIDO");
    delay(3000);
    h_anterior = h_actual;
    }
    
  }
