#include <TimerOne.h>
volatile long t;
volatile bool stanje, ispis;
void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
  Timer1.initialize(100);
  Timer1.attachInterrupt(stoMicro);
  attachInterrupt(digitalPinToInterrupt(2), tipkaD2, RISING);
  attachInterrupt(digitalPinToInterrupt(3), tipkaD3, RISING);
}

void stoMicro(){
  t++;
}

void tipkaD2(){
  if (stanje = !stanje){
    t = 0;
    Timer1.restart();
  }else{
    Timer1.stop();
  }
}

void tipkaD3(){
  ispis = true;
}

void loop() {
  if (ispis){
    int ms = t/10;
    int ss = ms/1000;
    int mm = ss/60;
    Serial.print(mm);
    Serial.print(":");
    Serial.print(ss);
    Serial.print(":");
    Serial.print(ms);
    Serial.print("\n");
    ispis = false;  
  }
}
