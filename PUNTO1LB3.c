#include <xc.h>
#define _XTAL_FREQ 8000000
#pragma config PLLDIV=1
#pragma config FOSC=XT_XT

void SEG7(int a,int b){
    float temp = 0.0;
      INTCONbits.GIE      = 1;
    INTCONbits.PEIE     = 0;
    ADCON0bits.GO_DONE  = 1;
    PORTB= 0b11111110;
    PORTB= 0b11111101;
    PORTB= 0b11111011;  
    PORTC= 0b00001000; //CONEXION DIGITO 1
    int t=0;
    while(t<50){
        PORTD = a;
        t++;
    }
    t=0;
    PORTCbits.RC4=1;     //DIGITO 1
       PORTCbits.RC5=1;      //DIGITO2
    while(t<50){
        LATD = b;
        t++;
    }
    t = 0;
    PORTC=0b00000000;     //DIGITO2
    if(temp >= 60 ){
            PORTCbits.RC6 = 1; //LED TEMPERATURA 
        }
        else{
            PORTCbits.RC6= 0;
    }
   
}


void main(void) {
    int cont= -1; 
    int  dig= 0; 
    int num = 0;  
    int d1 = 0;  
    int d2 = 0;  
    int e = 0; 
    float temp = 0.0;
    OSCCONbits.IRCF= 0b111; 
    OSCCONbits.SCS=0b10;   
    
    TRISA = 0b00000001;
    PORTA =0b00000000;
    TRISB= 0b11110000;
    PORTB= 0b00001111;
    PORTC=0b00000000;
    TRISC=0b00000000;        
    TRISD =0b10000000;
    PORTD= 0b00000000;
    
    ADCON1            = 0b00001110; 
    ADCON0            = 0b00000000; 
    ADCON2            = 0b10010001;
    ADCON0bits.ADON   = 1;
 
    INTCONbits.GIE    = 1;
    INTCONbits.PEIE   = 1;  
    PIE1bits.ADIE     = 1;  
    PIR1bits.ADIF     = 0;  
    INTCONbits.RBIE   = 1;  
    INTCONbits.RBIF   = 0;  
    INTCON2bits.NOT_RBPU=0;
        while(1){
            PORTB=0b11111110;
            PORTB=0b11111101;
            PORTB=0b11111011;
        }
    while(1){  
   
        SEG7(d1,d2);  //LLAMADO A LA FUNCION DEL DISPLAY
         PORTAbits.RA1 = 1; //LED DE REPOSO
         PORTAbits.RA2= 0;   //led activo
        if(dig == 1 && cont >= 0 && cont <= 9){
            d1 = cont;
            cont=-1;
        }   
        if(dig == 2 && cont >= 0 && cont <= 9){
            d2 = cont;
            cont=-1;
        }
        if(dig >= 2 && cont == 10){
            PORTAbits.RA1 = 0;  //LED DE REPOSO
            PORTAbits.RA2=1; //led activo
            for(d1=0;d1>=0;d1--){
                for(d2=0; d2 >= 0; d2--){
                    while(e <= 500){
                        SEG7(d1,d2);
                        while(num == 1 || temp== 60){
                            SEG7(11,10);
                        }
                        e++;
                    }
                    e = 0;
                }
                d2 = 9;
            }
            d1 = 0;
            d2 = 0;
            cont  = -1;
            dig = 0; 
        }
    } 
    return;
        }

void __interrupt() teclado1(void){
 
 if(INTCONbits.RBIF){ 
        int cont =-1;
        int num=0;
        int dig=0;
        

        if(PORTBbits.RB0        ==  0){
            if(PORTBbits.RB4    ==  0){cont = 1;PORTD=1;}
            if(PORTBbits.RB5    ==  0){cont = 4;PORTD=4;}
            if(PORTBbits.RB6    ==  0){cont = 7;PORTD=7;}
            if(PORTBbits.RB7    ==  0){cont= 10;PORTD=10;}
        }
        if(PORTBbits.RB1        ==  0){
            if(PORTBbits.RB4    ==  0){cont= 2;PORTD=2;}
            if(PORTBbits.RB5    ==  0){cont= 5;PORTD=5;}
            if(PORTBbits.RB6    ==  0){cont = 8;PORTD=8;}
            if(PORTBbits.RB7    ==  0){cont = 0;PORTD=0;}
        }
        if(PORTBbits.RB2        ==  0){
            if(PORTBbits.RB4    ==  0){cont = 3;PORTD=3;}
            if(PORTBbits.RB5    ==  0){cont = 6;PORTD=6;}
            if(PORTBbits.RB6    ==  0){cont= 9;PORTD=9;}
            if(PORTBbits.RB7    ==  0){num= 1;PORTD=1;}
        }

        while(PORTBbits.RB4 == 0||PORTBbits.RB5 == 0||PORTBbits.RB6 == 0||PORTBbits.RB7 == 0);

       /* if(cont > -1 && cont <= 9){
            dig++;
        }
        if(cont == 10){
            num = 0;
        }
        INTCONbits.RBIF = 0;
    */
    }}