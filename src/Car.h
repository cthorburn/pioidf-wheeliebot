#ifndef CAR_H
#define CAR_H
#include <DriveSide.h>

#define STEER_MIN -30
#define STEER_MAX 30
//LEFT

#define MD_A1 16
#define MD_A2 17
#define MD_B1 25
#define MD_B2 26

//RIGHT
#define MD_C1 21
#define MD_C2 22
#define MD_D1 14
#define MD_D2 33

#define STEER_EFFECT 1.0

class Car {
public:
    Car();
    void fwd(int speed);
    void rev(int speed);
    void steer(int angle);
    void stop();
    void test();
private:
    int adjust(int speed, int angle);
    DriveSide left, right;
    int angle = 0;
};

#endif