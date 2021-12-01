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
