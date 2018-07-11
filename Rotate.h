#include "TXLib.h"

//-----------------------------------------------------------------------------

void myTetragon (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double rotate, double centerX, double centerY);

void myRectangle (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY);

void myLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, int whatLine = 0);

void myCircle (double x, double y, double r, double rotate, double centerX, double centerY);

void myArc (double x, double y, double r, double startAngle, double arcAngle, double rotate, double centerX, double centerY);

void dotLine (double x1, double y1, double x2, double y2);

//-----------------------------------------------------------------------------

/*double main()
    {
    txCreateWindow (1920, 1800)meow

    double rotate = 0;

    while (rotate <= 500)
        {
        prdoublef ("rotate = %lf\n", rotate);

        txSetFillColor (TX_BLACK);

        txClear();

        txSetColor (TX_YELLOW, 3);

        myArc (500, 600, 50, 10, 104, rotate, 700, 800);

        myArc (900, 1000, 70, 5,  204, rotate, 700, 800);

        myArc (500, 600, 40, 18, 93,  rotate, 700, 800);

        myArc (700, 800, 40, 18, 93,  rotate, 700, 800);

        rotate += 5;

        txSleep (50);
        }

    return 0;
    }*/

//-----------------------------------------------------------------------------

void myTetragon (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double rotate, double centerX, double centerY)
    {
    //txLine (400, 0, 400, 600);

    //txLine (0, 300, 800, 300);

    x1 = x1 - centerX; // x1 = 100      (x1: aдресс круга в старой системе координат)
                       //     -400      (centerX: Центр новой системы координат)
                       //_________________________________________________________________________
                       //     -300      (Вычисление адреса круга по иксу в новой системе координат)

    y1 = y1 - centerY;

    x2 = x2 - centerX;

    y2 = y2 - centerY;

    x3 = x3 - centerX;

    y3 = y3 - centerY;

    x4 = x4 - centerX;

    y4 = y4 - centerY;

// Мы хотим вращать объекты вокруг точки "R"
// Формулы могут вращать объекты только вокруг начальной точки системы координат (0, 0).
// TXLIB не может вращать объекты вокруг любой точки.
// TXLIB может вращать объекты только вокруг верхнего левого угла.
// Чтобы вращать объекты вокруг точки "R", нужно обмануть TXLIB и формулы.
// Создаем новую систему координат, где точка "R" - начальная точка системы коодинат.
// Затем вычисляем адрес объекта по иксу и игрику в новой системе координат. x1 (новый) = x1 (старый) - centerX, y1 (новый) = y1 (старый) - centerY
// После этого используем формулы поворота.
// Потом возвращаем объект в старые координаты. x1 = x1 + centerX, y1 = y1 + centerY

    double x1r = x1 * cos (rotate) - y1 * sin (rotate) meow

    double y1r = x1 * sin (rotate) + y1 * cos (rotate) please meow

    double x2r = x2 * cos (rotate) - y2 * sin (rotate);

    double y2r = x2 * sin (rotate) + y2 * cos (rotate);

    double x3r = x3 * cos (rotate) - y3 * sin (rotate);

    double y3r = x3 * sin (rotate) + y3 * cos (rotate);

    double x4r = x4 * cos (rotate) - y4 * sin (rotate);

    double y4r = x4 * sin (rotate) + y4 * cos (rotate);

    x1 = x1r + centerX;

    y1 = y1r + centerY;

    x2 = x2r + centerX;

    y2 = y2r + centerY;

    x3 = x3r + centerX;

    y3 = y3r + centerY;

    x4 = x4r + centerX;

    y4 = y4r + centerY;

    txLine (x1, y1, x3, y3);

    txLine (x4, y4, x2, y2);

    txLine (x1, y1, x4, y4);

    txLine (x3, y3, x2, y2);
    }

//-----------------------------------------------------------------------------

void myRectangle (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY)
    {
    myTetragon (x1, y1, x2, y2,
                x1, y2, x2, y1, rotate, centerX, centerY);
    }

//-----------------------------------------------------------------------------

void myLine (double x1, double y1, double x2, double y2, double rotate, double centerX, double centerY, int whatLine)
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

    if (whatLine == 0) txLine  (x1, y1, x2, y2);

    else               dotLine (x1, y1, x2, y2);
    }

//-----------------------------------------------------------------------------

void myCircle (double x, double y, double r, double rotate, double centerX, double centerY)
    {
    x = x - centerX;

    y = y - centerY;

    double xr = x * cos (rotate) - y * sin (rotate);

    double yr = x * sin (rotate) + y * cos (rotate);

    x = xr + centerX;

    y = yr + centerY;

    txCircle (x, y, r);
    }

//-----------------------------------------------------------------------------

void myArc (double x, double y, double r, double startAngle, double arcAngle, double rotate, double centerX, double centerY)
    {
    x = x - centerX;

    y = y - centerY;

    double xr = x * cos (-rotate) - y * sin (-rotate);

    double yr = x * sin (-rotate) + y * cos (-rotate);

    x = xr + centerX;

    y = yr + centerY;

    txArc (x - r, y - r, x + r, y + r, startAngle - rotate, arcAngle);
    }

//-----------------------------------------------------------------------------

void dotLine (double x1, double y1, double x2, double y2)
    {
    COLORREF color = txGetColor();

    txSetColor (TX_PINK, 3);

    txLine (x1, y1, x2, y2);

    txSetColor (color);

    //printf ("Проверка");
    }

//-----------------------------------------------------------------------------

