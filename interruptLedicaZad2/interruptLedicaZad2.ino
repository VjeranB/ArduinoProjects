volatile bool state, bInterrupt;
volatile unsigned long cnt = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),Ledica,RISING);
}
void Ledica(){
  if (!bInterrupt){
    bInterrupt = true;
    digitalWrite(13,state = !state);
  }
}
void loop() {
  if(bInterrupt){
    Serial.print("interrupt ");
    Serial.println(cnt++);
    delay(50);
    bInterrupt = false;
  }
}
