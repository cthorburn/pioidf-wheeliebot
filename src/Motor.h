#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

#define MIN 140
#define MAX 200
#define FREQUENCY 200
#define RESOLUTION 8

class Motor {
public:
    Motor(uint8_t pinA, uint8_t pinB, int ledcChannel);
    void begin(int ledcChannel, int pin);
    void setSpeed(int speed); 
    void test();

private:
    void stopCleanly();
    void stopCleanly(uint8_t pin);
    uint8_t fwdPin;
    uint8_t revPin;
    int ledcChannel;
};    
#endif
