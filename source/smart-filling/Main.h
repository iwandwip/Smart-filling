#pragma once

struct MainSys {
        void Init(void (*Start)(void),
                  void (*Shutdown)(void));

        void Handler();
        void (*Reset)(void) = 0;


      private:
        uint32_t mainTmr;
};

extern MainSys sys;