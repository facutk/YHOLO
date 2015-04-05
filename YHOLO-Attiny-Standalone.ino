int pin0 = 0;
int pin1 = 1;
int pin2 = 2;
int pin3 = 3;

int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void clean(){
  pinMode(pin0, INPUT);
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
}

void setup() {                
  clean();
  //configure pin4 as an input and enable the internal pull-up resistor
  pinMode(4, INPUT_PULLUP);
}

void led1() {
  // LED 1
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin1, LOW);
  delay(100);
  clean();
}

void led2() {
  // LED 2
  pinMode(pin0, OUTPUT);
  pinMode(pin1, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin1, HIGH);
  delay(100);
  clean();
}

void led3() {
  // LED 3
  pinMode(pin0, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin2, LOW);
  delay(100);
  clean();
}

void led4() {
  // LED 4
  pinMode(pin0, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin2, HIGH);
  delay(100);
  clean();
}

void led5() {
  // LED 5
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  delay(100);
  clean();
}

void led6() {
  // LED 6
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  delay(100);
  clean();
}

void led7() {
  // LED 7
  pinMode(pin0, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin0, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

void led8() {
  // LED 8
  pinMode(pin0, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin0, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led9() {
  // LED 9
  pinMode(pin1, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led10() {
  // LED 10
  pinMode(pin1, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

void led11() {
  // LED 11
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
  delay(100);
  clean();
}

void led12() {
  // LED 12
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
  delay(100);
  clean();
}

// the loop routine runs over and over again forever:
void loop() {

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
  
  buttonState = digitalRead(4);

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
  
  switch (buttonPushCounter) {
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
}
