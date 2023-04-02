int ledPin = 3;
int potPin = A0;

int brightness = 0;

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    int potRead = analogRead(potPin);
    brightness = map(potRead,0, 1023, 0, 255);
    analogWrite(ledPin,brightness);
}