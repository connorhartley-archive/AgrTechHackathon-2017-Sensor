#include <SoftwareSerial.h>
#include "InterfaceBoard.h"

// Sensors

#define humidityPin A4

// LED

#define statusLight 13
#define scanningLight 12

InterfaceBoard pi(0, 1);

float statusMode = 1, scanningMode = 0, temperature;

void setup() {
    Serial.begin(9600);
    Serial.println("Initializing SensorBoard.");

    pinMode(statusLight, OUTPUT);
    pinMode(scanningLight, OUTPUT);

    // TODO: Next stuff.
}

void loop() {
    pi.synchronize();
}
