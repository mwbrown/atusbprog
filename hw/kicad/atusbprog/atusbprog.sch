EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J1
U 1 1 5E7D2F7A
P 1800 2600
F 0 "J1" H 1850 3217 50  0000 C CNN
F 1 "SMH-110-02-L-D" H 1850 3126 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x10_Pitch2.54mm_SMD" H 1800 2600 50  0001 C CNN
F 3 "https://suddendocs.samtec.com/prints/smh-1xx-xx-x-x-xx-footprint.pdf" H 1800 2600 50  0001 C CNN
	1    1800 2600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5E7D308D
P 1050 3400
F 0 "#PWR0101" H 1050 3150 50  0001 C CNN
F 1 "GND" H 1050 3227 50  0000 C CNN
F 2 "" H 1050 3400 50  0001 C CNN
F 3 "" H 1050 3400 50  0001 C CNN
	1    1050 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 3400 1050 2200
$Comp
L power:+3V3 #PWR0102
U 1 1 5E7D30F2
P 3050 1900
F 0 "#PWR0102" H 3050 1750 50  0001 C CNN
F 1 "+3V3" H 3050 2074 50  0000 C CNN
F 2 "" H 3050 1900 50  0001 C CNN
F 3 "" H 3050 1900 50  0001 C CNN
	1    3050 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1900 2800 3000
Wire Wire Line
	3050 3100 3050 1900
Text GLabel 2250 2300 2    50   Output ~ 0
EFM_MOSI
Wire Wire Line
	2100 3000 2800 3000
Wire Wire Line
	2100 3100 3050 3100
Text GLabel 2250 2400 2    50   Input ~ 0
EFM_MISO
Text GLabel 2250 2500 2    50   Output ~ 0
EFM_SCK
Text GLabel 2250 2600 2    50   Output ~ 0
EFM_RST
Wire Wire Line
	2100 2300 2250 2300
Wire Wire Line
	2100 2400 2250 2400
Wire Wire Line
	2100 2500 2250 2500
Wire Wire Line
	2100 2600 2250 2600
NoConn ~ 1600 2300
NoConn ~ 1600 2400
NoConn ~ 1600 2500
NoConn ~ 1600 2600
NoConn ~ 1600 2700
NoConn ~ 1600 2800
NoConn ~ 1600 3000
NoConn ~ 1600 3100
NoConn ~ 2100 2700
NoConn ~ 2100 2800
Text Notes 750  1700 0    75   ~ 0
EXP Connector
$Comp
L Device:Crystal Y1
U 1 1 5E7D71C7
P 6000 4900
F 0 "Y1" V 6046 4769 50  0000 R CNN
F 1 "24 MHz" V 5955 4769 50  0000 R CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 6000 4900 50  0001 C CNN
F 3 "https://abracon.com/Resonators/ABL.pdf" H 6000 4900 50  0001 C CNN
	1    6000 4900
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C3
U 1 1 5E7D7316
P 5700 4700
F 0 "C3" V 5448 4700 50  0000 C CNN
F 1 "30pF" V 5539 4700 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 5738 4550 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C315C300J1G5TA.pdf" H 5700 4700 50  0001 C CNN
	1    5700 4700
	0    1    1    0   
$EndComp
$Comp
L Device:C C4
U 1 1 5E7D739F
P 5700 5100
F 0 "C4" V 5448 5100 50  0000 C CNN
F 1 "30pF" V 5539 5100 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 5738 4950 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C315C300J1G5TA.pdf" H 5700 5100 50  0001 C CNN
	1    5700 5100
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5E7D7BE6
P 7400 5100
F 0 "#PWR0103" H 7400 4850 50  0001 C CNN
F 1 "GND" H 7400 4927 50  0000 C CNN
F 2 "" H 7400 5100 50  0001 C CNN
F 3 "" H 7400 5100 50  0001 C CNN
	1    7400 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5E7D7C02
P 5450 5250
F 0 "#PWR0104" H 5450 5000 50  0001 C CNN
F 1 "GND" H 5450 5077 50  0000 C CNN
F 2 "" H 5450 5250 50  0001 C CNN
F 3 "" H 5450 5250 50  0001 C CNN
	1    5450 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 4700 5550 4700
Wire Wire Line
	5850 5100 6000 5100
Wire Wire Line
	6000 5100 6000 5050
Wire Wire Line
	5850 4700 6000 4700
Wire Wire Line
	5450 5100 5550 5100
Wire Wire Line
	5450 5100 5450 4700
Wire Wire Line
	6000 4750 6000 4700
Wire Wire Line
	6000 5100 6450 5100
Connection ~ 6000 5100
Wire Wire Line
	5450 5100 5450 5250
Connection ~ 5450 5100
NoConn ~ 8200 4700
NoConn ~ 8200 4800
Text GLabel 6600 4600 0    50   Input ~ 0
ATS_RST
$Comp
L atusbprog:74HCT125 U1
U 1 1 5E850011
P 2300 4800
F 0 "U1" H 2000 5350 50  0000 C CNN
F 1 "SN74HCT125" H 2600 4250 50  0000 C CNN
F 2 "Housings_DIP:DIP-14_W7.62mm" H 2300 4800 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hct125.pdf" H 2300 4800 50  0001 C CNN
	1    2300 4800
	1    0    0    -1  
$EndComp
Text GLabel 6000 2500 0    50   Input ~ 0
ATS_SCK
Text GLabel 6000 2350 0    50   Output ~ 0
ATS_MISO
Text GLabel 6000 2200 0    50   Input ~ 0
ATS_MOSI
Text GLabel 1800 4400 0    50   Input ~ 0
EFM_MOSI
Text GLabel 1800 4500 0    50   Input ~ 0
EFM_SCK
Text GLabel 1800 4600 0    50   Input ~ 0
EFM_RST
Text GLabel 2800 4400 2    50   Output ~ 0
ATS_MOSI
Text GLabel 2800 4500 2    50   Output ~ 0
ATS_SCK
Text GLabel 2800 4600 2    50   Output ~ 0
ATS_RST
$Comp
L power:GND #PWR0105
U 1 1 5E8508CD
P 2300 5500
F 0 "#PWR0105" H 2300 5250 50  0001 C CNN
F 1 "GND" H 2300 5327 50  0000 C CNN
F 2 "" H 2300 5500 50  0001 C CNN
F 3 "" H 2300 5500 50  0001 C CNN
	1    2300 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 5100 1650 5100
Wire Wire Line
	1650 5100 1650 5000
Wire Wire Line
	1650 4900 1800 4900
Wire Wire Line
	1800 5000 1650 5000
Connection ~ 1650 5000
Wire Wire Line
	1650 5000 1650 4900
Text Notes 750  4050 0    75   ~ 0
TX Interface\n(3V3 -> 5V)
$Comp
L atusbprog:VMCU #PWR0106
U 1 1 5E852DA4
P 2550 1900
F 0 "#PWR0106" H 2550 1750 50  0001 C CNN
F 1 "VMCU" H 2550 2074 50  0000 C CNN
F 2 "" H 2550 1900 50  0001 C CNN
F 3 "" H 2550 1900 50  0001 C CNN
	1    2550 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1900 2550 2200
Wire Wire Line
	2550 2200 2100 2200
Text Notes 6600 5300 2    50   ~ 0
Machine Cyc. Freq = 2MHz
Text GLabel 2250 2900 2    50   Output ~ 0
EFM_OE_N
Wire Wire Line
	2100 2900 2250 2900
Text GLabel 1200 4900 0    50   Input ~ 0
EFM_OE_N
Wire Wire Line
	1650 5100 1650 5200
Wire Wire Line
	1650 5200 1800 5200
Connection ~ 1650 5100
Connection ~ 1650 4900
Text GLabel 1800 4700 0    50   Input ~ 0
EFM_AUX
Text GLabel 2800 4700 2    50   Output ~ 0
ATS_AUX
Text GLabel 1500 2900 0    50   Output ~ 0
EFM_AUX
Wire Wire Line
	1600 2900 1500 2900
Wire Wire Line
	1050 2200 1600 2200
Text Notes 750  6150 0    75   ~ 0
RX Interface\n(5V -> 3V3)
$Comp
L Device:R_US R2
U 1 1 5E8618AE
P 1950 6600
F 0 "R2" V 1745 6600 50  0000 C CNN
F 1 "0" V 1836 6600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1990 6590 50  0001 C CNN
F 3 "~" H 1950 6600 50  0001 C CNN
	1    1950 6600
	0    1    1    0   
$EndComp
Text GLabel 2250 6600 2    50   Input ~ 0
ATS_MISO
Text GLabel 1650 6600 0    50   Output ~ 0
EFM_MISO
Wire Wire Line
	1650 6600 1800 6600
Wire Wire Line
	2100 6600 2250 6600
Wire Notes Line
	700  3800 3350 3800
Wire Notes Line
	3350 5900 700  5900
Wire Notes Line
	700  1550 3350 1550
Wire Notes Line
	3350 1550 3350 7000
Wire Notes Line
	700  1550 700  7000
$Comp
L atusbprog:+5V #PWR0107
U 1 1 5E866733
P 2800 1900
F 0 "#PWR0107" H 2800 1750 50  0001 C CNN
F 1 "+5V" H 2800 2074 50  0000 C CNN
F 2 "" H 2800 1900 50  0001 C CNN
F 3 "" H 2800 1900 50  0001 C CNN
	1    2800 1900
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0108
U 1 1 5E8667E6
P 7400 2400
F 0 "#PWR0108" H 7400 2250 50  0001 C CNN
F 1 "+5V" H 7400 2574 50  0000 C CNN
F 2 "" H 7400 2400 50  0001 C CNN
F 3 "" H 7400 2400 50  0001 C CNN
	1    7400 2400
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0109
U 1 1 5E866830
P 2300 4100
F 0 "#PWR0109" H 2300 3950 50  0001 C CNN
F 1 "+5V" H 2300 4274 50  0000 C CNN
F 2 "" H 2300 4100 50  0001 C CNN
F 3 "" H 2300 4100 50  0001 C CNN
	1    2300 4100
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0110
U 1 1 5E866F02
P 8350 4600
F 0 "#PWR0110" H 8350 4450 50  0001 C CNN
F 1 "+5V" V 8350 4774 50  0000 C CNN
F 2 "" H 8350 4600 50  0001 C CNN
F 3 "" H 8350 4600 50  0001 C CNN
	1    8350 4600
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5E86F2E2
P 4000 6150
F 0 "SW1" H 4000 6343 50  0000 C CNN
F 1 "SW_Push" H 4000 6344 50  0001 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 4000 6350 50  0001 C CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 4000 6350 50  0001 C CNN
	1    4000 6150
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5E86F472
P 4000 6500
F 0 "SW2" H 4000 6693 50  0000 C CNN
F 1 "SW_Push" H 4000 6694 50  0001 C CNN
F 2 "Buttons_Switches_THT:SW_PUSH_6mm" H 4000 6700 50  0001 C CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf" H 4000 6700 50  0001 C CNN
	1    4000 6500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5E86F6BC
P 3600 6700
F 0 "#PWR0111" H 3600 6450 50  0001 C CNN
F 1 "GND" H 3600 6527 50  0000 C CNN
F 2 "" H 3600 6700 50  0001 C CNN
F 3 "" H 3600 6700 50  0001 C CNN
	1    3600 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 6500 3600 6500
Wire Wire Line
	3600 6500 3600 6700
Wire Wire Line
	3800 6150 3600 6150
Wire Wire Line
	3600 6150 3600 6500
Connection ~ 3600 6500
$Comp
L Device:LED D2
U 1 1 5E88D699
P 9100 2650
F 0 "D2" H 9250 2600 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 2533 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 2650 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 2650 50  0001 C CNN
	1    9100 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D4
U 1 1 5E88D77D
P 9100 2950
F 0 "D4" H 9250 2900 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 2833 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 2950 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 2950 50  0001 C CNN
	1    9100 2950
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 5E88D7C5
P 9100 2800
F 0 "D3" H 9250 2750 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 2683 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 2800 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 2800 50  0001 C CNN
	1    9100 2800
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D1
U 1 1 5E89581C
P 9100 2500
F 0 "D1" H 9250 2450 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 2383 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 2500 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 2500 50  0001 C CNN
	1    9100 2500
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D8
U 1 1 5E89588D
P 9100 3550
F 0 "D8" H 9250 3500 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 3433 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 3550 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 3550 50  0001 C CNN
	1    9100 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D7
U 1 1 5E8958D1
P 9100 3400
F 0 "D7" H 9250 3350 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 3283 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 3400 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 3400 50  0001 C CNN
	1    9100 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D6
U 1 1 5E895911
P 9100 3250
F 0 "D6" H 9250 3200 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 3133 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 3250 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 3250 50  0001 C CNN
	1    9100 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D5
U 1 1 5E895957
P 9100 3100
F 0 "D5" H 9250 3050 50  0000 C CNN
F 1 "LTL2R3KGD-EM" V 9047 2983 50  0001 R CNN
F 2 "LEDs:LED_D5.0mm" H 9100 3100 50  0001 C CNN
F 3 "https://media.digikey.com/pdf/Data%20Sheets/Lite-On%20PDFs/LTL2R3KGD-EM%20Preliminary.pdf" H 9100 3100 50  0001 C CNN
	1    9100 3100
	1    0    0    -1  
$EndComp
Text Notes 8450 2300 0    75   ~ 0
Port 0 LEDs
$Comp
L Device:R_Network08_US RN1
U 1 1 5E8965C5
P 9800 2150
F 0 "RN1" H 10180 2196 50  0000 L CNN
F 1 "1.2k" H 10180 2105 50  0000 L CNN
F 2 "Resistors_THT:R_Array_SIP9" V 10275 2150 50  0001 C CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/4600x.pdf" H 9800 2150 50  0001 C CNN
	1    9800 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2700 8450 2500
Wire Wire Line
	8200 2700 8450 2700
Wire Wire Line
	8500 2800 8500 2650
Wire Wire Line
	8200 2800 8500 2800
Wire Wire Line
	8550 2900 8550 2800
Wire Wire Line
	8200 2900 8550 2900
Wire Wire Line
	8600 3000 8600 2950
Wire Wire Line
	8200 3000 8600 3000
Wire Wire Line
	8600 3200 8600 3250
Wire Wire Line
	8200 3200 8600 3200
Wire Wire Line
	8550 3300 8550 3400
Wire Wire Line
	8200 3300 8550 3300
Wire Wire Line
	8450 3550 8450 3400
Wire Wire Line
	8200 3400 8450 3400
Wire Wire Line
	9400 2350 9400 2500
Wire Wire Line
	9400 2500 9250 2500
Wire Wire Line
	9500 2350 9500 2650
Wire Wire Line
	9500 2650 9250 2650
Wire Wire Line
	9600 2350 9600 2800
Wire Wire Line
	9600 2800 9250 2800
Wire Wire Line
	9700 2350 9700 2950
Wire Wire Line
	9700 2950 9250 2950
Wire Wire Line
	9800 2350 9800 3100
Wire Wire Line
	9800 3100 9250 3100
Wire Wire Line
	9900 2350 9900 3250
Wire Wire Line
	9900 3250 9250 3250
Wire Wire Line
	10000 2350 10000 3400
Wire Wire Line
	10000 3400 9250 3400
Wire Wire Line
	10100 2350 10100 3550
Wire Wire Line
	10100 3550 9250 3550
$Comp
L atusbprog:+5V #PWR0112
U 1 1 5E8D9469
P 9400 1950
F 0 "#PWR0112" H 9400 1800 50  0001 C CNN
F 1 "+5V" H 9400 2124 50  0000 C CNN
F 2 "" H 9400 1950 50  0001 C CNN
F 3 "" H 9400 1950 50  0001 C CNN
	1    9400 1950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J5
U 1 1 5E8DA286
P 8800 3950
F 0 "J5" H 8880 3896 50  0000 L CNN
F 1 "Conn_01x08" H 8880 3851 50  0001 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 8800 3950 50  0001 C CNN
F 3 "~" H 8800 3950 50  0001 C CNN
	1    8800 3950
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J4
U 1 1 5E8DA347
P 6000 3950
F 0 "J4" H 6100 3900 50  0000 C CNN
F 1 "Conn_01x08" H 5920 4376 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 6000 3950 50  0001 C CNN
F 3 "~" H 6000 3950 50  0001 C CNN
	1    6000 3950
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 5E8DAA27
P 6000 3000
F 0 "J3" H 6100 2950 50  0000 C CNN
F 1 "Conn_01x08" H 5920 3426 50  0001 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 6000 3000 50  0001 C CNN
F 3 "~" H 6000 3000 50  0001 C CNN
	1    6000 3000
	-1   0    0    -1  
$EndComp
$Comp
L atusbprog:AT89S52-24PU U2
U 1 1 5E7D2D66
P 7400 3750
F 0 "U2" H 6850 4950 50  0000 C CNN
F 1 "AT89S52-24PU" H 7800 2550 50  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 7350 4000 50  0001 C CNN
F 3 "" H 7200 4700 50  0001 C CNN
	1    7400 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 2500 6300 2500
Wire Wire Line
	6300 2500 6300 3400
Wire Wire Line
	6000 2350 6400 2350
Wire Wire Line
	6400 2350 6400 3300
Wire Wire Line
	6000 2200 6500 2200
Wire Wire Line
	6500 2200 6500 3200
Wire Wire Line
	8200 3650 8600 3650
Wire Wire Line
	8200 3750 8600 3750
Wire Wire Line
	8200 3850 8600 3850
Wire Wire Line
	8200 3950 8600 3950
Wire Wire Line
	8200 4050 8600 4050
Wire Wire Line
	8200 4150 8600 4150
Wire Wire Line
	8200 4250 8600 4250
Wire Wire Line
	8200 4350 8600 4350
Wire Wire Line
	8450 3550 8950 3550
Wire Wire Line
	8550 3400 8950 3400
Wire Wire Line
	8600 3250 8950 3250
Wire Wire Line
	8200 3100 8950 3100
Wire Wire Line
	8600 2950 8950 2950
Wire Wire Line
	8550 2800 8950 2800
Wire Wire Line
	8500 2650 8950 2650
Wire Wire Line
	8450 2500 8950 2500
Wire Wire Line
	6200 3400 6300 3400
Connection ~ 6300 3400
Wire Wire Line
	6300 3400 6600 3400
Wire Wire Line
	6600 3300 6400 3300
Connection ~ 6400 3300
Wire Wire Line
	6400 3300 6200 3300
Wire Wire Line
	6200 3200 6500 3200
Connection ~ 6500 3200
Wire Wire Line
	6500 3200 6600 3200
Wire Wire Line
	6600 3100 6200 3100
Wire Wire Line
	6200 3000 6600 3000
Wire Wire Line
	6600 2900 6200 2900
Wire Wire Line
	6200 2800 6600 2800
Wire Wire Line
	6200 2700 6600 2700
Wire Wire Line
	6200 3650 6600 3650
Wire Wire Line
	6600 3750 6200 3750
Wire Wire Line
	6200 3850 6600 3850
Wire Wire Line
	6200 3950 6600 3950
Wire Wire Line
	6600 4050 6200 4050
Wire Wire Line
	6200 4150 6600 4150
Wire Wire Line
	6600 4250 6200 4250
Wire Wire Line
	6200 4350 6600 4350
Wire Wire Line
	8200 4600 8350 4600
Text Label 6300 3850 0    75   ~ 0
BTN0
Text Label 6300 3950 0    75   ~ 0
BTN1
Connection ~ 6000 4700
Wire Wire Line
	6600 4700 6000 4700
Wire Wire Line
	6450 4800 6600 4800
Wire Wire Line
	6450 4800 6450 5100
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5E9ADB94
P 4600 5000
F 0 "J2" H 4680 4992 50  0000 L CNN
F 1 "Conn_01x04" H 4680 4901 50  0001 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 4600 5000 50  0001 C CNN
F 3 "~" H 4600 5000 50  0001 C CNN
	1    4600 5000
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0113
U 1 1 5E9ADCA0
P 4300 4850
F 0 "#PWR0113" H 4300 4700 50  0001 C CNN
F 1 "+5V" H 4300 5024 50  0000 C CNN
F 2 "" H 4300 4850 50  0001 C CNN
F 3 "" H 4300 4850 50  0001 C CNN
	1    4300 4850
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0114
U 1 1 5E9ADCD7
P 4050 4850
F 0 "#PWR0114" H 4050 4700 50  0001 C CNN
F 1 "+3V3" H 4050 5024 50  0000 C CNN
F 2 "" H 4050 4850 50  0001 C CNN
F 3 "" H 4050 4850 50  0001 C CNN
	1    4050 4850
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:VMCU #PWR0115
U 1 1 5E9ADD0E
P 3800 4850
F 0 "#PWR0115" H 3800 4700 50  0001 C CNN
F 1 "VMCU" H 3800 5024 50  0000 C CNN
F 2 "" H 3800 4850 50  0001 C CNN
F 3 "" H 3800 4850 50  0001 C CNN
	1    3800 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 5E9ADD87
P 4300 5300
F 0 "#PWR0116" H 4300 5050 50  0001 C CNN
F 1 "GND" H 4300 5127 50  0000 C CNN
F 2 "" H 4300 5300 50  0001 C CNN
F 3 "" H 4300 5300 50  0001 C CNN
	1    4300 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 4900 4300 4900
Wire Wire Line
	4300 4900 4300 4850
Wire Wire Line
	4050 4850 4050 5000
Wire Wire Line
	4050 5000 4400 5000
Wire Wire Line
	3800 4850 3800 5100
Wire Wire Line
	3800 5100 4400 5100
Wire Wire Line
	4400 5200 4300 5200
Wire Wire Line
	4300 5200 4300 5300
$Comp
L Device:C C1
U 1 1 5E9C2425
P 1300 5400
F 0 "C1" H 1415 5446 50  0000 L CNN
F 1 "0.1u" H 1415 5355 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 1338 5250 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C315C104M5U5TA7301.pdf" H 1300 5400 50  0001 C CNN
	1    1300 5400
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0117
U 1 1 5E9C2587
P 1300 5250
F 0 "#PWR0117" H 1300 5100 50  0001 C CNN
F 1 "+5V" H 1300 5424 50  0000 C CNN
F 2 "" H 1300 5250 50  0001 C CNN
F 3 "" H 1300 5250 50  0001 C CNN
	1    1300 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0118
U 1 1 5E9C25C0
P 1300 5550
F 0 "#PWR0118" H 1300 5300 50  0001 C CNN
F 1 "GND" H 1300 5377 50  0000 C CNN
F 2 "" H 1300 5550 50  0001 C CNN
F 3 "" H 1300 5550 50  0001 C CNN
	1    1300 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5E9CA775
P 9350 4450
F 0 "C5" H 9465 4496 50  0000 L CNN
F 1 "0.1u" H 9465 4405 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.8mm_W2.6mm_P2.50mm" H 9388 4300 50  0001 C CNN
F 3 "https://api.kemet.com/component-edge/download/datasheet/C315C104M5U5TA7301.pdf" H 9350 4450 50  0001 C CNN
	1    9350 4450
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0119
U 1 1 5E9CA77C
P 9350 4300
F 0 "#PWR0119" H 9350 4150 50  0001 C CNN
F 1 "+5V" H 9350 4474 50  0000 C CNN
F 2 "" H 9350 4300 50  0001 C CNN
F 3 "" H 9350 4300 50  0001 C CNN
	1    9350 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0120
U 1 1 5E9CA782
P 9350 4600
F 0 "#PWR0120" H 9350 4350 50  0001 C CNN
F 1 "GND" H 9350 4427 50  0000 C CNN
F 2 "" H 9350 4600 50  0001 C CNN
F 3 "" H 9350 4600 50  0001 C CNN
	1    9350 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5E9DB202
P 3500 5050
F 0 "C2" H 3618 5096 50  0000 L CNN
F 1 "47u" H 3618 5005 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P3.50mm" H 3538 4900 50  0001 C CNN
F 3 "http://industrial.panasonic.com/www-cgi/jvcr13pz.cgi?E+PZ+3+ABA0022+EEUFC1J470+7+WW" H 3500 5050 50  0001 C CNN
	1    3500 5050
	1    0    0    -1  
$EndComp
Text Notes 3600 5850 0    75   ~ 0
~INT0~/~INT1~ Buttons
Wire Wire Line
	4200 6150 4550 6150
Wire Wire Line
	4200 6500 4550 6500
Text Label 4550 6150 2    75   ~ 0
BTN0
Text Label 4550 6500 2    75   ~ 0
BTN1
Wire Notes Line
	700  7000 4800 7000
$Comp
L power:GND #PWR0121
U 1 1 5E9ECE5D
P 3500 5200
F 0 "#PWR0121" H 3500 4950 50  0001 C CNN
F 1 "GND" H 3500 5027 50  0000 C CNN
F 2 "" H 3500 5200 50  0001 C CNN
F 3 "" H 3500 5200 50  0001 C CNN
	1    3500 5200
	1    0    0    -1  
$EndComp
$Comp
L atusbprog:+5V #PWR0122
U 1 1 5E9ECFAD
P 3500 4900
F 0 "#PWR0122" H 3500 4750 50  0001 C CNN
F 1 "+5V" H 3500 5074 50  0000 C CNN
F 2 "" H 3500 4900 50  0001 C CNN
F 3 "" H 3500 4900 50  0001 C CNN
	1    3500 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 4900 1350 4900
$Comp
L Device:R_US R1
U 1 1 5E9F1A1C
P 1100 4700
F 0 "R1" V 895 4700 50  0000 C CNN
F 1 "100k" V 986 4700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1140 4690 50  0001 C CNN
F 3 "https://www.yageo.com/upload/media/product/products/datasheet/lr/Yageo_LR_MFR_1.pdf" H 1100 4700 50  0001 C CNN
	1    1100 4700
	0    1    1    0   
$EndComp
$Comp
L atusbprog:+5V #PWR0123
U 1 1 5E9F1C28
P 850 4550
F 0 "#PWR0123" H 850 4400 50  0001 C CNN
F 1 "+5V" H 850 4724 50  0000 C CNN
F 2 "" H 850 4550 50  0001 C CNN
F 3 "" H 850 4550 50  0001 C CNN
	1    850  4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 4700 1350 4900
Connection ~ 1350 4900
Wire Wire Line
	1350 4900 1650 4900
Wire Wire Line
	1350 4700 1250 4700
Wire Wire Line
	850  4550 850  4700
Wire Wire Line
	850  4700 950  4700
Text Notes 3600 4550 0    75   ~ 0
Ext. Power Header
Wire Notes Line
	4800 4350 4800 7000
Wire Notes Line
	4800 5600 3350 5600
Wire Notes Line
	4800 4350 3350 4350
$EndSCHEMATC
