#include "TXLib.h"

#include "Rotate.h"

//-----------------------------------------------------------------------------

struct Hero
    {
    int x, y, r, vx, vy;

    double rotate;

    COLORREF color;

    int keyRight, keyLeft, keyUp, keyDown, keyClockwise, keyCounterClockwise;
    };

//-----------------------------------------------------------------------------

void DrawXwing (const Hero* rebel);

void MoveHero();

void VehicleSpeed (struct Hero* rebel, int dt);

void HeroControl (struct Hero* rebel);

void myRectangle (int x1, int y1, int x2, int y2);

void DrawDeathStar (const Hero* star);

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
    Hero xWing     = { 141,  388, 4, 0, 0, 0, TX_YELLOW, 'D', 'A', 'W', 'S', 'E', 'Q' };

    Hero deathStar = { 1000, 503, 0, 0, 0, 0, TX_CYAN,   'L', 'J', 'I', 'K', 'O', 'U' };

    HDC fon = txLoadImage ("fon.bmp");

    int dt = 1;

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);

        if (! GetAsyncKeyState (VK_CONTROL)) txClear();

        txBitBlt (0, 0, fon);

        DrawXwing     (&xWing);

        VehicleSpeed  (&xWing, dt);

        HeroControl   (&xWing);

        DrawDeathStar (&deathStar);

        VehicleSpeed  (&deathStar, dt);

        HeroControl   (&deathStar);

        txSleep(10);
        }

    txDeleteDC (fon);
    }

//-----------------------------------------------------------------------------

void DrawXwing (const Hero* rebel)
    {
    txSetColor (rebel->color, 3);

    txSetFillColor (TX_NULL);

    myRectangle (rebel->x-50,  rebel->y-82, rebel->x-44,  rebel->y-72, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-44,  rebel->y-81, rebel->x-14,  rebel->y-75, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-35,  rebel->y-87, rebel->x-11,  rebel->y-81, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-14,  rebel->y-82, rebel->x-8,   rebel->y-72, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-28,  rebel->y-60, rebel->x-23,  rebel->y-51, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-25,  rebel->y-66, rebel->x-11,  rebel->y-57, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8,   rebel->y-79, rebel->x+16,  rebel->y-76, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+17,  rebel->y-78, rebel->x+64,  rebel->y-78, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+38,  rebel->y-84, rebel->x+38,  rebel->y-72, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-38,  rebel->y-75, rebel->x-46,  rebel->y-40, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y-72, rebel->x-11,  rebel->y-40, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-41,  rebel->y-60, rebel->x-35,  rebel->y-60, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-67,  rebel->y-39, rebel->x-67,  rebel->y-33, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-53,  rebel->y-40, rebel->x-37,  rebel->y-31, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-59,  rebel->y-31, rebel->x-53,  rebel->y-40, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-64,  rebel->y-40, rebel->x-59,  rebel->y-31, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-37,  rebel->y-45, rebel->x-25,  rebel->y-27, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-25,  rebel->y-36, rebel->x-13,  rebel->y-27, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-25,  rebel->y-36, rebel->x-13,  rebel->y-45, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-13,  rebel->y-45, rebel->x-2,   rebel->y-27, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-2,   rebel->y-42, rebel->x+3,   rebel->y-30, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y-27, rebel->x-11,  rebel->y-16, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y-16, rebel->x-53,  rebel->y-16, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-50,  rebel->y-31, rebel->x-55,  rebel->y-12, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-55,  rebel->y-12, rebel->x-55,  rebel->y+11, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y-16, rebel->x+91,  rebel->y-6,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+91,  rebel->y-7,  rebel->x+91,  rebel->y+8,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+91,  rebel->y-7,  rebel->x+119, rebel->y-4,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+119, rebel->y-4,  rebel->x+121, rebel->y-3,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+121, rebel->y-3,  rebel->x+122, rebel->y-1,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+122, rebel->y-1,  rebel->x+122, rebel->y+1,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+122, rebel->y+1,  rebel->x+121, rebel->y+3,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+121, rebel->y+3,  rebel->x+119, rebel->y+5,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+119, rebel->y+5,  rebel->x+91,  rebel->y+8,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+91,  rebel->y+7,  rebel->x-11,  rebel->y+17, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y+17, rebel->x-11,  rebel->y+27, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y+17, rebel-> x-53, rebel->y+17, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-55,  rebel->y+11, rebel->x-50,  rebel->y+32, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-53,  rebel->y+32, rebel->x-37,  rebel->y+41, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-53,  rebel->y+32, rebel->x-59,  rebel->y+41, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-59,  rebel->y+41, rebel->x-64,  rebel->y+32, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-67,  rebel->y+33, rebel->x-67,  rebel->y+39, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-37,  rebel->y+45, rebel->x-25,  rebel->y+27, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-25,  rebel->y+27, rebel->x-13,  rebel->y+36, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-25,  rebel->y+45, rebel->x-13,  rebel->y+36, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-13,  rebel->y+27, rebel->x-2,   rebel->y+45, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-2,   rebel->y+42, rebel->x+3,   rebel->y+30, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-46,  rebel->y+42, rebel->x-38,  rebel->y+75, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-11,  rebel->y+45, rebel->x-11,  rebel->y+74, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-28,  rebel->y+51, rebel->x-23,  rebel->y+60, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-11,  rebel->y+66, rebel->x-25,  rebel->y+56, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-41,  rebel->y+60, rebel->x-35,  rebel->y+60, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-50,  rebel->y+74, rebel->x-44,  rebel->y+83, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-44,  rebel->y+75, rebel->x-14,  rebel->y+81, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-14,  rebel->y+74, rebel->x-8,   rebel->y+83, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-35,  rebel->y+81, rebel->x-11,  rebel->y+87, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8,   rebel->y+77, rebel->x+16,  rebel->y+80, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+17,  rebel->y+78, rebel->x+64,  rebel->y+78, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+38,  rebel->y+72, rebel->x+38,  rebel->y+84, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x-55,  rebel->y+3,  rebel->x-11,  rebel->y-3,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-43,  rebel->y-16, rebel->x-43,  rebel->y+17, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-19,  rebel->y-16, rebel->x-19,  rebel->y+17, rebel->rotate, rebel->x, rebel->y);

    txCircle    (rebel->x,     rebel->y,    rebel->r);

    myLine      (rebel->x+11,  rebel->y-6,  rebel->x+11,  rebel->y+6,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+11,  rebel->y-6,  rebel->x+17,  rebel->y-12, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+11,  rebel->y+6,  rebel->x+17,  rebel->y+12, rebel->rotate, rebel->x, rebel->y);

    myRectangle (rebel->x+17,  rebel->y-3,  rebel->x+37,  rebel->y+4,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+37,  rebel->y,    rebel->x+85,  rebel->y,    rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+37,  rebel->y+1,  rebel->x+85,  rebel->y+1,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+98,  rebel->y,    rebel->x+113, rebel->y,    rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+98,  rebel->y+1,  rebel->x+98,  rebel->y+1,  rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+49,  rebel->y-9,  rebel->x+49,  rebel->y+10, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x+68,  rebel->y-7,  rebel->x+69,  rebel->y+8,  rebel->rotate, rebel->x, rebel->y);

    txSetColor (rebel->color, 2);

    myLine      (rebel->x-41,  rebel->y-54, rebel->x-36,  rebel->y-54, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-41,  rebel->y+65, rebel->x-36,  rebel->y+65, rebel->rotate, rebel->x, rebel->y);

    txSetColor (rebel->color, 1);

    myLine      (rebel->x-41,  rebel->y-65, rebel->x-33,  rebel->y-65, rebel->rotate, rebel->x, rebel->y);

    myLine      (rebel->x-41,  rebel->y+55, rebel->x-33,  rebel->y+55, rebel->rotate, rebel->x, rebel->y);

    printf ("угол равен %lg \n", rebel->rotate);
    }

//-----------------------------------------------------------------------------

void DrawDeathStar (const Hero* star)
    {
    txSetColor (star->color, 3);

    txSetFillColor (TX_NULL);

    myCircle (star->x-43,  star->y-42, 31,  star->rotate, star->x, star->y);

    myCircle (star->x-43,  star->y-42, 7,   star->rotate, star->x, star->y);

    myArc    (star->x,     star->y,    120, 82, 215,              star->rotate, star->x, star->y);

    myLine   (star->x-121, star->y,     star->x+119, star->y,     star->rotate, star->x, star->y);

    myLine   (star->x-121, star->y+3,   star->x+119, star->y+3,   star->rotate, star->x, star->y);

    myLine   (star->x+53,  star->y+106, star->x+53,  star->y+96,  star->rotate, star->x, star->y);

    myLine   (star->x+26,  star->y+96,  star->x+53,  star->y+96,  star->rotate, star->x, star->y);

    myLine   (star->x+35,  star->y+96,  star->x+35,  star->y+78,  star->rotate, star->x, star->y);

    myLine   (star->x+2,   star->y+78,  star->x+56,  star->y+78,  star->rotate, star->x, star->y);

    myLine   (star->x+2,   star->y+78,  star->x+2,   star->y+57,  star->rotate, star->x, star->y);

    myLine   (star->x-64,  star->y+57,  star->x+74,  star->y+57,  star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y+57,  star->x+23,  star->y+36,  star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y+36,  star->x+85,  star->y+36,  star->rotate, star->x, star->y);

    myLine   (star->x+85,  star->y+36,  star->x+85,  star->y+21,  star->rotate, star->x, star->y);

    myLine   (star->x+85,  star->y+21,  star->x+119, star->y+21,  star->rotate, star->x, star->y);

    myLine   (star->x+119, star->y+21,  star->x+119, star->y-18,  star->rotate, star->x, star->y);

    myLine   (star->x+119, star->y-18,  star->x+89,  star->y-18,  star->rotate, star->x, star->y);

    myLine   (star->x+89,  star->y-18,  star->x+89,  star->y-38,  star->rotate, star->x, star->y);

    myLine   (star->x+50,  star->y-38,  star->x+95,  star->y-38,  star->rotate, star->x, star->y);

    myLine   (star->x+56,  star->y-38,  star->x+56,  star->y-60,  star->rotate, star->x, star->y);

    myLine   (star->x+65,  star->y-60,  star->x+20,  star->y-60,  star->rotate, star->x, star->y);

    myLine   (star->x+29,  star->y-60,  star->x+29,  star->y-81,  star->rotate, star->x, star->y);

    myLine   (star->x+77,  star->y-81,  star->x+11,  star->y-81,  star->rotate, star->x, star->y);

    myLine   (star->x+41,  star->y-81,  star->x+41,  star->y-99,  star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y-81,  star->x+50,  star->y-81,  star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y-99,  star->x+50,  star->y-99,  star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y-99,  star->x+23,  star->y-117, star->rotate, star->x, star->y);

    myLine   (star->x+23,  star->y-118, star->x+15,  star->y-118, star->rotate, star->x, star->y);
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

    if (GetAsyncKeyState (rebel->keyClockwise))        rebel->rotate += 3;

    if (GetAsyncKeyState (rebel->keyCounterClockwise)) rebel->rotate -= 3;
    }
