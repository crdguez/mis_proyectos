char val;

int ledPin13 = 13;

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

 
if( val == '2' )
{ 
digitalWrite(ledPin13, LOW);
}

if( val == '3' )
{ 
digitalWrite(ledPin13, HIGH);
} 
}

