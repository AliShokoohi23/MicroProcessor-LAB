#include <mega32.h>
#include <delay.h>
void main(void)
{
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);

while (1)
      {
      // Place your code here
      //Display 1st Segment
      PORTD = 0b11111110;
      PORTC = 0x06;
      delay_ms(10);

      //Display 2nd Segment
      PORTD = 0b11111101;
      PORTC = 0x66;
      delay_ms(10);
      
      //Display 3rd Segment
      PORTD = 0b11111011;
      PORTC = 0x3F | 0x80;
      delay_ms(10);
                   
      //Display 4th Segment
      PORTD = 0b11110111;
      PORTC = 0x5B | 0x80;
      delay_ms(10);
      }
}
