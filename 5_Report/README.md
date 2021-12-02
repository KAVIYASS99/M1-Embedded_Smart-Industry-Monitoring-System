# **REQUIREMENTS**
# **INTRODUCTION**
Fire Accidents are most concerned issues as it risk the people’s life and the whole industrial area. Additionally temperature conditions should also be monitored in order to maintain the goods. The project proposes a solution to monitor temperature and detect fire. ATMega328 Microcontroller is been used as it produce high speed processing. When a fire is occur the fire sensor detects and alarm is produced, LED is on,aditionally notification is also sent to the registered mobile number to take the necessary actions. Temperature sensor is also been used to send the values to thingspeak server in order to monitor and set temperature accordingly.
# **FEATURES**
- Alerts the officials when fire is detected 
- Prevents fire based risk/accidents
- Prevents damages to warehouse goods
- User friendly and easy to monitor
# **STATE OF ART/RESEARCH**
**Before Technology**
- Temperature should be continuously monitored by labors 
- Fire occurred may not be detected and leads to accident

**After Technology**
- Temperature are monitored automatically using webpage 
- Fire occurred is been detected to take necessary actions 
# **4W AND 1H**
![image](https://user-images.githubusercontent.com/94182282/143625919-0c2a2e60-c9e9-4d13-8fc4-c3115fbfdedb.png)
# **SWOT ANALYSIS**
![image](https://user-images.githubusercontent.com/94182282/143672102-691865a7-602b-4ee9-a188-bd0e2bebff73.png)
# **HIGH LEVEL REQUIREMENTS**
- Smoke Sensor to detect the fire and produce alarm
- Temperature sensor to monitor the values
- Nodemcu to send values to thingspeak server (cloud)
- ADC to convert from analog to digital signal
- Buzzer,LED, GSM to alert the officials
# **LOW LEVEL REQUIREMENTS**
- Message is sent to Lcd display
# **DESIGN**
# **UML DIAGRAM**
![image](https://user-images.githubusercontent.com/94182282/144261702-e66766d2-a13e-44e3-a3f6-88ea9a3a0feb.png)
# **ACTIVITY DIAGRAM**
![image](https://user-images.githubusercontent.com/94182282/144259141-b4fbe1b7-1eb4-475e-9617-4f154bc5debc.png)
# **COMPONENT DIAGRAM**
![image](https://user-images.githubusercontent.com/94182282/144263187-a6bdf0af-0d17-4827-99ee-d09fea02cf2c.png)
# **CLASS DIAGRAM**
![image](https://user-images.githubusercontent.com/94182282/144262742-30a1d013-6789-4cf8-be75-2162e90f4752.png)
# **Simulation**
![image](https://user-images.githubusercontent.com/94182282/144391770-789ab418-518e-41bb-8c1f-ff8541256585.png)
# **BILLS OF MATERIALS**
| **S.NO** | **COMPONENTS** | **DESCRIPTION** | **QUANTITY** | **LINKS** |
| :------: | :------------: | :-------------: | :---------: | :-------: |
| 1 | ATMega328 | Microcontroller | 1 | https://www.electronicscomp.com/atmega328p-microcontroller-india?search=atmega328 |  
| 2 | Nodemcu | ESP 8266 Wifi module | 1 | https://www.electronicscomp.com/ai-thinker-nodemcu-esp8266-development-board?search=nodemcu |   
| 3 | ADC | Analog to Digital Converter | 1 | https://www.electronicscomp.com/adc0804-8-bit-analog-to-digital-a-d-converter-ic-dip-20-package?search=analog%20to%20digital%20converter |           
| 4 | LM35 | Temperature Sensor | 1 | https://www.electronicscomp.com/lm35-temprature-sensor?search=lm35%20sensor |
| 5 | MQ2 | Smoke Sensor | 1 | https://www.electronicscomp.com/mq2-flammable-gas-smoke-sensor-module-india?search=mq2%20sensor |  
| 6 | 16 X 2 LCD | Display Board | 1 | https://www.electronicscomp.com/16x2-1602-character-green-lcd-display-india |
| 7 | Transistor | BC548 | 2 | https://www.electronicscomp.com/bc548-npn-general-purpose-transistor-30v-100ma-to-92-package?search=BC548 |
| 8 | Resistor | 1k ohm | 3 | https://www.electronicscomp.com/1k-ohm-half-watt-resistance?search=1k%20ohm%20resistor |
| 9 | GSM | Sim 300 or 900 | 1 | https://www.electronicscomp.com/sim900a-gsm-gprs-module-india?search=gsm%20sim%20900 |
| 10 | Buzzer | Sound/Alarm | 1 | https://www.electronicscomp.com/active-buzzer-module-5v-india?search=buzzer |
| 11 | Bread Board | - | 1 | https://www.electronicscomp.com/400-points-half-size-solderless-breadboard?search=bread%20board&limit=50 |
| 12 | Jumper Wires | Connecting Wires | Infinity | https://www.electronicscomp.com/jumper-wire-male-female-connector?search=jumper%20wir |
# **TestPlanAndOutput**
# **HIGH LEVEL TEST PLAN**
| **TEST ID** | **DESCRIPTION** | **EXPECTED I/P** | **ACTUAL O/P** | **EXPECTED O/P** |
| :------------:  | :------------------: | :------------------: | :-----------------: | :-------------------: |
| H1               | To monitor the temperature | LM35 Sensor measures surrounding temperature | To control temperature conditions accordingly | To control temperature conditions accordingly |
| H2               | To detect fire and send SMS | MQ2 Sensor detects fire at initial stage | Alert the officials through GSM(Mobile) | Alert the officials through GSM(Mobile) |
| H3               | To detect fire and produce alarm | MQ2 Sensor detects fire at initial stage | Alert the Workers through buzzer sound and through LED | Alert the Workers through buzzer sound and through LED |
| H4               | To send Temperature values to Webpage | Nodemcu sends the value to Webpage | View values in Webpage | View values in Webpage |

# **LOW LEVEL TEST PLAN**
| **TEST ID** | **DESCRIPTION** | **EXPECTED I/P** | **ACTUAL O/P** | **EXPECTED O/P** |
| :------------:  | :------------------: | :------------------: | :-----------------: | :-------------------: |
|L1                  | To print the temperature values in LCD Board | LM35 Sensor measures surrounding temperature | Display the message in LCD | Display the message in LCD |
|L2                  | To print the fire detection in LCD Board | MQ2 Sensor detects the smoke | displays whether the fire is detected or not | displays whether the fire is detected or not |
# **ImagesAndVideos**
# **Temperature values**
![image](https://user-images.githubusercontent.com/94182282/144232022-0bcf8b47-baa8-432d-97cd-8f8d25342d66.png)
* ![image](https://user-images.githubusercontent.com/94182282/144232076-88f3e31e-ff8e-421e-b494-1c1ed7e8498a.png)
# **Fire Detection**
![fire output](https://user-images.githubusercontent.com/94182282/144265984-9796d9df-596d-453a-b9a6-b1e33e87c056.jpeg)
