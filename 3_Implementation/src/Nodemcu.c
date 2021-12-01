// initializes or defines the output pin of the LM35 temperature sensor
int outputpin= D0;

void setup() {
Serial.begin(9600); 
}

void loop()       //main loop

{
int digitalValue = digitalRead(outputpin);
float millivolts = (digitalValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
float celsius = millivolts/10;
Serial.print("in DegreeC=   ");
Serial.println(celsius);