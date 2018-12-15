/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 11:56:25 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 20:31:33
 * Inspired by Christian Aschoff / caschoff _AT_ mac _DOT_ com Qlockthree
 */
#ifndef ENCODER_H
#define ENCODER_H
#include <stdint.h>

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

/*
* differnt return values
* NOTHING 0, LEFT 1,RIGHT 2,CLICK 3, DOUBLECLICK 4,HOLD 8
*/
// Debounce time in ms
#define DEBOUNCE_TIME 50
// ----------------------------------------------------------------------------
// Button configuration (values for 1ms timer service calls)
//
#define BUTTONINTERVAL    10  // check button every x milliseconds, also debouce time
#define DOUBLECLICKTIME  600  // second click within 600ms
#define HOLDTIME 1200 // report held button after 1.2s

  
class Encoder {
public:
    typedef enum  State {
        UNKNOWN=0,
        LEFT,
        RIGHT,
        CLICK,
        DOUBLECLICK,
        HOLD
    }State;
public:
    Encoder(byte pinA,byte pinB,byte buttonPin,int steps=1,bool inverted=false);
    State Value(void);
    void ResetState(void);
    void service(void);
private:
    byte _pinA;
    byte _pinB;
    byte _buttonPin;
    int _steps;
    bool _inverted;
     volatile int16_t _last;
       static const int8_t _table[16];
         volatile int16_t _delta;
    State _state;
bool doubleClickEnabled;
};

#endif