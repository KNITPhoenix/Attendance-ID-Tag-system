#include <avr/io.h>
#include <util/delay.h>
#define rs PB0
#define rw PB1
#define en PB2
void lcdcmd(char x)
{
	PORTB=(x&(0xF0));
	PORTB&=~(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(40);
	PORTB&=~(1<<en);
	PORTB=((x<<4)&(0xF0));
	PORTB&=~(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(40);
	PORTB&=~(1<<en);
}
void lcddata(char x)
{
	PORTB=(x&(0xF0));
	PORTB|=(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(40);
	PORTB&=~(1<<en);
	PORTB=((x<<4)&(0xF0));
	PORTB|=(1<<rs);
	PORTB&=~(1<<rw);
	PORTB|=(1<<en);
	_delay_ms(40);
	PORTB&=~(1<<en);
}
void lcdini()
{
	DDRB=0xFF;
	lcdcmd(0x02);
	lcdcmd(0x28);
	lcdcmd(0x06);
	lcdcmd(0x0E);
	lcdcmd(0x01);
}
void lcdstring(char *c)
{
	while (*c!='\0')
	{
		lcddata(*c);
		*c++;
	}
}