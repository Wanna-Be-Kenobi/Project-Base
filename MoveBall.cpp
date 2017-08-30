#include "TXLib.h"

//-----------------------------------------------------------------------------

void MoveBall();

void DrawBall (int x, int y, int r, double red, double green, double blue);

void ColorControl (double red, double green, double blue);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    MoveBall();

    return 0;
    }

//-----------------------------------------------------------------------------

void MoveBall()
    {
    int x = 100, y = 100, r = 25;

    int vx = 3, vy = 2;

    int dt = 1;

    double red = 155, green = 155, blue = 155;

//-----------------------------------------------------------------------------

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_GRAY);

        if (! GetAsyncKeyState (VK_CONTROL)) txClear();

        ColorControl (red, green, blue);

        DrawBall (x, y, r, red, green, blue);

        if (GetAsyncKeyState (VK_LEFT))  vx -= 1;

        if (GetAsyncKeyState (VK_RIGHT)) vx += 1;

        if (GetAsyncKeyState (VK_DOWN))  vy -= 1;

        if (GetAsyncKeyState (VK_UP))    vy += 1;

        x = x + vx * dt;

        y = y + vy * dt;

        if (x > txGetExtentX() - r)
            {
            vx = -vx;

            x = txGetExtentX() - r;
            }

        if (y > txGetExtentY() - r)
            {
            vy = -vy;

            y = txGetExtentY() - r;
            }

        if (x < 0 + r)
            {
            vx = -vx;

            x = 0 + r;
            }

        if (y < 0 + r)
            {
            vy = - vy;

            y = 0 + r;
            }

        txSleep();
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r, double red, double green, double blue)
    {
    txSetColor     (RGB (red, green, blue));

    txSetFillColor (RGB (red, green, blue));

    txCircle (x, y, r);
    }

//-----------------------------------------------------------------------------

void ColorControl (double red, double green, double blue)
    {
    if (GetAsyncKeyState ('R'))
            {
            if (GetAsyncKeyState (VK_SHIFT)) red += 1;

            else                             red -= 1;
            }

        if (GetAsyncKeyState ('G'))
            {
            if (GetAsyncKeyState (VK_SHIFT)) green += 1;

            else                             green -= 1;
            }

        if (GetAsyncKeyState ('B'))
            {
            blue += (GetAsyncKeyState (VK_SHIFT)) ? +1 : -1;
            }
    }

//-----------------------------------------------------------------------------



