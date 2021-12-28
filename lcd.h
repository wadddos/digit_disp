#ifndef LCD_H
#define	LCD_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define FCY 12000000      // 12 Mhz
#include <libpic30.h>
//------------------------------------------------------------------------------
void displayinit(void);
void sendnibble(unsigned int NIBBLE, unsigned int MODE);
void sendbyte(unsigned int BYTE, unsigned int MODE);
void sendline(unsigned int LINE[20]);
//------------------------------------------------------------------------------
#endif /* LCD_H */


