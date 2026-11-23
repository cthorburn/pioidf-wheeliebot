#include <Arduino.h>
#include <Car.h>
#include <DriveSide.h>

Car::Car() : left(MD_A1, MD_A2, MD_B1, MD_B2, 8), right(MD_C1, MD_C2, MD_D1, MD_D2, 10) {}


void Car::fwd(int speed) {

    int leftSpeed = speed;
    int rightSpeed = speed;

    int speedDelta = speed * sin(abs(angle)) * STEER_EFFECT;

    if(angle < 0 ) {
        leftSpeed -= speedDelta;
        rightSpeed += speedDelta;
    }
    else if(angle > 0 ) {
        leftSpeed += speedDelta;
        rightSpeed -= speedDelta;

    }

    left.fwd(leftSpeed);
    right.fwd(rightSpeed);
} 


void Car::rev(int speed) {
    fwd(-speed);
} 


void Car::stop() {
    left.stop();
    right.stop();    
}


void Car::steer(int newAngle) {
    angle =  constrain(newAngle, STEER_MIN, STEER_MAX) * (PI/180);
}


int Car::adjust(int speed, int angle) {
    return sin(angle);

    return speed - ((speed * angle) / 100); //this is wrong
}


void Car::test() {

    for(;;) {
        left.test();
        right.test();
    }
}
