#include "TXLib.h"

//-----------------------------------------------------------------------------

int laserLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, double width1, double width2);

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

int laserLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, double width1, double width2)
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

    int message = 0;

    while (t <= 1)
        {
        x = x1 + t * (x2 - x1);

        y = y1 + t * (y2 - y1);

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

    txSetColor (TX_GREEN, width1);

    txLine (x, y, x1, y1);

    txSetColor (TX_LIGHTGREEN, width2);

    txLine (x, y, x1, y1);

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

    ��� message = 0 � MoveHero()  �� ���������� ������.
    }

//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
