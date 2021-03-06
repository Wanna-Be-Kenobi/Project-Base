#include "TXLib.h"

//-----------------------------------------------------------------------------

void laserLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, double width1, double width2);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    txSetColor (TX_GREEN, 3);

    txLine (300, 0, 300, 900);

    HDC fon = txLoadImage ("Background.bmp");

    HDC planet = txLoadImage ("planet.bmp");

    txAlphaBlend (txDC(), 0, 0, 1920, 1080, fon,   0,  0);

    txAlphaBlend (txDC(), 1100, 350, 0, 0, planet, 0,  0);

    laserLine (200, 800, 1300, 450, 0, 100, 100, 5, 1);

    return 0;
    }

//-----------------------------------------------------------------------------

void laserLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, double width1, double width2)
    {
    x1 = x1 - centerX;

    y1 = y1 - centerY;

    x2 = x2 - centerX;

    y2 = y2 - centerY;

    double x1r = x1 * cos (rotate) - y1 * sin (rotate);

    double y1r = x1 * sin (rotate) + y1 * cos (rotate);

    double x2r = x2 * cos (rotate) - y2 * sin (rotate);

    double y2r = x2 * sin (rotate) + y2 * cos (rotate);

    x1 = x1r + centerX;

    y1 = y1r + centerY;

    x2 = x2r + centerX;

    y2 = y2r + centerY;

    double t = 0;

    double x = 0;

    double y = 0;

    while (t <= 1)
        {
        x = x1 + t * (x2 - x1);

        y = y1 + t * (y2 - y1);

        COLORREF pColor = txGetPixel (x, y);

        //if (pColor != RGB (0, 0, 0)) break;

        t += 0.001;
        }

    txSetColor (TX_GREEN, width1);

    txLine (x, y, x1, y1);

    txSetColor (TX_LIGHTGREEN, width2);

    txLine (x, y, x1, y1);

    //printf ("Проверка");

    }

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
