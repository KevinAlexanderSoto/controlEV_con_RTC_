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
      INICIAR_MODULO ();// inicia el RTC con fecha de compilacion y setea otras opciones 
       h_anterior = GET_HOUR();
  }
  
  void loop() {
    ControlValve();
    Serial.print("MINUTO:");
    Serial.println(GET_HOUR());
    delay(100);
    Serial.print("TEMPERATURA:");
    Serial.println( GET_TEMPERATURE());
    Serial.println( "...........................");

    delay(5000);
  }
  
  void ControlValve(){
     h_actual = GET_HOUR();
     
    if(h_actual != h_anterior){
    Serial.println("LED ENCENDIDO");
    digitalWrite(valve1, HIGH);
    delay(5000);
    digitalWrite(valve1, LOW);
    Serial.println("LED APAGADO");
    h_anterior = h_actual;
    }
    
  }
