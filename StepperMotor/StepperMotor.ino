#define StepPin1 8
#define StepPin2 9
#define StepPin3 10
#define StepPin4 11

int stepnum = 0;
void setup()
{
    //Serial.begin(115200);
    pinMode(StepPin1, OUTPUT);
    pinMode(StepPin2, OUTPUT);
    pinMode(StepPin3, OUTPUT);
    pinMode(StepPin4, OUTPUT);
}

void loop()
{
    /*for(stepnum=0;stepnum<4;stepnum++)
    {
        Serial.println("Step Number is: ");
        Serial.print(stepnum);
        Serial.println("");
        oneStep(false);
        delay(2);
    }*/
    oneStep(true);
    delay(3);
}

void oneStep(bool dir)
{
    if (dir)
    {
        switch (stepnum)
        {
        case 0:
            digitalWrite(StepPin1,HIGH);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,LOW);
            break;
        case 1:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,HIGH);
            digitalWrite(StepPin4,LOW);
            break;
        case 2:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,HIGH);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,LOW);
            break;
        case 3:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,HIGH);
            break;
        }
    }
    else
    {
        switch (stepnum)
        {
        case 0:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,HIGH);
            break;
        case 1:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,HIGH);
            digitalWrite(StepPin4,LOW);
            break;
        case 2:
            digitalWrite(StepPin1,LOW);
            digitalWrite(StepPin2,HIGH);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,LOW);
            break;
        case 3:
            digitalWrite(StepPin1,HIGH);
            digitalWrite(StepPin2,LOW);
            digitalWrite(StepPin3,LOW);
            digitalWrite(StepPin4,LOW);
            break;
        }
    }
    stepnum++;
    if(stepnum>3)
    {
        stepnum=0;
    }
}