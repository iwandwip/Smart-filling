#include "Main.h"
#include "cfg.h"

MainSys sys;

void MainSys::Init(void (*StartCallback)(void),
                   void (*Shutdown)(void)) {

        StartCallback();
}

void MainSys::Handler() {
}