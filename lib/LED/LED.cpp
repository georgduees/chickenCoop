/*
 * @Author: georg.duees 
 * @Date: 2018-12-15 20:58:19 
 * @Last Modified by: georg.duees
 * @Last Modified time: 2018-12-16 01:04:40
 */

#include "LED.h"
#include "FastLED.h"

#define DEBUG

#include "DEBUG.h"

#define LED_TYPE APA102
//#define LED_TYPE_WS2812
#define LED_NUM 1
#define LED_BLINKDURATION 500
#define LED_COLORPROFILE BGR
#define PIN_LED_DATA 10
#define PIN_LED_CLK 13


LED::LED(ESPIChipsets type,int dataPin,int clockPin,EOrder colorProfile){

    FastLED.addLeds<LED_TYPE, PIN_LED_DATA, PIN_LED_CLK, LED_COLORPROFILE>(leds,LED_NUM);
}
void LED::blink(int times=1){
    LED::blink(times,CRGB::Green);
}
void LED::blink( int times=1,CRGB color=CRGB::Green) {
    unsigned long currentMillis = millis();
    unsigned long previousMillis =0;
    bool ledState=true;
    times=times*2;
        while(times>0){
            currentMillis = millis();
            if (currentMillis - previousMillis > LED_BLINKDURATION) {
                previousMillis = currentMillis;
                leds[0]=ledState?color:CRGB::Black;
                FastLED.show();
                ledState=!ledState;
                if(times==1){
                    delay(LED_BLINKDURATION);
                }
                times--;
            }
        }
}
void LED::show(CRGB color,int brightness,int duration){
    FastLED.clearData();
    unsigned long startMillis =0;
    startMillis=millis();
    do
    {
        leds[0]=color;
        FastLED.setBrightness(brightness);
        FastLED.show();
        /* code */
    } while (millis()<=startMillis+duration);
    LED::off();
}
void LED::off(){
    leds[0]=CRGB::Black;
    FastLED.clearData();
    FastLED.show();
}