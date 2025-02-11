.include "m32def.inc"
.ORG 	0
		RJMP	BEGIN
.ORG	OC1Aaddr
		RJMP	ROUTINE


BEGIN:	LDI		R16,HIGH(RAMEND)
		OUT		SPH,R16
		LDI		R16,LOW(RAMEND)
		OUT		SPL,R16

		LDI		R16,0xFF
		OUT		DDRB,R16

		;Initialize Timer 1
		LDI		R16,0b00000000
		OUT		TCCR1A,R16
		LDI		R16,0b00001100
		OUT		TCCR1B,R16
		LDI		R16,HIGH(31250-1)
		OUT		OCR1AH,R16
		LDI		R16,LOW(31250-1)
		OUT		OCR1AL,R16
		LDI		R16,0b00010000
		OUT		TIMSK,R16
		SEI

		LDI		R16,01
HERE:	OUT		PORTB,R16
		RJMP	HERE

ROUTINE:
		LSL		R16
		CPI		R16,0
		BRNE	RT
		LDI		R16,1
RT:		RETI
