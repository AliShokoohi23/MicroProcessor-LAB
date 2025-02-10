
//Ali Shokoohi
//400521477

#include <mega32.h>
#include <delay.h>
#include <stdlib.h>

#include <alcd.h>
signed char number = 0;
unsigned char led = 0;
interrupt [EXT_INT0] void ext_int0_isr(void)
{
    if(led == 1)
        number+=10;
    else
        number++;
}

interrupt [EXT_INT1] void ext_int1_isr(void)
{
    if(led == 1)
        number-=10;
    else
        number--;
}

interrupt [EXT_INT2] void ext_int2_isr(void)
{
    if(led == 1)
    {
        led = 0;
        PORTC = PORTC & 0b11110111;
    }
    else
    {   
        led = 1;
        PORTC = PORTC | 0b00001000;
    }
}

void main(void)
{
    DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
    PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);
    DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
    PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
    DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (1<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
    PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0); 
    DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
    PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

    GICR|=(1<<INT1) | (1<<INT0) | (1<<INT2);
    MCUCR=(1<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);
    GIFR=(1<<INTF1) | (1<<INTF0) | (1<<INTF2);

    ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
    SFIOR=(0<<ACME);

    lcd_init(16);
    #asm("sei")

    while (1)
    {
      char* output = 0;
      lcd_gotoxy(0,0);
      itoa(number,output);                                                                                      
      lcd_puts(output);
      lcd_puts("  ");
      delay_ms(20);
    }
}