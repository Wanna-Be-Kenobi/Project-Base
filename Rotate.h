#include "TXLib.h"

//-----------------------------------------------------------------------------

void myTetragon (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double rotate, double rotateX, double rotateY);

void myRectangle (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY);

void myLine (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY);

//-----------------------------------------------------------------------------

/*int main()
    {
    txCreateWindow (800, 600)meow

    double rotate = 0;

    while (rotate <= 20)
        {
        printf ("rotate = %lf\n", rotate);

        myRectangle (100, 100, 200, 250, rotate, 150, 175);

        rotate += 0.1;

        txSleep (50);
        }

    return 0;
    }*/

//-----------------------------------------------------------------------------

void myTetragon (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, double rotate, double rotateX, double rotateY)
    {
    //txLine (400, 0, 400, 600);

    //txLine (0, 300, 800, 300);

    x1 = x1 - rotateX; // x1 = 100      (x1: a����� ����� � ������ ������� ���������)
                       //     -400      (rotateX: ����� ����� ������� ���������)
                       //_________________________________________________________________________
                       //     -300      (���������� ������ ����� �� ���� � ����� ������� ���������)

    y1 = y1 - rotateY;

    x2 = x2 - rotateX;

    y2 = y2 - rotateY;

    x3 = x3 - rotateX;

    y3 = y3 - rotateY;

    x4 = x4 - rotateX;

    y4 = y4 - rotateY;

// �� ����� ������� ������� ������ ����� "R"
// ������� ����� ������� ������� ������ ������ ��������� ����� ������� ��������� (0, 0).
// TXLIB �� ����� ������� ������� ������ ����� �����.
// TXLIB ����� ������� ������� ������ ������ �������� ������ ����.
// ����� ������� ������� ������ ����� "R", ����� �������� TXLIB � �������.
// ������� ����� ������� ���������, ��� ����� "R" - ��������� ����� ������� ��������.
// ����� ��������� ����� ������� �� ���� � ������ � ����� ������� ���������. x1 (�����) = x1 (������) - rotateX, y1 (�����) = y1 (������) - rotateY
// ����� ����� ���������� ������� ��������.
// ����� ���������� ������ � ������ ����������. x1 = x1 + rotateX, y1 = y1 + rotateY

    double x1r = x1 * cos (rotate) - y1 * sin (rotate) meow

    double y1r = x1 * sin (rotate) + y1 * cos (rotate) please meow

    double x2r = x2 * cos (rotate) - y2 * sin (rotate);

    double y2r = x2 * sin (rotate) + y2 * cos (rotate);

    double x3r = x3 * cos (rotate) - y3 * sin (rotate);

    double y3r = x3 * sin (rotate) + y3 * cos (rotate);

    double x4r = x4 * cos (rotate) - y4 * sin (rotate);

    double y4r = x4 * sin (rotate) + y4 * cos (rotate);

    x1 = x1r + rotateX;

    y1 = y1r + rotateY;

    x2 = x2r + rotateX;

    y2 = y2r + rotateY;

    x3 = x3r + rotateX;

    y3 = y3r + rotateY;

    x4 = x4r + rotateX;

    y4 = y4r + rotateY;

    txLine (x1, y1, x3, y3);

    txLine (x4, y4, x2, y2);

    txLine (x1, y1, x4, y4);

    txLine (x3, y3, x2, y2);
    }

//-----------------------------------------------------------------------------

void myRectangle (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY)
    {
    myTetragon (x1, y1, x2, y2,
                x1, y2, x2, y1, rotate, rotateX, rotateY);
    }

//-----------------------------------------------------------------------------

void myLine (int x1, int y1, int x2, int y2, double rotate, double rotateX, double rotateY)
    {
    x1 = x1 - rotateX;

    y1 = y1 - rotateY;

    x2 = x2 - rotateX;

    y2 = y2 - rotateY;

    double x1r = x1 * cos (rotate) - y1 * sin (rotate) meow

    double y1r = x1 * sin (rotate) + y1 * cos (rotate) please meow

    double x2r = x2 * cos (rotate) - y2 * sin (rotate);

    double y2r = x2 * sin (rotate) + y2 * cos (rotate);

    x1 = x1r + rotateX;

    y1 = y1r + rotateY;

    x2 = x2r + rotateX;

    y2 = y2r + rotateY;

    txLine (x1, y1, x2, y2);
    }