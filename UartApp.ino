#include <avr/io.h>
#include <util/delay.h> 
#include "uart.h"

// define some macros
#define BAUD 9600                                   // define baud

int main(void){
  init();
   DDRB = 0x00;
   pinMode(11,OUTPUT);
   char button_status1[19]="Button is Pressed\n";
   char button_status2[20]="Button not Pressed\n";

  while (1)
  {
   int button = PINB;
  if (button==1){
    uart_transmit_array(button_status1,19);
  }else if(button == 0){
    uart_transmit_array(button_status2,20);
    _delay_ms(1000);

  }
  int led= uart_recieve ();
if(led=='h'){
  digitalWrite(11,HIGH);}
 else if(led=='l'){
  digitalWrite(11,LOW);}

}


return 0; 
  }
 


void init(){
  uart_init (BAUD);  
}

