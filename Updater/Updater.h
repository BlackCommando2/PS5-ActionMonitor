class Updater
{
public:
    int square, circle, triangle, cross;
    int right, down, up, left;
    int upRight, downRight, upLeft, downLeft;
    int l2, r2, l1, r1;
    int l2Value, r2Value;
    int lStickX, lStickY, l3, rStickX, rStickY, r3;
    int share, options, psButton, touchpad;
    ps5Controller *ps5;
    Updater(ps5Controller *ps5)
    {
        this->ps5 = ps5;
    }
    void update() // Update all the button data
    {
        square = ps5->Square();
        circle = ps5->Circle();
        triangle = ps5->Triangle();
        cross = ps5->Cross();

        right = ps5->Right();
        left = ps5->Left();
        up = ps5->Up();
        down = ps5->Down();

        upRight = ps5->UpRight();
        downRight = ps5->DownRight();
        upLeft = ps5->UpLeft();
        downLeft = ps5->DownLeft();

        l1 = ps5->L1();
        r1 = ps5->R1();
        l2Value = ps5->L2Value();
        r2Value = ps5->R2Value();
        l2 = ps5->L2();
        r2 = ps5->R2();

        lStickX = ps5->LStickX();
        lStickY = ps5->LStickY();
        l3 = ps5->L3();

        rStickX = ps5->RStickX();
        rStickY = ps5->RStickY();
        r3 = ps5->R3();

        share = ps5->Share();
        options = ps5->Options();
        psButton = ps5->PSButton();
        touchpad = ps5->Touchpad();
    }

} Ps5(&ps5);