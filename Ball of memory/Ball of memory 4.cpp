#include "TXLib.h"

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r);

void BallPhysics (int *x, int *y, int r, int *vx, int *vy, int dt);

void MainBall (int x,  int y,  int r,  int vx,  int vy,  int dt,
               int x2, int y2, int r2, int vx2, int vy2);

void BallControl (int *vx, int *vy, int keyUp, int keyDown, int keyRight, int keyLeft);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    MainBall (200, 200, 25, 10, 10, 1, 700, 700, 30, -11, -11);

    return 0;
    }

//-----------------------------------------------------------------------------

void MainBall (int x,  int y,  int r,  int vx,  int vy,  int dt,
               int x2, int y2, int r2, int vx2, int vy2)
    {
    while (1 > 0)
        {
        txSetFillColor (TX_GREY);

        txClear();

        DrawBall (x,  y,  r);

        DrawBall (x2, y2, r2);

        BallPhysics (&x, &y, r, &vx, &vy, dt);

        BallPhysics (&x2, &y2, r2, &vx2, &vy2, dt);

        BallControl (&vx, &vy, 'W', 'S', 'D', 'A');

        BallControl (&vx2, &vy2, VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT);

        txSleep (10);
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r)
    {
    txSetColor (TX_BLUE);

    txSetFillColor (TX_BLUE);

    txCircle (x, y, r);
    }

//-----------------------------------------------------------------------------

void BallPhysics (int *x, int *y, int r, int *vx, int *vy, int dt)
    {
    *x = *x + *vx * dt;

    *y = *y + *vy * dt;

    if (*x > txGetExtentX() - r)
        {
        *x = txGetExtentX() - r;

        *vx = - *vx;
        }

    if (*x < 0 + r)
        {
        *x = 0 + r;

        *vx = - *vx;
        }

    if (*y > txGetExtentY() - r)
        {
        *y = txGetExtentY() - r;

        *vy = - *vy;
        }

    if (*y < 0 + r)
        {
        *y = 0 + r;

        *vy = - *vy;
        }
    }

//-----------------------------------------------------------------------------

void BallControl (int *vx, int *vy, int keyUp, int keyDown, int keyRight, int keyLeft)
    {
    if (GetAsyncKeyState (keyUp))
        {
        *vy = *vy - 1;
        }

    if (GetAsyncKeyState (keyDown))
        {
        *vy = *vy + 1;
        }

    if (GetAsyncKeyState (keyRight))
        {
        *vx = *vx + 1;
        }

    if (GetAsyncKeyState (keyLeft))
        {
        *vx = *vx - 1;
        }
    }











