/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 22:50:15 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-16 00:29:07
 */

#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#define UPPER_SWITCH_PIN 8
class DoorSensor {
public:
    typedef enum  State {
    UNKNOWN=0,
    SWITCH1=1,
    SWITCH2=2,
    CLOSED=3
    }State;
    
public:
  DoorSensor(byte switchPin1,byte switchPin2, bool inverted);
  State Value(void);
  void service(void);
  
//ENUM FOR STATUS
    // ENUM FUNCTION STATE
private:
    byte _switchPin1;
    byte _switchPin2;
    int _prevState;
    State _state;
    bool _inverted;
};
#endif