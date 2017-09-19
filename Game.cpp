#include "TXLib.h"

//-----------------------------------------------------------------------------

struct Hero
    {
    int x, y, r, vx, vy;

    int keyRight, keyLeft, keyUp, keyDown;
    };

//-----------------------------------------------------------------------------

void DrawXwing (Hero* rebel);

void MoveHero();

void VehicleSpeed (struct Hero* rebel, int dt);

void HeroControl (struct Hero* rebel);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    txSetFillColor (TX_WHITE);

    txClear();

    MoveHero();

    return 0;
    }

//-----------------------------------------------------------------------------

void MoveHero()
    {
    Hero xWing = { 141, 388, 4, 0, 0, 'D', 'A', 'W', 'S' };

    int dt = 1;

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);

        if (! GetAsyncKeyState (VK_CONTROL)) txClear();

        DrawXwing    (&xWing);

        VehicleSpeed (&xWing, dt);

        HeroControl  (&xWing);

        txSleep(10);
        }
    }

//-----------------------------------------------------------------------------

void DrawXwing (Hero* rebel)
    {
    txSetColor (TX_BLACK, 3);

    txSetFillColor (TX_WHITE);

    txRectangle (rebel->x-50,  rebel->y-82, rebel->x-44,  rebel->y-72);

    txRectangle (rebel->x-44,  rebel->y-81, rebel->x-14,  rebel->y-75);

    txRectangle (rebel->x-35,  rebel->y-87, rebel->x-11,  rebel->y-81);

    txRectangle (rebel->x-14,  rebel->y-82, rebel->x-8,   rebel->y-72);

    txRectangle (rebel->x-28,  rebel->y-60, rebel->x-23,  rebel->y-51);

    txRectangle (rebel->x-25,  rebel->y-66, rebel->x-11,  rebel->y-57);

    txSetFillColor (TX_BLACK);

    txRectangle (rebel->x-8,   rebel->y-79, rebel->x+16,  rebel->y-76);

    txLine      (rebel->x+17,  rebel->y-78, rebel->x+64,  rebel->y-78);

    txLine      (rebel->x+38,  rebel->y-84, rebel->x+38,  rebel->y-72);

    txLine      (rebel->x-38,  rebel->y-75, rebel->x-46,  rebel->y-40);

    txLine      (rebel->x-11,  rebel->y-72, rebel->x-11,  rebel->y-40);

    txLine      (rebel->x-41,  rebel->y-60, rebel->x-35,  rebel->y-60);

    txLine      (rebel->x-67,  rebel->y-39, rebel->x-67,  rebel->y-33);

    txSetFillColor (TX_WHITE);

    txRectangle (rebel->x-53,  rebel->y-40, rebel->x-37,  rebel->y-31);

    txRectangle (rebel->x-59,  rebel->y-31, rebel->x-53,  rebel->y-40);

    txRectangle (rebel->x-64,  rebel->y-40, rebel->x-59,  rebel->y-31);

    txRectangle (rebel->x-37,  rebel->y-45, rebel->x-25,  rebel->y-27);

    txRectangle (rebel->x-25,  rebel->y-36, rebel->x-13,  rebel->y-27);

    txRectangle (rebel->x-25,  rebel->y-36, rebel->x-13,  rebel->y-45);

    txRectangle (rebel->x-13,  rebel->y-45, rebel->x-2,   rebel->y-27);

    txRectangle (rebel->x-2,   rebel->y-42, rebel->x+3,   rebel->y-30);

    txLine      (rebel->x-11,  rebel->y-27, rebel->x-11,  rebel->y-16);

    txLine      (rebel->x-11,  rebel->y-16, rebel->x-53,  rebel->y-16);

    txLine      (rebel->x-50,  rebel->y-31, rebel->x-55,  rebel->y-12);

    txLine      (rebel->x-55,  rebel->y-12, rebel->x-55,  rebel->y+11);

    txLine      (rebel->x-11,  rebel->y-16, rebel->x+91,  rebel->y-6);

    txLine      (rebel->x+91,  rebel->y-7,  rebel->x+91,  rebel->y+8);

    txLine      (rebel->x+91,  rebel->y-7,  rebel->x+119, rebel->y-4);

    txLine      (rebel->x+119, rebel->y-4,  rebel->x+121, rebel->y-3);

    txLine      (rebel->x+121, rebel->y-3,  rebel->x+122, rebel->y-1);

    txLine      (rebel->x+122, rebel->y-1,  rebel->x+122, rebel->y+1);

    txLine      (rebel->x+122, rebel->y+1,  rebel->x+121, rebel->y+3);

    txLine      (rebel->x+121, rebel->y+3,  rebel->x+119, rebel->y+5);

    txLine      (rebel->x+119, rebel->y+5,  rebel->x+91,  rebel->y+8);

    txLine      (rebel->x+91,  rebel->y+7,  rebel->x-11,  rebel->y+17);

    txLine      (rebel->x-11,  rebel->y+17, rebel->x-11,  rebel->y+27);

    txLine      (rebel->x-11,  rebel->y+17, rebel-> x-53, rebel->y+17);

    txLine      (rebel->x-55,  rebel->y+11, rebel->x-50,  rebel->y+32);

    txRectangle (rebel->x-53,  rebel->y+32, rebel->x-37,  rebel->y+41);

    txRectangle (rebel->x-53,  rebel->y+32, rebel->x-59,  rebel->y+41);

    txRectangle (rebel->x-59,  rebel->y+41, rebel->x-64,  rebel->y+32);

    txLine      (rebel->x-67,  rebel->y+33, rebel->x-67,  rebel->y+39);

    txRectangle (rebel->x-37,  rebel->y+45, rebel->x-25,  rebel->y+27);

    txRectangle (rebel->x-25,  rebel->y+27, rebel->x-13,  rebel->y+36);

    txRectangle (rebel->x-25,  rebel->y+45, rebel->x-13,  rebel->y+36);

    txRectangle (rebel->x-13,  rebel->y+27, rebel->x-2,   rebel->y+45);

    txRectangle (rebel->x-2,   rebel->y+42, rebel->x+3,   rebel->y+30);

    txLine      (rebel->x-46,  rebel->y+42, rebel->x-38,  rebel->y+75);

    txLine      (rebel->x-11,  rebel->y+45, rebel->x-11,  rebel->y+74);

    txRectangle (rebel->x-28,  rebel->y+51, rebel->x-23,  rebel->y+60);

    txRectangle (rebel->x-11,  rebel->y+66, rebel->x-25,  rebel->y+56);

    txLine      (rebel->x-41,  rebel->y+60, rebel->x-35,  rebel->y+60);

    txRectangle (rebel->x-50,  rebel->y+74, rebel->x-44,  rebel->y+83);

    txRectangle (rebel->x-44,  rebel->y+75, rebel->x-14,  rebel->y+81);

    txRectangle (rebel->x-14,  rebel->y+74, rebel->x-8,   rebel->y+83);

    txRectangle (rebel->x-35,  rebel->y+81, rebel->x-11,  rebel->y+87);

    txSetFillColor (TX_BLACK);

    txRectangle (rebel->x-8,   rebel->y+77, rebel->x+16,  rebel->y+80);

    txLine      (rebel->x+17,  rebel->y+78, rebel->x+64,  rebel->y+78);

    txLine      (rebel->x+38,  rebel->y+72, rebel->x+38,  rebel->y+84);

    txRectangle (rebel->x-55,  rebel->y+3,  rebel->x-11,  rebel->y-3);

    txLine      (rebel->x-43,  rebel->y-16, rebel->x-43,  rebel->y+17);

    txLine      (rebel->x-19,  rebel->y-16, rebel->x-19,  rebel->y+17);

    txCircle    (rebel->x,     rebel->y,    rebel->r);

    txLine      (rebel->x+11,  rebel->y-6,  rebel->x+11,  rebel->y+6);

    txLine      (rebel->x+11,  rebel->y-6,  rebel->x+17,  rebel->y-12);

    txLine      (rebel->x+11,  rebel->y+6,  rebel->x+17,  rebel->y+12);

    txRectangle (rebel->x+17,  rebel->y-3,  rebel->x+37,  rebel->y+4);

    txLine      (rebel->x+37,  rebel->y,    rebel->x+85,  rebel->y);

    txLine      (rebel->x+37,  rebel->y+1,  rebel->x+85,  rebel->y+1);

    txLine      (rebel->x+98,  rebel->y,    rebel->x+113, rebel->y);

    txLine      (rebel->x+98,  rebel->y+1,  rebel->x+98,  rebel->y+1);

    txLine      (rebel->x+49,  rebel->y-9,  rebel->x+49,  rebel-> y+10);

    txLine      (rebel->x+68,  rebel->y-7,  rebel->x+69,  rebel->y+8);

    txSetColor (TX_BLACK, 2);

    txLine      (rebel->x-41,  rebel->y-54, rebel->x-36,  rebel->y-54);

    txLine      (rebel->x-41,  rebel->y+65, rebel->x-36,  rebel->y+65);

    txSetColor (TX_BLACK, 1);

    txLine      (rebel->x-41,  rebel->y-65, rebel->x-33,  rebel->y-65);

    txLine      (rebel->x-41,  rebel->y+55, rebel->x-33,  rebel->y+55);
    }

//-----------------------------------------------------------------------------

void VehicleSpeed (Hero* rebel, int dt)
    {
    rebel->x = rebel->x + rebel->vx * dt;

    rebel->y = rebel->y + rebel->vy * dt;

    if (rebel->x > txGetExtentX() - rebel->r)
        {
        rebel->vx = -rebel->vx;

        rebel->x = txGetExtentX() - rebel->r;
        }

    if (rebel->y > txGetExtentY() - rebel->r)
        {
        rebel->vy = -rebel->vy;

        rebel->y = txGetExtentY() - rebel->r;
        }

    if (rebel->x < 0 + rebel->r)
        {
        rebel->vx = -rebel->vx;

        rebel->x = 0 + rebel->r;
        }

    if (rebel->y < 0 + rebel->r)
        {
        rebel->vy = -rebel->vy;

        rebel->y = 0 + rebel->r;
        }
    }

//-----------------------------------------------------------------------------

void HeroControl (struct Hero* rebel)
    {
    if (GetAsyncKeyState (rebel->keyRight)) rebel->vx += 1;

    if (GetAsyncKeyState (rebel->keyLeft))  rebel->vx -= 1;

    if (GetAsyncKeyState (rebel->keyUp))    rebel->vy -= 1;

    if (GetAsyncKeyState (rebel->keyDown))  rebel->vy += 1;
    }
