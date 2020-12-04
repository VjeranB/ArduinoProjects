volatile bool state;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),Ledica,RISING);
}
void Ledica(){
  digitalWrite(13,state = !state);
}

void loop() {}
