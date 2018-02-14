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

void YourAlphaBlend (HDC destImage,   double xDest,   double yDest,   double width, double height,
                     HDC sourceImage, double xSource, double ySource, double alpha, double scale);

double Dist ( const Hero first, const Hero second);

void ScaleControl();

//-----------------------------------------------------------------------------

double Scale = 1;

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
    Hero xWing     = { rand() % (int) (1921 - 100 * 0.5 * 2) + 100 * 0.5, rand() % (int) (1081 - 100 * 0.5 * 2) + 100 * 0.5, 1, 1, 100, 0.5, NULL,  0.785, TX_YELLOW, 'W', 'S', VK_RSHIFT, 'E', 'Q', VK_F1, VK_F2 };

    Hero deathStar = { rand() % (int) (1921 - 120 * 1.5 * 2) + 120 * 1.5, rand() % (int) (1081 - 120 * 1.5 * 2) + 120 * 1.5, 0, 0, 120, 1.5, NULL,  3.14,  TX_CYAN,   'I', 'K', VK_LSHIFT, 'O', 'U'             };

    Hero planet    = { rand() % (int) (1921 - 136 * 0.5 * 2) + 68  * 0.5, rand() % (int) (1081 - 136 * 0.5 * 2) + 136 * 0.5, 0, 0, 136, 0.5, txLoadImage ("planet.bmp")                                         };

    HDC fon        = txLoadImage ("Background.bmp");

    double dt = 1;

    double t  = 0;

    //SetStartLocation (xWing, deathStar, planet);

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);

        txClear();

        txAlphaBlend (txDC(), 0,     0, 1920, 1080,      fon,    0,  0                          );

        txAlphaBlend (txDC(), 0,     0, 1920, 1080,      fon, 1920,  0, (sin (t / 25.0) + 1) / 2);

        DrawXwing     (&xWing);

        DrawDeathStar (&deathStar);

        DrawPlanet    (&planet);

        double distance = Dist (xWing, deathStar);

        double route    = Dist (xWing, planet);

        if (distance <= xWing.r * xWing.scale * Scale + deathStar.r * deathStar.scale * Scale)
            {
            txMessageBox ("Game over");

            break;
            }

        if (route    <= xWing.r * xWing.scale * Scale + planet.r * planet.scale * Scale)
            {
            txMessageBox ("Congratulations! You won!");

            break;
            }

        VehicleSpeed  (&xWing, dt);

        VehicleSpeed  (&deathStar, dt);

        HeroControl   (&xWing);

        HeroControl   (&deathStar);

        ScaleControl();

        if (GetAsyncKeyState (VK_F5))
            {
            planet.scale += 0.1;
            }

        if (GetAsyncKeyState (VK_F6))
            {
            planet.scale -= 0.1;
            }

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

    myRectangle (rebel->x-50 * rebel->scale * Scale,  rebel->y-82 * rebel->scale * Scale, rebel->x-44 * rebel->scale * Scale,  rebel->y-72 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-44 * rebel->scale * Scale,  rebel->y-81 * rebel->scale * Scale, rebel->x-14 * rebel->scale * Scale,  rebel->y-75 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-35 * rebel->scale * Scale,  rebel->y-87 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y-81 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-14 * rebel->scale * Scale,  rebel->y-82 * rebel->scale * Scale, rebel->x-8  * rebel->scale * Scale,  rebel->y-72 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-28 * rebel->scale * Scale,  rebel->y-60 * rebel->scale * Scale, rebel->x-23 * rebel->scale * Scale,  rebel->y-51 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale * Scale,  rebel->y-66 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y-57 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8  * rebel->scale * Scale,  rebel->y-79 * rebel->scale * Scale, rebel->x+16 * rebel->scale * Scale,  rebel->y-76 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+17 * rebel->scale * Scale,  rebel->y-78 * rebel->scale * Scale, rebel->x+64 * rebel->scale * Scale,  rebel->y-78 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+38 * rebel->scale * Scale,  rebel->y-84 * rebel->scale * Scale, rebel->x+38 * rebel->scale * Scale,  rebel->y-72 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-38 * rebel->scale * Scale,  rebel->y-75 * rebel->scale * Scale, rebel->x-46 * rebel->scale * Scale,  rebel->y-40 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y-72 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y-40 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y-60 * rebel->scale * Scale, rebel->x-35 * rebel->scale * Scale,  rebel->y-60 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-67 * rebel->scale * Scale,  rebel->y-39 * rebel->scale * Scale, rebel->x-67 * rebel->scale * Scale,  rebel->y-33 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-53 * rebel->scale * Scale,  rebel->y-40 * rebel->scale * Scale, rebel->x-37 * rebel->scale * Scale,  rebel->y-31 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-59 * rebel->scale * Scale,  rebel->y-31 * rebel->scale * Scale, rebel->x-53 * rebel->scale * Scale,  rebel->y-40 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-64 * rebel->scale * Scale,  rebel->y-40 * rebel->scale * Scale, rebel->x-59 * rebel->scale * Scale,  rebel->y-31 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-37 * rebel->scale * Scale,  rebel->y-45 * rebel->scale * Scale, rebel->x-25 * rebel->scale * Scale,  rebel->y-27 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale * Scale,  rebel->y-36 * rebel->scale * Scale, rebel->x-13 * rebel->scale * Scale,  rebel->y-27 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale * Scale,  rebel->y-36 * rebel->scale * Scale, rebel->x-13 * rebel->scale * Scale,  rebel->y-45 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-13 * rebel->scale * Scale,  rebel->y-45 * rebel->scale * Scale, rebel->x-2  * rebel->scale * Scale,  rebel->y-27 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-2  * rebel->scale * Scale,  rebel->y-42 * rebel->scale * Scale, rebel->x+3  * rebel->scale * Scale,  rebel->y-30 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y-27 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->x-53 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-50 * rebel->scale * Scale,  rebel->y-31 * rebel->scale * Scale, rebel->x-55 * rebel->scale * Scale,  rebel->y-12 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-55 * rebel->scale * Scale,  rebel->y-12 * rebel->scale * Scale, rebel->x-55 * rebel->scale * Scale,  rebel->y+11 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->x+91 * rebel->scale * Scale,  rebel->y-6  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale * Scale,  rebel->y-7  * rebel->scale * Scale, rebel->x+91 * rebel->scale * Scale,  rebel->y+8  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale * Scale,  rebel->y-7  * rebel->scale * Scale, rebel->x+119* rebel->scale * Scale,  rebel->y-4  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+119* rebel->scale * Scale,  rebel->y-4  * rebel->scale * Scale, rebel->x+121* rebel->scale * Scale,  rebel->y-3  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+121* rebel->scale * Scale,  rebel->y-3  * rebel->scale * Scale, rebel->x+122* rebel->scale * Scale,  rebel->y-1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+122* rebel->scale * Scale,  rebel->y-1  * rebel->scale * Scale, rebel->x+122* rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+122* rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->x+121* rebel->scale * Scale,  rebel->y+3  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+121* rebel->scale * Scale,  rebel->y+3  * rebel->scale * Scale, rebel->x+119* rebel->scale * Scale,  rebel->y+5  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+119* rebel->scale * Scale,  rebel->y+5  * rebel->scale * Scale, rebel->x+91 * rebel->scale * Scale,  rebel->y+8  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+91 * rebel->scale * Scale,  rebel->y+7  * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y+27 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->x-53 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-55 * rebel->scale * Scale,  rebel->y+11 * rebel->scale * Scale, rebel->x-50 * rebel->scale * Scale,  rebel->y+32 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-53 * rebel->scale * Scale,  rebel->y+32 * rebel->scale * Scale, rebel->x-37 * rebel->scale * Scale,  rebel->y+41 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-53 * rebel->scale * Scale,  rebel->y+32 * rebel->scale * Scale, rebel->x-59 * rebel->scale * Scale,  rebel->y+41 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-59 * rebel->scale * Scale,  rebel->y+41 * rebel->scale * Scale, rebel->x-64 * rebel->scale * Scale,  rebel->y+32 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-67 * rebel->scale * Scale,  rebel->y+33 * rebel->scale * Scale, rebel->x-67 * rebel->scale * Scale,  rebel->y+39 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-37 * rebel->scale * Scale,  rebel->y+45 * rebel->scale * Scale, rebel->x-25 * rebel->scale * Scale,  rebel->y+27 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale * Scale,  rebel->y+27 * rebel->scale * Scale, rebel->x-13 * rebel->scale * Scale,  rebel->y+36 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-25 * rebel->scale * Scale,  rebel->y+45 * rebel->scale * Scale, rebel->x-13 * rebel->scale * Scale,  rebel->y+36 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-13 * rebel->scale * Scale,  rebel->y+27 * rebel->scale * Scale, rebel->x-2  * rebel->scale * Scale,  rebel->y+45 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-2  * rebel->scale * Scale,  rebel->y+42 * rebel->scale * Scale, rebel->x+3  * rebel->scale * Scale,  rebel->y+30 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-46 * rebel->scale * Scale,  rebel->y+42 * rebel->scale * Scale, rebel->x-38 * rebel->scale * Scale,  rebel->y+75 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-11 * rebel->scale * Scale,  rebel->y+45 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y+74 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-28 * rebel->scale * Scale,  rebel->y+51 * rebel->scale * Scale, rebel->x-23 * rebel->scale * Scale,  rebel->y+60 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-11 * rebel->scale * Scale,  rebel->y+66 * rebel->scale * Scale, rebel->x-25 * rebel->scale * Scale,  rebel->y+56 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y+60 * rebel->scale * Scale, rebel->x-35 * rebel->scale * Scale,  rebel->y+60 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-50 * rebel->scale * Scale,  rebel->y+74 * rebel->scale * Scale, rebel->x-44 * rebel->scale * Scale,  rebel->y+83 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-44 * rebel->scale * Scale,  rebel->y+75 * rebel->scale * Scale, rebel->x-14 * rebel->scale * Scale,  rebel->y+81 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-14 * rebel->scale * Scale,  rebel->y+74 * rebel->scale * Scale, rebel->x-8  * rebel->scale * Scale,  rebel->y+83 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-35 * rebel->scale * Scale,  rebel->y+81 * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y+87 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetFillColor (rebel->color);

    myRectangle (rebel->x-8  * rebel->scale * Scale,  rebel->y+77 * rebel->scale * Scale, rebel->x+16 * rebel->scale * Scale,  rebel->y+80 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+17 * rebel->scale * Scale,  rebel->y+78 * rebel->scale * Scale, rebel->x+64 * rebel->scale * Scale,  rebel->y+78 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+38 * rebel->scale * Scale,  rebel->y+72 * rebel->scale * Scale, rebel->x+38 * rebel->scale * Scale,  rebel->y+84 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x-55 * rebel->scale * Scale,  rebel->y+3  * rebel->scale * Scale, rebel->x-11 * rebel->scale * Scale,  rebel->y-3  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-43 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->x-43 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-19 * rebel->scale * Scale,  rebel->y-16 * rebel->scale * Scale, rebel->x-19 * rebel->scale * Scale,  rebel->y+17 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    txCircle    (rebel->x,             rebel->y,                      4 * rebel->scale * Scale                                                         );
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y-6  * rebel->scale * Scale, rebel->x+11 * rebel->scale * Scale,  rebel->y+6  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y-6  * rebel->scale * Scale, rebel->x+17 * rebel->scale * Scale,  rebel->y-12 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y+6  * rebel->scale * Scale, rebel->x+17 * rebel->scale * Scale,  rebel->y+12 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x+17 * rebel->scale * Scale,  rebel->y-3  * rebel->scale * Scale, rebel->x+37 * rebel->scale * Scale,  rebel->y+4  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale * Scale,  rebel->y,            rebel->x+85 * rebel->scale * Scale,  rebel->y,            rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->x+85 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale * Scale,  rebel->y,            rebel->x+113* rebel->scale * Scale,  rebel->y,            rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->x+98 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+49 * rebel->scale * Scale,  rebel->y-9  * rebel->scale * Scale, rebel->x+49 * rebel->scale * Scale,  rebel->y+10 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+68 * rebel->scale * Scale,  rebel->y-7  * rebel->scale * Scale, rebel->x+69 * rebel->scale * Scale,  rebel->y+8  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 2);

    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y-54 * rebel->scale * Scale, rebel->x-36 * rebel->scale * Scale,  rebel->y-54 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y+65 * rebel->scale * Scale, rebel->x-36 * rebel->scale * Scale,  rebel->y+65 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 1);

    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y-65 * rebel->scale * Scale, rebel->x-33 * rebel->scale * Scale,  rebel->y-65 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y+55 * rebel->scale * Scale, rebel->x-33 * rebel->scale * Scale,  rebel->y+55 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    //txSetFillColor (TX_NULL);

    //txCircle    (rebel->x,     rebel->y,    rebel->r);

    //printf ("угол равен %lg \n", rebel->rotate);
    }

//-----------------------------------------------------------------------------

void DrawDeathStar (const Hero* star)
    {
    txSetColor (star->color, 3);

    txSetFillColor (TX_NULL);

    myCircle (star->x+43 * star->scale * Scale,  star->y+42 * star->scale * Scale,          31 * star->scale * Scale,                             star->rotate, star->x, star->y);
    myCircle (star->x+43 * star->scale * Scale,  star->y+42 * star->scale * Scale,           7 * star->scale * Scale,                             star->rotate, star->x, star->y);
    myArc    (star->x,                   star->y,                   star->r    * star->scale * Scale,  82,          215,          star->rotate, star->x, star->y);
    myLine   (star->x+121* star->scale * Scale,  star->y,                   star->x-119* star->scale * Scale,  star->y,                   star->rotate, star->x, star->y);
    myLine   (star->x+121* star->scale * Scale,  star->y-3  * star->scale * Scale,  star->x-119* star->scale * Scale,  star->y-3  * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-53 * star->scale * Scale,  star->y-106* star->scale * Scale,  star->x-53 * star->scale * Scale,  star->y-96 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-26 * star->scale * Scale,  star->y-96 * star->scale * Scale,  star->x-53 * star->scale * Scale,  star->y-96 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-35 * star->scale * Scale,  star->y-96 * star->scale * Scale,  star->x-35 * star->scale * Scale,  star->y-78 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-2  * star->scale * Scale,  star->y-78 * star->scale * Scale,  star->x-56 * star->scale * Scale,  star->y-78 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-2  * star->scale * Scale,  star->y-78 * star->scale * Scale,  star->x-2  * star->scale * Scale,  star->y-57 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x+64 * star->scale * Scale,  star->y-57 * star->scale * Scale,  star->x-74 * star->scale * Scale,  star->y-57 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y-57 * star->scale * Scale,  star->x-23 * star->scale * Scale,  star->y-36 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y-36 * star->scale * Scale,  star->x-85 * star->scale * Scale,  star->y-36 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-85 * star->scale * Scale,  star->y-36 * star->scale * Scale,  star->x-85 * star->scale * Scale,  star->y-21 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-85 * star->scale * Scale,  star->y-21 * star->scale * Scale,  star->x-119* star->scale * Scale,  star->y-21 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-119* star->scale * Scale,  star->y-21 * star->scale * Scale,  star->x-119* star->scale * Scale,  star->y+18 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-119* star->scale * Scale,  star->y+18 * star->scale * Scale,  star->x-89 * star->scale * Scale,  star->y+18 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-89 * star->scale * Scale,  star->y+18 * star->scale * Scale,  star->x-89 * star->scale * Scale,  star->y+38 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-50 * star->scale * Scale,  star->y+38 * star->scale * Scale,  star->x-95 * star->scale * Scale,  star->y+38 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-56 * star->scale * Scale,  star->y+38 * star->scale * Scale,  star->x-56 * star->scale * Scale,  star->y+60 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-65 * star->scale * Scale,  star->y+60 * star->scale * Scale,  star->x-20 * star->scale * Scale,  star->y+60 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-29 * star->scale * Scale,  star->y+60 * star->scale * Scale,  star->x-29 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-77 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->x-11 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-41 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->x-41 * star->scale * Scale,  star->y+99 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->x-50 * star->scale * Scale,  star->y+81 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y+99 * star->scale * Scale,  star->x-50 * star->scale * Scale,  star->y+99 * star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y+99 * star->scale * Scale,  star->x-23 * star->scale * Scale,  star->y+117* star->scale * Scale,  star->rotate, star->x, star->y);
    myLine   (star->x-23 * star->scale * Scale,  star->y+118* star->scale * Scale,  star->x-15 * star->scale * Scale,  star->y+118* star->scale * Scale,  star->rotate, star->x, star->y);

    //txCircle (star->x,     star->y,     star->r);
    }

//-----------------------------------------------------------------------------

void DrawPlanet (const Hero* planet)
    {
    BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

    Win32::AlphaBlend (txDC(),
                       planet->x - planet->r        * planet->scale * Scale,
                       planet->y - planet->r        * planet->scale * Scale,
                       txGetExtentX (planet->image) * planet->scale * Scale,
                       txGetExtentY (planet->image) * planet->scale * Scale,
                       planet->image, 0, 0,
                       txGetExtentX (planet->image),
                       txGetExtentY (planet->image),
                       blend);

    txSetColor (TX_PINK, 3);

    txSetFillColor (TX_NULL);

    txCircle     (planet->x, planet->y, planet->r * planet->scale * Scale);
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

    if (GetAsyncKeyState (rebel->keyLeft))    rebel->vx -= 1;

    if (GetAsyncKeyState (rebel->keyUp))      rebel->vy -= 1;

    if (GetAsyncKeyState (rebel->keyDown))    rebel->vy += 1;*/

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

    //Если при нажатии клавиши Правый Шифт, v = 0, то нужно увеличить v на 1 и пересчитать проекции.

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
        rebel->scale  = 0.1;
        }
    if (rebel->scale >= 5)
        {
        rebel->scale  = 5;
        }
    }

//-----------------------------------------------------------------------------

void ScaleControl()
    {
    if (GetAsyncKeyState (VK_F10))
        {
        Scale += 0.1;

        //printf ("Scale = %lg \n", Scale);
        }

    if (GetAsyncKeyState (VK_F11))
        {
        Scale -= 0.1;

        //printf ("Scale = %lg \n", Scale);
        }


    if (Scale <= 0.1)
        {
        Scale  = 0.1;
        }

    if (Scale >= 2)
        {
        Scale  = 2;
        }
    }

//-----------------------------------------------------------------------------

double Dist (const Hero first, const Hero second)
    {
    return sqrt ( (first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y) );
    }

//-----------------------------------------------------------------------------

/*void SetStartLocation (const Hero xWing, const Hero deathStar, const Hero planet)
    {
    xwing.x = 0, xWing.y = 0;

    deathStar.x = 0, deathStar.y = 0;

    planet.x = 0, planet.y = 0;
    }   */










