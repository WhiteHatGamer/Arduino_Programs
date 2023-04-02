#include <Servo.h>

Servo Servo11;

int servoPin = 11;
int potPin = A0;

void setup(){
    Serial.begin(9600);
    Servo11.attach(servoPin);
}

void loop(){
    int potRead = analogRead(potPin);
    //int angle = map(potRead, 0, 1023, 500, 2400); for Microseconds
    int angle = map(potRead, 0, 1023, 0, 180);
    Serial.print("Potentiometer: ");
    Serial.print(potRead);
    Serial.print("\t Angle: ");
    Serial.println(angle);
    //Servo11.writeMicroseconds(angle);
    Servo11.write(angle);
}
