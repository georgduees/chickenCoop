/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 12:58:46 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 20:31:07
 */
#include "ENCODER.h"

#define DEBUG

#include "DEBUG.h"

 const int8_t Encoder::_table[16] __attribute__((__progmem__)) = { 
       0, 1, -1, 0, -1, 0, 0, 1, 1, 0, 0, -1, 0, -1, 1, 0 
     };   
Encoder::Encoder(byte pinA,byte pinB,byte buttonPin,int steps,bool inverted=false):_delta(0){
    _pinA=pinA;
    _pinB=pinB;
    _buttonPin=buttonPin;
    _state=UNKNOWN;
    _steps=steps;
    _inverted=inverted;
   _last=0;
    uint8_t configType = (inverted == LOW) ? INPUT_PULLUP : INPUT;

     pinMode(_pinA, configType);
  pinMode(_pinB, configType);
  pinMode(_buttonPin, configType);
    if (digitalRead(pinA) == _inverted) {
    _last = 3;
  }

  if (digitalRead(pinB) == _inverted) {
    _last ^=1;
  }

}
Encoder::State Encoder::Value(void){

  Encoder::State ret = _state;
  if (_state ==0) {
    _state = UNKNOWN; // reset
  }
  return ret;
}
void Encoder::ResetState(void){
    _state=UNKNOWN;

}
void Encoder::service (void){

  bool moved = false;
  unsigned long now = millis();
//default enc
 int8_t curr = 0;

  if (digitalRead(_pinA) == _inverted) {
    curr = 3;
  }

  if (digitalRead(_pinB) == _inverted) {
    curr ^= 1;
  }
  
  int8_t diff = _last - curr;

  if (diff & 1) {            // bit 0 = step
    _last = curr;
    _delta += (diff & 2) - 1; // bit 1 = direction (+/-)
    moved = true;    
  }

    static uint16_t keyDownTicks = 0;
  static uint8_t doubleClickTicks = 0;
  static unsigned long lastButtonCheck = 0;

  //
if(_buttonPin>0&&(now-lastButtonCheck)>=BUTTONINTERVAL){
    //check button logic if button exists and lastButtonCheck is older than the Interval
//set the button check to NOW
lastButtonCheck=now;


 if (digitalRead(_buttonPin) == !_inverted) { // key is down

      keyDownTicks++;
      if (keyDownTicks > ( HOLDTIME/BUTTONINTERVAL)) {
        _state = HOLD;
      }
     


    }


//doubleclickCheck
    if (digitalRead(_buttonPin) == _inverted) { // key is now up
    if (keyDownTicks > BUTTONINTERVAL) {
        if (_state == HOLD) {
          _state = UNKNOWN;
          doubleClickTicks = 0;
        }
        else {
            if(doubleClickTicks>1){
 if (doubleClickTicks < (DOUBLECLICKTIME / BUTTONINTERVAL)) {
              _state = DOUBLECLICK;
              doubleClickTicks = 0;
            }
            }else{
            doubleClickTicks =  (DOUBLECLICKTIME / BUTTONINTERVAL) ;
            }
        }
      }
keyDownTicks = 0;
    }
   if (doubleClickTicks > 0) {
      doubleClickTicks--;
      if (--doubleClickTicks == 0) {
        _state = CLICK;
      }
    }

}

    //calculate status
  int16_t val;

val=_delta;
if (_steps == 2) _delta = val & 1;
  else if (_steps == 4) _delta = val & 3;
  else _delta = 0; // default to 1 step per notch
 

  if (_steps == 4) val >>= 2;
  if (_steps == 2) val >>= 1;

  int16_t r = 0;
    int16_t accel =  0;
if (val < 0) {
    r -= 1 + accel;
  }
  else if (val > 0) {
    r += 1 + accel;
  }
 
 switch (r)
 {
     case -1:
         _state=LEFT;
         break;
      case 1:
         _state=RIGHT;
         break;
     default:
         break;
 }



  }


   
  



