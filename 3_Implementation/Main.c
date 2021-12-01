#include <avr/io.h>
#include <string.h>

int main(void)
{
setpoint=60;  //Temprature Limit For detection of Fire
SmokeSet=100; //Smoke Setpoint
 char Flag;

 DDRB = 0xF1;  //Set LCD Port Direction   
 DDRD = 0xE0;
 PORTB = 0x06; //Pull up for switches

delay_ms(500);  //Initiaize LCD
dispinit();
delay_ms(200);

USART_Init();  //9600 Baud rate at internal oscillator Clock 1MHz

display("Temperature:32 C",1);
display("Smoke:55 PPM    ",2);
while(1)
  {
    //Measure Temprature and Display
    ADMUX=0xE5;
    ADCSRA=0xC7;  //Internal Referance 2.56V
    while (!(ADCSRA & (1<<ADIF)));
    Temperature=ADCH;
    ADCSRA |= 1<<4;
sprintf(mystr, "%03d", Temperature);
    display("Temperature:",1);
displaybyte(mystr[1]);
displaybyte(mystr[2]);
displaybyte(0xDF);
displaybyte('C');
displaybyte(0x20);

    ADMUX=0xE4;   //Smoke Sensor
    ADCSRA=0xC7;  //Internal Referance 2.56V
    while (!(ADCSRA & (1<<ADIF)));
    Smoke=ADCH;   //Do some math here for calibration
ADCSRA |= 1<<4;
sprintf(mystr, "%03d", Smoke);
    display("Smoke:",2);
displaybyte(mystr[0]);
displaybyte(mystr[1]);
displaybyte(mystr[2]);
displaybyte('P');
displaybyte('P');
displaybyte('M');
displaybyte(0x20);

  //Compare with Set Points and Send SMS
  if(Temperature>setpoint || Smoke>SmokeSet) 
  {
   //Over Temprature SMS
     if(Flag==0)
     {
sendSMS();
    Flag=1;
    PORTB &=~(1<<PB5);  //Turn of  Electrical Supply
    PORTB |=(1<<PB4);  //Turn on buzzer 
}
  }
  else
  { 
   Flag=0;
   PORTB |=(1<<PB5);   //Keep on Electrical Supply
   PORTB &=~(1<<PB4);   //Turn off buzzer 
  }
  }
}
