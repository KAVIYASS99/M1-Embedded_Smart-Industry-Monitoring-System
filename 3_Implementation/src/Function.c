#include <avr/io.h>
#include <string.h>

#define E   PD7
#define RS   PB0

void display(char string[16], char LineNo);
void displaybyte(char D);
void dispinit(void);
void epulse(void);
void delay_ms(unsigned int de);

void USART_Transmit(char data );
void senddata(char string[16]);
void USART_Init();
void USART_Receive();
void sendSMS();

 char mystr[6];
int Temperature,setpoint,Smoke,SmokeSet;
unsigned char u8_data;