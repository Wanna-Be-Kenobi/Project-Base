//#define _TX_ALLOW_TRACE 9

#include "TXLib.h"

#include "Rotate.h"

//-----------------------------------------------------------------------------

double Scale = 1;

const int NxWings = 5;

const int Nbuttons = 4;

COLORREF dStarColor = TX_CYAN;

//-----------------------------------------------------------------------------

struct Hero
    {
    double x, y, vx, vy;

    double r, scale;

    HDC image;

    double rotate;

    COLORREF color;

    int keyForward, keyBackwards, keyClockwise, keyCounterClockwise, keyCloser, keyFarther;
    };

//-----------------------------------------------------------------------------

struct Button
    {
    //(x, y + (height + dy) * 0, width, height, 10, "PLAY", TX_GREEN, RGB (0, 64, 0));

    char name [20];

    double x, y, width, height;

    COLORREF color, textColor;
    };

//-----------------------------------------------------------------------------

#include "Beam.h"

//-----------------------------------------------------------------------------

void MainMenu();

void DrawMenu (struct Button button [Nbuttons]);

void CreateButtons (struct Button button [Nbuttons]);

void DrawButton (struct Button button, double corner);

int CheckMouse (struct Button button);

void DrawXwing (const Hero* rebel, double beam, double beamX1, double beamY1, double beamX2, double beamY2);

void MoveHero (double lvls);

void VehicleSpeed (struct Hero* rebel, double dt);

void HeroControl (struct Hero* rebel);

void myRectangle (double x1, double y1, double x2, double y2);

void DrawDeathStar (const Hero* star);

void DrawPlanet (const Hero* planet);

void YourAlphaBlend (HDC destImage,   double xDest,   double yDest,   double width, double height,
                     HDC sourceImage, double xSource, double ySource, double alpha, double scale);

double Dist (const Hero first, const Hero second);

void ScaleControl();

void ShotDist (const Hero rebel, const Hero star);

void CreateXWings (struct Hero miniWing [NxWings]);

void DrawXWings   (struct Hero miniWing [NxWings]);

void XWingsSpeed  (struct Hero miniWing [NxWings], double dt);

void Random (double min, double max);

void ScoreBoard (double lvls, double x, double y, double width, double height, double cooldown, double shots);

void DrawShadowRect (double x1, double y1, double x2, double y2, double corner,
                      COLORREF fillColor, COLORREF color);

void DrawShadowText (double x1, double y1, double x2, double  y2, char str [20], COLORREF textColor, double shadow = 4);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920 - 20, 1080 - 120);

    MainMenu();

    return 0;
    }

//-----------------------------------------------------------------------------

void MainMenu()
    {
    txBegin();

    Button buttons [Nbuttons] = { {"PLAY", 0, 400}, {"ENTER NAME"}, {"SCOREBOARD"}, {"EXIT"} } ;

    //(850 < txMouseX() && txMouseX() < 1050 && 400 < txMouseY() && txMouseY() < 455)

    CreateButtons (buttons);

    while (true)
        {
        DrawMenu (buttons);

        if (GetAsyncKeyState (VK_LBUTTON))
            {
            if (CheckMouse (buttons [Nbuttons]) == 1)
                {
                double lvls = 1;

                while (lvls < 11)
                    {
                    //printf ("�������: %lg \n", lvls);

                    MoveHero (lvls);

                    lvls ++;
                    }
                }

           /* if (GetAsyncKeyState (VK_BUTTON))
                {
                if (850 < txMouseX() && txMouseX() < 1050 &&

                } */


            }
        txSleep (10);
        }
    txEnd();
    }

//-----------------------------------------------------------------------------

void DrawMenu (struct Button buttons [Nbuttons])
    {
    int i = 0;

    while (i < Nbuttons)
        {
        DrawButton (buttons [i], 10);

        i++;
        }
    //DrawButton (x, y + (height + dy) * 3, width, height, 10, "EXIT",       TX_GREEN, RGB (0, 64, 0));
    }

//-----------------------------------------------------------------------------

void CreateButtons (struct Button buttons [Nbuttons])
    {
    int i = 0;

    while (i < Nbuttons)
        {
        buttons [i].x         = 850;

        buttons [i].y         = buttons->y + (buttons ->height + 15) * i;

        buttons [i].width     = 200;

        buttons [i].height    = 50;

        buttons [i].color     = TX_GREEN;

        buttons [i].textColor = RGB (0, 64, 0);

        i++;
        }
    }

//-----------------------------------------------------------------------------

void DrawButton (struct Button button, double corner)
    {
    DrawShadowRect (button.x, button.y, button.x + button.width, button.y + button.height, corner, button.color, button.textColor);

    txSelectFont ("FixedSys", 40);

    DrawShadowText (button.x, button.y, button.x + button.width, button.y + button.height, button.name, TX_LIGHTGREEN);
    }

//-----------------------------------------------------------------------------

int CheckMouse (struct Button button)
    {
    //printf ("Check x = %lg y = %lg mouse x = %d  mouse y = %d \n", button.x, button.y, txMouseX(), txMouseY());

    printf ("x = %lg y = %lg \n", button.x, button.y);

    //printf ("mouse x = %d mouse y = %d \n", txMouseX(), txMouseY());

    if (button.x < txMouseX() && txMouseX() < button.x + button.width &&
        button.y < txMouseY() && txMouseY() < button.y + button.height)
        {
        return 1;
        }
    else
        return 0;
    }

//-----------------------------------------------------------------------------

void MoveHero (double lvls)
    {
    txBegin();

    Hero xWing        = { rand() % (int) (1921 - 100 * 0.5 * 2) + 100 * 0.5, rand() % (int) (1081 - 100 * 0.5 * 2) + 100 * 0.5, 1, 1, 100, 0.5, NULL,  0.785, TX_YELLOW, 'W', 'S', 'E', 'Q', VK_F1, VK_F2 };

    Hero deathStar    = { rand() % (int) (1921 - 120 * 1.5 * 2) + 120 * 1.5, rand() % (int) (1081 - 120 * 1.5 * 2) + 120 * 1.5, 0, 0, 120, 1.5, NULL,  3.14,  dStarColor,   'I', 'K', 'O', 'U'               };

    Hero planet       = { rand() % (int) (1921 - 136 * 0.5 * 2) + 68  * 0.5, rand() % (int) (1081 - 136 * 0.5 * 2) + 136 * 0.5, 0, 0, 136, 0.5, txLoadImage ("planet.bmp")                                };

    Hero miniWing [NxWings]  = { } ;

    HDC fon = txLoadImage ("BackgroundNew.bmp");

    double dt = 1;

    double t  = 0;

    CreateXWings (miniWing);

    double cooldown = 100;

    double shots = 10;

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txBitBlt (txDC(), 0, 0, 1920, 1080, fon,    0,  0                          );

        //txAlphaBlend (txDC(), 0, 0, 1920, 1080, fon, 1920,  0, (sin (t / 25.0) + 1) / 2);

        ScoreBoard (lvls, 5, 5, 240, 100, cooldown, shots);

        DrawDeathStar (&deathStar);

        DrawPlanet       (&planet);

        DrawXWings      (miniWing);

        int message = 0;

        double beamX1 = 0, beamY1 = 0, beamX2 = 0, beamY2 = 0;

        if (GetAsyncKeyState ('R') && cooldown == 100 && shots > 0)
            {
            message = intersectionCheck (&xWing, &beamX1, &beamY1, &beamX2, &beamY2);

            DrawXwing (&xWing, 3, beamX1, beamY1, beamX2, beamY2);

            cooldown = 0;

            shots --;
            }

        else
            {
            DrawXwing (&xWing, -1, 0, 0, 0, 0);

            cooldown += 4;
            }

        if (message == 1)
            {
            txMessageBox ("Death Star is defeated.\nCongratulations!");
            }

        //txMessageBox ("You've defeated your ally");

        int i = 0;

        while (i < NxWings)
            {
            if (sqrt ((beamX2 - miniWing [i].x) * (beamX2 - miniWing [i].x) + (beamY2 - miniWing [i].y) * (beamY2 - miniWing [i].y)) <= 100)
                {
                miniWing [i].color  = (TX_PINK);
                }
            i++;
            }

        if (cooldown >= 100)
            {
            cooldown = 100;
            }

        //printf ("shots = %lg", shots);

        //dotLine (100, 100, 900, 800);

        double distance = Dist (xWing, deathStar);

        double route    = Dist (xWing, planet);

        if (distance <= xWing.r * xWing.scale * Scale + deathStar.r * deathStar.scale * Scale)
            {
            txMessageBox ("Game over");

            break;
            }

        if (route    <= xWing.r * xWing.scale * Scale + planet.r * planet.scale * Scale)
            {
            if (sqrt (xWing.vx * xWing.vx + xWing.vy * xWing.vy) <= 17)
                {
                txMessageBox ("Congratulations! You won!");
                }

            if (sqrt (xWing.vx * xWing.vx + xWing.vy * xWing.vy) >= 17)
                {
                txMessageBox ("You crashed on the planet \n P.S. Too high speed");
                }

            break;
            }

        VehicleSpeed  (&xWing,     dt);

        VehicleSpeed  (&deathStar, dt);

        XWingsSpeed   (miniWing,   dt);

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

    txEnd();
    }

//-----------------------------------------------------------------------------

void DrawXwing (const Hero* rebel, double beam, double beamX1, double beamY1, double beamX2, double beamY2)
    {
    txSetColor (rebel->color, 1.5 + rebel->scale * 2);

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

    txCircle    (rebel->x,                            rebel->y,                                     4 * rebel->scale * Scale                                                         );
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y-6  * rebel->scale * Scale, rebel->x+11 * rebel->scale * Scale,  rebel->y+6  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y-6  * rebel->scale * Scale, rebel->x+17 * rebel->scale * Scale,  rebel->y-12 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+11 * rebel->scale * Scale,  rebel->y+6  * rebel->scale * Scale, rebel->x+17 * rebel->scale * Scale,  rebel->y+12 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myRectangle (rebel->x+17 * rebel->scale * Scale,  rebel->y-3  * rebel->scale * Scale, rebel->x+37 * rebel->scale * Scale,  rebel->y+4  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale * Scale,  rebel->y,                           rebel->x+85 * rebel->scale * Scale,  rebel->y,                           rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+37 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->x+85 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale * Scale,  rebel->y,                           rebel->x+113* rebel->scale * Scale,  rebel->y,                           rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+98 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->x+98 * rebel->scale * Scale,  rebel->y+1  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+49 * rebel->scale * Scale,  rebel->y-9  * rebel->scale * Scale, rebel->x+49 * rebel->scale * Scale,  rebel->y+10 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x+68 * rebel->scale * Scale,  rebel->y-7  * rebel->scale * Scale, rebel->x+69 * rebel->scale * Scale,  rebel->y+8  * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 2);

    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y-54 * rebel->scale * Scale, rebel->x-36 * rebel->scale * Scale,  rebel->y-54 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y+65 * rebel->scale * Scale, rebel->x-36 * rebel->scale * Scale,  rebel->y+65 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    txSetColor  (rebel->color, 1);

    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y-65 * rebel->scale * Scale, rebel->x-33 * rebel->scale * Scale,  rebel->y-65 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);
    myLine      (rebel->x-41 * rebel->scale * Scale,  rebel->y+55 * rebel->scale * Scale, rebel->x-33 * rebel->scale * Scale,  rebel->y+55 * rebel->scale * Scale, rebel->rotate, rebel->x, rebel->y);

    if (beam >= 0)
        {
        txSetColor  (RGB (0, 90, 0), 5 * beam * rebel->scale * Scale);

        txSetColor (TX_GREEN,      5);
        txLine (beamX1, beamY1, beamX2, beamY2);
        txSetColor (TX_LIGHTGREEN, 1);
        txLine (beamX1, beamY1, beamX2, beamY2);

        //txSetColor  (RGB (150, 255, 150), 1 * beam * rebel->scale * Scale);
        //laserLine      (rebel->x+125 * rebel->scale * Scale,  rebel->y+0 * rebel->scale * Scale, rebel->x+10000 * rebel->scale * Scale,  rebel->y+0 * rebel->scale * Scale,  rebel->rotate, rebel->x, rebel->y, 1);
        }

    //txSetFillColor (TX_NULL);

    //txCircle    (rebel->x,     rebel->y,    rebel->r);

    //printf ("���� ����� %lg \n", rebel->rotate);
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
    double v = sqrt (rebel->vy * rebel->vy + rebel->vx * rebel->vx);

    rebel->vx = cos (rebel->rotate) * v;

    rebel->vy = sin (rebel->rotate) * v;

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
        }

    if (GetAsyncKeyState (rebel->keyCounterClockwise))
        {
        rebel->rotate -= 0.1;
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

//-----------------------------------------------------------------------------

void ShotDist (const Hero rebel, const Hero star)
    {
    /*
    x1 = rebel->x,
    y1 = rebel->y,

    x2 = rebel->x + (10000 * rebel->scale * Scale),
    y2 = rebel->y + (10000 * rebel->scale * Scale),

    rebel->rotate,
    rebel->x,
    rebel->y

    ���� ������ �������� 2-�� ������� - ������ ����� (x1 y1), ������ ����� (x2 y2)          x2 y2
                                                                                             /
    ����������� ��������� ������                                                            /
    a = y1 - y2                                                                            /
    b = x2 - x1                                                                           *\__
    c = x1 * y2 - x2 * y1                                                                /    \__(���������������� ������ = d)
                                                                                        /        \__
    �����, �� ������� �� �������� ���������� (x, y, r);                                /            \
                                                                                      /             x y
    d = |a * x + b * y + c| / sqrt (a * a + b * b)                                   /
                                                                                    /
    if d =< r, �� ����������� ����                                                x1 y1
    */
    }

//-----------------------------------------------------------------------------

void CreateXWings (struct Hero miniWing [NxWings])
    {
    int i = 0;

    while (i < NxWings)
            {
            miniWing [i].x      = rand() % (int) (1921 - 100 * 0.5 * 2) + 100 * 0.5;

            miniWing [i].y      = rand() % (int) (1081 - 100 * 0.5 * 2) + 100 * 0.5;

            miniWing [i].vx     = 5.0;

            miniWing [i].vy     = 5.0;

            miniWing [i].r      = 100;

            miniWing [i].scale  = rand() % 101 * 0.01 * 0.2 + 0.1;

            //                   \______/
            //                   0-32767
            //                   \___________/
            //                       0-100
            //                   \__________________/
            //                         0.00-1.00
            //                   \________________________/
            //                            0.00-0.20
            //                   \_______________________________/
            //                                0.10-0.30

            miniWing [i].rotate = rand() % 7;

            miniWing [i].color  = RGB ((rand() % 250 + 50) * 2 + 1, rand() % 250 + 50, rand() % 250 + 50);

            i++;
            }
    }

//-----------------------------------------------------------------------------
void DrawXWings (struct Hero miniWing [NxWings])
    {
    int i = 0;

    while (i < NxWings)
        {
        DrawXwing (&miniWing [i], -1, 0, 0, 0, 0);

        i++;
        }
    }

//-----------------------------------------------------------------------------

void XWingsSpeed (struct Hero miniWing [NxWings], double dt)
    {
    int i = 0;

    while (i < NxWings)
        {
        VehicleSpeed  (&miniWing [i], dt);

        i++;
        }
    }

//-----------------------------------------------------------------------------
 void ScoreBoard (double lvls, double x, double y, double width, double height, double cooldown, double shots)
    {
    char str     [20] = "";

    //Win32::RoundRect (txDC(), 5, 5, 165 + 5, 65 + 5, 10, 10);

    //DrawShadowRect (5, 5, 190, 50, 10, TX_GREEN, RGB (0, 64, 0));

    DrawShadowRect (x, y, x + width, y + height, 10, TX_GREEN, RGB (0, 64, 0));

    txSelectFont ("FixedSys", 40);

    sprintf   (str, "Level: %lg \n \nShots Left %lg", lvls, shots);

    DrawShadowText (x, y, x + width, y + height, str, TX_LIGHTGREEN);

    txSetColor (TX_RED);

    txSetFillColor (TX_RED);

    txRectangle (25, 40, 225, 65);

    txSetColor (TX_LIGHTGREEN);

    txSetFillColor (TX_LIGHTGREEN);

    txRectangle (26, 41, 25 + 1.99 * cooldown, 64);
    }

//-----------------------------------------------------------------------------
 void DrawShadowRect (double x1, double y1, double x2, double y2, double corner,
                      COLORREF fillColor, COLORREF color)
    {
    txSetColor     (TX_BLACK);

    txSetFillColor (TX_BLACK);

    Win32::RoundRect (txDC(), x1 + 5, y1 + 5, x2 + 5, y2 + 5, corner, corner);

    txSetFillColor (fillColor);

    txSetColor (color);

    Win32::RoundRect (txDC(), x1, y1, x2, y2, corner, corner);
    }

//-----------------------------------------------------------------------------

void DrawShadowText (double x1, double y1, double x2, double  y2, char str [20], COLORREF textColor, double shadow)
    {
    txSetColor (TX_BLACK);

    txDrawText (x1 + shadow, y1 + shadow, x2 + shadow, y2 + shadow, str);

    txSetColor (textColor);

    txDrawText (x1, y1, x2, y2, str);
    }

//-----------------------------------------------------------------------------
//void DrawShot (double x1, double y1, double x2, double y2);












