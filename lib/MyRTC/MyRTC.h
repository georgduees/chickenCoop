/**
 * MyRTC
 * Klasse fuer den Zugriff auf die DS1307/DS3231 Echtzeituhr.
 *
 * @mc       Arduino/RBBB
 * @autor    Christian Aschoff / caschoff _AT_ mac _DOT_ com
 * @version  2.1
 * @created  1.3.2011
 * @updated  16.2.2015
 *
 * Versionshistorie:
 * V 1.1:  - dayOfMonth nach date umbenannt.
 * V 1.2:  - Kompatibilitaet zu Arduino-IDE 1.0 hergestellt.
 * V 1.3:  - getMinutesOfDay eingefuehrt.
 * V 1.4:  - getMinutesOf12HoursDay eingefuehrt.
 * V 1.5:  - Optimierung hinsichtlich Speicherbedarf.
 * V 1.6:  - Verbessertes Debugging.
 * V 1.7:  - Multi-MCU-Faehigkeit hinzugefuegt.
 * V 1.8:  - Auslesen verbessert. Falls die angeforderten 7 Bytes nicht kommen, verwerfen und neu anfordern.
 * V 1.9:  - Macro zum Stellen der Uhr durch die Compile-Zeit von Kee-Labs geklaut und hier eingefuegt.
 * V 2.0:  - DS1307 nach MyRTC umbenannt, weil es jetzt nicht mehr nur um die DS1307 geht.
 *         - Getrennte Logik fuer das Rachtencksignal (SQW) eingefuehrt, danke an Erich M.
 * V 2.1:  - Unterstuetzung fuer die alte Arduino-IDE (bis 1.0.6) entfernt.
 */
#ifndef MYRTC_H
#define MYRTC_H

#include "Arduino.h"

class MyRTC {
public:
    MyRTC(int address);
    void readTime();
    void writeTime();

    void enableSQWOnDS1307();
    void enableSQWOnDS3231();

    void set(const char* date, const char* time);
    void setSeconds(byte seconds);
    void setMinutes(byte minutes);
    void incMinutes();
    void setHours(byte hours);
    void incHours();
    void setDayOfWeek(byte dayOfWeek);
    void setDate(byte date);
    void setMonth(byte month);
    void setYear(byte year);

    byte getSeconds();
    byte getMinutes();
    unsigned int getMinutesOfDay();
    unsigned int getMinutesOf12HoursDay();
    byte getHours();
    byte getDayOfWeek();
    byte getDate();
    byte getMonth();
    byte getYear();

private:
    int _address;

    byte _seconds;
    byte _minutes;
    byte _hours;
    byte _dayOfWeek;
    byte _date;
    byte _month;
    byte _year;

    byte decToBcd(byte val);
    byte bcdToDec(byte val);
    uint8_t conv2d(const char* p);
};

#endif
