#include "Arduino.h"
#include "InterfaceBoard.h"
#include "SoftwareSerial.h"

InterfaceBoard::InterfaceBoard(int rx, int tx): _SoftSerial(rx, tx) {
    _SoftSerial.begin(9600);
    i = 0;
    inputString = "";
    stringComplete = false;
    postIndex = 0;
}

void InterfaceBoard::post(String str, float* ptr) {
    s[postIndex] = str;
    p[postIndex] = ptr;
    postIndex++;
}

void InterfaceBoard::synchronize() {
    serialMessage();
    if (stringComplete) {
        for (i = 0; i < postIndex; i++) {
            if (inputString.indexOf('=') == -1) {
                if (s[i].equalsIgnoreCase(inputString.substring(2,inputString.indexOf('>')))) {
                    _SoftSerial.println(*p[i]);
                }
            } else {
                if (s[i].equalsIgnoreCase(inputString.substring(2,inputString.indexOf('=')))) {
                    *p[i] = inputString.substring(inputString.indexOf('=')+1,inputString.indexOf('>')).toFloat();
                    _SoftSerial.println(*p[i]);
                }
            }
        }
        inputString = "";
        stringComplete = false;
    }
}

void InterfaceBoard::serialMessage() {
    while (_SoftSerial.available() && !stringComplete) {
        char inChar = (char) _SoftSerial.read();
        inputString += inChar;
        if (inChar == '>') {
            stringComplete = true;
        }
    }
}
