#include <xc.h>
#include "config.h"
#include "serial.h"
#include "timer.h"

#define _XTAL_FREQ 16000000

void main(void) {
    Serial_init();
    timer_init();
    TRISGbits.TRISG0=0;
     
    while(1){
        LATGbits.LATG0 ^= 1;
        //LATGbits.LATG1 =0;
        while(!PIR4bits.TX2IF);
        TX2REG = 'Y';
        __delay_ms(100);
    }
    return;
}
