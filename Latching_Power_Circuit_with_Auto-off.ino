// C++ code
//
const int analogSensor = A0;
const int digitalSensor = 2;
const int relayTransistor = 8;
const int ledActive = 10;
const int ledIdle = 11;

void setup() {
  pinMode(digitalSensor, INPUT);
  pinMode(relayTransistor, OUTPUT);
  pinMode(ledActive, OUTPUT);
  pinMode(ledIdle, OUTPUT);
  
  digitalWrite(relayTransistor, HIGH);  // Turn ON relay to keep system running
}

void loop() {
  int analogValue = analogRead(analogSensor);
  int digitalValue = digitalRead(digitalSensor);

  if (analogValue > 200 || digitalValue == HIGH) {
    digitalWrite(ledActive, HIGH);
    digitalWrite(ledIdle, LOW);
    digitalWrite(relayTransistor, HIGH); // Keep relay ON
  } else {
    // Blink warning before shutdown
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledIdle, HIGH);
      delay(100);
      digitalWrite(ledIdle, LOW);
      delay(100);
    }
    digitalWrite(ledActive, LOW);
    digitalWrite(relayTransistor, LOW); // Shut off relay = power OFF
  }

  delay(100);
}

