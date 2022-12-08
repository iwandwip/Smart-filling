#include "Main.h"
#include "Sensors.h"
#include "UI.h"
#include "cfg.h"

void Start() {
        ui.Init();
        sens.Init();
}

void Shutdown() {
}

void setup() {
        sys.Init(Start, Shutdown);
}

void loop() {
        sys.Handler();
        sens.Handler();
        ui.Handler();
}
