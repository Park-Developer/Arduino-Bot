#include "cmd_receiver.h"

//extern void blink_led(Adafruit_NeoPixel led_obj,int led_num,int rgb_array);
//extern void initial_display(Adafruit_NeoPixel led_obj1,Adafruit_NeoPixel led_obj2,int loopnum=3);

bool read_code(String recv_code,Adafruit_NeoPixel *led_obj1, Adafruit_NeoPixel *led_obj2){
    bool is_excution=true; // 명령어 실행 여부
    
    Serial.print("func1");
    if(recv_code=="#D00000") //Initial Setting
    {
        Serial.print("func2 " +String(RING_LED_NUMBER));
        int blink_number=3;
        //addd(3,10);
        initial_display(led_obj1,led_obj2,blink_number);

        //

    /*
    // LED #1 Setting
      led_obj1.setPixelColor(3,led_obj1.Color(224,0,0));
      
      // LED #2 Setting
      led_obj2.setPixelColor(3,led_obj2->Color.,0,0));
      
    led_obj1.show(); 
    led_obj2.show(); 
    */
    }        
    else if(recv_code=="#D00001")	//Normal State
    {}
    else if(recv_code=="#D00002")	//Warning State
    {}
    else
    {
      is_excution=false;
    }

    return is_excution;

} ;
