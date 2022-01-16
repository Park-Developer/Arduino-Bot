
#ifndef __SETTING_H__
  #define __SETTING_H__

  #include "led.h"

  #ifdef __AVR__
    #include <avr/power.h>
  #endif



    // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
#endif
