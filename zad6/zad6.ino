#include <TimerOne.h>
volatile byte select, segment;
void setup() {
  for(int i=0; i<11; i++){
    pinMode(i+2, OUTPUT);
  }
  Timer1.initialize(1000);
  Timer1.attachInterrupt(ms);
}

void ms(){
  digitalWrite(select+2, HIGH);
  if(++select>3) {
    select = 0;
  }
  switch(select){
    case 0: segment = 0b11000000; break;
    case 1: segment = 0b11111001; break;
    case 2: segment = 0b10100100; break;
    case 3: segment = 0b10110000; break;
  }
  for(int i=0; i<7; i++){
    digitalWrite(i+6, segment & (1<<i));
  }
  digitalWrite(select+2, LOW);
}

void loop() {}
