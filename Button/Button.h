int defaultZeroAnalog = 0;
class stateManager//This class is used to store state of button and its value with little proccessing.
{
public:
    int prevValue, *currentValue, value;
    int threshold = 0;
    int buffer = 0;
    stateManager(int *value, int threshold = 0, int buffer = 0)
    {
        this->buffer = buffer;
        this->threshold = threshold;
        currentValue = value;
        prevValue = *value;
    }

    bool check()
    {
        if (prevValue != *currentValue )
        {
            
            if (*currentValue != 0 && *currentValue != 1 && abs(*currentValue - prevValue) < threshold)
            {
                return false;
            }
            prevValue = *currentValue;
            
            if (abs(*currentValue) < buffer)
            {
                if(value==0) return false;
                value=0;
            }
            else
            {
                value = *currentValue;
            }
            return true;
        }
        return false;
    }
};
class Button
{
public:
    stateManager *currentValue1;
    stateManager *currentValue;
    stateManager *currentState;
    Button(int *btn, int *btnValue = &defaultZeroAnalog, int *btnValue1 = &defaultZeroAnalog)
    {
        SetButton();
        this->currentValue1 = new stateManager(btnValue1, 6, 15);// for change in Y
        this->currentState = new stateManager(btn);
        this->currentValue = new stateManager(btnValue, 6, 15); // for change in X
    }
    Button(){};
    void SetButton();
    void (*buttonPressed)() = none;
    void (*buttonReleased)() = none;
    void (*buttonValueChangeX)(int v) = none;
    void (*buttonValueChangeY)(int v) = none;
    void attachRelease(void (*f)())
    {
        this->buttonReleased = f;
    }
    void attachPress(void (*f)())
    {
        this->buttonPressed = f;
    }
    void attachAnalogX(void (*f)(int v))
    {
        this->buttonValueChangeX = f;
    }
    void attachAnalogY(void (*f)(int v))
    {
        this->buttonValueChangeY = f;
    }
    void update()
    {
        if (currentValue->check())
        {
            buttonValueChangeX(currentValue->value);
        }
        if (currentValue1->check())
        {
            buttonValueChangeY(currentValue1->value);
        }
        if (currentState->check())
        {
            if (currentState->value)
            {
                buttonPressed();
            }
            else
            {
                buttonReleased();
                // buttonValueChangeX(0);
                // buttonValueChangeY(0);
            }
        }
    }
};
Button *allButton[25];
int buttonIndex = 0;
void Button::SetButton()
{
    allButton[buttonIndex++] = this;
}
void updateAllButtons()
{
    for (int i = 0; i < buttonIndex; i++)
    {
        allButton[i]->update();
    }
}
