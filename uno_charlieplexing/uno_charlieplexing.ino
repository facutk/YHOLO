int pin0 = 9;
int pin1 = 10;
int pin2 = 11;
int pin3 = 12;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void clean() {
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
}


void led1() {
  // LED 1
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led2() {
  // LED 2  
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

void led3() {
  // LED 3
  pinMode(pin1, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led4() {
  // LED 4
  pinMode(pin1, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

void led5() {
  // LED 5
  pinMode(pin0, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led6() {
  // LED 6
  pinMode(pin0, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

void led7() {
  // LED 7
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, HIGH);
  delay(100);
  clean();
}

void led8() {
  // LED 8
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin1, LOW);
  delay(100);
  clean();
}

void led9() {
  // LED 9
  pinMode(pin0, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin2, HIGH);
  delay(100);
  clean();
}

void led10() {
  // LED 10
  pinMode(pin0, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin2, LOW);
  delay(100);
  clean();
}

void led11() {
  // LED 11
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(100);
  clean();
}

void led12() {
  // LED 12
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(100);
  clean();
}


void led_on(int led){

  switch (led) {
    case 0:  // LED 1
      pinMode(pin2, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      break;
    case 1:  // LED 2  
      pinMode(pin2, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      break;
    case 2:  // LED 3
      pinMode(pin1, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin1, LOW);
      digitalWrite(pin3, HIGH);
      break;
    case 3:  // LED 4
      pinMode(pin1, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin3, LOW);
      break;
    case 4:  // LED 5
      pinMode(pin0, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin0, LOW);
      digitalWrite(pin3, HIGH);
      break;
    case 5:  // LED 6
      pinMode(pin0, OUTPUT);
      pinMode(pin3, OUTPUT);
      digitalWrite(pin0, HIGH);
      digitalWrite(pin3, LOW);
      break;
    case 6:  // LED 7
      pinMode(pin0, OUTPUT);
      pinMode(pin1, OUTPUT);
      digitalWrite(pin0, LOW);
      digitalWrite(pin1, HIGH);
      break;
    case 7:  // LED 8
      pinMode(pin0, OUTPUT);
      pinMode(pin1, OUTPUT);
      digitalWrite(pin0, HIGH);
      digitalWrite(pin1, LOW);
      break;
    case 8:  // LED 9 
      pinMode(pin0, OUTPUT);
      pinMode(pin2, OUTPUT);
      digitalWrite(pin0, LOW);
      digitalWrite(pin2, HIGH);
      break;
    case 9:  // LED 10
      pinMode(pin0, OUTPUT);
      pinMode(pin2, OUTPUT);
      digitalWrite(pin0, HIGH);
      digitalWrite(pin2, LOW);
      break;
    case 10:  // LED 11
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      break;
    case 11:  // LED 12
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      break;
  }
  
}


void setup() {
  clean();
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  //Serial.begin(9600);
}

//int incomingByte = 0;



long previousMicros = 0;




const int max_led = 12;

void print_row( long row ) {
  
  long delta = 0;
  long interval = 10;           // interval at which to blink (milliseconds)
  unsigned long initialMillis = millis();
  int i;
  long row_tmp = row;

  while( delta < interval ) {
    row_tmp = row;
    
    for ( i = 0; i <= max_led ; i++ ) {
      if ( ( row_tmp & 1 ) > 0 ) {
        led_on( i );
        delayMicroseconds(50); //delayMicroseconds
        clean();
      }
      row_tmp >>= 1;
    }

    delta = millis() - initialMillis;

  }
  //delay(25);

}
// 100000000001 = 2049
// 010000000010 = 1026
// 001000000100 = 516
// 000100001000 = 264
// 000010010000 = 144
// 000001100000 = 96
// 000001100000 = 96
// 000010010000 = 144
// 000100001000 = 264
// 001000000100 = 516
// 010000000010 = 1026
// 100000000001 = 2049


// the loop routine runs over and over again forever:
long sequence[] = {0, 0, 0, 4095, 4095, 4095, 240, 240, 240, 240, 4095, 4095, 4095, 0, 0, 0};
void loop() {

  //int i;
  //for( i = 0; i < 24; i++ ) {
  //  print_row( sequence[i] );
  //}

  int sensorVal = digitalRead(2);
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } 
  else {
    digitalWrite(13, HIGH);
  }
  
  //print_row( 2049 );
  //print_row( 1026 );
  //print_row( 516 );
  //print_row( 264 );
  //print_row( 144 );
  //print_row( 96 );
  //print_row( 144 );
  //print_row( 264 );
  //print_row( 516 );
  //print_row( 1026 );

  /*
  long i;
  for ( i = 0; i < 4095; i++ ) {
    print_row( i );
  }
  
  int i;
  for( i = 0; i < 12; i++) {
    led_on( i );
    delay(100); //delayMicroseconds
    clean();
  };
  for( i = 11; i >= 0; i--) {
    led_on( i );
    delay(100);
    clean();
  };
  
  unsigned long currentMicros = micros();
 
  if(currentMicros - previousMicros > interval) {
    previousMicros = currentMicros;   
  }
  */
  /*
  led1();
  led2();
  led3();
  led4();
  led5();
  led6();
  led7();
  led8();
  led9();
  led10();
  led11();
  led12();
  */
  /*
  */
  /*
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();


  }
  
  buttonState = digitalRead(2);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {

    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      buttonPushCounter++;
      if ( buttonPushCounter > 12) {
        buttonPushCounter = 0;
      }

    }
  }


  lastButtonState = buttonState;
  


  switch (incomingByte) {
    case 0:
      led12();
      break;
    case 1:
      led1();
      break;
    case 2:
      led2();
      break;
    case 3:
      led3();
      break;
    case 4:
      led4();
      break;
    case 5:
      led5();
      break;
    case 6:
      led6();
      break;
    case 7:
      led7();
      break;
    case 8:
      led8();
      break;
    case 9:
      led9();
      break;
    case 10:
      led10();
      break;
    case 11:
      led11();
      break;
  }
  */
}
