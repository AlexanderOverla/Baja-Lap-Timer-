

const byte IR_LED = 11; // IR transmitter LED with 100ohm (minimum) CL resistor
const byte IR_Receiver = 8; // from receiver output
const byte onboard_LED = 13; // onboard indicator LED
boolean receiverState;

void setup() {
  pinMode (onboard_LED, OUTPUT);
  pinMode (IR_LED, OUTPUT);
  pinMode (IR_Receiver, INPUT);
  // from Nick Gammon
  TCCR2A = _BV (COM2A0) | _BV(WGM21);
  TCCR2B = _BV (CS20);
  OCR2A =  219; // ~209 = ~38kHz | ~219 = ~36kHz
}

void loop() {
  receiverState = digitalRead (IR_Receiver);
  
  if (receiverState == HIGH) { // beam interrupted
    digitalWrite(onboard_LED, LOW); // green onboard LED off
    delay(1000);
  }
  else { // beam detected
    digitalWrite(onboard_LED, HIGH); // green LED on
  }
}
