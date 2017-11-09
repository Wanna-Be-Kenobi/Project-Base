
#include "TXLib.h"

void DrawStars();

int main()
    {
    txCreateWindow (1920, 1080);

    int t = 0;

    HDC fon = txLoadImage ("new fon.bmp");

    txBitBlt (0, 0, fon);

    while (t < 200)
        {
        txCircle (rand() % 1920, rand() % 1800, rand() % 6);

        t++;
        }

    txDeleteDC (fon);

    txSaveImage ("Background 2.bmp", txDC());

    return 0;
    }
