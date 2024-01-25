#include "global.h"

#define DEST_SAVE_ADDR 0x8FC0000

NAKED void Batteryless_Init(void)
{
	//u16 test = *((vu16*)0x8FC000);
	s32 i;
	vu8* srcAddr;
	vu8* sramAddr;

	srcAddr = (vu8*)DEST_SAVE_ADDR;
	sramAddr = (vu8*)0xE000000;

	for (i = 0; i < 0x10000; i++) {
		while (*srcAddr != *srcAddr)
			; // ??????

		*sramAddr = *srcAddr;
		sramAddr++;
		srcAddr++;
	}

	// Jump back to Init as usual
	asm("bx lr");
}
