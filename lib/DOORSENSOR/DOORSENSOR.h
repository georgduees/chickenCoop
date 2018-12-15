/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 22:50:15 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 22:55:51
 */

#ifndef DOORSENSOR_H
#define DOORSENSOR_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif


class DoorSensor {
public:
  DoorSensor(byte switchPin1,byte switchPin2);
  void service(void);
//ENUM FOR STATUS
    // ENUM FUNCTION STATE
private:
  byte _switchPin1;
 byte _switchPin2;


};
#endif