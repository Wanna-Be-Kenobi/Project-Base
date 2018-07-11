#include "TXLib.h"

//-----------------------------------------------------------------------------
 int main()
    {
    HDC fon = txLoadImage ("BackgroundNew.bmp");

    int fonY = txGetExtentY (fon);

    int fonX = txGetExtentX (fon);

    txCreateWindow (fonX, fonY);

    txBitBlt (0, 0, fon, 0, 0);

    int y = 0;


    while (y <= fonY)
        {
        printf ("y = %d \r", y);

        int x = 0;

        while (x <= fonX)
            {
            COLORREF pixelColor = txGetPixel (x, y);

            int red   = txExtractColor (pixelColor, TX_RED);

            int green = txExtractColor (pixelColor, TX_GREEN);

            int blue  = txExtractColor (pixelColor, TX_BLUE);

            if (red   % 2 != 0) txSetPixel (x, y, TX_PINK);

            if (green % 2 != 0) txSetPixel (x, y, TX_PINK);

            if (blue  % 2 != 0) txSetPixel (x, y, TX_PINK);

            x++;
            }
        y++;
        }

    return 0;
    }

//-----------------------------------------------------------------------------
