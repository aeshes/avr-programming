#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

void uart_init()
{
	UBRR0H = 0;
	UBRR0L = 129;
	
	UCSR0A=0b00000000;
	UCSR0B=0b00011000;
	UCSR0C=0b10000110;
}

void uart_send(unsigned char c)
{
	while (!(UCSR0A & (1 << UDRE0))) {}
	UDR0 = c;
}

void uart_send_str(const unsigned char *s)
{
	while (*s != 0)
	{
		uart_send(*s++);
	}
}

int main(void)
{
    uart_init();
	
    while (1) 
    {
		uart_send_str("Hello!");
		_delay_ms(500);
    }
}

