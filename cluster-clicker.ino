#include <Servo.h>

const int LED_PIN = 13;
bool busy = false;

const int SERVO_PIN = 9;
const int SERVO_MIN = 10;
const int SERVO_MAX = 160;

const int SWEEP_DELAY = 200;
const int COOLDOWN_DELAY = 200;

Servo finger;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    finger.attach(SERVO_PIN);
    finger.write(SERVO_MIN);

    Serial.begin(9600);
    delay(500);
}

void loop() {
    if (Serial.available() && !busy) {
        char c = Serial.read();

        if (c == 'T') {
            spin();
        }
    }
}

void spin() {
    busy = true;

    digitalWrite(LED_PIN, HIGH);
    finger.write(SERVO_MAX);
    delay(SWEEP_DELAY);

    finger.write(SERVO_MIN);
    delay(SWEEP_DELAY);

    digitalWrite(LED_PIN, LOW);
    delay(COOLDOWN_DELAY);

    while (Serial.available()) {
        Serial.read();
    }

    busy = false;
    delay(50);
}