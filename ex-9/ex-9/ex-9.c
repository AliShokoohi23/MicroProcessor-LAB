/*******************************************************
This program was created by the
CodeWizardAVR V3.14 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : ex-9
Version : 
Date    : 4/30/2024
Author  : alibest3@yahoo.com
Company : IUST
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/
//Ali Shokoohi
//400521477
#include <mega32.h>
// Alphanumeric LCD functions
#include <alcd.h>
#include <stdio.h>
#include <delay.h>
#define CR 0x0D
#define LF 0x0A

void usart_transmit_str(char *str);

void main(void) {
	unsigned char c;
	unsigned char counter;
    UCSRA = 0x00;
    UCSRB = 0x18;
    UCSRC = 0x86;
    UBRRH = 0x00;
    UBRRL = 0x33;
    
    lcd_init(16);

    while (1) {
        c = getchar();
        putchar(c);
        lcd_putchar(c);
        
        if (c == 'C') {
            lcd_clear();
            putchar(CR);
            putchar(LF);
        }
        else if (c == 'N') {
            putchar(CR);
            putchar(LF);
            usart_transmit_str("Ali Shokoohi");
            putchar(CR);
            putchar(LF);
        }
        else if (c == 'c') {
            for (counter = 0; counter < 24; counter++) {
                putchar(CR);
                putchar(LF);
            }
        }
        else if(c == 'M') {
            putchar(CR);
            putchar(LF);
            lcd_clear();
            lcd_gotoxy(0, 0);
            lcd_puts("Ali Shokoohi");
        }
    }
}
void usart_transmit_str(char *str) {
    unsigned char i;
    for(i = 0; str[i]; i++)
        putchar(str[i]);
}
