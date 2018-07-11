#include "TXLib.h"

//-----------------------------------------------------------------------------

struct Ball
    {
    double x, y, r, vx, vy;

    int keyLeft, keyRight, keyUp, keyDown;
    };

//-----------------------------------------------------------------------------

void DrawBall (const struct Ball *ball);

void BallPhysics (struct Ball *ball, int dt);

void MainBall ();

void BallControl (struct Ball *ball);

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

    while (true)
        {
        txSetFillColor (TX_GREY);

        txClear();

        DrawBall (&First);

        DrawBall (&Second);

        BallPhysics (&First, dt);

        BallPhysics (&Second, dt);

        BallControl (&First);

        BallControl (&Second);

        txSleep (10);
        }
    }

//-----------------------------------------------------------------------------

void DrawBall (const struct Ball *ball)
    {
    txSetColor (TX_BLUE);

    txSetFillColor (TX_BLUE);

    txCircle (ball->x, ball->y, ball->r);
    }

//-----------------------------------------------------------------------------

void BallPhysics (struct Ball *ball, int dt)
    {
    ball->x = ball->x + ball->vx * dt;

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

void BallControl (struct Ball *ball)
    {
    if (GetAsyncKeyState (ball->keyUp))
        {
        ball->vy = ball->vy - 1;
        }

    if (GetAsyncKeyState (ball->keyDown))
        {
        ball->vy = ball->vy + 1;
        }

    if (GetAsyncKeyState (ball->keyRight))
        {
        ball->vx = ball->vx + 1;
        }

    if (GetAsyncKeyState (ball->keyLeft))
        {
        ball->vx = ball->vx - 1;
        }
    }










