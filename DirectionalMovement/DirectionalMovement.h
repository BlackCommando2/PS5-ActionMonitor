//This file is used to combine joystick , l2 and r2 button to get x,y and r for movement of any robot
void leftJoyStickX(int v);
void leftJoyStickY(int v);
void rightJoyStickX(int v);
void rightJoyStickY(int v);
void analog_l2Btn(int v);
void analog_r2Btn(int v);
class DirectionalMovement
{
public:
    Button *leftJoyStick;
    Button *rightJoyStick;
    Button *r2, *l2;
    void attachObject();
    double outputRightX,outputRightY,outputLeftX,outputLeftY,outputR;
    void (*allDataValueChange)(int lX,int lY,int rX,int rY,int r) = none;
    DirectionalMovement(Button *leftJoyStick,Button *rightJoyStick, Button *r2, Button *l2)
    {
        this->leftJoyStick = leftJoyStick;
        this->rightJoyStick = rightJoyStick;
        this->r2 = r2;
        this->l2 = l2;
        attachAllOutput();
        attachObject();
    }
    void attachAllOutput()
    {
        leftJoyStick->attachAnalogX(leftJoyStickX);
        leftJoyStick->attachAnalogY(leftJoyStickY);
        rightJoyStick->attachAnalogX(rightJoyStickX);
        rightJoyStick->attachAnalogY(rightJoyStickY);
        r2->attachAnalogX(analog_r2Btn);
        l2->attachAnalogX(analog_l2Btn);
    }
    void m_leftJoyStickX(int v)
    {
        if (v != 0)
            outputLeftX = map(v, -128, 127, -255, 255);
        else
            outputLeftX = 0;
        sendData();
    }
    void m_leftJoyStickY(int v)
    {
        if (v != 0)
            outputLeftY = map(v, -128, 127, -255, 255);
        else
            outputLeftY = 0;
        sendData();
    }
    void m_rightJoyStickX(int v)
    {
        if (v != 1 && v != 0)
            if(v<0)
                outputRightX = map(v, -128, -1, -255, -1);
            else
                outputRightX = map(v,1,127,1,255);
            
        else
            // outputRightY = 0;
            outputRightX = 1;
        sendData();
    }
    void m_rightJoyStickY(int v)
    {
        if (v != 1 && v != 0)
            if(v<0)
                outputRightY = map(v, -128, -1, -255, -1);
            else
                outputRightY = map(v,1,127,1,255);
            
        else
            // outputRightY = 0;
            outputRightY = 1;
        sendData();
    }
    void m_l2Btn(int v)
    {
        outputR=v*(-1);
        sendData();
    }
    void m_r2Btn(int v)
    {
        outputR=v;
        sendData();
    }
    void sendData()
    {
        // printData();//uncomment to print data from library
        allDataValueChange(outputLeftX,outputLeftY,outputRightX,outputRightY,outputR);
    }
    void printData()
    {
        Serial.println(String(outputLeftX)+","+String(outputLeftY)+","+String(outputLeftX)+","+String(outputLeftY)+","+String(outputR));

    }
    void attachAllAnalogData(void (*f)(int lX,int lY,int rX,int rY,int r))
    {
        this->allDataValueChange=f;
    }
};
DirectionalMovement *directionalMovementObject;
void DirectionalMovement::attachObject(){
    directionalMovementObject=this;
}
void leftJoyStickX(int v)
{
    directionalMovementObject->m_leftJoyStickX(v);
}
void leftJoyStickY(int v)
{
    directionalMovementObject->m_leftJoyStickY(v);
}
void rightJoyStickX(int v)
{
    directionalMovementObject->m_rightJoyStickX(v);
}
void rightJoyStickY(int v)
{
    directionalMovementObject->m_rightJoyStickY(v);
}
void analog_l2Btn(int v)
{
    directionalMovementObject->m_l2Btn(v);
}
void analog_r2Btn(int v)
{
    directionalMovementObject->m_r2Btn(v);
}