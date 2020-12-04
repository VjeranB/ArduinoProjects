int numArray[10][7]  = { { 0,0,0,0,0,0,1 },  //    0
                       { 1,0,0,1,1,1,1 },    //    1
                       { 0,0,1,0,0,1,0 },    //    2
                       { 0,0,0,0,1,1,0 },    //    3
                       { 1,0,0,1,1,0,0 },    //    4
                       { 0,1,0,0,1,0,0 },    //    5
                       { 0,1,0,0,0,0,0 },    //    6
                       { 0,0,0,1,1,1,1 },    //    7
                       { 0,0,0,0,0,0,0 },    //    8
                       { 0,0,0,0,1,0,0 }};   //    9
#include "TimerOne.h"
void setup( ) {
for(  int i=0 ; i<11  ; i++ ) {
pinMode(  i+2,  OUTPUT  );  }
Timer1.initialize(  5000  );  //  microseconds
Timer1.attachInterrupt( znamenka  );
}
volatile int broj;
volatile int select;
void znamenka(  ) {
digitalWrite( 5 - select ,  HIGH  );  //  ugasi trenutno  svjetleći pokaznik
if( ++select >  3 ) { select =  0;  }       //  promjena  indeksa pokaznika
int z = int(  broj  / pow(  10  , select )  ) % 10; //  znamenka
for(  int i=0 ; i<7 ; i++ ) {
digitalWrite( i+6 , numArray[ z ][  i ] );  //  ugasi/upali i-ti  segment
}
digitalWrite( 5 - select ,  LOW );  //  upali pokaznik
}
void loop(  ) {
broj++; //  broj  koji  se  prikazuje na  4-digit 7-segmentnom  pokazniku
delay(  1000  );
}
