#pragma once

#include "stdint.h"

struct Sensor {
        void Init();
        void Handler();
        void Debug();

        char getKey() {
                return this->key;
        }
        uint32_t getDist() {
                return this->dist;
        }
        uint8_t getProx() {
                return this->prox;
        }

      private:
        uint32_t sensTmr;
        uint32_t dist;
        uint8_t prox;
        char key;
        void errMsg();
};

extern Sensor sens;