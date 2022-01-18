#ifndef CMD_RECEIVER_H
    #define CMD_RECEIVER_H
    #include "led.h"

    #ifdef __AVR__
        #include <avr/power.h>
    #endif

    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
    #if defined (__AVR_ATtiny85__)
        if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
    #endif

    bool read_code(String recv_code,Adafruit_NeoPixel *led_obj1, Adafruit_NeoPixel *led_obj2);

#endif
