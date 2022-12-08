#pragma once

/**     \def Indicator
        @param LED_G Pin Led Hijau
        @param LED_R Pin Led Merah
        @param BUZZER Pin BUzzer
        @param LCDADDR alamat i2c LCD
*/
#define LED_G 4
#define LED_R 5
#define BUZZER 6
#define LCDADDR 0x27

/**     \def KeypadI2C
        @param KEYADDR merupakan alamat i2c Keypad
        @param ROWS Keypad memiliki 4 Rows ( baris )
        @param COLS Keypad memiliki 4 Cols ( kolom )
        @param hexa hexaKey pada Keypad 
        @param pins Keypad Pin
*/
#define KEYADDR 0x21
#define ROWS 4
#define COLS 4

char hexa[4][4] = {
        { '1', '2', '3', 'A' },
        { '4', '5', '6', 'B' },
        { '7', '8', '9', 'C' },
        { 'E', '0', 'F', 'D' }
};

byte pins[2][4] = { { 3, 2, 1, 0 },
                    { 7, 6, 5, 4 } };

/**     \def Ultrasonic Jsn-sr04t
        @param TRIG Pin Trigger
        @param ECHO Pin Echo
*/
#define TRIG 2
#define ECHO 3

/**     \def Proximity
        @param PROX_P Pin Proximity
*/
#define PROX_P 7