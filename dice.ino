#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"


#define btn 13
#define buzzer 2

ArduinoLEDMatrix matrix;

const uint32_t dices[][4] = {
  {
    0x0,
    0x600600,
    0x0,
    66
  },
  {
    0x0,
    0x1981980,
    0x0,
    66
  },
  {
    0x6006,
    0x1981,
    0x98000000,
    66
  },
  {
    0x19819,
    0x80001981,
    0x98000000,
    66
  },
  {
    0x30c30,
    0xc0600603,
    0xc30c000,
    66
  },
  {
    0x36c36,
    0xc0000003,
    0x6c36c000,
    66
  }
};

void setup() {
  Serial.begin(9600);
  matrix.begin();
  pinMode(btn, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int state = !digitalRead(btn);

  if (state) {
    int random_num = random(1, 6);
    Serial.println(random_num);
    sounds();
    matrix.loadFrame(dices[random_num - 1]);
  }

  delay(100);
}

void sounds() {
  for (int i = 0; i < 3; i++) {
    tone(buzzer, 255);
    delay(1000);
    tone(buzzer,0);
    delay(1000);
  }
}