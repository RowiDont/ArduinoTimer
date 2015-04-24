//Constants
const int buttonPin = 2;
const int playLED = 11;
const int pauseLED = 12;


//Vars that will change
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
int time1 = 0;
int time2 = 0;
int now = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(playLED, OUTPUT);
  pinMode(pauseLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
    }
  }
  lastButtonState = buttonState;
  
  if ((buttonPushCounter % 2) == 0 && buttonPushCounter != 0) {
    digitalWrite(playLED, LOW);
    digitalWrite(pauseLED, HIGH);
  }
  if (buttonPushCounter == 0) {
    time1 = millis();
    now = millis();
  }
  if ((buttonPushCounter %2) != 0 && buttonPushCounter > 0) {
    digitalWrite(playLED, HIGH);
    digitalWrite(pauseLED, LOW);
    
    if (millis() - now > 10) {
      time1 = time1 + (millis() - now);
    }
    time2 = millis()-time1;
    now = millis();
  }
  
  if (time2 > 90000) {
    buttonPushCounter = 0;
    digitalWrite(playLED, HIGH);
    digitalWrite(pauseLED, HIGH);
  }
  
}
