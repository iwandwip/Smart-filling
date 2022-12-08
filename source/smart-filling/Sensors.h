#pragma once
#include "stdint.h"

struct Sensor {
        void Init();
        void Handler();
        void Debug();
        
        char getKey();
        uint32_t getDist();
        uint8_t getProx();

      private:
        uint32_t sensTmr;
        uint32_t dist;
        uint8_t prox;
        char key;
        void errMsg();
};

extern Sensor sens;