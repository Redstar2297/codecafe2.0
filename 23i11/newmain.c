/* 
 * File:   newmain.c
 * Author: Mads Yde
 *
 * Created on 23. november 2016, 09:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <proc/p32mx250f128b.h>
#include <xc.h>
#include "config.h"

/*
 * Reading analogue signals
 */
void init_ADC();
void init_timer();
//void transmitNumber();
//void init_UART();

int delay(int x)
{
    int counter;
    while(counter != x)      //x = 100ms
    {
        TMR1 = 0;
        while(TMR1 <= 7813){}
        counter++;
    }
}

int main(int argc, char** argv)
{
    TRISBbits.TRISB3 = 1;       //B3 -> input
    ANSELBbits.ANSB3 = 1;       //B3 -> analogue
    TRISBbits.TRISB4 = 0;       //The ports below are to the myDaq setting up digital outputs
    TRISBbits.TRISB5 = 0;
    TRISBbits.TRISB13 = 0;
    ANSELBbits.ANSB13 = 0;
    TRISBbits.TRISB10 = 0;
    init_ADC();
    //init_UART();              //Used for debugging
    TRISACLR = 0b0011;          //Enables the LED 1 A0 and LED 2 A1
    
    while(1)
    {
        int wait = ADC1BUF0 / 30;
        delay(wait);
        LATAbits.LATA0 = 1;
        delay(wait);
        LATAbits.LATA0 = 0;
    }
    /*while(1)      //Debugging UART
    {
        if(!U1STAbits.UTXBF)
        {
            U1TXREG = ADC1BUF0;
            transmitNumber(ADC1BUF0);
        }
    }*/
    return (EXIT_SUCCESS);
}

void init_timer()
{
    T1CONbits.ON = 1;           //turn on timer
    T1CONbits.TCKPS = 0b11;     //1:256 prescale
}

void init_ADC()
{
    AD1CON1bits.ON = 0;         //Turn off ADC module
    AD1CON1bits.ASAM = 1;       //ADC sample auto-start set
    AD1CON1bits.SSRC = 0b111;   //Auto-start conversion
    AD1CON2bits.CSCNA = 1;      //enables inputs scanning
    AD1CON2bits.SMPI = 0b1111;  //interrupts at the completion of conversion for each 16th same convert sequence
    AD1CON3bits.SAMC = 0b0001;  //Auto-sample time bits TAD
    AD1CSSLbits.CSSL5 = 1;      //enables pin AN5 to a scan input
    AD1CON1bits.ON = 1;         //Turn on ADC module
}

/*void init_UART()      //Debugging code to screen
{
    //Setup
    U1RXR = 0b0010;                 //Sets RA4 (pin 12) as a input 
    RPB4R = 0b0001;                 //Sets RB5 (pin 11) as a output
    U1BRG = 129;                    //Set the baud rate
    U1STAbits.UTXEN = 1;            //Enables the transmitter
    U1STAbits.URXEN = 1;            //Enables the receiver
    U1MODEbits.ON = 1;              //Turns on the UART ports
}

 void transmitNumber(int num)       //Writes to the terminal screen used for debugging
{
    char str[20];
    int index = 0;
    
    int j = sprintf(str,"%d",num);
    str[j] = '\n';
    
    while(index < j)
    {
        if(!U1STAbits.UTXBF)
        {
            U1TXREG = str[index++];
        }
    }
}*/