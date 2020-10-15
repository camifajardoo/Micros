#include <xc.h>
#define _XTAL_FREQ 4000000
void main(void){
    TRISD= 0B00000000;
    PORTD= 0b00000000;
    TRISB= 0B11111111;
    PORTB= 0B00000000;
        
   if(PORTB==0b10000000) {
    
    __delay_ms(10);
          PORTD=0b00000001;            
         __delay_ms(2000);            
        PORTD=0b00000011;
          __delay_ms(2000);
        PORTD=0b00000111; 
        __delay_ms(2000);
        PORTD=0b00001111;
      __delay_ms(2000);
        PORTD=0b00011111;
      __delay_ms(2000);
        PORTD=0b00111111;
     __delay_ms(2000);
        PORTD=0b01111111;
          __delay_ms(2000);
        PORTD=0b11111111;
         __delay_ms(3000);
        PORTD=0b01111111;  
          __delay_ms(3000);
        PORTD=0b00111111;
          __delay_ms(2000);
        PORTD=0b00011111;
          __delay_ms(2000);
        PORTD=0b00001111;
         __delay_ms(2000);
        PORTD=0b00000111;
       __delay_ms(2000);
        PORTD=0b00000011;
    __delay_ms(2000);
        PORTD=0b00000001; 
         __delay_ms(2000);
        PORTD=0b00000000; 
   }
    return;
}