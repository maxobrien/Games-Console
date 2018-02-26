EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Games Console-cache
EELAYER 25 0
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
L ATMEGA328P-AU U1
U 1 1 59FB9251
P 4400 2400
F 0 "U1" H 3650 3650 50  0000 L BNN
F 1 "ATMEGA328P-AU" H 4800 1000 50  0000 L BNN
F 2 "Housings_QFP:TQFP-32_7x7mm_Pitch0.8mm" H 4400 2400 50  0001 C CIN
F 3 "" H 4400 2400 50  0001 C CNN
	1    4400 2400
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x07_Male J3
U 1 1 59FB929C
P 4700 4950
F 0 "J3" H 4700 5350 50  0000 C CNN
F 1 "Conn_01x07_Male" H 4700 4550 50  0000 C CNN
F 2 "Max_Kicad:OLED-1.3" H 4700 4950 50  0001 C CNN
F 3 "" H 4700 4950 50  0001 C CNN
	1    4700 4950
	1    0    0    -1  
$EndComp
Text GLabel 5000 4850 2    60   Input ~ 0
CLK
Text GLabel 5000 4950 2    60   Input ~ 0
MOSI
Text GLabel 5000 5050 2    60   Input ~ 0
RES
Text GLabel 5000 5150 2    60   Input ~ 0
DC
Text GLabel 5000 5250 2    60   Input ~ 0
CS
Text GLabel 5450 1500 2    60   Input ~ 0
CS
Text GLabel 5450 1400 2    60   Input ~ 0
DC
Text GLabel 5450 1300 2    60   Input ~ 0
RES
Text GLabel 5450 1600 2    60   Input ~ 0
MOSI
Text GLabel 5450 1800 2    60   Input ~ 0
CLK
$Comp
L SW_Push SW1
U 1 1 59FB9800
P 1200 3100
F 0 "SW1" H 1250 3200 50  0000 L CNN
F 1 "SW_Push" H 1200 3040 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 3300 50  0001 C CNN
F 3 "" H 1200 3300 50  0001 C CNN
	1    1200 3100
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 59FB9980
P 1750 3100
F 0 "R1" V 1830 3100 50  0000 C CNN
F 1 "10k" V 1750 3100 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 3100 50  0001 C CNN
F 3 "" H 1750 3100 50  0001 C CNN
	1    1750 3100
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW2
U 1 1 59FBA05A
P 1200 3450
F 0 "SW2" H 1250 3550 50  0000 L CNN
F 1 "SW_Push" H 1200 3390 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 3650 50  0001 C CNN
F 3 "" H 1200 3650 50  0001 C CNN
	1    1200 3450
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 59FBA060
P 1750 3450
F 0 "R2" V 1830 3450 50  0000 C CNN
F 1 "10k" V 1750 3450 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 3450 50  0001 C CNN
F 3 "" H 1750 3450 50  0001 C CNN
	1    1750 3450
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW3
U 1 1 59FBA252
P 1200 3800
F 0 "SW3" H 1250 3900 50  0000 L CNN
F 1 "SW_Push" H 1200 3740 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 4000 50  0001 C CNN
F 3 "" H 1200 4000 50  0001 C CNN
	1    1200 3800
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 59FBA258
P 1750 3800
F 0 "R3" V 1830 3800 50  0000 C CNN
F 1 "10k" V 1750 3800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 3800 50  0001 C CNN
F 3 "" H 1750 3800 50  0001 C CNN
	1    1750 3800
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW4
U 1 1 59FBA25E
P 1200 4150
F 0 "SW4" H 1250 4250 50  0000 L CNN
F 1 "SW_Push" H 1200 4090 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 4350 50  0001 C CNN
F 3 "" H 1200 4350 50  0001 C CNN
	1    1200 4150
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59FBA264
P 1750 4150
F 0 "R4" V 1830 4150 50  0000 C CNN
F 1 "10k" V 1750 4150 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 4150 50  0001 C CNN
F 3 "" H 1750 4150 50  0001 C CNN
	1    1750 4150
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW5
U 1 1 59FBA514
P 1200 4500
F 0 "SW5" H 1250 4600 50  0000 L CNN
F 1 "SW_Push" H 1200 4440 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 4700 50  0001 C CNN
F 3 "" H 1200 4700 50  0001 C CNN
	1    1200 4500
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 59FBA51A
P 1750 4500
F 0 "R5" V 1830 4500 50  0000 C CNN
F 1 "10k" V 1750 4500 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 4500 50  0001 C CNN
F 3 "" H 1750 4500 50  0001 C CNN
	1    1750 4500
	0    1    1    0   
$EndComp
$Comp
L SW_Push SW6
U 1 1 59FBA520
P 1200 4850
F 0 "SW6" H 1250 4950 50  0000 L CNN
F 1 "SW_Push" H 1200 4790 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_B3S-1000" H 1200 5050 50  0001 C CNN
F 3 "" H 1200 5050 50  0001 C CNN
	1    1200 4850
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 59FBA526
P 1750 4850
F 0 "R6" V 1830 4850 50  0000 C CNN
F 1 "10k" V 1750 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 1680 4850 50  0001 C CNN
F 3 "" H 1750 4850 50  0001 C CNN
	1    1750 4850
	0    1    1    0   
$EndComp
Text GLabel 2050 3250 2    60   Input ~ 0
UP
Text GLabel 2050 3600 2    60   Input ~ 0
RIGHT
Text GLabel 2050 3950 2    60   Input ~ 0
DOWN
Text GLabel 2050 4300 2    60   Input ~ 0
LEFT
Text GLabel 2050 4650 2    60   Input ~ 0
MENU
Text GLabel 2050 5000 2    60   Input ~ 0
SELECT
Text GLabel 5450 2350 2    60   Input ~ 0
UP
Text GLabel 5450 2450 2    60   Input ~ 0
RIGHT
Text GLabel 5450 2150 2    60   Input ~ 0
DOWN
Text GLabel 5450 2250 2    60   Input ~ 0
LEFT
Text GLabel 5450 2550 2    60   Input ~ 0
MENU
Text GLabel 5450 2650 2    60   Input ~ 0
SELECT
Text GLabel 5450 3200 2    60   Input ~ 0
BUZZER
Text GLabel 3200 4700 0    60   Input ~ 0
BUZZER
$Comp
L 2N7002 Q1
U 1 1 59FE3C17
P 3450 4700
F 0 "Q1" H 3650 4775 50  0000 L CNN
F 1 "2N7002" H 3650 4700 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23_Handsoldering" H 3650 4625 50  0001 L CIN
F 3 "" H 3450 4700 50  0001 L CNN
	1    3450 4700
	1    0    0    -1  
$EndComp
$Comp
L Buzzer BZ1
U 1 1 59FE435A
P 3650 5100
F 0 "BZ1" H 3800 5150 50  0000 L CNN
F 1 "Buzzer" H 3800 5050 50  0000 L CNN
F 2 "Max_Kicad:KMTG1603_Piezo_Buzzer" V 3625 5200 50  0001 C CNN
F 3 "" V 3625 5200 50  0001 C CNN
	1    3650 5100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 59FF5486
P 5300 4550
F 0 "#PWR01" H 5300 4400 50  0001 C CNN
F 1 "+5V" H 5300 4690 50  0000 C CNN
F 2 "" H 5300 4550 50  0001 C CNN
F 3 "" H 5300 4550 50  0001 C CNN
	1    5300 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 59FF5621
P 5450 4700
F 0 "#PWR02" H 5450 4450 50  0001 C CNN
F 1 "GND" H 5450 4550 50  0000 C CNN
F 2 "" H 5450 4700 50  0001 C CNN
F 3 "" H 5450 4700 50  0001 C CNN
	1    5450 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 59FF5A8C
P 1950 5200
F 0 "#PWR03" H 1950 4950 50  0001 C CNN
F 1 "GND" H 1950 5050 50  0000 C CNN
F 2 "" H 1950 5200 50  0001 C CNN
F 3 "" H 1950 5200 50  0001 C CNN
	1    1950 5200
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 59FF5D0F
P 950 2850
F 0 "#PWR04" H 950 2700 50  0001 C CNN
F 1 "+5V" H 950 2990 50  0000 C CNN
F 2 "" H 950 2850 50  0001 C CNN
F 3 "" H 950 2850 50  0001 C CNN
	1    950  2850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 59FF605C
P 3550 4450
F 0 "#PWR05" H 3550 4300 50  0001 C CNN
F 1 "+5V" H 3550 4590 50  0000 C CNN
F 2 "" H 3550 4450 50  0001 C CNN
F 3 "" H 3550 4450 50  0001 C CNN
	1    3550 4450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 59FF614D
P 3550 5250
F 0 "#PWR06" H 3550 5000 50  0001 C CNN
F 1 "GND" H 3550 5100 50  0000 C CNN
F 2 "" H 3550 5250 50  0001 C CNN
F 3 "" H 3550 5250 50  0001 C CNN
	1    3550 5250
	1    0    0    -1  
$EndComp
$Comp
L USB_OTG J1
U 1 1 59FF6B84
P 1350 1450
F 0 "J1" H 1150 1900 50  0000 L CNN
F 1 "USB_OTG" H 1150 1800 50  0000 L CNN
F 2 "Connectors_USB:USB_Micro-B_Molex-105017-0001" H 1500 1400 50  0001 C CNN
F 3 "" H 1500 1400 50  0001 C CNN
	1    1350 1450
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 59FF6F5F
P 1900 1150
F 0 "#PWR07" H 1900 1000 50  0001 C CNN
F 1 "+5V" H 1900 1290 50  0000 C CNN
F 2 "" H 1900 1150 50  0001 C CNN
F 3 "" H 1900 1150 50  0001 C CNN
	1    1900 1150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 59FF7BC0
P 3400 3700
F 0 "#PWR08" H 3400 3450 50  0001 C CNN
F 1 "GND" H 3400 3550 50  0000 C CNN
F 2 "" H 3400 3700 50  0001 C CNN
F 3 "" H 3400 3700 50  0001 C CNN
	1    3400 3700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR09
U 1 1 59FF7EEF
P 3400 1200
F 0 "#PWR09" H 3400 1050 50  0001 C CNN
F 1 "+5V" H 3400 1340 50  0000 C CNN
F 2 "" H 3400 1200 50  0001 C CNN
F 3 "" H 3400 1200 50  0001 C CNN
	1    3400 1200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 59FF8211
P 1900 1950
F 0 "#PWR010" H 1900 1700 50  0001 C CNN
F 1 "GND" H 1900 1800 50  0000 C CNN
F 2 "" H 1900 1950 50  0001 C CNN
F 3 "" H 1900 1950 50  0001 C CNN
	1    1900 1950
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59FF839F
P 1900 1600
F 0 "C1" H 1925 1700 50  0000 L CNN
F 1 "0.1uF" H 1925 1500 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 1938 1450 50  0001 C CNN
F 3 "" H 1900 1600 50  0001 C CNN
	1    1900 1600
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 59FFA67E
P 5950 2600
F 0 "R7" V 6030 2600 50  0000 C CNN
F 1 "10k" V 5950 2600 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5880 2600 50  0001 C CNN
F 3 "" H 5950 2600 50  0001 C CNN
	1    5950 2600
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR011
U 1 1 59FFA886
P 5950 2400
F 0 "#PWR011" H 5950 2250 50  0001 C CNN
F 1 "+5V" H 5950 2540 50  0000 C CNN
F 2 "" H 5950 2400 50  0001 C CNN
F 3 "" H 5950 2400 50  0001 C CNN
	1    5950 2400
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 59FFB163
P 6300 1950
F 0 "Y1" H 6300 2100 50  0000 C CNN
F 1 "16mHz" H 6300 1800 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-U_Vertical" H 6300 1950 50  0001 C CNN
F 3 "" H 6300 1950 50  0001 C CNN
	1    6300 1950
	0    1    1    0   
$EndComp
$Comp
L GND #PWR012
U 1 1 59FFC40E
P 7000 2050
F 0 "#PWR012" H 7000 1800 50  0001 C CNN
F 1 "GND" H 7000 1900 50  0000 C CNN
F 2 "" H 7000 2050 50  0001 C CNN
F 3 "" H 7000 2050 50  0001 C CNN
	1    7000 2050
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 59FFD2E6
P 6650 1750
F 0 "C5" H 6675 1850 50  0000 L CNN
F 1 "18pF" H 6675 1650 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6688 1600 50  0001 C CNN
F 3 "" H 6650 1750 50  0001 C CNN
	1    6650 1750
	0    1    1    0   
$EndComp
$Comp
L C C6
U 1 1 59FFD335
P 6650 2150
F 0 "C6" H 6675 2250 50  0000 L CNN
F 1 "18pF" H 6675 2050 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 6688 2000 50  0001 C CNN
F 3 "" H 6650 2150 50  0001 C CNN
	1    6650 2150
	0    1    1    0   
$EndComp
Text GLabel 5450 1700 2    60   Input ~ 0
MISO
Text Notes 1400 2600 2    60   ~ 0
Button Inputs
Text Notes 1400 850  2    60   ~ 0
USB / Power
Text Notes 7000 2700 2    60   ~ 0
Programming Header
Text Notes 3550 850  2    60   ~ 0
ATmega238p-au
Text Notes 3100 4400 2    60   ~ 0
Buzzer
Text Notes 5050 4400 2    60   ~ 0
Screen Headers
$Comp
L C C4
U 1 1 5A006B5A
P 3400 3100
F 0 "C4" H 3425 3200 50  0000 L CNN
F 1 "0.1uF" H 3425 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3438 2950 50  0001 C CNN
F 3 "" H 3400 3100 50  0001 C CNN
	1    3400 3100
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 5A006C40
P 3150 3100
F 0 "C3" H 3175 3200 50  0000 L CNN
F 1 "0.1uF" H 3175 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3188 2950 50  0001 C CNN
F 3 "" H 3150 3100 50  0001 C CNN
	1    3150 3100
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5A006C97
P 2900 3100
F 0 "C2" H 2925 3200 50  0000 L CNN
F 1 "0.1uF" H 2925 3000 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 2938 2950 50  0001 C CNN
F 3 "" H 2900 3100 50  0001 C CNN
	1    2900 3100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x06_Male J2
U 1 1 5A004D0B
P 6150 3300
F 0 "J2" H 6150 3600 50  0000 C CNN
F 1 "Conn_01x06_Male" H 6500 2850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x06_Pitch2.54mm" H 6150 3300 50  0001 C CNN
F 3 "" H 6150 3300 50  0001 C CNN
	1    6150 3300
	1    0    0    -1  
$EndComp
Text GLabel 6400 3300 2    60   Input ~ 0
CLK
Text GLabel 6400 3400 2    60   Input ~ 0
MOSI
Text GLabel 6400 3600 2    60   Input ~ 0
MISO
$Comp
L +5V #PWR013
U 1 1 5A005AAC
P 6700 3000
F 0 "#PWR013" H 6700 2850 50  0001 C CNN
F 1 "+5V" H 6700 3140 50  0000 C CNN
F 2 "" H 6700 3000 50  0001 C CNN
F 3 "" H 6700 3000 50  0001 C CNN
	1    6700 3000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR014
U 1 1 5A005AF6
P 6850 3150
F 0 "#PWR014" H 6850 2900 50  0001 C CNN
F 1 "GND" H 6850 3000 50  0000 C CNN
F 2 "" H 6850 3150 50  0001 C CNN
F 3 "" H 6850 3150 50  0001 C CNN
	1    6850 3150
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 5A00D23C
P 5950 1950
F 0 "R8" V 6030 1950 50  0000 C CNN
F 1 "1M" V 5950 1950 50  0000 C CNN
F 2 "Resistors_SMD:R_1206_HandSoldering" V 5880 1950 50  0001 C CNN
F 3 "" H 5950 1950 50  0001 C CNN
	1    5950 1950
	1    0    0    -1  
$EndComp
NoConn ~ 5400 2900
NoConn ~ 5400 3000
NoConn ~ 5400 3100
NoConn ~ 5400 3300
NoConn ~ 5400 3500
NoConn ~ 5400 3600
NoConn ~ 3500 1900
NoConn ~ 3500 2650
NoConn ~ 3500 2750
NoConn ~ 1650 1450
NoConn ~ 1650 1550
NoConn ~ 1650 1650
$Comp
L PWR_FLAG #FLG015
U 1 1 5A0473D3
P 3350 2200
F 0 "#FLG015" H 3350 2275 50  0001 C CNN
F 1 "PWR_FLAG" H 3350 2350 50  0000 C CNN
F 2 "" H 3350 2200 50  0001 C CNN
F 3 "" H 3350 2200 50  0001 C CNN
	1    3350 2200
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG016
U 1 1 5A0482CB
P 3500 4950
F 0 "#FLG016" H 3500 5025 50  0001 C CNN
F 1 "PWR_FLAG" H 3500 5100 50  0000 C CNN
F 2 "" H 3500 4950 50  0001 C CNN
F 3 "" H 3500 4950 50  0001 C CNN
	1    3500 4950
	0    -1   -1   0   
$EndComp
$Comp
L PWR_FLAG #FLG017
U 1 1 5A048A1C
P 1600 5200
F 0 "#FLG017" H 1600 5275 50  0001 C CNN
F 1 "PWR_FLAG" H 1600 5350 50  0000 C CNN
F 2 "" H 1600 5200 50  0001 C CNN
F 3 "" H 1600 5200 50  0001 C CNN
	1    1600 5200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4900 4650 5450 4650
Wire Wire Line
	5300 4750 4900 4750
Wire Wire Line
	4900 4850 5000 4850
Wire Wire Line
	5000 4950 4900 4950
Wire Wire Line
	4900 5050 5000 5050
Wire Wire Line
	5000 5150 4900 5150
Wire Wire Line
	4900 5250 5000 5250
Wire Wire Line
	5400 1500 5450 1500
Wire Wire Line
	5400 1400 5450 1400
Wire Wire Line
	5450 1300 5400 1300
Wire Wire Line
	5450 1600 5400 1600
Wire Wire Line
	5450 1800 5400 1800
Wire Wire Line
	950  2850 950  4850
Wire Wire Line
	950  4850 1000 4850
Wire Wire Line
	1000 4500 950  4500
Connection ~ 950  4500
Wire Wire Line
	950  4150 1000 4150
Connection ~ 950  4150
Wire Wire Line
	1000 3800 950  3800
Connection ~ 950  3800
Wire Wire Line
	950  3450 1000 3450
Connection ~ 950  3450
Wire Wire Line
	1000 3100 950  3100
Connection ~ 950  3100
Wire Wire Line
	1400 3100 1600 3100
Wire Wire Line
	1400 3450 1600 3450
Wire Wire Line
	1400 3800 1600 3800
Wire Wire Line
	1400 4150 1600 4150
Wire Wire Line
	1400 4500 1600 4500
Wire Wire Line
	1400 4850 1600 4850
Wire Wire Line
	1900 3100 1950 3100
Wire Wire Line
	1950 4850 1900 4850
Wire Wire Line
	1950 4500 1900 4500
Connection ~ 1950 4500
Wire Wire Line
	1950 4150 1900 4150
Connection ~ 1950 4150
Wire Wire Line
	1950 3800 1900 3800
Connection ~ 1950 3800
Wire Wire Line
	1900 3450 1950 3450
Connection ~ 1950 3450
Connection ~ 1950 3100
Wire Wire Line
	1500 4850 1500 5000
Wire Wire Line
	1500 5000 2050 5000
Connection ~ 1500 4850
Wire Wire Line
	1500 4500 1500 4650
Wire Wire Line
	1500 4650 2050 4650
Connection ~ 1500 4500
Wire Wire Line
	2050 4300 1500 4300
Wire Wire Line
	1500 4300 1500 4150
Connection ~ 1500 4150
Wire Wire Line
	1500 3800 1500 3950
Wire Wire Line
	1500 3950 2050 3950
Connection ~ 1500 3800
Wire Wire Line
	2050 3600 1500 3600
Wire Wire Line
	1500 3600 1500 3450
Connection ~ 1500 3450
Wire Wire Line
	1500 3100 1500 3250
Wire Wire Line
	1500 3250 2050 3250
Connection ~ 1500 3100
Wire Wire Line
	5450 2150 5400 2150
Wire Wire Line
	5400 2250 5450 2250
Wire Wire Line
	5450 2350 5400 2350
Wire Wire Line
	5400 2450 5450 2450
Wire Wire Line
	5450 2550 5400 2550
Wire Wire Line
	5400 2650 5450 2650
Wire Wire Line
	3200 4700 3250 4700
Wire Wire Line
	3550 4450 3550 4500
Wire Wire Line
	3550 5200 3550 5250
Wire Wire Line
	3550 4900 3550 5000
Wire Wire Line
	5450 4650 5450 4700
Wire Wire Line
	5300 4750 5300 4550
Connection ~ 1950 4850
Wire Wire Line
	1950 3100 1950 5200
Wire Wire Line
	1900 1150 1900 1450
Wire Wire Line
	1900 1250 1650 1250
Wire Wire Line
	3400 1300 3500 1300
Wire Wire Line
	3400 1200 3400 2950
Wire Wire Line
	3400 1400 3500 1400
Connection ~ 3400 1300
Wire Wire Line
	3400 1600 3500 1600
Connection ~ 3400 1400
Wire Wire Line
	1350 1850 1350 1900
Wire Wire Line
	1250 1900 1900 1900
Wire Wire Line
	1900 1750 1900 1950
Wire Wire Line
	1250 1900 1250 1850
Connection ~ 1350 1900
Connection ~ 1900 1900
Connection ~ 1900 1250
Wire Wire Line
	5400 1900 5850 1900
Wire Wire Line
	5850 1900 5850 1750
Wire Wire Line
	6300 1750 6300 1800
Wire Wire Line
	5400 2000 5850 2000
Wire Wire Line
	5850 2000 5850 2150
Wire Wire Line
	6300 2150 6300 2100
Connection ~ 6300 1750
Connection ~ 6300 2150
Wire Wire Line
	5850 2150 6500 2150
Wire Wire Line
	5850 1750 6500 1750
Wire Wire Line
	6800 1750 6850 1750
Wire Wire Line
	6850 1750 6850 2150
Wire Wire Line
	6850 2150 6800 2150
Wire Wire Line
	6850 1950 7000 1950
Wire Wire Line
	7000 1950 7000 2050
Connection ~ 6850 1950
Wire Wire Line
	5450 1700 5400 1700
Wire Notes Line
	750  2450 750  5450
Wire Notes Line
	750  5450 2550 5450
Wire Notes Line
	2550 5450 2550 2450
Wire Notes Line
	2550 2450 750  2450
Wire Notes Line
	2550 2250 750  2250
Wire Notes Line
	750  2250 750  700 
Wire Notes Line
	750  700  2550 700 
Wire Notes Line
	2550 700  2550 2250
Wire Notes Line
	2750 4050 2750 700 
Wire Notes Line
	2750 700  7100 700 
Wire Notes Line
	2750 4050 7100 4050
Wire Notes Line
	2750 4250 2750 5450
Wire Notes Line
	2750 5450 4100 5450
Wire Notes Line
	4100 5450 4100 4250
Wire Notes Line
	4100 4250 2750 4250
Wire Notes Line
	4300 4250 4300 5450
Wire Notes Line
	4300 5450 5650 5450
Wire Notes Line
	4300 4250 5650 4250
Wire Notes Line
	7100 4050 7100 700 
Connection ~ 3400 1600
Wire Wire Line
	3400 3400 3500 3400
Wire Wire Line
	3400 3250 3400 3700
Connection ~ 3400 3400
Connection ~ 3400 3500
Connection ~ 3400 3600
Wire Wire Line
	2900 2900 3400 2900
Wire Wire Line
	2900 2900 2900 2950
Wire Wire Line
	3150 2900 3150 2950
Connection ~ 3150 2900
Connection ~ 3400 2900
Wire Wire Line
	2900 3300 3400 3300
Wire Wire Line
	2900 3300 2900 3250
Connection ~ 3400 3300
Wire Wire Line
	3150 3250 3150 3300
Connection ~ 3150 3300
Wire Wire Line
	3500 3500 3400 3500
Wire Wire Line
	3400 3600 3500 3600
Wire Wire Line
	6350 3100 6850 3100
Wire Wire Line
	6850 3100 6850 3150
Wire Wire Line
	6700 3000 6700 3200
Wire Wire Line
	6700 3200 6350 3200
Wire Wire Line
	6400 3300 6350 3300
Wire Wire Line
	6350 3400 6400 3400
Wire Wire Line
	6350 3500 6950 3500
Wire Wire Line
	6350 3600 6400 3600
Wire Notes Line
	5650 4250 5650 5450
Wire Wire Line
	5950 1800 5950 1750
Connection ~ 5950 1750
Wire Wire Line
	5950 2100 5950 2150
Connection ~ 5950 2150
Wire Wire Line
	3350 2200 3400 2200
Connection ~ 3400 2200
Wire Wire Line
	3500 4950 3550 4950
Connection ~ 3550 4950
Wire Wire Line
	1600 5200 1600 5150
Wire Wire Line
	1600 5150 1950 5150
Connection ~ 1950 5150
Wire Wire Line
	6950 2750 6950 3500
Wire Notes Line
	6050 2700 6050 3850
Wire Notes Line
	6050 3850 7050 3850
Wire Notes Line
	7050 3850 7050 2700
Wire Notes Line
	7050 2700 6050 2700
Wire Wire Line
	5450 3200 5400 3200
NoConn ~ 5400 3400
Wire Wire Line
	5950 2400 5950 2450
Wire Wire Line
	5400 2750 6950 2750
Connection ~ 5950 2750
$EndSCHEMATC
