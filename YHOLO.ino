/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
#define n_outs 6

// the setup routine runs once when you press reset:
void setup() {                
    // initialize the serial communication
  Serial.begin(9600);
  
  // initialize the digital pins as an output.
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}


void f0(){
  digitalWrite(7,LOW);      //OFF LED6
  digitalWrite(2, HIGH);    //ON LED1
  delay(100);               //delay for 100ms
  digitalWrite(2, LOW);     //OFF LED1
  digitalWrite(3,HIGH);     //ON LED2
  delay(100);               //delay for 100ms 
  digitalWrite(3, LOW);     //OFF LED2
  digitalWrite(4,HIGH);     //ON LED3
  delay(100);               //delay for 100ms 
  digitalWrite(4, LOW);     //OFF LED3
  digitalWrite(5,HIGH);     //ON LED4
  delay(100);               //delay for 100ms 
  digitalWrite(5, LOW);     //OFF LED4
  digitalWrite(6,HIGH);     //ON LED5
  delay(100);               //delay for 100ms 
  digitalWrite(6, LOW);     //OFF LED5
  digitalWrite(7,HIGH);     //ON LED6
  delay(100);               //delay for 100ms 
}

void num_to_bin( char num, int led[n_outs] )
{
    int i;
    int base = 1;

    for (i = 0; i < n_outs; i++) {
        led[ i ] = ((num & base) > 0)? HIGH : LOW ;
        base = base * 2;
    }

}

void out_state( int led[n_outs] )
{
  int i;
  
  for( i = 0; i < n_outs; i++ ) {
    digitalWrite( i+2, led[i] );
  }
  
}


//  loop function
//=======================================================================
void loop()
{
 /* 
  f0();
*/

  int led[ n_outs ];
  int zeros[ n_outs ];
  
  num_to_bin( 0, zeros );



  byte num;

  // check if data has been sent from the computer
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    num = Serial.read();
    num_to_bin( num, led );
    out_state( led );
  } 
  /*else {
    out_state( zeros );
    delay(1);               //delay for 5ms
    out_state( led );
    delay(49);               //delay for 5ms
    
  }*/


}
