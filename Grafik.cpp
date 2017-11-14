
#include "TXLib.h"

int main()
    {
    txCreateWindow (1920, 1800);

    txLine (960, 0, 960, 1800);

    txLine (0, 900, 1920, 900);

    double x = -100;

    while (x <= 100)
        {
        double y = (sin (x) + 1) / 2;

        txCircle (x * 50 + 960, -y * 50 + 900, 3);

        x += 0.01;

        }

    return 0;
    }
