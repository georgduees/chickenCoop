/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 12:58:46 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 14:38:43
 */
#include "EC11.h"
//#define DEBUG

EC11::EC11(byte pinA,byte pinB,byte buttonPin){
    _pinA=pinA;
    _pinB=pinB;
    _buttonPin=buttonPin;
    
    #ifdef DEBOUNCETIME
    _debounceTime= DEBOUNCE_TIME;
    #endif
    pinMode(_pinA,INPUT);
pinMode(_pinB,INPUT);
pinMode(_buttonPin,INPUT);
}
EC11::EC11_STATE EC11::value(){
    EC11_STATE retVal =left;

 return retVal;
}