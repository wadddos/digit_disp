#ifndef BUTTON_H
#define	BUTTON_H

#include <xc.h>

#define S_PRESS 1
#define L_PRESS 2
#define XL_PRESS 3
#define S_TIME 3   
#define L_TIME 100
#define XL_TIME 200
#define IDDLE 0b1111

unsigned char buttons_polling(unsigned char button_code);	

#endif	/* BUTTON_H */

