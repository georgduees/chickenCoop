/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 20:49:01 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 22:37:51
 */
#ifndef LED_H
#define LED_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "FastLED.h"

class LED {
public:
  LED(ESPIChipsets type,int dataPin,int clockPin,EOrder colorProfile);

  void blink(int times,CRGB color);
    void blink(int times);

  void show(CRGB color,int brightness,int duration);
  void off();
 CRGB leds[1];
private:
  byte _dataPin;
 byte _clockPin;
  ESPIChipsets _type;
 EOrder _colorProfile;
 CRGB _color;

 int _brightness;
};
#endif