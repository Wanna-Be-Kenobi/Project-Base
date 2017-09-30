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

    x1 = x1 - rotateX; // x1 = 100      (x1: a����� ����� � ������ ������� ���������)
                       //     -400      (rotateX: ����� ����� ������� ���������)
                       //_________________________________________________________________________
                       //     -300      (���������� ������ ����� �� ���� � ����� ������� ���������)

    y1 = y1 - rotateY;

    x2 = x2 - rotateX;

    y2 = y2 - rotateY;

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

    x1 = x1r + rotateX;

    y1 = y1r + rotateY;

    x2 = x2r + rotateX;

    y2 = y2r + rotateY;

    txLine (x1, y1, x2, y1);

    txLine (x1, y1, x1, y2);

    txLine (x2, y1, x2, y2);

    txLine (x1, y2, x2, y2);
    }
