#include <xc.h>
#include "timer.h"
#include <stdint.h>

uint8_t timetick=0;

void timer_init(){
    
    //OSCILLATOR
    OSCCONbits.SCS = 0b11;
    OSCCONbits.IRCF = 0b1111;
    OPTION_REGbits.TMR0CS =0;   //8bit timer
    OPTION_REGbits.PSA =1;  // 1:1 prescaler
    INTCONbits.TMR0IE=1;
    TRISGbits.TRISG2 =0;
}

void interrupt whatifiliall(void){
    if(INTCONbits.TMR0IF){
        INTCONbits.TMR0IF =0;
        timetick++;
        LATGbits.LATG2 ^= 1;
    }
}