#include "calc.h"

//------------------------------------------------------------------------------
unsigned int symboltohex(unsigned int HEX)
{
    switch(HEX)
    {
        case 0x0: return 0x30; break;
        case 0x1: return 0x31; break;
        case 0x2: return 0x32; break;
        case 0x3: return 0x33; break;
        case 0x4: return 0x34; break;
        case 0x5: return 0x35; break;
        case 0x6: return 0x36; break;
        case 0x7: return 0x37; break;
        case 0x8: return 0x38; break;
        case 0x9: return 0x39; break;
        case 0xA: return 0x41; break;
        case 0xB: return 0x42; break;
        case 0xC: return 0x43; break;
        case 0xD: return 0x44; break;
        case 0xE: return 0x45; break;
        case 0xF: return 0x46; break;
        default: return 0x3F;
    }
}
//------------------------------------------------------------------------------