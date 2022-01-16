#include "led.h"
#include "cmd_receiver.h"

// LED objs Setting
Adafruit_NeoPixel ring_led = Adafruit_NeoPixel(RING_LED_NUMBER, RING_LED_PIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel bar_led = Adafruit_NeoPixel(BAR_LED_NUMBER, BAR_LED_PIN , NEO_GRB + NEO_KHZ800);


int incomingByte = 0;    // for incoming serial data

void setup() {

  // [1] System Setting  
  bool debug_mode=true; // user setting mode


  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  // [2] LED Setting
  ring_led.begin(); // This initializes the NeoPixel library.
  bar_led.begin(); // This initializes the NeoPixel library.
  // [3] Serial Setting
  Serial.begin(9600); 


  // LED Initial Setting
  initial_display(ring_led, bar_led );

}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
  
    // read the incoming byte:
    incomingByte = Serial.read();
  
    // say what you got:
    Serial.print((char)incomingByte);
  }
}
