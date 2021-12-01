#include"adc.h"
#include"uart.h"
intmain()
{
int adcValue;
int temp;
int Smoke;
ADC_Init();       // Initialize the ADC module 
UART_Init(9600);  // Initialize UART at 9600 baud rate 
while(1){
adcValue = ADC_GetAdcValue(0); // Read the ADC value of channel zero where the temperature sensor(LM35) is connected
Smoke = ADC_GetAdcValue(1); // Read the ADC value of Channel one where the Smoke Sensor(MQ2) is connected
temp = adcValue/2.0; // Divide by 2 to get the temp value.
UART_Printf("ADC0 Value:%4d  Equivalent Temperature:%dC\n\r",adcValue,temp);     // Send the value on UART
}
return (0);
}
