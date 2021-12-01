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
