/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 11:56:45 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 20:46:17
 * Inspired by Christian Aschoff / caschoff _AT_ mac _DOT_ com Qlockthree*/
#include "LDR.h"

#include "DEBUG.h"
 //#define DEBUG

/**
 * Initialisierung mit dem Pin, an dem der LDR haengt
 */

LDR::LDR(byte pin,bool inverted ) {
  _pin = pin;
  _meanpointer = 0;
#ifdef LDR_AUTOSCALE
  _min = 1023;
  _max = 0;
#else
  _min = 0;
  _max = 1023;
#endif
_inverted=inverted;

}
/*
 * Welchen Wert hat der LDR?
 */
int LDR::value() {
       int val = analogRead(_pin);
    if(_inverted){
    val = 1023-val;
    }
  // glaetten
  _meanvalues[_meanpointer] = val;
  _meanpointer++;
  if(_meanpointer == LDR_MEAN) {
    _meanpointer = 0;
  }
  long ret = 0;
  for(int i=0; i<LDR_MEAN; i++) {
    ret += _meanvalues[i];
  }
  return ret/LDR_MEAN;
}
/**
 * Welche Helligkeit haben wir?
 */
int LDR::brightness() {
  int val = value();
#ifdef LDR_AUTOSCALE
    if(val < _min) {
      _min = val;
    }
    if(val > _max) {
      _max = val;
    }
#else
  val = constrain(val, _min, _max);
#endif
  int b = map(val, _min, _max, MAX_BRIGHTNESS, 1);

    DEBUG_PRINT(F(" _inverted: "));
    DEBUG_PRINT(_inverted);
    DEBUG_PRINT(F(" _min: "));
    DEBUG_PRINT(_min);
    DEBUG_PRINT(F(" _max: "));
    DEBUG_PRINT(_max);
    DEBUG_PRINT(F(" ldr: "));
    DEBUG_PRINT(val);
    DEBUG_PRINT(F(" brightness: "));
    DEBUG_PRINTLN(b);

  return b;
}

