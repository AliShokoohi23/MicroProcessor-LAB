/*******************************************************
This program was created by the CodeWizardAVR V3.40 
Automatic Program Generator
� Copyright 1998-2020 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro

Project : 
Version : 
Date    : 
Author  : Ali Shokoohi
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>

int left_number = 0, right_number = 0, index = 0, toggle = 0, highest = 9999, lowest = 0;
int leftDigits[4], rightDigits[4];
int divisor, digitIndex;

const char segments[] = { 0x3F, 0x06, 0x5B, 0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F, 0x77,0x7C, 0x39 , 0x5E, 0x79, 0x71 }  ;

interrupt [TIM1_COMPA] void timer1_compa_isr(void)
{
right_number++;

if (toggle != 1) 
{
    toggle = 1;
} 
else 
{
    left_number--; 
    toggle = 0;
}

}

interrupt [TIM0_COMP] void timer0_comp_isr(void)
{
    index++;
    index %= 8;
}


void main(void)
{
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);
DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (1<<WGM01) | (1<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x7C;
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (1<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0xF4;
OCR1AL=0x23;
OCR1BH=0x00;
OCR1BL=0x00;
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (1<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (1<<OCIE0) | (0<<TOIE0);
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);
#asm("sei")

while (1)
      {
      if (left_number < lowest)
        {
            left_number = highest;
        }
        if (right_number > highest)
        {
            right_number = lowest;
        }
        divisor = 1000;
        digitIndex = 0;
        while (divisor >= 1) {
            leftDigits[digitIndex] = (left_number / divisor) % 10;
            rightDigits[digitIndex] = (right_number / divisor) % 10;
            divisor /= 10;
            digitIndex++;
        }
        switch(index)
        {
            case 0:
                PORTD = 0xFE;
                PORTC = segments[leftDigits[0]];
                break;
            case 1:
                PORTD = 0xFD;
                PORTC = segments[leftDigits[1]];
                break;
            case 2:
                PORTD = 0xFB;
                PORTC = segments[leftDigits[2]];
                break;
            case 3:
                PORTD = 0xF7;
                PORTC = segments[leftDigits[3]];
                break;
            case 4:
                PORTD = 0xEF;
                PORTC = segments[rightDigits[0]];
                break;
            case 5:
                PORTD = 0xDF;
                PORTC = segments[rightDigits[1]];
                break;
            case 6:
                PORTD = 0xBF;
                PORTC = segments[rightDigits[2]];
                break;
            case 7:
                PORTD = 0x7F;
                PORTC = segments[rightDigits[3]];
                break;
        }

      }
}
