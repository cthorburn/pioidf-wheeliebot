#include <Arduino.h>
#include <WheelieTooth.h>
#include <Car.h>

//WheelieTooth tooth;
Car car;

void setup() {
    Serial.begin(115200);
}

void loop() {
    car.fwd(140);
    delay(2000);
    
    car.stop();
    delay(2000);

    car.rev(140);
    delay(2000);
}

