#include "lcd.h"

#define RS PORTCbits.RC13 // 1 - data  0 - command
#define E PORTCbits.RC14
//------------------------------------------------------------------------------
void displayinit(void)
{
    __delay_ms(30);
    sendnibble(0b0011,0);
    __delay_ms(10);
    sendnibble(0b0011,0);
    __delay_us(200);
    sendnibble(0b0011,0);
    __delay_us(100);
    sendnibble(0b0010,0);
    __delay_us(100);
    sendnibble(0b0010,0);
    sendnibble(0b1000,0);
    __delay_us(100);
    sendnibble(0,0);
    sendnibble(0b1110,0); //курсор в виде подчеркивания включен
    __delay_us(100);
    sendnibble(0,0);
    sendnibble(0b0001,0);
    __delay_ms(3);
    sendnibble(0,0);
    sendnibble(0b0110,0);
    __delay_us(100);
}
//------------------------------------------------------------------------------
void sendnibble(unsigned int NIBBLE, unsigned int MODE)
{
  PORTE = NIBBLE;
  if(MODE == 0) RS = 0;
  else RS = 1;
  E = 0;
  __delay_us(2);
  E = 1;
}
//------------------------------------------------------------------------------
void sendbyte(unsigned int BYTE, unsigned int MODE)
{
    sendnibble(((BYTE & 0b0000000011110000)>>4),MODE);
    sendnibble((BYTE & 0b0000000000001111),MODE);
    __delay_us(100);
}
//------------------------------------------------------------------------------
void sendline(unsigned int LINE[20])
{
    unsigned char i=0;
    for (i=0;i<20;i++)
    {
        sendbyte(LINE[i],1);
    }
}
