#include "TXLib.h"


//-----------------------------------------------------------------------------

int main()
    {
    HDC fon = txLoadImage ("Background.bmp");

    int y = 0;

    int fonY = txGetExtentY (fon);

    int fonX = txGetExtentX (fon);

    while (y <= fonY)
        {
        printf ("y = %d \r", y);

        int x = 0;

        while (x <= fonX)
            {
            COLORREF pixelColor = txGetPixel (x, y, fon);

            int red   = txExtractColor (pixelColor, TX_RED);

            int green = txExtractColor (pixelColor, TX_GREEN);

            int blue  = txExtractColor (pixelColor, TX_BLUE);

            if (red   % 2 != 0) red--;

            if (green % 2 != 0) green--;

            if (blue  % 2 != 0) blue--;

            txSetPixel (x, y, RGB (red, green, blue), fon);

            x++;
            }
        y++;
        }

    txSaveImage ("BackgroundNew.bmp", fon);

    return 0;
    }