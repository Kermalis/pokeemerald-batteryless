	.include "constants/gba_constants.inc"

	.syntax unified

	.arm

	.align 2, 0
Batteryless_Init_ARM::
	ldr sp, =0x3007F00 @ May not be necessary but do it anyway
	ldr lr, =Init
	ldr r0, =Batteryless_Init + 1
	bx r0

	.pool

	.align 2, 0 @ Don't pad with nop.
