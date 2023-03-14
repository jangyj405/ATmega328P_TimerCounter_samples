#define F_CPU 16000000L
#include <avr/io.h>
#include <avr/interrupt.h>

/* 
//Overflow Interrupt
int count = 0;
ISR(TIMER0_OVF_vect)
{
	count++;
	if(count == 32)
	{
		count = 0;
		PORTB ^= 0x01 << PORTB5;
	}
}

int main(void)
{
	DDRB |= 0x01 << DDB5;
	PORTB &= ~(0x01 << PORTB5);
	
	TCCR0B |= (0x01 << CS02) | (0x01 << CS00);
	TIMSK0 |= (0x01 << TOIE0);
	sei();
	
    while (1);
	return 0;
}
*/

/*
//Compare Match Interrupt
int count = 0;

ISR(TIMER0_COMPA_vect)
{
	count++;
	TCNT0 = 0;
	if(count == 64)
	{
		count = 0;
		PORTB ^= 0x01 << PORTB5;	
	}	
}

int main(void)
{
	DDRB |= 0x01 << DDB5;
	PORTB &= ~(0x01 << PORTB5);
	
	TCCR0B |= (0x01 << CS02) | (0x01 << CS00);
	OCR0A = 128;
	TIMSK0 |= 0x01 << OCIE0A;
	sei();
	
	while(1);
	
	return 0;
}
*/


/*
//simplify ISR Function
volatile int count = 0;

ISR(TIMER0_COMPA_vect)
{
	TCNT0 = 0;
	count++;
}

int main(void)
{
	
	DDRB |= 0x01 << DDB5;
	PORTB &= ~(0x01 << PORTB5);
	
	TCCR0B |= (0x01 << CS02) | (0x01 << CS00);
	OCR0A = 128;
	TIMSK0 |= 0x01 << OCIE0A;
	sei();
	while(1)
	{
		if(count == 64)
		{
			count = 0;
			PORTB ^= 0x01 << PORTB5;	
		}
	}
	return 0;
}
*/

/*
//Compare Match Interrupt 16bit
ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0;
	PORTB ^= 0x01 << PORTB5;	
}

int main(void)
{
	DDRB |= 0x01 << DDB5;
	PORTB &= ~(0x01 << PORTB5);
	
	TCCR1B |= (0x01 << CS12) | (0x01 << CS10);
	
	OCR1A = 0x2000;
	
	TIMSK1 |= (1 << OCIE1A);
	sei();
	while(1);
	return 0;
}
*/

/*
//Compare Match Interrupt & OC1A pin
ISR(TIMER1_COMPA_vect)
{
	TCNT1 = 0;
}

int main(void)
{
	DDRB |= 0x01 << DDB1;
	
	TCCR1A |= 0x01 << COM1A0;
	TCCR1B |= (0x01 << CS12) | (0x01 << CS10);
	
	OCR1A = 0x2000;
	
	TIMSK1 |= (1 << OCIE1A);
	sei();
	while(1);
	return 0;
}
*/

//Clear Time on Compare Match
int main(void)
{
	DDRB |= 0x01 << DDB1;
	
	TCCR1A |= 0x01 << COM1A0;
	TCCR1B |= 0x01 << WGM12;
	TCCR1B |= (0x01 << CS12) | (0x01 << CS10);
	
	OCR1A = 0x2000;
	
	while(1);
	return 0;
}
