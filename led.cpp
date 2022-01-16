#include "led.h"

void blink_led(Adafruit_NeoPixel led_obj,int led_num,int rgb_array){
  //ring_led.setPixelColor(3, ring_led.Color(0,150,0)); // Moderately bright green color.

    //ring_led.show(); // This sends the updated pixel color to the hardware.

    led_obj.setPixelColor(led_num,rgb_array); // Moderately bright green color.

    led_obj.show(); // This sends the updated pixel color to the hardware.

    delay(DELAY_TERM); // Delay for a period of time (in milliseconds).
}

void initial_display(Adafruit_NeoPixel led_obj1,Adafruit_NeoPixel led_obj2,int loopnum=3){
  int mod;
  int r;
  int g;
  int b;
  
  for(int i=0;i<loopnum;i++){
    // LED color Setting
    mod=i%3;
    switch(mod){
      case 0:
        r=224;
        g=0;
        b=0;
        break;
    
      case 1:
        r=0;
        g=224;
        b=0;
        break;

      case 2:
        r=0;
        g=0;
        b=224;
        break;

      default:
        break;
    }
    
    // LED #1 Setting
    led_obj1.setPixelColor(1,led_obj1.Color(r,g,b));
    led_obj1.show(); 

    // LED #2 Setting
    led_obj2.setPixelColor(1,led_obj2.Color(r,g,b));
    led_obj2.show(); 

    delay(DELAY_TERM); 
  }

      // LED #1 Setting
    led_obj1.setPixelColor(1,led_obj1.Color(0,0,0));
    led_obj1.show(); 

    // LED #2 Setting
    led_obj2.setPixelColor(1,led_obj2.Color(0,0,0));
    led_obj2.show(); 

}
