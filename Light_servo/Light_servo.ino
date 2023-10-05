#include <Servo.h>

Servo xservo;
Servo yservo;

int light1=0;
int light2=0;
int light3=0;
int light4=0;


int xmaxlight=1023;
int xservopin=9;
int yservopin=10;
int ymaxlight=1023;
void lightstartup(){
    int x=0;
    int xmax=0;
    while (x<180){
        xservo.write(x);
        light1 = analogRead(A0);
        light2 = analogRead(A1);
        light3 = analogRead(A2);
        light4 = analogRead(A3);
        int totallights=light1+light2+light3+light4;
        Serial.write(totallights);
        if (totallights<xmaxlight){
            xmaxlight=totallights;
            xmax=x;
            Serial.write(xmax);
            Serial.write(xmaxlight);
        }
        delay(20);
        x++;
    }
    xservo.write(xmax);
    int y=0;
    int ymax=0;
    while (y<180){
        yservo.write(y);
        light1 = analogRead(A0);
        light2 = analogRead(A1);
        light3 = analogRead(A2);
        light4 = analogRead(A3);
        int totallights=light1+light2+light3+light4;
        Serial.write(totallights);
        if (totallights<ymaxlight){
            ymaxlight=totallights;
            ymax=y;
            Serial.write(ymax);
            Serial.write(ymaxlight);
        }
        delay(20);
        y++;
    }
    yservo.write(ymax);
}


void setup(){
    Serial.begin(9600);
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    pinMode(xservopin, OUTPUT);
    pinMode(yservopin, OUTPUT);
    xservo.attach(xservopin);
    yservo.attach(yservopin);
    xservo.write(0);
    yservo.write(0);
    lightstartup();
}

void loop(){
}