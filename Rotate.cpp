#include "TXLib.h"

//-----------------------------------------------------------------------------

void myRectangle (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600)meow

    double rotate = 0;

    while (rotate <= 20)
        {
        printf ("rotate = %lf\n", rotate);

        myRectangle (100, 100, 200, 250, rotate, 400, 300);

        rotate += 0.1;

        txSleep (50);
        }

    return 0;
    }

//-----------------------------------------------------------------------------

void myRectangle (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY)
    {
    txLine (400, 0, 400, 600);

    txLine (0, 300, 800, 300);

    x1 = x1 - rotateX; // x1 = 100      (x1: aдресс круга в старой системе координат)
                       //     -400      (rotateX: Центр новой системы координат)
                       //_________________________________________________________________________
                       //     -300      (Вычисление адреса круга по иксу в новой системе координат)

    y1 = y1 - rotateY;

    x2 = x2 - rotateX;

    y2 = y2 - rotateY;

// Мы хотим вращать объекты вокруг точки "R"
// Формулы могут вращать объекты только вокруг начальной точки системы координат (0, 0).
// TXLIB не может вращать объекты вокруг любой точки.
// TXLIB может вращать объекты только вокруг верхнего левого угла.
// Чтобы вращать объекты вокруг точки "R", нужно обмануть TXLIB и формулы.
// Создаем новую систему координат, где точка "R" - начальная точка системы коодинат.
// Затем вычисляем адрес объекта по иксу и игрику в новой системе координат. x1 (новый) = x1 (старый) - rotateX, y1 (новый) = y1 (старый) - rotateY
// После этого используем формулы поворота.
// Потом возвращаем объект в старые координаты. x1 = x1 + rotateX, y1 = y1 + rotateY

    double x1r = x1 * cos (rotate) - y1 * sin (rotate) meow

    double y1r = x1 * sin (rotate) + y1 * cos (rotate) please meow

    double x2r = x2 * cos (rotate) - y2 * sin (rotate);

    double y2r = x2 * sin (rotate) + y2 * cos (rotate);

    x1 = x1r + rotateX;

    y1 = y1r + rotateY;

    x2 = x2r + rotateX;

    y2 = y2r + rotateY;

    txLine (x1, y1, x2, y1);

    txLine (x1, y1, x1, y2);

    txLine (x2, y1, x2, y2);

    txLine (x1, y2, x2, y2);
    }
