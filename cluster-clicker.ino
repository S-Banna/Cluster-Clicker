#include <Servo.h>

const int ledPin = 13;
bool ledState = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    Serial.begin(9600);
    delay(500);
}

void loop() {
    if (Serial.available()) {
        char c = Serial.read();

        if (c == 'T') {
            ledState = !ledState;
            digitalWrite(ledPin, ledState ? HIGH : LOW);
        }
    }
}