String parseString(String data, char separator[], int index) {
        int found = 0;
        int strIndex[] = { 0, -1 };
        int maxIndex = data.length() - 1;
        for (int i = 0; i <= maxIndex && found <= index; i++) {
                if (data.charAt(i) == separator[0] || i == maxIndex) {
                        found++;
                        strIndex[0] = strIndex[1] + 1;
                        strIndex[1] = (i == maxIndex) ? i + 1 : i;
                }
        }
        return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void serialSend() {
        if (Serial.available() > 1) {
                String read1, read2;
                String Read = Serial.readString();  //t#33#1.80#3.30
                read1 = parseString(Read, "#", 0);
                if (read1 == "speed") {  // suhu
                        read2 = parseString(Read, "#", 1);
                        SPEED_1 = read2.toInt();
                        if (SPEED_1 > 255) SPEED_1 = 255;
                        Serial.println("Speed = " + String(SPEED_1));
                } else if (read1 == "r" || read1 == "reset") {
                        st = 0;
                        Serial.println("State = " + String(1));
                } else if (read1 == "delay") {
                        read2 = parseString(Read, "#", 1);
                        _delay = read2.toInt();
                        Serial.println("delay = " + String(_delay));
                } else if (read1 == "run") {
                        read2 = parseString(Read, "#", 1);
                        motor_run = read2.toInt();
                        Serial.println("Motor Run = " + String(motor_run));
                } else if (read1 == "info") {
                        read2 = parseString(Read, "#", 1);
                        Serial.println("Motor Run = " + String(motor_run));
                        Serial.println("delay = " + String(_delay));
                        Serial.println("Speed = " + String(SPEED_1));
                }
        }
}
