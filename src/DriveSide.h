#ifndef DRIVESIDE_H
#define DRIVESIDE_H

#include <Motor.h>

class DriveSide {
public:
    DriveSide(int pinFF, int pinFR, int pinRF, int pinRR, int ledcChannel);
    void fwd(int speed);
    void rev(int speed);
    void stop();
    void test();
private:
    Motor front, rear;
};

#endif