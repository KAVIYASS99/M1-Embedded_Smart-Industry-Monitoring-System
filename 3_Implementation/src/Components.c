// Lcd Function
void dispinit(void)
{
int count;
 char init[]={0x43,0x03,0x03,0x02,0x28,0x01,0x0C,0x06,0x02,0x02};

 PORTB &= ~(1<<RS);           // RS=0
 for (count = 0; count <= 9; count++)
  {
displaybyte(init[count]);
  }
 PORTB |= 1<<RS;    //RS=1
}
// Enable Pulse Function
void epulse(void)
{
 PORTD |= 1<<E;
delay_ms(1); //Adjust delay if required
 PORTD &= ~(1<<E);
delay_ms(1); //Adjust delay if required
}
// Send Byte to Lcd Display Function
void displaybyte(char D)
{
//D4=PD6
//D5=PD5
//D6=PB7
//D7=PB6
 //data is in Temp Register
  char K1;
  K1=D;
  K1=K1 & 0xF0;
  K1=K1 >>4;  //Send MSB

  PORTD &= 0x9F;  //Clear data pins 
  PORTB &= 0x3F;

if((K1 & 0x01)==0x01){PORTD |= (1<<PD6);}
if((K1 & 0x02)==0x02){PORTD |= (1<<PD5);}
if((K1 & 0x04)==0x04){PORTB |= (1<<PB7);}
if((K1 & 0x08)==0x08){PORTB |= (1<<PB6);}
epulse();

  K1=D;
  K1=K1 & 0x0F;  //Send LSB
  PORTD &= 0x9F;  //Clear data pins 
  PORTB &= 0x3F;

if((K1 & 0x01)==0x01){PORTD |= (1<<PD6);}
if((K1 & 0x02)==0x02){PORTD |= (1<<PD5);}
if((K1 & 0x04)==0x04){PORTB |= (1<<PB7);}
if((K1 & 0x08)==0x08){PORTB |= (1<<PB6);}
epulse();
}
// Display line on LCD Function
void display(char string[16], char LineNo)
{
intlen,count;

 PORTB &= ~(1<<RS);           // RS=0 Command Mode

 if(LineNo==1)
 {
displaybyte(0x80);  //Move Coursor to Line 1
 }
 else
 { 
displaybyte(0xC0);  //Move Coursor to Line 2
 }
 PORTB |= (1<<RS);           // RS=1 Data Mode
len = strlen(string);

   for (count=0;count<len;count++)
  {
displaybyte(string[count]);
 }
}
// Delay Function
void delay_ms(unsigned int de)
{
unsigned intrr,rr1;
   for (rr=0;rr<de;rr++)
   {

  for(rr1=0;rr1<30;rr1++)   //395
  {
asm("nop");
  }

   }
}
// UART Function
void USART_Transmit(char data )
{
 UDR = data;
 /* Wait for empty transmit buffer */
 while ( !( UCSRA & (1<<UDRE)) )
 ;
 /* Put data into buffer, sends the data */

}
void senddata(char string[16])
{
intlen,count;
len = strlen(string);

   for (count=0;count<len;count++)
  {
USART_Transmit(string[count]);
 }
}
void USART_Init()
{
/* Set baud rate */
 UBRRH = 0x00;  //12, 9600 Baud At 1MHz
 UBRRL =12; 
//Set double speed enabled 
  UCSRA |= (1<<U2X);
/* Enable receiver and transmitter */
 UCSRB = (1<<RXEN)|(1<<TXEN);
/* Set frame format: 8data, 2stop bit */
 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
//Set interrupt on RX
//  UCSRB |= (1<<RXCIE);
}
void USART_Receive()
{
/* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) )
;
/* Get and return received data from buffer */
u8_data=UDR;
} 

// Send SMS Function
void sendSMS()
{
senddata("AT+CMGD=1");
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);

senddata("AT+CMGF=1");
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);

senddata("AT+CMGW=");
USART_Transmit(34);
senddata("+91XXXXXXXXXX");  //Enter Your Mobile number
USART_Transmit(34);
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);

senddata("Alert: Fire Detected");
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);
senddata("Temperature:");

     ADMUX=0xE5;
     ADCSRA=0xC7;  //Internal Referance 2.56V
     while (!(ADCSRA & (1<<ADIF)));
     Temperature=ADCH;
     ADCSRA |= 1<<4;

sprintf(mystr, "%03d", Temperature);
USART_Transmit(mystr[1]);
USART_Transmit(mystr[2]);
USART_Transmit('C');
USART_Transmit(13);
USART_Transmit(10);

senddata("Smoke Level:");
ADMUX=0xE4;   //Smoke Sensor
     ADCSRA=0xC7;  //Internal Referance 2.56V
     while (!(ADCSRA & (1<<ADIF)));
     Smoke=ADCH;   //Do some math here for calibration
     ADCSRA |= 1<<4;
sprintf(mystr, "%03d", Smoke);
USART_Transmit(mystr[0]);
USART_Transmit(mystr[1]);
USART_Transmit(mystr[2]);
USART_Transmit('P');
USART_Transmit('P');
USART_Transmit('M');
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);
USART_Transmit(26); //Cntrl+Z
delay_ms(1000);
delay_ms(1000);

senddata("AT+CMSS=1");
USART_Transmit(13);
USART_Transmit(10);
delay_ms(1000);
}
