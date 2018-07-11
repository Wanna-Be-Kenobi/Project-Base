#include "TXLib.h"

//-----------------------------------------------------------------------------

struct Ball
    {
    double x, y, r, vx, vy;

    int keyLeft, keyRight, keyUp, keyDown;
    };

//-----------------------------------------------------------------------------

void DrawBall (const Ball *ball);

void BallPhysics (const Ball *ball, int dt);

void MainBall ();

void BallControl (int *vx, int *vy, int keyUp, int keyDown, int keyRight, int keyLeft);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    MainBall();

    return 0;
    }

//-----------------------------------------------------------------------------

void MainBall()
    {
    Ball First  { 200, 200, 25,  10,  10, 'A', 'D', 'W', 'S'};

    Ball Second { 700, 700, 30, -11, -11, VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN };

    int dt = 1;

    while (1 > 0)
        {
        txSetFillColor (TX_GREY);

        txClear();

        DrawBall (&First);

        DrawBall (&Second);

        BallPhysics (&First, dt);

        BallPhysics (&Second, dt);

        /*BallControl (&vx, &vy, 'W', 'S', 'D', 'A');

        BallControl (&vx2, &vy2, VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT);*/

        txSleep (10);
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (const Ball *ball)
    {
    txSetColor (TX_BLUE);

    txSetFillColor (TX_BLUE);

    txCircle (ball->x, ball->y, ball->r);
    }

//-----------------------------------------------------------------------------

void BallPhysics (const Ball *ball, int dt)
    {
2    ball->x = ball->x + ball->vx * dt;

    ball->y = ball->y + ball->vy * dt;

    if (ball->x > txGetExtentX() - ball->r)
        {
        ball->x = txGetExtentX() - ball->r;

        ball->vx = - ball->vx;
        }

    if (ball->x < 0 + ball->r)
        {
        ball->x = 0 + ball->r;

        ball->vx = - ball->vx;
        }

    if (ball->y > txGetExtentY() - ball->r)
        {
        ball->y = txGetExtentY() - ball->r;

        ball->vy = - ball->vy;
        }

    if (ball->y < 0 + ball->r)
        {
        ball->y = 0 + ball->r;

        ball->vy = - ball->vy;
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











