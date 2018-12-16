/*
 * @Author: georg.duees 
 * @Date: 2018-12-16 01:35:25 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-16 01:44:39
 */

#ifndef LCD_H
#define LCD_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <LiquidCrystal_I2C.h>

class LCD {
public:
  LCD(byte i2cAdress,int rowCount,int charCount);
  //TODO: ADD FUNCTIONS AND DETERMITE USED FUNCTIONS

  //TODO: CREATE TEMPERATURE HELPER LIBRARY TO READ OUT TEMPERATURE AND GATHER THAT DATA REGULARLY

  //TODO: CREATE LCD LIBRARY TO CREATE VIEWS
  
  //TODO: SETTINGSLOAD AND SAVE FROM EEPROM

  //TODO: CHANGE SETTINGS FROM MENU/LCD DISPLAY MODE.

  //TODO: CALCULATE SUNRISE AND SUNDOWN
  
  //TODO: REMOTE_CONTROL VIA GRPC/PJON
  
  //TODO: UPDATE FIRMWARE VIA RASPBERRY PI
private:
  LiquidCrystal_I2C _lcd;
  int _i2cAdress; 
  byte _clockPin;
  int _rowCount;
  int _charCount;
 int _timeOut;
};
#endif