#include "led.h"

void initial_display(Adafruit_NeoPixel led_obj,int led_num,int rgb_array){
  //ring_led.setPixelColor(3, ring_led.Color(0,150,0)); // Moderately bright green color.

    //ring_led.show(); // This sends the updated pixel color to the hardware.

    led_obj.setPixelColor(led_num,rgb_array); // Moderately bright green color.

    led_obj.show(); // This sends the updated pixel color to the hardware.

    delay(DELAY_TERM); // Delay for a period of time (in milliseconds).
}

