/*
 * File:   Disp_mainXC16.c
 * Author: Wados
 *
 * Created on 2 сентября 2021 г., 23:32
 */



#include "Disp_mainXC16.h"

#define PRESSING_BUTTONS ((PORTB & 0b111) | ((PORTE & 0b10000000) >> 4)
#define WORK    1
#define SETTING 2
#define LEFT_S   0b111001
#define RIGHT_S  0b110101
#define PROG_S   0b101101
#define RESET_S  0b010101

int main(void)
{
    ADPCFG = 0xFFFF;
    TRISB = 0x3f; // All intputs
    TRISC = 0; // All outputs
    TRISE = 0x100; // RE8 - input, other - outputs
    TRISD = 1;
    PR1 = 15000; // число в счетном регистре таймера для периода 10 мс
    T1CON = 0x10;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 1;
    
    unsigned char pressing = 0; // код нажатой кнопки+тип нажатия, если = 0,- кнопка ненажата/отпущена
    unsigned char mode = WORK; // при запуске включен рабочий режим
    
    return 0;
}
