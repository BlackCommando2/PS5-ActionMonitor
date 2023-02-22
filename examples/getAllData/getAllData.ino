//#include <EspNow.h>
#include <PS5-ActionMonitor.h>
//JSONVar msg;
//Peer remote;
int selectType, val1, val2, val3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initPS5("50:E0:85:A5:99:BA");
  //setId("TenZZ");
  //  remote.init("WardL");
  //Attaching function with buttons
  square.attachPress(sqaurePressed);
  square.attachRelease(sqaureReleased);

  circle.attachPress(circlePressed);
  circle.attachRelease(circleReleased);

  triangle.attachPress(trianglePressed);
  triangle.attachRelease(triangleReleased);

  cross.attachPress(crossPressed);
  cross.attachRelease(crossReleased);

  up.attachPress(upPressed);
  up.attachRelease(upReleased);

  down.attachPress(downPressed);
  down.attachRelease(downReleased);

  left.attachPress(leftPressed);
  left.attachRelease(leftReleased);

  right.attachPress(rightPressed);
  right.attachRelease(rightReleased);

  l1.attachPress(l1Pressed);
  l1.attachRelease(l1Released);

  r1.attachPress(r1Pressed);
  r1.attachRelease(r1Released);


  rJoystick.attachAnalogX(rightjoystickX); // comment this for DirectionalMovement to avoid possible conflicts
  rJoystick.attachAnalogY(rightjoystickY);// comment this for DirectionalMovement to avoid possible conflicts

  share.attachPress(sharePressed);
  share.attachRelease(shareReleased);

  options.attachPress(optionPressed);
  options.attachRelease(optionReleased);

  psButton.attachPress(psPressed);
  psButton.attachRelease(psReleased);

  touchpad.attachPress(touchpadPressed);
  touchpad.attachRelease(touchpadReleased);

  leftJoystick.attachAllData(base);
  //allAnalog.attachAllAnalogData(directionalBase);
  //uncomment this to use both joystick and r analog together + uncomment allAnalog in AllListner.h and comment leftJoystick in AllListner.h
}
int lx, ly, rightX, rightY;
void loop()
{
  if (Serial.available())
  {
    selectType = Serial.readStringUntil(',').toInt();
    val1 = Serial.readStringUntil(',').toInt();
    val2 = Serial.readStringUntil(',').toInt();
    val3 = Serial.readStringUntil('\n').toInt();
    if (selectType != 1 && selectType != 2 && selectType != 3)
    {
      Serial.println("Enter 1st Value as 1 or 2 or 3");
    }
    else
    {
      if (selectType == 1)
      {
        setLedVal(val1, val2, val3);
      }
      else if (selectType == 2)
      {
        setRumbleVal(val1, val2);
      }
      else if (selectType == 3)
      {
        setFlashRateVal(val1, val2);
      }
    }
  }
}
void rightjoystickX(int v)
{
  rightX = v;
  Serial.println("RightJoystick=" + String(rightX) + "," + String(rightY));
}
void rightjoystickY(int v)
{
  rightY = v;
  Serial.println("RightJoystick=" + String(rightX) + "," + String(rightY));
}
void l1Pressed()
{
  Serial.println("l1 Pressed");
}
void l1Released()
{
  Serial.println("l1 Released");
}

void r1Pressed()
{
  Serial.println("r1 Pressed");
}
void r1Released()
{
  Serial.println("r1 Released");
}

void crossPressed()
{
  Serial.println("crossPressed");
}
void crossReleased()
{
  Serial.println("crossReleased");
}

void circlePressed()
{
  Serial.println("circlePressed");
}
void circleReleased()
{
  Serial.println("circlePressed");
}

void trianglePressed()
{
  Serial.println("trianglePressed");
}
void triangleReleased()
{
  Serial.println("triangleReleased");
}

void sqaurePressed()
{
  Serial.println("sqaure pressed");
}
void sqaureReleased()
{
  Serial.println("sqaure Released");
}

void upPressed()
{
  Serial.println("up pressed");
}
void upReleased()
{
  Serial.println("up Released");
}

void downPressed()
{
  Serial.println("down pressed");
}
void downReleased()
{
  Serial.println("down Released");
}

void leftPressed()
{
  Serial.println("left pressed");
}
void leftReleased()
{
  Serial.println("left Released");
}

void rightPressed()
{
  Serial.println("right pressed");
}
void rightReleased()
{
  Serial.println("right Released");
}

void sharePressed()
{
  Serial.println("share pressed");
}
void shareReleased()
{
  Serial.println("share Released");
}

void optionPressed()
{
  Serial.println("option pressed");
}
void optionReleased()
{
  Serial.println("option Released");
}

void psPressed()
{
  Serial.println("ps pressed");
}
void psReleased()
{
  Serial.println("ps Released");
}

void touchpadPressed()
{
  Serial.println("touchpad pressed");
}
void touchpadReleased()
{
  Serial.println("touchpad Released");
}
void base(int x, int y, int r)
{
  //  msg["type"]="drive";
  //  msg["fx"]=x;
  //  msg["fy"]=y;
  //  msg["fr"]=r;
  //  remote.send(msg);
  Serial.println("X=" + String(x) + " ,Y=" + String(y) + " ,R=" + String(r));
}
void directionalBase(int lX, int lY, int rX, int rY, int r)
{
  Serial.println("lX: " + String(lX) + " lY: " + String(lY) + "rX: " + String(rX) + " lY: " + String(rY) + "," + String(r));
}

void setLedVal(int r, int g, int b)
{
  ps5.setLed(uint8_t(r), uint8_t(g), uint8_t(b));
}

void setRumbleVal(int small, int large)
{
  ps5.setRumble(uint8_t(small), uint8_t(large));
}

void setFlashRateVal(int onTime, int offTime)
{
  ps5.setFlashRate(uint8_t(onTime), uint8_t(offTime));
}