# 4100901-Final_Exam-Drill
This workshop was made by Gabriela Romo Mendoza and David Santiago Perez Gomez.

### System Requirements

#### Non functionals:
1. LED to indicate the security system status (with library called LED).
2. Hexadecimal keypad to enter the password of system on digits.
3. Depuration Port with the PC (USART2 on 256000 baud rate).
4. OLED display to show events on system.

#### Functionals:
5. Keypad receive the key on digits, which is the ID of one of us (1080691539).
6. OLED display show the ID entered, this way user can validate the password in real time.
7. There's two options, to validate the password you should press key '#', if it want to reset the system you should press key '*'.
8. LED turn on for 3 seconds, blinks to 4Hz if the password is incorrect, and keeps static (0Hz) if the password is correct.
9. OLED display shows at the same time (with the LED) the text 'Success' or 'Error' depending of the result on the validation.
10.  on YAT (with UART and printf) gonna appear different texts depending on the events on the system.
