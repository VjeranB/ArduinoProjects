#include <TimerOne.h>
void setup() {
  pinMode(2, INPUT_PULLUP);
  for(int i=0; i<8; i++){
    pinMode(i+4, OUTPUT);
    digitalWrite(i+4, LOW);
  }
  Timer1.initialize(100000);
  Timer1.attachInterrupt(sekunda);
  attachInterrupt(digitalPinToInterrupt(2), tipka, RISING);
}

volatile bool smjer;
volatile int index;

void tipka(){
  smjer = !smjer;
}

void sekunda(){
  digitalWrite(index+4, HIGH);
  if(smjer){
    if(++index>7){
      index = 0;
    }
  }else{
    if(--index<0){
      index = 7;
    }
  }
  digitalWrite(index+4, LOW);
}

void loop() {}
