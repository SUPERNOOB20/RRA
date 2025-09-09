#include "vram_clear.h"

BN_CODE_IWRAM void reset_vram();

/* void reset_vram(int bios_call_param)         // Please call this with int 3.
{   asm("swi 0x01");   }
*/

/*
void reset_vram()
{
    for (int i = 0; 98300; i++){
        ((unsigned short*)0x06000000)[i] = 0x0000;
    }
    return;
}
*/