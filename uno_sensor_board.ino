#include <SoftwareSerial.h>
#include "InterfaceBoard.h"

#define humidityPin A0

InterfaceBoard pi(2, 3);

/*

*/

void setup() {
    Serial.begin(9600);
}

void loop() {
    pi.synchronize();
}
