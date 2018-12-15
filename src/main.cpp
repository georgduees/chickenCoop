#include <Arduino.h>
#include <Wire.h> 


#include "DS1307.h"
#include "MyRTC.h"
#include "LDR.h"


// enable DEBUG OUTPUT RETURNS MORE VERBOSE OUTPUTS
#define DEBUG

#include "DEBUG.h"
// Die Geschwindigkeit der seriellen Schnittstelle. Default: 57600. Die Geschwindigkeit brauchen wir immer,
// da auch ohne DEBUG Meldungen ausgegeben werden!
#define SERIAL_SPEED 9600
//Einstellungen
//Settings: Einstellungen zum Typ der  verwendeten Hardware
//type of LED attached
#define LED_TYPE_APA102
//#define LED_TYPE_WS2812
#define LED_NUM 1
// RTC Module I2C Adress
#define I2C_RTC 0x68
// LCD Module Adress
#define I2C_LCD 0x27
//LCD Module number of rows
#define LCD_ROW 4
//LCD Module number of characters per line
#define LCD_CHARACTER 20
//Define if LCD supports lcd.backlight() code from liquidcrystal library
#define LCD_BACKLIGHT 
// If Backlight is supported in code.
//define LCD_NOBACKLIGHT
// Set Timeout for Backlight to Turn off after X Seconds (Default 30)
#define LCD_TIMEOUT 30
// ACTIVATE LDR
#define ENABLE_LDR
// INVERT THE LDR SIGNAL
#define LDR_INVERTED true


//Set Up Onewire Temperature Sensor adresses:
#define ONEWIRE_TEMP1 {0x28 ,0x78,0x1E,0x75,0x32,0x14,0x01,0xC8}
#define ONEWIRE_TEMP2 {0x28, 0xAA, 0xE9, 0xA4, 0x1D, 0x13, 0x02, 0x5C}
/* Set the resolution of the Temperature readings, keep in mind that lower resolutions means faster readings.
   As this is supposed to control a chickenscoop and a 'average' temperature is sufficient we opt for a 10bit temperature resoluition.

    9 bit : 0.5°c
    10 bit : 0.25°c
    11 bit : 0.125°c
    12 bit : 0.0625°c
*/
#define ONEWIRE_RESOLUTION 10

//PIN_Layout: Pinmapping auf dem Arduino
//Onewire Device Pin
#define PIN_ONEWIRE D2
//Rotary Encoder Pins Ec11 encoder with Pushbutton, Pushbutton is C, A und B fuer Rotation \o/ Erdrotation, wer braucht die schon?!?
#define PIN_ENC1_A 7
#define PIN_ENC1_B 6
#define PIN_ENC1_C 5

//REED SWITCH PINS
#define PIN_REED_1 8
#define PIN_REED_2 9
// LED STRIP PINOUT
#define PIN_LED_DATA D10
#define PIN_LED_CLK D13
// MOTOR PINS A1 und A2 
#define PIN_MOTOR_A1 D11
#define PIN_MOTOR_A2 D12

// SDA und SCL Pin fuer RTC und LCD.
#define PIN_SDA A4
#define PIN_SCL A5
// Input Pin fuer den LDR zur Bestimmung der Helligkeit.
#define PIN_LDR A7


//TIME DEFINITION
/**
 * Die Real-Time-Clock mit der Status-LED fuer das SQW-Signal.
 */
MyRTC rtc(I2C_RTC);
byte helperSeconds;

    /**
 * Der Helligkeitssensor
 */
LDR ldr(PIN_LDR,LDR_INVERTED);
unsigned long lastBrightnessCheck;

//HELPER FUNCTIONS

//helper functions
/**
 * Den freien Specher abschaetzen.
 * Kopiert von: http://playground.arduino.cc/Code/AvailableMemory
 */
  int freeRam() {
      extern int __heap_start, *__brkval;
      int v;
      return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
  }
void setup() {
    Serial.begin(SERIAL_SPEED);

    // Set Timeout of 50ms for Serial.parseInt()
    Serial.setTimeout(50);
    DEBUG_PRINTLN(F("chickenCoop is initializing..."));
    DEBUG_PRINTLN(F("... and starting in debug-mode..."));
    DEBUG_FLUSH();

  //load Settings from EEPROM.

    // starte Wire-Library als I2C-Bus Master
    Wire.begin();

    /*// RTC-Interrupt-Pin konfigurieren
    pinMode(PIN_SQW_SIGNAL, INPUT);
    digitalWrite(PIN_SQW_SIGNAL, HIGH);
  */
    DEBUG_PRINT(F("Compiled: "));
    DEBUG_PRINT(F(__TIME__));
    DEBUG_PRINT(F(" / "));
    DEBUG_PRINTLN(F(__DATE__));

    // RTC starten...
    rtc.readTime();




    rtc.writeTime();
    helperSeconds = rtc.getSeconds();
    DEBUG_PRINT(F("RTC-Time: "));
    DEBUG_PRINT(rtc.getHours());
    DEBUG_PRINT(F(":"));
    DEBUG_PRINT(rtc.getMinutes());
    DEBUG_PRINT(F(":"));
    DEBUG_PRINT(helperSeconds);
    DEBUG_PRINT(F(" RTC-Date: "));
    DEBUG_PRINT(rtc.getDate());
    DEBUG_PRINT(F("."));
    DEBUG_PRINT(rtc.getMonth());
    DEBUG_PRINT(F("."));
    DEBUG_PRINTLN(rtc.getYear());
  /*
    // Den Interrupt konfigurieren,
    // nicht mehr CHANGE, das sind 2 pro Sekunde,
    // RISING ist einer pro Sekunde, das reicht.
    // Auf FALLING geandert, das signalisiert
    // den Sekundenwechsel, Danke an Peter.
    attachInterrupt(0, updateFromRtc, FALLING);
  */
    // Werte vom LDR einlesen und vermuellen, da die ersten nichts taugen...
    for (int i = 0; i < 1000; i++) {
      analogRead(PIN_LDR);
    }

    // ein paar Infos ausgeben
    DEBUG_PRINTLN(F("... done and ready to rock!"));
    DEBUG_PRINT(F("Driver: "));
  // ledDriver.printSignature();

    DEBUG_PRINT(F("Free ram: "));
    DEBUG_PRINT(freeRam());
    DEBUG_PRINTLN(F(" bytes."));
    DEBUG_FLUSH();
DEBUG_PRINT(F("LDR Value: "));
    DEBUG_PRINTLN(ldr.value());
DEBUG_PRINT(F("LDR Brightness: "));
    DEBUG_PRINT(ldr.brightness());
    DEBUG_PRINT(F(" / "));
    DEBUG_PRINTLN(MAX_BRIGHTNESS);

    DEBUG_FLUSH();

}
void loop(){
DEBUG_PRINT(F("LDR Brightness: "));
    DEBUG_PRINT(ldr.brightness());
    DEBUG_PRINT(F(" / "));
    DEBUG_PRINTLN(MAX_BRIGHTNESS);
    DEBUG_FLUSH();
    delay(100);

}

