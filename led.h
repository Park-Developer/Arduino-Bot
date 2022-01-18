#ifndef LED_h
#define LED_h

#ifndef ADAFAULT_NEOPIXEL_H
#include "Adafruit_NeoPixel.h"

  #define ADAFAULT_NEOPIXEL_H
  #define RING_LED_PIN            4
  #define BAR_LED_PIN             5

  // How many NeoPixels are attached to the Arduino?
  #define RING_LED_NUMBER      8
  #define BAR_LED_NUMBER      8
  // When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
  // Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
  // example for more information on possible values.


  #define DELAY_TERM 500  // delay for half a second
  
  #ifdef __AVR__
    #include <avr/power.h>
  #endif

void blink_led(Adafruit_NeoPixel led_obj,int led_num,int rgb_array);
void initial_display(Adafruit_NeoPixel *led_obj1,Adafruit_NeoPixel *led_obj2,int loopnum=3);
//void addd(Adafruit_NeoPixel *led_obj);
#endif



#endif
