#ifndef InterfaceBoard_h
#define InterfaceBoard_h
#include "Arduino.h"
#include <SoftwareSerial.h>

class InterfaceBoard {
  public:
    InterfaceBoard(int rx, int tx);
    void post(String str, float* ptr);
    void synchronize();
    void serialMessage();
  private:
    float *p[20];
    String s[20];
    String inputString;
    boolean stringComplete;
    int i;
    byte postIndex;
    SoftwareSerial _SoftSerial;
};
#endif
