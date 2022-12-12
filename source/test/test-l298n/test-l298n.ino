#define IN1 27  // deklarasi pin IN1
#define IN3 14  // deklarasi pin IN3
#define ENA 26  // deklarasi pin ENA
#define ENB 12  // deklarasi pin ENB

#define IN12 32  // deklarasi pin IN1
#define IN32 33  // deklarasi pin IN3
#define ENA2 2   // deklarasi pin ENA
#define ENB2 25  // deklarasi pin ENB

#define TEST_MOTOR_1 1
#define TEST_MOTOR_2 1
#define TEST_MOTOR_3 1
#define TEST_MOTOR_4 1

uint8_t SPEED_1 = 80;
uint8_t SPEED_2 = 80;
uint8_t SPEED_3 = 80;
uint8_t SPEED_4 = 80;

uint8_t st = 0;
uint32_t _delay = 3000;
uint32_t uiTmr;

uint8_t motor_run = 1;

void setup() {
        Serial.begin(115200);
        //  Konfigurasi pin - pin sebagai Output
        pinMode(IN1, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(ENA, OUTPUT);
        pinMode(ENB, OUTPUT);
        pinMode(IN12, OUTPUT);
        pinMode(IN32, OUTPUT);
        pinMode(ENA2, OUTPUT);
        pinMode(ENB2, OUTPUT);
}

void loop() {
        switch (motor_run) {
                case 1: run(IN1, ENA, SPEED_1, _delay); break;
                case 2: run(IN3, ENB, SPEED_1, _delay); break;
                case 3: run(IN12, ENA2, SPEED_1, _delay); break;
                case 4: run(IN32, ENB2, SPEED_1, _delay); break;
        }

        //  analogWrite(ENB, 255); // Mengatur kecepatan motor B (0-255)
        //  analogWrite(ENA, 80); // Mengatur kecepatan motor A (0-255)
        //  digitalWrite(IN1, TEST_MOTOR_1);
        //  digitalWrite(IN3, TEST_MOTOR_2);
        //  delay(30); // Jeda 2 detik
        //
        //  analogWrite(ENA2, SPEED_3); // Mengatur kecepatan motor A (0-255)
        //  analogWrite(ENB2, SPEED_4); // Mengatur kecepatan motor B (0-255)
        //  digitalWrite(IN12, TEST_MOTOR_3);
        //  digitalWrite(IN32, TEST_MOTOR_4);
        //  delay(30); // Jeda 2 detik
        //  Serial.println("Halo");
        serialSend();
}

void run(int _pin, int _ena, int _speed, uint32_t _delay_) {
        if (st == 0) {
                analogWrite(_ena, 255);  // Mengatur kecepatan motor A (0-255)
                digitalWrite(_pin, TEST_MOTOR_1);
                delay(200);
                analogWrite(_ena, _speed);  // Mengatur kecepatan motor A (0-255)
                digitalWrite(_pin, TEST_MOTOR_1);
                delay(_delay_);
                digitalWrite(_pin, 0);
                st = 1;
        }
}
