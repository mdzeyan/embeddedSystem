#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

char value;

void ledSelect(char value)
{
  switch(value)
  {
    case '0':
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      break;
      
    case '1':
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      break;
      
    case '2':
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      break;
      
    case '3':
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      break;
      
    default:
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
  }
}



void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {

  if (mySerial.available())
  {

//    value = Serial.read();
    value = mySerial.read();
    Serial.println(value);
    ledSelect(value);
    
  }

}
