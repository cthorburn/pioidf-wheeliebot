#include <Arduino.h>
#include <DriveSide.h>
#include <Motor.h>


DriveSide::DriveSide(int pinFF, int pinFR, int pinRF, int pinRR, int ledcChannel) : front(pinFF, pinFR, ledcChannel), rear(pinRF, pinRR, ledcChannel + 1)  { }

void DriveSide::fwd(int speed) {
    front.setSpeed(speed);    
    rear.setSpeed(speed);    
}


void DriveSide::rev(int speed) {
    front.setSpeed(-speed);    
    rear.setSpeed(-speed);    
}


void DriveSide::stop() {
    front.setSpeed(0);    
    rear.setSpeed(0);    
}

void DriveSide::test() {
    front.test();    
    rear.test();    
}

