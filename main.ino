#include "led.h"
#include "cmd_receiver.h"

// LED objs Setting
Adafruit_NeoPixel ring_led = Adafruit_NeoPixel(RING_LED_NUMBER, RING_LED_PIN , NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel bar_led = Adafruit_NeoPixel(BAR_LED_NUMBER, BAR_LED_PIN , NEO_GRB + NEO_KHZ800);

// Global Variable Setting
int incomingByte = 0;    // for incoming serial data
int cmd_num=0;
String recv_cmd;
bool cmd_reading=false;
int RED_LED_PIN=6;
int GREEN_LED_PIN=7;

void setup() {

  // [1] System Setting  
  bool debug_mode=true; // user setting mode

  // [2] LED Setting
  ring_led.begin(); // This initializes the NeoPixel library.
  bar_led.begin(); // This initializes the NeoPixel library.
  
  // [3] Serial Setting
  Serial.begin(9600); 

  initial_display(&ring_led, &bar_led );

  // [4] State Display LED Setting
  pinMode(RED_LED_PIN, OUTPUT); // Red LED   (Abnormal State)
  pinMode(GREEN_LED_PIN,OUTPUT);  // Green LED (Normal State)
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void loop() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    digitalWrite(GREEN_LED_PIN, HIGH);
    
    // read the incoming byte:
    incomingByte = Serial.read();
    
    if((char)incomingByte=='#'){ // '#' : Command Identifier
      Serial.print("Received Command : #");
      recv_cmd="#";
      cmd_num=1;
       cmd_reading=true;
    }else{
     if (cmd_reading==true){
        if (cmd_num>0 && cmd_num<7){
          cmd_num=cmd_num+1;
          recv_cmd=recv_cmd+(char)incomingByte;
        }else if(cmd_num==7){ // 정상적인 명령어 수신 완료
          // Serial Print
          Serial.print("\nRun Command : "+recv_cmd+"\n"); 
        
          // Command Excution
          read_code(recv_cmd,&ring_led,&bar_led);
  
          // Initialize
          cmd_num=0; 
          recv_cmd="";
          cmd_reading=false;
        }
     }
      Serial.print((char)incomingByte); // convert byte to string    
    }
    

    
  }else{ 
 
  }
}
