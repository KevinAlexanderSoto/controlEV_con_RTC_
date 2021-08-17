#include<Arduino.h>
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#define DHTTYPE DHT11 



void INICIAR_MODULO_DHT(){
    DHT dht(DHTPIN, DHTTYPE);
    dht.begin();
    Serial.println(F("DHTxx test!"));

}

float GET_HUMIDITY(){
    return dht.readHumidity();
}