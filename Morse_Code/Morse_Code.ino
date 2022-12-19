/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

int timev = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.println("Serial Started");
  pinMode(LED_BUILTIN, OUTPUT);
}

void lightdot(int a)
{
  int i=1;
  while(i<=a)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    i++;
  }
}

void lightdash(int a)
{
  int i=1;
  while(i<=a)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    i++;
  }
}

// the loop function runs over and over again forever
void loop()
{
  if (Serial.available() > 0)
  {
    delay(295);
    timev = Serial.read();
    delay(5);
    switch(timev)
    {
      case 'a':
      case 'A':
        Serial.println("A");
        lightdot(1);
        lightdash(1);
        break;
      case 'b':
      case 'B':
        Serial.println("B");
        lightdash(1);
        lightdot(3);
        break;
      case 'c':
      case 'C':
        Serial.println("C");
        lightdash(1);
        lightdot(1);
        lightdash(1);
        lightdot(1);
        break;
      case 'd':
      case 'D':
        Serial.println("D");
        lightdash(1);
        lightdot(2);
        break;
      case 'e':
      case 'E':
        Serial.println("E");
        lightdot(1);
        break;
      case 'f':
      case 'F':
        Serial.println("F");
        lightdot(2);
        lightdash(1);
        lightdot(1);
        break;
      case 'g':
      case 'G':
        Serial.println("G");
        lightdash(2);
        lightdot(1);
        break;
      case 'h':
      case 'H':
        Serial.println("H");
        lightdot(4);
        break;
      case 'i':
      case 'I':
        Serial.println("I");
        lightdot(2);
        break;
      case 'j':
      case 'J':
        Serial.println("J");
        lightdot(1);
        lightdash(3);
        break;
      case 'k':
      case 'K':
        Serial.println("K");
        lightdash(1);
        lightdot(1);
        lightdash(1);
        break;
      case 'l':
      case 'L':
        Serial.println("L");
        lightdot(1);
        lightdash(1);
        lightdot(2);
        break;
      case 'm':
      case 'M':
        Serial.println("M");
        lightdash(2);
        break;
      case 'n':
      case 'N':
        Serial.println("N");
        lightdash(1);
        lightdot(1);
        break;
      case 'o':
      case 'O':
        Serial.println("O");
        lightdash(3);
        break;
      case 'p':
      case 'P':
        Serial.println("P");
        lightdot(1);
        lightdash(2);
        lightdot(1);
        break;
      case 'q':
      case 'Q':
        Serial.println("Q");
        lightdash(2);
        lightdot(1);
        lightdash(1);
        break;
      case 'r':
      case 'R':
        Serial.println("R");
        lightdot(1);
        lightdash(1);
        lightdot(1);
        break;
      case 'S':
      case 's':
        Serial.println("S");
        lightdot(3);
        break;
      case 't':
      case 'T':
        Serial.println("T");
        lightdash(1);
        break;
      case 'u':
      case 'U':
        Serial.println("U");
        lightdot(2);
        lightdash(1);
        break;
      case 'v':
      case 'V':
        Serial.println("V");
        lightdot(3);
        lightdash(1);
        break;
      case 'w':
      case 'W':
        Serial.println("W");
        lightdot(1);
        lightdash(2);
        break;
      case 'x':
      case 'X':
        Serial.println("X");
        lightdash(1);
        lightdot(2);
        lightdash(1);
        break;
      case 'y':
      case 'Y':
        Serial.println("Y");
        lightdash(1);
        lightdot(1);
        lightdash(2);
        break;
      case 'z':
      case 'Z':
        Serial.println("Z");
        lightdash(2);
        lightdot(2);
        break;
      case ' ':
        Serial.println("space");
        delay(400);
        break;
      case '1':
        Serial.println("1");
        lightdot(1);
        lightdash(4);
        break;
      case '2':
        Serial.println("2");
        lightdot(2);
        lightdash(3);
        break;
      case '3':
        Serial.println("3");
        lightdot(3);
        lightdash(2);
        break;
      case '4':
        Serial.println("4");
        lightdot(4);
        lightdash(1);
        break;
      case '5':
        Serial.println("5");
        lightdot(5);
        break;
      case '6':
        Serial.println("6");
        lightdash(1);
        lightdot(4);
        break;
      case '7':
        Serial.println("7");
        lightdash(2);
        lightdot(3);
        break;
      case '8':
        Serial.println("8");
        lightdash(3);
        lightdot(2);
        break;
      case '9':
        Serial.println("9");
        lightdash(4);
        lightdot(1);
        break;
      case '0':
        Serial.println("0");
        lightdash(5);
        break;
      default:
        Serial.println("LED Hangover");
    }
  }
}
