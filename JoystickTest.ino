//Pins
int pinAccell = A0;

//Accelerator vars
int accInVal = 512;
int accMinInVal = 1024;
int accMaxInVal = 0;
float accRange = 0.0f;

void setup() {
  // put your setup code here, to run once:
    Joystick.begin();
}

int clamp(int input)
{
  if (input>127)
    return 127;
  if (input<-127)
    return -127;
   return input;
}

void loop() {
  
    accInVal = analogRead(pinAccell);

    if (accInVal>accMaxInVal) 
    {
      accMaxInVal = accInVal;
      accRange = accMaxInVal - accMinInVal;      
    }
    if (accInVal<accMinInVal)
    {
      accMinInVal = accInVal;
      accRange = accMaxInVal - accMinInVal;
    }

    if (accRange>0) {
      int outputValue = clamp(((accInVal - accMinInVal) / accRange * 256)-128);
      Joystick.setXAxis(outputValue);
    }

    Joystick.sendState();


}
