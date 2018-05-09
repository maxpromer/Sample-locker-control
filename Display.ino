#include <TimerOne.h>

byte data[3];

#define CK1 A5
#define CK2 A4
#define CK3 A3

void out7seg(byte data) {
  for (int i=0;i<7;i++)
    digitalWrite(13 - i, (0x01<<i)&data);
/*
  digitalWrite(13, 0b00000001&data);
  digitalWrite(12, 0b00000010&data);
  digitalWrite(11, 0b00000100&data);
  digitalWrite(10, 0b00001000&data);
  digitalWrite(9,  0b00010000&data);
  digitalWrite(8,  0b00100000&data);
  digitalWrite(7,  0b01000000&data);
  */
}

int nDigi = 0;

void displayText(char *font) {
  memcpy(data, font, 3);
}

void DisplaySetup() {
  for (int i=7;i<=13;i++)
    pinMode(i, OUTPUT);

  pinMode(CK1, OUTPUT);
  pinMode(CK2, OUTPUT);
  pinMode(CK3, OUTPUT);
  digitalWrite(CK1, 1);
  digitalWrite(CK2, 1);
  digitalWrite(CK3, 1);

  Timer1.initialize(1000);
  Timer1.attachInterrupt([]() {
    digitalWrite(CK1 - nDigi, 1);
    nDigi = (nDigi + 1) > 2 ? 0 : nDigi + 1;
    // int n = count / (int)pow(10, nDigi) % 10;
    out7seg(data[2-nDigi]);
    digitalWrite(CK1 - nDigi, 0);
  });
  
  memset(data, 0, 3);
}

