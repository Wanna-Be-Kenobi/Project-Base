//#define _TX_ALLOW_TRACE 9

#include "TXLib.h"

#include "Rotate.h"

//-----------------------------------------------------------------------------

struct Hero
    {
    double x, y, vx, vy;

    double r, scale;

    HDC image;

    double rotate;

    COLORREF color;

    int keyForward, keyBackwards, keyBrake, keyClockwise, keyCounterClockwise, keyCloser, keyFarther;
    };

//-----------------------------------------------------------------------------

void DrawXwing (const Hero* rebel);

void MoveHero();

void VehicleSpeed (struct Hero* rebel, double dt);

void HeroControl (struct Hero* rebel);

void myRectangle (double x1, double y1, double x2, double y2);

void DrawDeathStar (const Hero* star);

void DrawPlanet (const Hero* planet);

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
    Hero xWing     = { 141,  388,  1, 1, 100, 0.5, NULL,  0.785, TX_YELLOW, 'W', 'S', VK_RSHIFT, 'E', 'Q', VK_F1, VK_F2 };

    Hero deathStar = { 1000, 503,  0, 0, 120, 1,   NULL,  3.14,  TX_CYAN,   'I', 'K', VK_LSHIFT, 'O', 'U'               };

    Hero planet    = { 1500, 750,  0, 0, 136, 1,   txLoadImage ("planet.bmp")                                           };

    HDC fon        = txLoadImage ("Background.bmp");

    double dt = 1;

    double t  = 0;

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);

        txClear();

        txAlphaBlend (txDC(), 0,     0, 1920, 1080,      fon,    0,  0                          );

        txAlphaBlend (txDC(), 0,     0, 1920, 1080,      fon, 1920,  0, (sin (t / 25.0) + 1) / 2);

        DrawXwing     (&xWing);

        DrawDeathStar (&deathStar);

        DrawPlanet    (&planet);

        double distance = sqrt ( (xWing.x - deathStar.x) * (xWing.x - deathStar.x) + (xWing.y - deathStar.y) * (xWing.y - deathStar.y) );

        double route    = sqrt ( (xWing.x - planet.x) * (xWing.x - planet.x) + (xWing.y - planet.y) * (xWing.y - planet.y) );

        if (distance <= xWing.r * xWing.scale + deathStar.r * deathStar.scale)
            {
            txMessageBox ("Game over");

            break;
            }

        if (route    <= xWing.r * xWing.scale + planet.r * planet.scale)
            {
            txMessageBox ("Congratulations! You won!");

            break;
            }

        VehicleSpeed  (&xWing, dt);

        VehicleSpeed  (&deathStar, dt);

        HeroControl   (&xWing);

        HeroControl   (&deathStar);

        txSleep (10);

        t++;
        }

    txDeleteDC (fon);
    }

//-----------------------------------------------------------------------------

void DrawXwing (const Hero* rebel)
    {
    txSetColor (rebel->color, 3);

    txSetFillColor (TX_NULL);

    myRectangle (rebel->x-50 * rebel->scale,  rebel->y-82 * rebel->scale, rebel->x-44 * rebel->scale,  rebel->y-72 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-44 * rebel->scale,  rebel->y-81 * rebel->scale, rebel->x-14 * rebel->scale,  rebel->y-75 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-35 * rebel->scale,  rebel->y-87 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y-81 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-14 * rebel->scale,  rebel->y-82 * rebel->scale, rebel->x-8  * rebel->scale,  rebel->y-72 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-28 * rebel->scale,  rebel->y-60 * rebel->scale, rebel->x-23 * rebel->scale,  rebel->y-51 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale,  rebel->y-66 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y-57 * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8  * rebel->scale,  rebel->y-79 * rebel->scale, rebel->x+16 * rebel->scale,  rebel->y-76 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+17 * rebel->scale,  rebel->y-78 * rebel->scale, rebel->x+64 * rebel->scale,  rebel->y-78 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+38 * rebel->scale,  rebel->y-84 * rebel->scale, rebel->x+38 * rebel->scale,  rebel->y-72 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-38 * rebel->scale,  rebel->y-75 * rebel->scale, rebel->x-46 * rebel->scale,  rebel->y-40 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y-72 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y-40 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale,  rebel->y-60 * rebel->scale, rebel->x-35 * rebel->scale,  rebel->y-60 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-67 * rebel->scale,  rebel->y-39 * rebel->scale, rebel->x-67 * rebel->scale,  rebel->y-33 * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-53 * rebel->scale,  rebel->y-40 * rebel->scale, rebel->x-37 * rebel->scale,  rebel->y-31 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-59 * rebel->scale,  rebel->y-31 * rebel->scale, rebel->x-53 * rebel->scale,  rebel->y-40 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-64 * rebel->scale,  rebel->y-40 * rebel->scale, rebel->x-59 * rebel->scale,  rebel->y-31 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-37 * rebel->scale,  rebel->y-45 * rebel->scale, rebel->x-25 * rebel->scale,  rebel->y-27 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale,  rebel->y-36 * rebel->scale, rebel->x-13 * rebel->scale,  rebel->y-27 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale,  rebel->y-36 * rebel->scale, rebel->x-13 * rebel->scale,  rebel->y-45 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-13 * rebel->scale,  rebel->y-45 * rebel->scale, rebel->x-2  * rebel->scale,  rebel->y-27 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-2  * rebel->scale,  rebel->y-42 * rebel->scale, rebel->x+3  * rebel->scale,  rebel->y-30 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y-27 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->x-53 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-50 * rebel->scale,  rebel->y-31 * rebel->scale, rebel->x-55 * rebel->scale,  rebel->y-12 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-55 * rebel->scale,  rebel->y-12 * rebel->scale, rebel->x-55 * rebel->scale,  rebel->y+11 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->x+91 * rebel->scale,  rebel->y-6  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale,  rebel->y-7  * rebel->scale, rebel->x+91 * rebel->scale,  rebel->y+8  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale,  rebel->y-7  * rebel->scale, rebel->x+119* rebel->scale,  rebel->y-4  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+119* rebel->scale,  rebel->y-4  * rebel->scale, rebel->x+121* rebel->scale,  rebel->y-3  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+121* rebel->scale,  rebel->y-3  * rebel->scale, rebel->x+122* rebel->scale,  rebel->y-1  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+122* rebel->scale,  rebel->y-1  * rebel->scale, rebel->x+122* rebel->scale,  rebel->y+1  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+122* rebel->scale,  rebel->y+1  * rebel->scale, rebel->x+121* rebel->scale,  rebel->y+3  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+121* rebel->scale,  rebel->y+3  * rebel->scale, rebel->x+119* rebel->scale,  rebel->y+5  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+119* rebel->scale,  rebel->y+5  * rebel->scale, rebel->x+91 * rebel->scale,  rebel->y+8  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale,  rebel->y+7  * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y+27 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->x-53 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-55 * rebel->scale,  rebel->y+11 * rebel->scale, rebel->x-50 * rebel->scale,  rebel->y+32 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-53 * rebel->scale,  rebel->y+32 * rebel->scale, rebel->x-37 * rebel->scale,  rebel->y+41 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-53 * rebel->scale,  rebel->y+32 * rebel->scale, rebel->x-59 * rebel->scale,  rebel->y+41 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-59 * rebel->scale,  rebel->y+41 * rebel->scale, rebel->x-64 * rebel->scale,  rebel->y+32 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-67 * rebel->scale,  rebel->y+33 * rebel->scale, rebel->x-67 * rebel->scale,  rebel->y+39 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-37 * rebel->scale,  rebel->y+45 * rebel->scale, rebel->x-25 * rebel->scale,  rebel->y+27 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale,  rebel->y+27 * rebel->scale, rebel->x-13 * rebel->scale,  rebel->y+36 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale,  rebel->y+45 * rebel->scale, rebel->x-13 * rebel->scale,  rebel->y+36 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-13 * rebel->scale,  rebel->y+27 * rebel->scale, rebel->x-2  * rebel->scale,  rebel->y+45 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-2  * rebel->scale,  rebel->y+42 * rebel->scale, rebel->x+3  * rebel->scale,  rebel->y+30 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-46 * rebel->scale,  rebel->y+42 * rebel->scale, rebel->x-38 * rebel->scale,  rebel->y+75 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale,  rebel->y+45 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y+74 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-28 * rebel->scale,  rebel->y+51 * rebel->scale, rebel->x-23 * rebel->scale,  rebel->y+60 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-11 * rebel->scale,  rebel->y+66 * rebel->scale, rebel->x-25 * rebel->scale,  rebel->y+56 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale,  rebel->y+60 * rebel->scale, rebel->x-35 * rebel->scale,  rebel->y+60 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-50 * rebel->scale,  rebel->y+74 * rebel->scale, rebel->x-44 * rebel->scale,  rebel->y+83 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-44 * rebel->scale,  rebel->y+75 * rebel->scale, rebel->x-14 * rebel->scale,  rebel->y+81 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-14 * rebel->scale,  rebel->y+74 * rebel->scale, rebel->x-8  * rebel->scale,  rebel->y+83 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-35 * rebel->scale,  rebel->y+81 * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y+87 * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8  * rebel->scale,  rebel->y+77 * rebel->scale, rebel->x+16 * rebel->scale,  rebel->y+80 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+17 * rebel->scale,  rebel->y+78 * rebel->scale, rebel->x+64 * rebel->scale,  rebel->y+78 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+38 * rebel->scale,  rebel->y+72 * rebel->scale, rebel->x+38 * rebel->scale,  rebel->y+84 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-55 * rebel->scale,  rebel->y+3  * rebel->scale, rebel->x-11 * rebel->scale,  rebel->y-3  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-43 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->x-43 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-19 * rebel->scale,  rebel->y-16 * rebel->scale, rebel->x-19 * rebel->scale,  rebel->y+17 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    txCircle    (rebel->x,             rebel->y,                      4 * rebel->scale                                                         );
    myLine      (rebel->x+11 * rebel->scale,  rebel->y-6  * rebel->scale, rebel->x+11 * rebel->scale,  rebel->y+6  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale,  rebel->y-6  * rebel->scale, rebel->x+17 * rebel->scale,  rebel->y-12 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale,  rebel->y+6  * rebel->scale, rebel->x+17 * rebel->scale,  rebel->y+12 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x+17 * rebel->scale,  rebel->y-3  * rebel->scale, rebel->x+37 * rebel->scale,  rebel->y+4  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale,  rebel->y,            rebel->x+85 * rebel->scale,  rebel->y,            rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale,  rebel->y+1  * rebel->scale, rebel->x+85 * rebel->scale,  rebel->y+1  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale,  rebel->y,            rebel->x+113* rebel->scale,  rebel->y,            rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale,  rebel->y+1  * rebel->scale, rebel->x+98 * rebel->scale,  rebel->y+1  * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+49 * rebel->scale,  rebel->y-9  * rebel->scale, rebel->x+49 * rebel->scale,  rebel->y+10 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+68 * rebel->scale,  rebel->y-7  * rebel->scale, rebel->x+69 * rebel->scale,  rebel->y+8  * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 2);

    myLine      (rebel->x-41 * rebel->scale,  rebel->y-54 * rebel->scale, rebel->x-36 * rebel->scale,  rebel->y-54 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale,  rebel->y+65 * rebel->scale, rebel->x-36 * rebel->scale,  rebel->y+65 * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 1);

    myLine      (rebel->x-41 * rebel->scale,  rebel->y-65 * rebel->scale, rebel->x-33 * rebel->scale,  rebel->y-65 * rebel->scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale,  rebel->y+55 * rebel->scale, rebel->x-33 * rebel->scale,  rebel->y+55 * rebel->scale, rebel->rotate, rebel->x, rebel->y);

    //txSetFillColor (TX_NULL);

    //txCircle    (rebel->x,     rebel->y,    rebel->r);

    //printf ("���� ����� %lg \n", rebel->rotate);
    }

//-----------------------------------------------------------------------------

void DrawDeathStar (const Hero* star)
    {
    txSetColor (star->color, 3);

    txSetFillColor (TX_NULL);

    myCircle (star->x+43,  star->y+42, 31,  star->rotate, star->x, star->y);

    myCircle (star->x+43,  star->y+42, 7,   star->rotate, star->x, star->y);

    myArc    (star->x,     star->y,     star->r, 82, 215,        star->rotate, star->x, star->y);

    myLine   (star->x+121, star->y,     star->x-119, star->y,     star->rotate, star->x, star->y);

    myLine   (star->x+121, star->y-3,   star->x-119, star->y-3,   star->rotate, star->x, star->y);

    myLine   (star->x-53,  star->y-106, star->x-53,  star->y-96,  star->rotate, star->x, star->y);

    myLine   (star->x-26,  star->y-96,  star->x-53,  star->y-96,  star->rotate, star->x, star->y);

    myLine   (star->x-35,  star->y-96,  star->x-35,  star->y-78,  star->rotate, star->x, star->y);

    myLine   (star->x-2,   star->y-78,  star->x-56,  star->y-78,  star->rotate, star->x, star->y);

    myLine   (star->x-2,   star->y-78,  star->x-2,   star->y-57,  star->rotate, star->x, star->y);

    myLine   (star->x+64,  star->y-57,  star->x-74,  star->y-57,  star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y-57,  star->x-23,  star->y-36,  star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y-36,  star->x-85,  star->y-36,  star->rotate, star->x, star->y);

    myLine   (star->x-85,  star->y-36,  star->x-85,  star->y-21,  star->rotate, star->x, star->y);

    myLine   (star->x-85,  star->y-21,  star->x-119, star->y-21,  star->rotate, star->x, star->y);

    myLine   (star->x-119, star->y-21,  star->x-119, star->y+18,  star->rotate, star->x, star->y);

    myLine   (star->x-119, star->y+18,  star->x-89,  star->y+18,  star->rotate, star->x, star->y);

    myLine   (star->x-89,  star->y+18,  star->x-89,  star->y+38,  star->rotate, star->x, star->y);

    myLine   (star->x-50,  star->y+38,  star->x-95,  star->y+38,  star->rotate, star->x, star->y);

    myLine   (star->x-56,  star->y+38,  star->x-56,  star->y+60,  star->rotate, star->x, star->y);

    myLine   (star->x-65,  star->y+60,  star->x-20,  star->y+60,  star->rotate, star->x, star->y);

    myLine   (star->x-29,  star->y+60,  star->x-29,  star->y+81,  star->rotate, star->x, star->y);

    myLine   (star->x-77,  star->y+81,  star->x-11,  star->y+81,  star->rotate, star->x, star->y);

    myLine   (star->x-41,  star->y+81,  star->x-41,  star->y+99,  star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y+81,  star->x-50,  star->y+81,  star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y+99,  star->x-50,  star->y+99,  star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y+99,  star->x-23,  star->y+117, star->rotate, star->x, star->y);

    myLine   (star->x-23,  star->y+118, star->x-15,  star->y+118, star->rotate, star->x, star->y);

    //txCircle (star->x,     star->y,     star->r);
    }

//-----------------------------------------------------------------------------

void DrawPlanet (const Hero* planet)
    {
    txAlphaBlend (txDC(), planet->x - planet->r, planet->y - planet->r, 0, 0, planet->image, 0, 0);

    //txCircle     (planet->x, planet->y, planet->r);
    }

//-----------------------------------------------------------------------------

void VehicleSpeed (Hero* rebel, double dt)
    {
    rebel->x = rebel->x + rebel->vx * dt;

    rebel->y = rebel->y + rebel->vy * dt;

    if (rebel->x > txGetExtentX() - rebel->r)
        {
        rebel->x = 0 + rebel->r;
        }

    if (rebel->y > txGetExtentY() - rebel->r)
        {
        rebel->y = 0 + rebel->r;
        }

    if (rebel->x < 0 + rebel->r)
        {
        rebel->x = txGetExtentX() - rebel->r;
        }

    if (rebel->y < 0 + rebel->r)
        {
        rebel->y = txGetExtentY() - rebel->r;
        }
    }

//-----------------------------------------------------------------------------

void HeroControl (struct Hero* rebel)
    {
    /*if (GetAsyncKeyState (rebel->keyRight)) rebel->vx += 1;

    if (GetAsyncKeyState (rebel->keyLeft))   rebel->vx -= 1;

    if (GetAsyncKeyState (rebel->keyUp))     rebel->vy -= 1;

    if (GetAsyncKeyState (rebel->keyDown))   rebel->vy += 1;*/

    if (GetAsyncKeyState (rebel->keyClockwise))
        {
        rebel->rotate += 0.1;

        double v = sqrt (rebel->vy * rebel->vy + rebel->vx * rebel->vx);

        rebel->vx = cos (rebel->rotate) * v;

        rebel->vy = sin (rebel->rotate) * v;
        }

    if (GetAsyncKeyState (rebel->keyCounterClockwise))
        {
        rebel->rotate -= 0.1;

        double v = sqrt (rebel->vy * rebel->vy + rebel->vx * rebel->vx);

        rebel->vx = cos (rebel->rotate) * v;

        rebel->vy = sin (rebel->rotate) * v;
        }

    if (GetAsyncKeyState (rebel->keyForward))
        {
        rebel->vx = rebel->vx * 1.2;

        rebel->vy = rebel->vy * 1.2;
        }

    //���� ��� ������� ������� ������ ����, v = 0, �� ����� ��������� v �� 1 � ����������� ��������.

    if (GetAsyncKeyState (rebel->keyForward) && fabs (rebel->vx) <= 0.01 && fabs (rebel->vy) <= 0.01)
        {
        /*double v = sqrt (rebel->vy * rebel->vy + rebel->vx * rebel->vx);

        double v = 0;

        v = v + 1;

        rebel->vx = cos (rebel->rotate) * v;

        rebel->vy = sin (rebel->rotate) * v;*/

        rebel->vx = cos (rebel->rotate);

        rebel->vy = sin (rebel->rotate);
        }

    if (GetAsyncKeyState (rebel->keyBackwards))
        {
        rebel->vx = rebel->vx * 0.6;

        rebel->vy = rebel->vy * 0.6;
        }

    if (GetAsyncKeyState (rebel->keyCloser))
        {
        rebel->scale += 0.1;
        }

    if (GetAsyncKeyState (rebel->keyFarther))
        {
        rebel->scale -= 0.1;
        }

    if (rebel->scale <= 0.1)
        {
        rebel->scale = 0.1;
        }
    if (rebel->scale >= 5)
        {
        rebel->scale = 5;
        }
    }
