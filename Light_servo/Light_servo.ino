int light1=0;
int light2=0;
int light3=0;
int light4=0;



void lightcheck(){
    light1 = analogRead(A0);
    light2 = analogRead(A1);
    light3 = analogRead(A2);
    light4 = analogRead(A3);
}


void setup(){
    Serial.begin(9600);
    pinMode(A0, INPUT);
}

void loop(){
    int light = analogRead(A0);
    Serial.println(light);
    delay(1000);}