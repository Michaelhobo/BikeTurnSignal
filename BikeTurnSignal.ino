int on_coil = 8;
int off_coil = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(on_coil, OUTPUT);
  pinMode(off_coil, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  EL_on();
  delay(1000);
  EL_off();
  delay(1000);
}

/* Turn EL panel on */
void EL_on() {
  digitalWrite(off_coil, LOW);
  digitalWrite(on_coil, HIGH);
}

/* Turn El panel off */
void EL_off() {
  digitalWrite(on_coil, LOW);
  digitalWrite(off_coil, HIGH);
}

