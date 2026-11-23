#ifndef WTOOTH_H
#define WTOOTH_H

#include <BluetoothSerial.h>

#define MAX_MSG_LEN 64
#define ACK 0x06

struct Control {
    char msgBuffer[MAX_MSG_LEN];
    int msgIdx = 0;
    volatile bool messageReady = false;
    bool isReceiving = false;
};

class WheelieTooth {

    public:
        WheelieTooth();
        void begin();
        String read();
        void write(String data);
        static void onBluetoothData(const uint8_t *buffer, size_t size);
    private:
        static const char START_MARKER = '<';
        static const char END_MARKER   = '>';
        static Control control;
};

#endif

