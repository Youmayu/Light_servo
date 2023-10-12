#include <Servo.h>
const int servoPin = 9;
const int servoPin2 = 10;
const int t = 420;
int value1 = 90;
int value2 = 90;

int lysverdi_1 = 0;
int lysverdi_2 = 0;
int lysverdi_3 = 0;
int lysverdi_4 = 0;

Servo servo;
Servo servo2;

void setup(){
    Serial.begin(115200);
    servo.attach(servoPin);
    servo2.attach(servoPin2);
    pinMode(A0,INPUT_PULLUP);
    pinMode(A1,INPUT_PULLUP);
    pinMode(A2,INPUT_PULLUP);
    pinMode(A3,INPUT_PULLUP);
}
void loop(){
    Serial.println(analogRead(A0));
    lysverdi_1 = (analogRead(A0));
    lysverdi_2 = (analogRead(A1));
    lysverdi_3 = (analogRead(A2));
    lysverdi_4 = (analogRead(A3));
    if ((lysverdi_1+lysverdi_3)>(lysverdi_2+lysverdi_4)){
        if (value2<180){
            value2++;
        }
    }
    else {
        if (value2>0){
            value2--;
        }
    }
    if ((lysverdi_1+lysverdi_2)>(lysverdi_3+lysverdi_4)){
        if (value1<180){
            value1++;
        }
    }
    else {
        if (value1>0){
            value1--;
        }
    }
    servo.write(value1);
    servo2.write(value2);
    Serial.println(lysverdi_1+lysverdi_3);
    Serial.println(lysverdi_2+lysverdi_4);
}