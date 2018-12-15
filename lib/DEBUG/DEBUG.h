/*
 * @Author: georg.duees 
 * @Date: 2018-12-14 20:32:20 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2018-12-14 20:32:57
 */


#ifdef DEBUG
    #define DEBUG_PRINT(x) Serial.print(x)
    #define DEBUG_PRINT2(x, y) Serial.print(x, y)
    #define DEBUG_PRINTLN(x) Serial.println(x)
    #define DEBUG_PRINTLN2(x, y) Serial.println(x, y)
    #define DEBUG_FLUSH() Serial.flush()
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_PRINT2(x, y)
    #define DEBUG_PRINTLN(x)
    #define DEBUG_PRINTLN2(x, y)
    #define DEBUG_FLUSH()
#endif
