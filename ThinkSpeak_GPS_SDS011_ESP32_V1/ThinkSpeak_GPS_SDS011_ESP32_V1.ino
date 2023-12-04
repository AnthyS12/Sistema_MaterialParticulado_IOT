#include <SDS011.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

//------------------------Datos Wifi Coneccion------------------------
const char* ssid = "Tu Wifi";          // Nombre de la red Wi-Fi
const char* password = "Tu Password";     // Contraseña la red Wi-Fi
const char* server = "api.thingspeak.com"; // Server del ThingSpeak
WiFiClient client;                         // Inicialización del Wifi 

//------------------------LEDS------------------------
int ledPinVerde = 2;  // LED verde
int ledPinAzul = 4;  // LED azul

//RGB
#define PIN_RED    23 // GPIO23
#define PIN_GREEN  22 // GPIO22
#define PIN_BLUE   21 // GPIO21

TinyGPSPlus gps;// Inicializa el objeto GPS
SDS011 my_sds;// Inicializa el objeto SDS011

//---------Variable para almacenar la API Key de ThingSpeak----------------------------------------
const char* myWriteAPIKey = "y6y6y6y6yy6";   // Cambia "myWriteAPIKey" con tu propia API Key
unsigned long myChannelNumber = 60000000;   // Cambia "myChannelNumber" con tu propia CHANNEL_ID

void setup() {
  my_sds.begin(3,4); // Usa los pines 3 (RX0) y 1 (TX0) en forma inversa
  Serial.begin(9600);// Inicializa la comunicación con el GPS a 9600 baudios
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Usa los pines16 (RX2) y 17 (TX2) en forma inversa
   
   // Inicializa el LED como una salida
  pinMode(ledPinVerde, OUTPUT);
  pinMode(ledPinAzul, OUTPUT);

  //LEd RGB
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  
  //----------------Conexion a Wifi y thingSpeak-------------------
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
    digitalWrite(ledPinVerde, LOW);  // Enciende el LED verde
  }
  digitalWrite(ledPinVerde, HIGH);  // Enciende el LED verde
  Serial.println("Conexión Wi-Fi establecida");
  Serial.println("**********************************************************");
  ThingSpeak.begin(client);
}

void loop() {
  digitalWrite(ledPinAzul, LOW);
  delay(5000); // Espera 5 segundo para que el sensor se estabilice
  
  //Se mantienen detro de un if ambos datos para evitar los datos vacíos
  //-------------------------GPS-------------------------------
  // Lee los datos del GPS
  while (Serial2.available() > 0){
    gps.encode(Serial2.read());
      if (gps.location.isUpdated()){
        // Obtener latitud y longitud
        float lat = gps.location.lat();
        float lon = gps.location.lng();
        float sat = gps.satellites.value();  //Satelites en uso
        
        // Imprimir los datos del GPS
        Serial.print("Satellites en uso = "); 
        Serial.println(sat);
        Serial.print("Latitud: ");
        Serial.println(lat, 7);
        Serial.print("Longitud: ");
        Serial.println(lon, 7);
        Serial.println("");
        
        //-------------------------------SDS011-----------------------------------
        float p10,p25;
        int error;
        error = my_sds.read(&p25,&p10);
        if (! error) {
          Serial.println("P2.5: "+String(p25));
          Serial.println("P10:  "+String(p10));
          Serial.println();
          Serial.println("---------------------------------");

          //------------------------Colores LED RGB MP---------------------

            if (p10 >= 0 && p10 <= 50) {
              // Verde rgb(0, 128, 0)
              analogWrite(PIN_RED,   0);
              analogWrite(PIN_GREEN, 128);
              analogWrite(PIN_BLUE,  0);
            } else if (p10 > 50 && p10 <= 100) {
              // Amarillo rgb(255, 255, 0)
              analogWrite(PIN_RED,   255);
              analogWrite(PIN_GREEN, 255);
              analogWrite(PIN_BLUE,  0);
            } else if (p10 > 100 && p10 <= 150) {
              // Morado rgb(255, 0, 255)
              analogWrite(PIN_RED,   255);
              analogWrite(PIN_GREEN, 0);
              analogWrite(PIN_BLUE,  255);
            } else if (p10 > 150){
              // Rojo  rgb(255, 0, 0)
              analogWrite(PIN_RED,   255);
              analogWrite(PIN_GREEN, 0);
              analogWrite(PIN_BLUE,  0);
            }

          //------------------------Enviar datos a ThingSpeak---------------------
          ThingSpeak.setField(1, p25);
          ThingSpeak.setField(2, p10);
          ThingSpeak.setField(3, lat);
          ThingSpeak.setField(4, lon);
          int httpCode = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
          
          if (httpCode == 200) {
            Serial.println("Datos enviados a ThingSpeak correctamente");
            Serial.println("---------------------------------");
            // Enciende el LED
            digitalWrite(ledPinAzul, HIGH);
            delay(1000);  // Espera 1 segundo (1000 milisegundos)

            // Apaga el LED
            digitalWrite(ledPinAzul, LOW);
            delay(1000);  // Espera 1 segundo (1000 milisegundos)
          } else {
            digitalWrite(ledPinAzul, LOW);
            Serial.println("Error al enviar los datos a ThingSpeak");
            Serial.println("ProblemHTTP error code " + String(httpCode));
            Serial.println("---------------------------------");
          }

        }
      delay(15000); // Esperar 15 segundo antes de volver a leer los datos      
    }
  } 
}