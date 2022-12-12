#include <Keypad_I2C.h>
#include <Keypad.h>  // GDY120705
#include <Wire.h>

#define I2CADDR 0x20

char customKey;

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
        { '1', '4', '7', '*' },
        { '2', '5', '8', '0' },
        { '3', '6', '9', '#' },
        { 'A', 'B', 'C', 'D' }
};
byte rowPins[ROWS] = { 3, 2, 1, 0 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 7, 6, 5, 4 };  //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad_I2C customKeypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS, I2CADDR);

void setup() {
        Wire.begin();          // GDY200622
        customKeypad.begin();  // GDY120705
        Serial.begin(9600);
}

void loop() {
        customKey = customKeypad.getKey();

        if (customKey != NO_KEY) {
                Serial.println(customKey);
        }       
}
