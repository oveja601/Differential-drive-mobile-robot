#define F_CPU 4000000UL
#include <avr/io.h>
#include <util/delay.h>

void straight(int l, int y){
    // Left motor
    OCR2A = l;
    OCR2B = 25;

    // Right motor
    OCR0A = 25;
    OCR0B = y;
}

void left(int x){
    OCR2A = 0;
    OCR2B = 0;
    OCR0A = 25;
    OCR0B = x;
}

void right(int x){
    OCR2A = x;
    OCR2B = 25;
    OCR0A = 0;
    OCR0B = 0;
}

void steering(int x){
    if(x > 100){
        x = 100;
    }

    if(x < -100){
        x = -100;
    }

    if(x > 0){
        // Left motor backward, right motor forward
        OCR2A = 25;
        OCR2B = 70 + (185 / 100) * x;
        OCR0A = 25;
        OCR0B = 70 + (185 / 100) * x;
    }
    else{
        // Left motor forward, right motor backward
        OCR2A = 70 - (185 / 100) * x;
        OCR2B = 25;
        OCR0A = 70 - (185 / 100) * x;
        OCR0B = 25;
    }
}

void stop(){
    OCR2A = 0;
    OCR2B = 0;
    OCR0A = 0;
    OCR0B = 0;
}

void ADC_Init() {
    // Set reference voltage to AVCC
    ADMUX = (1 << REFS0);

    // Enable ADC and set prescaler to 128
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t IR_Sensor_Read0() {
    // Select ADC0 channel
    ADMUX = (1 << REFS0);

    // Start ADC conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    // Return ADC value
    return ADC;
}

uint16_t IR_Sensor_Read2() {
    // Select ADC2 channel
    ADMUX = (1 << REFS0) | (1 << MUX1);

    // Start ADC conversion
    ADCSRA |= (1 << ADSC);

    // Wait for conversion to complete
    while (ADCSRA & (1 << ADSC));

    // Return ADC value
    return ADC;
}

const int b = 600;
const int w = 100;

int main(void){
    CLKPR = (1 << CLKPCE);
    CLKPR = 0b00000001; // Set clock frequency to 4 MHz

    DDRD = 0xFF;
    DDRB = 0xFF;

    TCCR0A = 0b10100011; // Fast PWM mode, non-inverted output for right motor
    TCCR0B = 0b00000001; // Timer prescaler

    TCCR2A = 0b10100011; // Fast PWM mode, non-inverted output for left motor
    TCCR2B = 0b00000001; // Timer prescaler

    ADC_Init();

    while(1){
        straight(150, 150);
        _delay_ms(3000);

        right(150);
        _delay_ms(1700);
    }
}
