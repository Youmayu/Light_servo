#include <Servo.h>
const int servoPin = 9;
const int t = 420;

Servo servo;

void setup(){
    servo.attach(servoPin);
}
void loop(){
    servo.write(0);
    delay(t);
    servo.write(180);
    delay(t);
}