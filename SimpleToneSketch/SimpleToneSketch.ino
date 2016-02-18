//This will create a simple chirper that plays tones when told to by the iOS app.
//Successfully works with the app build on Feb 18 2016

//Includes
#include <SoftwareSerial.h>

//Globals
int Buzzer = 10;
int LED = 13;
unsigned int buzzTimer = 0;
SoftwareSerial BLE_Shield(4,5);

void setup() {
  pinMode(Buzzer, OUTPUT);  //Sets the pin to be an output pin
  pinMode(LED, OUTPUT);
  BLE_Shield.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (BLE_Shield.available())   //Meaning there is data available for us to look at.
  {
    Serial.println(BLE_Shield.read());
    buzzTimer = millis();
    tone(Buzzer, 500);      //Turn the buzzer and the LED on
    digitalWrite(LED, HIGH);
  }
  if ((millis() - buzzTimer) >= 1000) {    //After a second, turn everything off
    noTone(Buzzer);
    digitalWrite(LED, LOW);
  }
}

