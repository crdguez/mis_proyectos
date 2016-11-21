#include <NewPing.h>

    char val;
    int ledPin13 = 13;
    int cm;
    #define limite_cm 5
    #define TRIGGER_PIN  12
    #define ECHO_PIN     11
    #define MAX_DISTANCE 200
     
    NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     


void setup() { 
//Serial.begin(57600); // Aqui establecemos la velocidad
Serial.begin(9600); // Aqui establecemos la velocidad
pinMode(ledPin13, OUTPUT); 
}

void loop() { 

          



if( Serial.available() ){
  val = Serial.read();
    Serial.write(val);
   }
else val = '0';

 
if( val == '2' )
          { 
          digitalWrite(ledPin13, LOW);
          
          }
          
else if( val == '3' )
          { 
          digitalWrite(ledPin13, HIGH);
          }
else
          {
                      cm=sonar.ping_cm();
          //Serial.print(sonar.ping_cm());
          //Serial.println();
            
          
          if(cm < limite_cm && cm > 0) {
            digitalWrite(ledPin13, HIGH);
         
            }
          
          else {
            digitalWrite(ledPin13, LOW);
            
            }
            
          } 
}
