int GSM1 = 3;

// ******Parameter******
int forward = true;
int reverse = true;
int maxspeed = 50;
int spinning_time = 10000;
int pause_time = 3000;
// ******Parameter******

#define In1 5
#define In2 6

void setup() {
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(GSM1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (forward) {
    startSpin();
    delay(spinning_time);
  }
  stopSpin();
  if (reverse) {
    reverseSpin();
    delay(spinning_time);
    stopSpin();
  }
  delay(pause_time);
}

void startSpin() {
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i);
    Serial.println(i);
    delay(50);
  }
}

void reverseSpin() {
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  for (int i = 0; i <= maxspeed; i += 1) {
    analogWrite(GSM1, i);
    Serial.println(i);

    delay(50);
  }
}

void stopSpin() {
  for (int i = maxspeed; i >= 0; i -= 1) {
    analogWrite(GSM1, i);
    delay(50);
  }
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
}
