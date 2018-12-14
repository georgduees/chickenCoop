#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

float oldLDR,newLDR;
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
   lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
  // put your setup code here, to run once:
        lcd.print("23:09:37    07.12.18T2:21.3 CLOSE 22:00T1:17.4 OPEN  05:17LDR:12");

}
int readLDR(){
  int sensorValue =analogRead(A7);
  return sensorValue;
}

void loop() {
  // put your main code here, to run repeatedly:
   newLDR=readLDR();
if(newLDR!=oldLDR){
Serial.println("BRIGHTNESS");
Serial.println(map(newLDR,0,1023,0,100));
oldLDR=newLDR;
}
 // when characters arrive over the serial port...

  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
          lcd.clear();
          lcd.write(Serial.read());


    }
  }
delay(500); 
}

 