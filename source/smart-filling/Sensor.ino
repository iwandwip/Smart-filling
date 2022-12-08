#include "Sensors.h"
#include "cfg.h"
#include "NewPing.h"
#include "Keypad_I2C.h"
#include "Keypad.h"
#include "Wire.h"

#define MAX_DIST 400

Keypad_I2C Keys(makeKeymap(hexa),
                pins[0], pins[1],
                ROWS, COLS, KEYADDR);

NewPing sonar = NewPing(TRIG, ECHO, MAX_DIST);

Sensor sens;

void Sensor::Init() {
        Keys.begin();
        Wire.begin();
        pinMode(PROX_P, INPUT);
}

void Sensor::Handler() {
        if (millis() - sensTmr >= 30) {

                this->key = Keys.getKey();
                this->dist = sonar.ping_cm();
                this->prox = digitalRead(PROX_P);

                sensTmr = millis();
        }
}

char Sensor::getKey() {
        return this->key;
}

uint32_t Sensor::getDist() {
        return this->dist;
}

uint8_t Sensor::getProx() {
        return this->prox;
}