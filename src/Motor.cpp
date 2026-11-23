#include <Arduino.h>
#include <Motor.h>


Motor::Motor(uint8_t pinA, uint8_t pinB, int chan) : fwdPin(pinA), revPin(pinB), ledcChannel(chan) { 
    pinMode(fwdPin, OUTPUT);
    digitalWrite(fwdPin, LOW);

    pinMode(revPin, OUTPUT);
    digitalWrite(revPin, LOW);
}

void Motor::begin(int channel, int pin) {
  ledcSetup(channel, FREQUENCY, RESOLUTION);
  ledcAttachPin(pin, channel);
}


void Motor::stopCleanly() {
  stopCleanly(fwdPin);
  stopCleanly(revPin);
}  


void Motor::stopCleanly(uint8_t pin) {
    ledcWrite(pin, 0);
    ledcDetachPin(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void Motor::setSpeed(int speed) {

  begin(ledcChannel, fwdPin);
  begin(ledcChannel + 1, revPin);

  if(speed == 0) {
    stopCleanly();
  } 
  else if(speed > 0) {
    ledcWrite(ledcChannel + 1, 0);
    ledcWrite(ledcChannel, constrain(speed, MIN, MAX));
  }
  else {
    ledcWrite(ledcChannel, 0);
    ledcWrite(ledcChannel + 1, constrain(-speed, MIN, MAX));
  }
}


void Motor::test() {

  setSpeed(140);
  delay(1000);

  setSpeed(0);
  delay(500);
  
  setSpeed(-140);
  delay(1000);
  setSpeed(0);
  Serial.println("tested");
}
