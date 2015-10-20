int x;

void setup() {
  // put your setup code here, to run once:
  Joystick.begin();
  x=-127;
}

void loop() {
  // put your main code here, to run repeatedly:
  Joystick.setXAxis(x);
  Joystick.sendState();
  x++;
  if (x==127)
  x=-127;y
  
  delay(50);
}
