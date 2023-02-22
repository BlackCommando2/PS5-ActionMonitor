Button square(&Ps5.square);
Button cross(&Ps5.cross);
Button triangle(&Ps5.triangle);
Button circle(&Ps5.circle);

Button up(&Ps5.up);
Button down(&Ps5.down);
Button left(&Ps5.left);
Button right(&Ps5.right);

Button upRight(&Ps5.upRight);
Button downRight(&Ps5.downRight);
Button upLeft(&Ps5.upLeft);
Button downLeft(&Ps5.downLeft);

Button l1(&Ps5.l1);
Button r1(&Ps5.r1);
Button l2(&Ps5.l2,&Ps5.l2Value);
Button r2(&Ps5.r2,&Ps5.r2Value);

Button lJoystick(&Ps5.l3,&Ps5.lStickX,&Ps5.lStickY);
Button rJoystick(&Ps5.r3,&Ps5.rStickX,&Ps5.rStickY);

Button share(&Ps5.share);
Button options(&Ps5.options);
Button psButton(&Ps5.psButton);
Button touchpad(&Ps5.touchpad);

Movement leftJoystick(&lJoystick,&r2,&l2);  // comment this to use DirectionalMovement

//DirectionalMovement allAnalog(&lJoystick,&rJoystick,&r2,&l2); // comment out this to all analog values