//Pins
int pinAccell = A0;
int pinBrake = A1;
int pinClutch = A2;

//Accelerator vars
int accInVal = 512;
int accMinInVal = 1024;
int accMaxInVal = 0;
float accRange = 0.0f;

//Brake vars
int brkInVal = 512;
int brkMinInVal = 1024;
int brkMaxInVal = 0;
float brkRange = 0.0f;

//Clutch vars
int cltInVal = 512;
int cltMinInVal = 1024;
int cltMaxInVal = 0;
float cltRange = 0.0f;


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

float getStickValue(int inputValue, int minReading, int range) 
{
    return ((inputValue - minReading) / range * 256)-128;
}

void loop() {

  
    //Accel
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
      int outputValue =clamp(getStickValue(accInVal, accMinInVal, accRange));
      Joystick.setXAxis(outputValue);
    }

    //Brake
    brkInVal = analogRead(pinBrake);
    
    if (brkInVal>brkMaxInVal) 
    {
      brkMaxInVal = brkInVal;
      brkRange = brkMaxInVal - brkMinInVal;      
    }
    if (brkInVal<brkMinInVal)
    {
      brkMinInVal = brkInVal;
      brkRange = brkMaxInVal - brkMinInVal;
    }

    if (brkRange>0) {
      int outputValue =clamp(getStickValue(brkInVal, brkMinInVal, brkRange));
      Joystick.setYAxis(outputValue);
    }

    //Clutch
    cltInVal = analogRead(pinClutch);
    
    if (cltInVal>cltMaxInVal) 
    {
      cltMaxInVal = cltInVal;
      cltRange = cltMaxInVal - cltMinInVal;      
    }
    if (cltInVal<cltMinInVal)
    {
      cltMinInVal = cltInVal;
      cltRange = cltMaxInVal - cltMinInVal;
    }

    if (cltRange>0) {
      int outputValue =clamp(getStickValue(cltInVal, cltMinInVal, cltRange));
      Joystick.setZAxis(outputValue);
    }
    

    Joystick.sendState();
}
