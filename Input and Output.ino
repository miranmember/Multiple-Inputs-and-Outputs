
// 1- Miran Member
// 2- Multiple inputs and output
// 3- Description - Part 1: using photo sensors turn the led on based on its values. Part 2: Using Potentio Meter make sounds using analog.



//A0 for the pResistor that sends the value which is read by the analogread. and samething for potentio meter on A1.
const int pResistor = A0, pMeter = A1;
int value = 0, value2 = 0;

const int ledPin1 =  2
const int ledPin2 = 3;
const int ledPin3 =  4;
const int ledPin4 = 5;
int ledState = HIGH;
void setup() {
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  value = analogRead(pResistor);
  value2 = analogRead(pMeter);
  value2 = map(value2, 0, 1023,50,10000); // using map to fix the analogread so the buzzer can have consistant sound.
  displayBrightness(value);
  pMeterFunction(value2);
  delay(25);
}

void pMeterFunction(int value2) {
  tone(11, value2);
}
void displayBrightness(int value) {
  
  
  if (value <= 500) { // create states where the sensor can give values and we can read it and based on thoes values we can change the LEDS.
    digitalWrite(ledPin1, ledState);
    digitalWrite(ledPin2, ledState);
    digitalWrite(ledPin3, ledState);
    digitalWrite(ledPin4, ledState);
  }else if (value <= 600) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, ledState);
    digitalWrite(ledPin3, ledState);
    digitalWrite(ledPin4, ledState);
  }
  
  else if (value <= 700) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, ledState);
    digitalWrite(ledPin4, ledState);
  }
  
  else if (value <= 800) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, ledState);
  }
  
  else if (value <= 900) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW );
    digitalWrite(ledPin4, LOW);
  }
}
