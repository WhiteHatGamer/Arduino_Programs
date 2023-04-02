// Includes the Servo library
#include <Servo.h>

int potPin = A0;
int servoPin = 11;
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 10;
// Variables for the duration and the distance
long duration;
int distance;

Servo myServo; // Creates a servo object for controlling the servo motor

void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600);
    myServo.attach(servoPin); // Defines on which pin is the servo motor attached
}
void loop() {
    //getting the value from pot
    //int potRead = analogRead(potPin);
    //int angle = map(potRead,0,1023,0,180);
    //myServo.write(angle);
    //int distance = calculateDistance();
    //Serial.print(angle); // Sends the current degree into the Serial Port
    //Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    //Serial.print(distance); // Sends the distance value into the Serial Port
    //Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing

    // rotates the servo motor from 15 to 165 degrees
    for(int i=1;i<=180;i++){  
        myServo.write(i);
        delay(30);
        distance = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree

        Serial.print(i); // Sends the current degree into the Serial Port
        Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
        Serial.print(distance); // Sends the distance value into the Serial Port
        Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    }

    // Repeats the previous lines from 165 to 15 degrees
    for(int i=180;i>1;i--){  
        myServo.write(i);
        delay(30);
        distance = calculateDistance();
        Serial.print(i);
        Serial.print(",");
        Serial.print(distance);
        Serial.print(".");
    }
    
}
//Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
    distance= duration*0.034/2;
    return distance;
}