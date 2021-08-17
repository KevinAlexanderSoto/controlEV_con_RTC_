  
  #include "DHT11_EXPORT.h";
  #include "RTC_EXPORT.h";
  
  
  #define valve1 8 
  #define valve2 7

  int h_activado  ;
  int h_actual ;

  int intervalo_Activado = 2;//brecha de activacion de las valvulas
  
  void setup() {
      Serial.begin(9600); 
      Serial.println("serial init");// inicializa comunicacion serie a 9600 bps
      pinMode(valve1,OUTPUT);
      pinMode(valve2,OUTPUT);
      INICIAR_MODULO ();// inicia el RTC con fecha de compilacion y setea otras opciones
      INICIAR_MODULO_DHT();
      h_activado = GET_MINUTE()+ intervalo_Activado;
  }
  void loop() {
    ControlValve();
    Serial.print("MINUTO:");
    Serial.println(GET_MINUTE());
    delay(100);
    Serial.print("TEMPERATURA:");
    Serial.println( GET_RTCTEMPERATURE());

  Serial.print("HUMIDITY:");
    Serial.println( GET_HUMIDITY());
    Serial.println( "...........................");
    

    delay(5000);
  }
  
  void ControlValve(){
    
    if(h_activado > 60){// para caso especial de usar minutos, con hora es 24
      h_activado = h_activado - 60;
      }
      
     h_actual = GET_MINUTE();
     
    if(h_actual >= h_activado){
    Serial.println("VALVE1 ON");
    digitalWrite(valve1, HIGH);
  
    int timeOff = 1 + GET_MINUTE();// le sumamos la cantidad de tiempo que va a estar prendido
    
    if(timeOff > 60){// para caso especial de usar minutos 
      timeOff = timeOff - 60;
      }
      
    while(timeOff != GET_MINUTE()){
       delay(5000);  
      };
   
    digitalWrite(valve1, LOW);
    Serial.println("VALVE1 OFF");

    // TODO: activar segunda salida "valve2"
    
    h_activado = GET_MINUTE()+ intervalo_Activado;// para volver a comparar y hacer el ciclo 
    }
    
  }
