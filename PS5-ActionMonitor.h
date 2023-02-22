#include <ps5Controller.h>
#include "Updater/Updater.h"
void none(){};
void none(int v){};
void none(int lx,int ly,int rx,int ry,int r){};
void none(int x,int y,int r){};
#include "Button/Button.h"
#include "Movement/Movement.h"
#include "DirectionalMovement/DirectionalMovement.h"
#include "AllListner/AllListner.h"

void updateAllEntities()
{
    Ps5.update();
    updateAllButtons();
}
void initPS5(String addr)
{
    ps5.begin(addr.c_str());
    ps5.attach(updateAllEntities);
}
