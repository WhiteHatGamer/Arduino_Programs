#define WINVER 0x0500
#include <windows.h>

int buttonvalue=0;
int button=3;
int led=2;

void setup() {
  Serial.begin(9600);
  INPUT ip;
  pinMode(button,INPUT);
  pinMode(led, OUTPUT);
  // Set up a generic keyboard event.
  ip.type = INPUT_KEYBOARD;
  ip.ki.wScan = 0; // hardware scan code for key
  ip.ki.time = 0;
  ip.ki.dwExtraInfo = 0;
}

void loop() {
  buttonvalue = digitalRead(button);
  if (buttonvalue!=0)
  {
    digitalWrite(led,HIGH);
    // Press the "A" key
    ip.ki.wVk = 0x41; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
 
    // Release the "A" key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
