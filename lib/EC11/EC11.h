/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 11:56:25 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 14:37:29
 * Inspired by Christian Aschoff / caschoff _AT_ mac _DOT_ com Qlockthree
 */
#ifndef EC11_H
#define EC11_H

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

  
class EC11 {
public:
    typedef enum  EC11_STATE_e {
        unknown=0,
        left,
        right,
        click,
        doubleclick,
        hold
    } EC11_STATE;
public:
    EC11(byte pinA,byte pinB,byte buttonPin);
public:
    EC11_STATE value(void);
private:
    byte _pinA;
    byte _pinB;
    byte _buttonPin;
    int _debounceTime;
};

#endif