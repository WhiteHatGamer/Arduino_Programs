int ledPin = 3;
int buttonPin = 2;

int buttonState = 0;
int brightness = 0;
int brightup = 2;

void setup()
{
    //Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop()
{
    analogWrite(ledPin, 0);
    buttonState = digitalRead(buttonPin);

    if (buttonState == HIGH)
    {
        for (brightness = 0; brightness < 255; brightness += brightup)
        {
            analogWrite(ledPin, brightness);
            delay(30);
        }
        for (brightness = 255; brightness > 0; brightness -= brightup)
        {
            analogWrite(ledPin, brightness);
            delay(30);
        }
        
        //digitalWrite(ledPin,HIGH);
    }
    if (brightness >= 255)
    {
        brightness = 0;
    }
    //Serial.println(brightness);
    delay(30);
    //else
    //{
    //    digitalWrite(ledPin, LOW);
    //}
}