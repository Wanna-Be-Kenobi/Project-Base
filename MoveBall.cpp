#include "TXLib.h"

//-----------------------------------------------------------------------------

void MoveBall();

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
    int x = 100, y = 100;

    int vx = 5, vy = 5;

    int dt = 1;

    while (true)
        {
        txSetFillColor (TX_GRAY);

        txClear();

        txSetColor (TX_BLUE);

        txSetFillColor (TX_BLUE);

        txCircle (x, y, 25);

        x = x + vx * dt;

        y = y + vy * dt;

        if (x > 1895)
            {
            vx = -vx;

            x = 1895;
            }

        if (y > 1055)
            {
            vy = -vy;

            y = 1055;
            }

        if (x < 25)
            {
            vx = -vx;

            x = 25;
            }

        if (y < 25)
            {
            vy = - vy;

            y = 25;
            }

        txSleep (10);
        }
    }

