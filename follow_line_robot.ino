
int sensR = 7;
int sensL = 4;
int M1 = 11;
int M2 = 10;
int M3 = 9;
int M4 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(sensL, INPUT);
  pinMode(sensR, INPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
}

void loop() {

  int r = digitalRead(sensR);
  int l = digitalRead(sensL);
  if (r == 0 && l == 0) {
    fw();
  }

  if (r == 1 && l == 1) {
    stop();
  }

  if (l == 0 && r == 1 ) {
    tr();
  }

  if (l == 1 && r == 0) {
    tl();
  }
}

void fw() {
  analogWrite(M1, 70);
  analogWrite(M2, 0);
  analogWrite(M3, 70);
  analogWrite(M4, 0);
}

void stop() {
  analogWrite(M1, 0);
  analogWrite(M2, 0);
  analogWrite(M3, 0);
  analogWrite(M4, 0);
}

void tl() {
  analogWrite(M1, 160);
  analogWrite(M2, 0);
  analogWrite(M3, 0);
  analogWrite(M4, 160);
}

void tr() {
  analogWrite(M1, 0);
  analogWrite(M2, 160);
  analogWrite(M3, 160);
  analogWrite(M4, 0);
}
