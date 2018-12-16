/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 23:01:11 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-16 01:08:56
 */


#include "DOORSENSOR.h"

#define DEBUG

#include "DEBUG.h"

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

DoorSensor::DoorSensor(byte switchPin1,byte switchPin2,bool inverted=false){
    _switchPin1=switchPin1;
    _switchPin2=switchPin2;
    _state=UNKNOWN;
    _inverted=inverted;
    _prevState=-1;
    pinMode(_switchPin1, INPUT);
    pinMode(_switchPin2, INPUT);
   
}

DoorSensor::State DoorSensor::Value(void){
  return _state;
}
void DoorSensor::service(void){
    int curStatus=0;

    if(digitalRead(_switchPin1)&& !_inverted){
        curStatus=curStatus+SWITCH1;

    }
    if(digitalRead(_switchPin2)&&!_inverted){
       curStatus=curStatus+SWITCH2;
    }
       

  /*  if(CHECK_BIT(curStatus,UPPERLIMIT)){
        curStatus=OPEN;
    }*/
    if(_prevState!=curStatus){
    _state=static_cast<State>(curStatus);
    _prevState=curStatus; 

    }



}
