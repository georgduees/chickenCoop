/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 11:56:25 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-15 20:45:40
 * Inspired by Christian Aschoff / caschoff _AT_ mac _DOT_ com Qlockthree
 */
#ifndef LDR_H
#define LDR_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define LDR_AUTOSCALE

/**
 * Die maximale Helligkeit (default = 9)
 */
#define MAX_BRIGHTNESS 100
/**
 * Die Menge der Werte fuer die Glaettung. Mehr Werte bringen bessere Ergebnisse aber
 * brauchen auch mehr Zeit. (Gleitender Mittelwert)
 */
#define LDR_MEAN 64

class LDR {
public:
  LDR(byte pin,bool inverted);

  int value();
  int brightness();

private:
  byte _pin;
  int _meanvalues[LDR_MEAN];
  byte _meanpointer;
  bool _inverted;
  /**
   * Die Maximalwerte vom LDR. Ueber den Messwert vom
   * LDR und diesen Grenzen wird die Helligkeit bestimmt.
   * Idealerweise misst man einmal im #define-DEBUG-Mode
   * die Grenzen aus.
   * Oder man verwendet das #define-LDR_AUTOSCALE-Feature.
   */
  int _min;
  int _max;
};

#endif