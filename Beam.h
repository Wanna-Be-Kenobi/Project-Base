#include "TXLib.h"

//-----------------------------------------------------------------------------

int intersectionCheck (const Hero* xWing, double *x1, double *y1, double *x2, double *y2);

//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------

/*int main()
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
    }*/

//-----------------------------------------------------------------------------
/*
                                                   MoveHero()

                                [ beamX1 ]  [ beamY1 ]  [ beamX2 ]  [ beamY2 ]
                                   ^            ^            ^           ^
                               ____|____________|____________|___________|_____
                                   |            |            |           |
                                   V            V            V           V
                                [ *x1 ]      [ *y1 ]      [ *x2 ]     [ *y2 ]

                                               intersectionCheck
*/

int intersectionCheck (const Hero* xWing, double *x1, double *y1, double *x2, double *y2)
    {
    *x1 = xWing->x +   130 * xWing->scale * Scale;
    *y1 = xWing->y +     0 * xWing->scale * Scale;
    *x2 = xWing->x + 10000 * xWing->scale * Scale;
    *y2 = xWing->y +     0 * xWing->scale * Scale;

    *x1 = *x1 - xWing->x;

    *y1 = *y1 - xWing->y;

    *x2 = *x2 - xWing->x;

    *y2 = *y2 - xWing->y;

    double x1r = *x1 * cos (xWing->rotate) - *y1 * sin (xWing->rotate);

    double y1r = *x1 * sin (xWing->rotate) + *y1 * cos (xWing->rotate);

    double x2r = *x2 * cos (xWing->rotate) - *y2 * sin (xWing->rotate);

    double y2r = *x2 * sin (xWing->rotate) + *y2 * cos (xWing->rotate);

    *x1 = x1r + xWing->x;

    *y1 = y1r + xWing->y;

    *x2 = x2r + xWing->x;

    *y2 = y2r + xWing->y;

    double t = 0;

    double x = 0;

    double y = 0;

    int message = 0;

    while (t <= 1)
        {
        x = *x1 + t * (*x2 - *x1);

        y = *y1 + t * (*y2 - *y1);

        COLORREF pColor = txGetPixel (x, y);

        int red = txExtractColor (pColor, TX_RED);

        int blue = txExtractColor (pColor, TX_BLUE);

        int green = txExtractColor (pColor, TX_GREEN);

        COLORREF dStarColor = TX_CYAN;

        //printf ("x1 = %lg y1 = %lg x2 = %lg y2 = %lg t = %lg x = %lg y = %lg color = %d %d %d %x, %x\n", x1, y1, x2, y2, t, x, y, red, green, blue, pColor, CLR_INVALID);

        if (pColor == CLR_INVALID)
            {
            break;
            }

        if (pColor == dStarColor)
            {
            message = 1;

            break;
            }

        if (red % 2 != 0)
            {
            txSetColor (TX_PINK);

            txSetFillColor (TX_PINK);

            txCircle (x, y, 15);

            message = 2;

            break;
            }

        t += 0.001;
        }

    *x2 = x;

    *y2 = y;

    return message;

    //printf ("��������");

    // �������� return �� ���������, � �������, ������� ���������� 'void'
    /*
    ����������� �������� ���������� message �� ������� laserLine � ������� MoveHero(), ������� ����� ��������� �������� 0, 1, 2

    ��� �������� �������� ���������� ������������� �������� return.

    Return �� ����� ���������� ���������� �� 'void' �������, ������� ������� laserLine, ��� ��������� return ���� ����������� � ������� 'int'.

    return ������� message � ������� DrawXWing, ��� ���������� laserLine.

    DrawXWing ����� ��� ���������� � 'int' �������, ����� return ��� �� ��� ���������� message ��� � MoveHero(), ��� ���������� DrawXWing.

    �������� ���������� message � DrawXWing. ����� ��������� message � laserLine, ������� ���������� �������� message � laserLine c ������� return.

    ����� �������� message � MoveHero().

    ��������� �� � DrawXWing, ������� ���� ���������� �������� message c ������� return (��� �� laseLine) .

    �������� message = 0 / 1 / 2, � ����������� �� if-�� � ������� laserLine.

    ��� message = 1 � MoveHero() ���������� ���� MessageBox.

    ��� message = 2 � MoveHero() ���������� ������ MessageBox.

    ��� message = 0 � MoveHero()  �� ���������� ������.*/
    }

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
