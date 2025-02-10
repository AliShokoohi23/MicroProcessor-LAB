;
; AssemblerApplication1.asm
;
; Created: 2/23/2024 9:21:28 PM
; Author : Ali Shokoohi
; Student ID:400521477


.INCLUDE "M32DEF.INC"
.ORG 0X00
LDI R16, HIGH(RAMEND)
OUT SPH,R16
LDI R16, LOW(RAMEND)
OUT SPL,R16
LDI R16,0XFF
OUT DDRB,R16
OUT PORTA,R16
OUT PORTB,R16
LDI R16,0XFE
GODOWN:
	OUT PORTB,R16     
    CALL DELAY 
	BST R16,7
    ROL R16
    BLD R16,0        
	CPI R16,0X7F
	BRNE GODOWN
	LDI R16,0XFF
	RJMP GOUP


GOUP:
    ROR R16             
    OUT PORTB, R16    
    CALL DELAY           
	CPI R16,0XFE
	BRNE GOUP
	LDI R16,0XFD
    RJMP GODOWN


DELAY:
	LDI R20,0X00
	OUT DDRA,R20
	LDI R20,0X10
LOOP0:
	LDI R21,0XFF
LOOP1:
	IN R22,PINA
	CPSE R22,R23
LOOP2:
	DEC R22
	BRNE LOOP2
	DEC R21
	BRNE LOOP1
	DEC R20
	BRNE LOOP0
	RET







