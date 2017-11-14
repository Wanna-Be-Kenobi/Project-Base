#include "TXLib.h"

//-----------------------------------------------------------------------------

struct Hero
    {
    int x, y, r, vx, vy;

    double xSize, ySize, faceSize, leftEye, rightEye, noseSize;

    int moveNose, leftPunch, rightPunch;

    int leftStep, rightStep, leftHand, rightHand;

    double lips, closeEyes, leftEyebrow, rightEyebrow;

    double red, green, blue;

    int keyRed, keyGreen, keyBlue;

    int keyLeft, keyRight, keyDown, keyUp;
    };

//-----------------------------------------------------------------------------

void MoveBall();

void DrawBall (int x, int y, int r, double red, double green, double blue);

void ColorControl (struct Hero* hero);

void HeroControl  (struct Hero* hero);

void BallSpeed    (struct Hero* hero, int dt);

void DrawGreenCharacter (struct Hero* hero);

void DrawCharacterBase (struct Hero* hero);

void DrawYellowCharacter (struct Hero* hero);

void DrawBlueCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int leftStep, int rightStep,
                                double hatSize, double moveEyesX, double moveEyesY);

void DrawPinkCharacter (struct Hero* hero);
//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1920, 1080);

    MoveBall();

    return 0;
    }
/*struct Hero
    {
    int x, y, r, vx, vy;

    double xSize, ySize, faceSize, leftEye, rightEye, noseSize;

    int moveNose, leftPunch, rightPunch;

    int leftStep, rightStep, leftHand, rightHand;

    double lips, closeEyes, leftEyebrow, rightEyebrow;

    double red, green, blue;

    int keyRed, keyGreen, keyBlue;

    int keyLeft, keyRight, keyDown, keyUp;
    };*/
//-----------------------------------------------------------------------------

void MoveBall()
    {
    Hero ball   = { 100,  100, 25, 3, 2, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 155, 155, 155, '1', '2', '3' },

         yellow = { 250,  900, 60, 0, 0, 1, 1, 1, 1, 1, 1,  10, 1, 1, 1, 1, 0, 0,  0, 0, 0, 0, 255, 255,   0, '4', '5', '6',     'A',      'D',   'W',     'S' },

         green  = { 500,  500, 75, 4, 4, 1, 1, 1, 1, 1, 1, -10, 0, 0, 1, 1, 1, 1, 28, 1, 0, 0,   0, 128,   0, '7', '8', '9', VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN },

         pink   = { 1700, 180, 75, 0, 0, 1, 1, 1, 1, 1, 1,  10, 0, 0, 1, 1, 1, 1,  0, 0, 1, 1,  255,   0, 255,  0,   0,   0,       0,        0,     0,       0 };

    int dt = 1;

    int t = 0;

    while (! GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_WHITE);

        if (! GetAsyncKeyState (VK_CONTROL)) txClear();

        ColorControl (&ball);
        ColorControl (&yellow);
        ColorControl (&green);

        DrawBall            (ball.x, ball.y, ball.r, ball.red, ball.green, ball.blue);
        DrawYellowCharacter (&yellow);

        //DrawYellowCharacter (yellow.x, yellow.y, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);
        DrawGreenCharacter  (&green);

        DrawPinkCharacter   (&pink);
        DrawBlueCharacter   (1700, 900, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), (t % 6), ((t + 3) % 6), 1.5, (t % 10), 1);

        //DrawBlueCharacter   (1700, 900, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), (t % 6), ((t + 3) % 6), 1.5, (t % 10), 1);
        //DrawPinkCharacter   (1700, 180, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, (t % 3) * 14 + 1, (t % 3) * 14 + 1, -(t % 3) * 14 + 1, -(t % 3) * 14 + 1, 1, 1);

        HeroControl (&yellow);
        HeroControl (&green);

        BallSpeed (&ball, dt);
        BallSpeed (&yellow, dt);
        BallSpeed (&green, dt);

        //CharactersAnimation (&pink);


        //printf ("����� ���� = %p\n", &x);

        txSleep(10);

        t++;
        }
    }

//-----------------------------------------------------------------------------

void CharactersAnimation (struct Hero* hero)
    {






    }

//-----------------------------------------------------------------------------

void DrawYellowCharacter (struct Hero* hero)
    {
    DrawCharacterBase (hero);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txEllipse (hero->x + 16, hero->y - 17, hero->x + 38, hero->y - 39*hero->rightEye);

    txEllipse (hero->x - 8,  hero->y - 17, hero->x - 30, hero->y - 39*hero->leftEye);

    txSetColor (TX_BLACK, 6*hero->faceSize);

    txLine (hero->x - 16*hero->xSize, hero->y + 7*hero->ySize,  hero->x - 35*hero->xSize, hero->y + 20*hero->ySize);

    txLine (hero->x - 21*hero->xSize, hero->y + 15*hero->ySize, hero->x - 8*hero->xSize,  hero->y + 27*hero->ySize);

    txLine (hero->x - 8*hero->xSize,  hero->y + 27*hero->ySize, hero->x + 16*hero->xSize, hero->y + 27*hero->ySize);

    txSetFillColor (RGB (hero->red, hero->green, hero->blue));

    txSetColor (TX_BLACK, 6*hero->faceSize);

    txCircle (hero->x + hero->moveNose*hero->noseSize, hero->y, 9*hero->noseSize);
    }

//-----------------------------------------------------------------------------

void DrawGreenCharacter (struct Hero* hero)
    {
    DrawCharacterBase (hero);

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txRectangle (hero->x - 40*hero->xSize, hero->y - 36*hero->ySize + hero->closeEyes, hero->x - 16*hero->xSize, hero->y - 21*hero->ySize);

    txRectangle (hero->x + 5*hero->xSize, hero->y - 36*hero->ySize + hero->closeEyes, hero->x + 29*hero->xSize, hero->y - 21*hero->ySize);

    txSetColor (RGB (0, 0, 0), 6*hero->faceSize);

    txLine (hero->x - 37*hero->xSize, hero->y + 43*hero->ySize - hero->lips, hero->x - 24*hero->xSize, hero->y + 29*hero->ySize);

    txLine (hero->x - 24*hero->xSize, hero->y + 29*hero->ySize, hero->x + 24*hero->xSize, hero->y + 29*hero->ySize);

    txLine (hero->x + 24*hero->xSize, hero->y + 29*hero->ySize, hero->x + 37*hero->xSize, hero->y + 43*hero->ySize - hero->lips);

    txLine (hero->x - 22*hero->xSize, hero->y - 47*hero->ySize, hero->x - 8*hero->xSize, hero->y - 38*hero->ySize);

    txLine (hero->x + 13*hero->xSize, hero->y - 47*hero->ySize, hero->x - 1*hero->xSize, hero->y - 38*hero->ySize);

    txSetFillColor (RGB (hero->red, hero->green, hero->blue));

    txSetColor (TX_BLACK, 6*hero->faceSize);

    txCircle (hero->x + hero->moveNose*hero->faceSize, hero->y, 9*hero->faceSize);
    }

//-----------------------------------------------------------------------------

void DrawPinkCharacter (struct Hero* hero)
    {
    DrawCharacterBase (hero);

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txCircle (hero->x - 18*hero->xSize, hero->y - 29*hero->ySize, 11*hero->faceSize);

    txCircle (hero->x + 27*hero->xSize, hero->y - 29*hero->ySize, 11*hero->faceSize);

    txSetColor (RGB (0, 0, 0), 6*hero->faceSize);

    txLine (hero->x - 22*hero->xSize, hero->y - 47*hero->ySize, hero->x - 36*hero->xSize + hero->rightEyebrow, hero->y - 33*hero->ySize);

    txLine (hero->x + 34*hero->xSize, hero->y - 47*hero->ySize, hero->x + 48*hero->xSize + hero->leftEyebrow, hero->y - 33*hero->ySize);

    txSetColor (RGB (204, 0, 0), 8*hero->faceSize);

    txSetFillColor (RGB (255, 0, 255));

    txCircle (hero->x + 3*hero->xSize, hero->y + 29*hero->ySize, 14*hero->faceSize);

    txSetFillColor (RGB (hero->red, hero->green, hero->blue));

    txSetColor (TX_BLACK, 6*hero->faceSize);

    txCircle (hero->x + hero->moveNose*hero->faceSize, hero->y, 9*hero->faceSize);
    }

//-----------------------------------------------------------------------------

void DrawBlueCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor,int leftStep, int rightStep,
                                double hatSize, double moveEyesX, double moveEyesY)
    {
    txSetColor (contourColor, 8*faceSize);

    txSetFillColor (bodyColor);

    txCircle (x, y, 52*faceSize);

    txCircle (x - 26*xSize, y + 71*ySize - leftStep, 20*faceSize);

    txCircle (x + 24*xSize, y + 71*ySize - rightStep, 20*faceSize);

    txCircle (x + 70*xSize, y + 22*ySize, 20*faceSize);

    txCircle (x - 70*xSize, y + 22*ySize, 20*faceSize);

    txSetColor (contourColor);

    txSetFillColor (TX_BLACK);

    txRectangle (x - 36*xSize + moveEyesX, y - 25*ySize + moveEyesY, x - 12*xSize + moveEyesX, y - 10*ySize + moveEyesY);

    txRectangle (x + 4*xSize + moveEyesX, y - 25*ySize + moveEyesY, x + 28*xSize + moveEyesX, y - 10*ySize + moveEyesY);

    txSetColor (contourColor, 8*faceSize);

    txLine (x - 26*xSize, y - 34*ySize, x - 12*xSize, y - 34*ySize);

    txLine (x + 4*xSize, y - 34*ySize, x + 20*xSize, y - 34*ySize);

    txLine (x - 8*xSize, y + 31*ySize, x + 14*xSize, y + 31*ySize);

    txLine (x + 14*xSize, y + 31*ySize, x + 10*xSize, y + 16*ySize);

    txSetColor (RGB (160, 82, 45), 8*faceSize);

    txSetFillColor (RGB (160, 82, 45));

    txCircle (x - 80*xSize, y + 29*ySize, 10 * faceSize);

    txLine (x - 80*xSize, y + 36*ySize, x - 80*xSize, y + 100*ySize);

    txSetColor (RGB (210, 105, 30), 6*faceSize);

    txLine (x + 5*xSize, y + 21*ySize, x + 17*xSize, y + 34*ySize);

    txSetColor (TX_GREY);

    txSetFillColor (TX_GREY);

    txCircle (x + 17*xSize, y + 34*ySize, 4*faceSize);

    txSetColor (contourColor, 8*faceSize);

    txSetFillColor (TX_BLACK);

    txLine (x + 10*xSize, y + 16*ySize, x - 8*xSize, y + 27*ySize);

    txSetColor (contourColor);

    txSetFillColor (TX_BLACK);

    txRectangle (x - 33*xSize*hatSize, y - 59*ySize, x + 32*xSize*hatSize, y - 49*ySize);

    txRectangle (x - 15*xSize*hatSize, y - 101*ySize*hatSize, x + 15*xSize*hatSize, y - 59*ySize);
    }

//-----------------------------------------------------------------------------

void DrawCharacterBase (struct Hero* hero)
    {

    txSetFillColor (RGB (hero->red, hero->green, hero->blue));

    txSetColor (TX_BLACK, 8*hero->faceSize);

    txRectangle (hero->x - 60*hero->xSize, hero->y - 57*hero->ySize, hero->x + 59*hero->xSize, hero->y + 60*hero->ySize);

    txRectangle (hero->x  - 92*hero->xSize - hero->leftHand, hero->y + 1*hero->ySize, hero->x - 61*hero->xSize - hero->leftHand, hero->y + 40*hero->ySize);

    txRectangle (hero->x  + 60*hero->xSize + hero->rightHand, hero->y  + 1*hero->ySize, hero->x + 90*hero->xSize + hero->rightHand, hero->y + 40*hero->ySize);

    txRectangle (hero->x - 45*hero->xSize, hero->y + 61*hero->ySize - hero->leftStep, hero->x - 11*hero->xSize, hero->y + 90*hero->ySize - hero->leftStep);

    txRectangle (hero->x + 10*hero->xSize, hero->y + 61*hero->ySize - hero->rightStep, hero->x + 44*hero->xSize, hero->y + 90*hero->ySize - hero->rightStep);
    }

//-----------------------------------------------------------------------------

void BallSpeed (struct Hero* hero, int dt)
    {
    hero->x = hero->x + hero->vx * dt;

    hero->y = hero->y + hero->vy * dt;

    if (hero->x > txGetExtentX() - hero->r)
        {
        hero->vx = -hero->vx;

        hero->x = txGetExtentX() - hero->r;
        }

    if (hero->y > txGetExtentY() - hero->r)
        {
        hero->vy = -hero->vy;

        hero->y = txGetExtentY() - hero->r;
        }

    if (hero->x < 0 + hero->r)
        {
        hero->vx = -hero->vx;

        hero->x = 0 + hero->r;
        }

    if (hero->y < 0 + hero->r)
        {
        hero->vy = -hero->vy;

        hero->y = 0 + hero->r;
        }
    }

//-----------------------------------------------------------------------------

void HeroControl (struct Hero* hero)
    {
    if (GetAsyncKeyState (hero->keyLeft))  hero->vx -= 1;

    if (GetAsyncKeyState (hero->keyRight)) hero->vx += 1;

    if (GetAsyncKeyState (hero->keyDown))  hero->vy -= 1;

    if (GetAsyncKeyState (hero->keyUp))    hero->vy += 1;
    }

//-----------------------------------------------------------------------------

void DrawBall (int x, int y, int r, double red, double green, double blue)
    {
    txSetColor     (RGB (red, green, blue));

    txSetFillColor (RGB (red, green, blue));

    txCircle (x, y, r);
    }

//-----------------------------------------------------------------------------

void ColorControl (struct Hero* hero)
    {
    if (GetAsyncKeyState (hero->keyRed))
        {
        if (GetAsyncKeyState (VK_SHIFT)) hero->red += 1;

        else                             hero->red -= 1;
        }

    if (GetAsyncKeyState (hero->keyGreen))
        {
        if (GetAsyncKeyState (VK_SHIFT)) hero->green += 1;

        else                             hero->green -= 1;
        }

    if (GetAsyncKeyState (hero->keyBlue))
        {
        hero->blue += (GetAsyncKeyState (VK_SHIFT)) ? +1 : -1;
        }
    }
