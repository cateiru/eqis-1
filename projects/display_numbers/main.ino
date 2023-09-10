#include <Arduino.h>
#include <SoftwareSerial.h>

void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println("Nya");
    delay(2000);
}
