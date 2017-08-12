#include "TXLib.h"

//-----------------------------------------------------------------------------

//Prototypes

void DrawYellowCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int rightStep, int leftStep, int rightPunch, int leftPunch,
                                double rightEye, double leftEye, double noseSize);

void DrawGreenCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int rightStep, int leftStep, int rightHand, int leftHand,
                                double lips, double closeEyes);

void DrawBlueCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int leftStep, int rightStep,
                                double hatSize, double moveEyesX, double moveEyesY);

void DrawJetPack (int x, int y, double xSize, double ySize, double faceSize);

void DrawPinkCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int leftStep, int rightStep, int leftHand, int rightHand,
                                double leftEyebrow, double rightEyebrow);

void DrawCannonball (int x, int y, double faceSize, COLORREF bodyColor, COLORREF contourColor);

void DrawCannon (int x, int y, double xSize, double ySize, double faceSize);

void DrawEvilMinion (int x, int y, double xSize, double ySize, double faceSize);

void DrawEvilShot (int x, int y, double xSize, double ySize, double faceSize);

void DrawLaserCannon (int x, int y, double xSize, double ySize, double faceSize);

void DrawLaser (int x, int y, double xSize, double ySize, double faceSize);

void DrawCharacterBase (int x, int y, COLORREF bodyColor, COLORREF contourColor,
                        double xScale, double yScale, double faceSize, int leftStep, int rightStep, int leftHand, int rightHand);

void DrawPinkBackground();

void MoveAll();

void WierdTalk();

void ScaryMeeting();

void Punch();

void DrawBackground();

void DrawBackground2();

void DrawBackground3();

void DrawBackground4();

void DrawBackground5();

void DrawBackground6();

void DrawPinkGreen();

void YellowPunch();

void Explosion();

void FirstScene();

void DrawPark();

void SecondScene();

void DrawFightClub();

void DrawCage();

void ThirdScene();

void DrawDarkPark();

void DrawRoboArmy (int x, int y, int t);


//-----------------------------------------------------------------------------


int main()
    {
    txCreateWindow (1500, 1000);

    /*MoveAll();

    ScaryMeeting();

    Punch();

    WierdTalk();

    Explosion();*/

    FirstScene();

    //SecondScene();

    //ThirdScene();

    return 0;
    }


//-----------------------------------------------------------------------------


void FirstScene()
    {
    int t = 0;

    while (t < 100)
        {
        txSetFillColor (TX_WHITE);

        txClear();

        DrawPark();

        DrawYellowCharacter (290 + 3 * t, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, (t % 4) * 5, ((t + 2) % 4) * 5, 1, 1, 1, 1, 1);

        DrawPinkCharacter (100 + 3 * t, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, (t % 4) * 5, ((t + 2) % 4) * 5, 1, 1, 1, 1);

        txSelectFont ("Comic Sans MS", 40);

        txTextOut (250 + 3 * t, 700, "Would you like some ice cream?");

        t ++ ;

        txSleep (20);
        }

    while (t < 315)
        {
        txSetFillColor (TX_WHITE);

        txClear();

        DrawPark();

        DrawRoboArmy (1600 - 10 * t, 200, t);

        DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawPinkCharacter (400, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, -30, 1);

        t ++ ;

        txSleep (5);
        }

// The characters' talk

        {
        DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawPinkCharacter (400, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1);

        DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        txSelectFont ("Comic Sans MS", 40);

        txTextOut (700, 700, "IT WAS MY ROBO-ARMY");

        txSleep (3000);

        txSetFillColor (TX_WHITE);

        txClear();

        DrawPark();

        DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawPinkCharacter (400, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1);

        DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        txSelectFont ("Comic Sans MS", 40);

        txTextOut (700, 700, "AND NOW I'll TAKE YOUR GIRLFRIEND >:)");

        txSleep (3000);

        txSetFillColor (TX_WHITE);

        txClear();

        DrawPark();

        DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

        txSetFillColor (TX_BLACK);

        txClear();

        txSleep (1000);
        }
    }


//-----------------------------------------------------------------------------


void DrawRoboArmy (int x, int y, int t)
    {
    int n = 0 ;

    while (n <= 5)
        {
        DrawEvilMinion  (x        + 200 * n, y,       (t % 2) * 0.2 + 1, (t % 2) * 0.2 + 1, (t % 2) + 1);

        DrawEvilMinion ((x + 100) + 200 * n, y + 200, (t % 2) * 0.2 + 1, (t % 2) * 0.2 + 1, (t % 2) + 1);   // 0  1   2  3   4  5     t
                                                                                                            // 0  1   0  1   0  1     t % 2
                                                                                                            // 0  0.2 0  0.2 0  0.2   t % 2 * 0.2
                                                                                                            // 1  1.2 1  1.2 1  1.2   t % 2 * 0.2 + 1

        n ++ ;
        }
    }



//-----------------------------------------------------------------------------
void DrawPark()
    {
    txSetColor (TX_YELLOW);

    txSetFillColor (TX_YELLOW);

    txCircle (1, 1, 150);

    txSetColor (TX_GREEN);

    txSetFillColor (TX_GREEN);

    txRectangle (1, 850, 1500, 1000);

    txSetColor (RGB (110, 139, 61));

    txSetFillColor (RGB (110, 139, 61));

    txEllipse (850, 350, 1100, 700);

    txEllipse (50, 350, 300, 700);

    txEllipse (450, 350, 700, 700);

    txSetColor (RGB (139, 90, 43));

    txSetFillColor (RGB (139, 90, 43));

    txRectangle (930, 550, 1020, 850);

    txRectangle (130, 550, 220, 850);

    txRectangle (530, 550, 620, 850);
    }


//-----------------------------------------------------------------------------


void SecondScene()
    {
    int t = 0;

    {
    txSetFillColor (TX_GRAY);

    txClear();

    DrawFightClub();

    DrawYellowCharacter (390, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

    txSelectFont ("Comic Sans MS", 200, 40);

    txTextOut (650, 550, "VS");

    txSleep (2000);

    txSetFillColor (TX_GRAY);

    txClear();

    DrawFightClub();

    DrawYellowCharacter (390, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

    txSelectFont ("Comic Sans MS", 200, 40);

    txTextOut (570, 550, "FIGHT");

    txSleep (2000);
    }

    while (t < 100)
        {
        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawYellowCharacter (390 + 4 * t, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, (t % 4) * 5, ((t + 2) % 4) * 5, 1, 1, 1, 1, 1);

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        t ++ ;

        txSleep (5);
        }

        {
        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        txSleep (1000);

        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 20, 1, 1, 1, 1);

        txSleep (1000);

        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        txSleep (1000);

        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

        txSleep (1000);

        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        DrawGreenCharacter (1000, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

        txSleep (1000);

        txSelectFont ("Comic Sans MS", 50);

        txTextOut (900, 650, "I'll meet you again... Later...");

        txSleep (3000);

        txSetFillColor (TX_GRAY);

        txClear();

        DrawFightClub();

        DrawYellowCharacter (790, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

        txSleep (2000);
        }
    }


//-----------------------------------------------------------------------------


void ThirdScene()
    {
    txSetFillColor (TX_BLACK);

    txClear();

    txSleep (1000);

    DrawDarkPark();

    DrawYellowCharacter (490, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawPinkCharacter (300, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1);

    DrawBlueCharacter (800, 800, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawDarkPark()
    {
    txSetFillColor (RGB (25, 25, 112));

    txClear();

    txSetColor (TX_WHITE);

    txSetFillColor (TX_WHITE);

    txCircle (1250, 850, 100);

    txSetColor (RGB (0, 100, 0));

    txSetFillColor (RGB (0, 100, 0));

    txRectangle (1, 850, 1500, 1000);

    txSetColor (RGB (110, 139, 61));

    txSetFillColor (RGB (110, 139, 61));

    txEllipse (850, 350, 1100, 700);

    txEllipse (50, 350, 300, 700);

    txEllipse (450, 350, 700, 700);

    txSetColor (RGB (139, 90, 43));

    txSetFillColor (RGB (139, 90, 43));

    txRectangle (930, 550, 1020, 850);

    txRectangle (130, 550, 220, 850);

    txRectangle (530, 550, 620, 850);
    }


//-----------------------------------------------------------------------------



void DrawFightClub()
    {
    DrawCage();

    DrawPinkCharacter (750, 300, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

    txSetColor (RGB (255, 185, 15), 10);

    txLine (400, 550, 1100, 550);

    txLine (400, 580, 1100, 580);

    txLine (400, 610, 1100, 610);

    txLine (400, 640, 1100, 640);

    txLine (400, 550, -500, 1550);

    txLine (400, 580, -500, 1580);

    txLine (400, 610, -500, 1610);

    txLine (400, 640, -500, 1640);

    txLine (1100, 550, 2300, 1550);

    txLine (1100, 580, 2300, 1580);

    txLine (1100, 610, 2300, 1610);

    txLine (1100, 640, 2300, 1640);

    txSetColor (RGB (139, 69, 19), 20);

    txLine (400, 500, 400, 700);

    txLine (1100, 500, 1100, 700);
    }


//-----------------------------------------------------------------------------


void DrawCage()
    {
    txSetColor ((TX_BLACK), 10);

    txRectangle (666, 236, 832, 382);

    txLine (750, 1, 750, 236);
    }


//-----------------------------------------------------------------------------


void DrawYellowCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int leftStep, int rightStep, int leftPunch, int rightPunch,
                                double leftEye, double rightEye, double noseSize)
    {
    DrawCharacterBase (x, y, bodyColor, contourColor, xSize, ySize, faceSize, rightStep, leftStep, rightPunch, leftPunch);

    txSetColor (contourColor);

    txSetFillColor (contourColor);

    txEllipse (x + 16, y - 17, x + 38, y - 39*rightEye);

    txEllipse (x - 8, y - 17, x - 30, y - 39*leftEye);

    txSetColor (RGB (0, 0, 0), 6*faceSize);

    txLine (x - 16*xSize, y + 7*ySize, x - 35*xSize, y + 20*ySize);

    txLine (x - 21*xSize, y + 15*ySize, x - 8*xSize, y + 27*ySize);

    txLine (x - 8*xSize, y + 27*ySize, x + 16*xSize, y + 27*ySize);

    txSetFillColor (bodyColor);

    txSetColor (contourColor, 6*faceSize);

    txCircle (x + moveNose*noseSize, y, 9*noseSize);
    }

//-----------------------------------------------------------------------------


void DrawGreenCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int leftStep, int rightStep, int leftHand, int rightHand,
                                double lips, double closeEyes)
    {
    DrawCharacterBase (x, y, bodyColor, contourColor, xSize, ySize, faceSize, rightStep, leftStep, rightHand, leftHand);

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txRectangle (x - 40*xSize, y - 36*ySize + closeEyes, x - 16*xSize, y - 21*ySize);

    txRectangle (x + 5*xSize, y - 36*ySize + closeEyes, x + 29*xSize, y - 21*ySize);

    txSetColor (RGB (0, 0, 0), 6*faceSize);

    txLine (x - 37*xSize, y + 43*ySize - lips, x - 24*xSize, y + 29*ySize);

    txLine (x - 24*xSize, y + 29*ySize, x + 24*xSize, y + 29*ySize);

    txLine (x + 24*xSize, y + 29*ySize, x + 37*xSize, y + 43*ySize - lips);

    txLine (x - 22*xSize, y - 47*ySize, x - 8*xSize, y - 38*ySize);

    txLine (x + 13*xSize, y - 47*ySize, x - 1*xSize, y - 38*ySize);

    txSetFillColor (bodyColor);

    txSetColor (contourColor, 6*faceSize);

    txCircle (x + moveNose*faceSize, y, 9*faceSize);
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


void DrawJetPack (int x, int y, double xSize, double ySize, double faceSize)
    {
    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txRectangle (x - 40*xSize, y - 43*ySize, x - 21*xSize, y + 41*ySize);

    txRectangle (x + 20*xSize, y - 43*ySize, x + 39*xSize, y + 41*ySize);

    txRectangle (x - 36*xSize, y - 57*ySize, x - 26*xSize, y - 42*ySize);

    txRectangle (x + 25*xSize, y - 57*ySize, x + 35*xSize, y - 42*ySize);

    txSetColor (RGB (218, 165, 32));

    txSetFillColor (RGB (218, 165, 32));

    txRectangle (x - 35*xSize, y - 37*ySize, x + 34*xSize, y + 37*ySize);

    txSetColor (RGB (0, 0, 0), 8*faceSize);

    txSetFillColor (TX_BLACK);

    txLine (x - 23*xSize, y - 32*ySize, x - 23*xSize, y + 32*ySize);

    txLine (x + 22*xSize, y - 32*ySize, x + 22*xSize, y + 32*ySize);
    }


//-----------------------------------------------------------------------------


void DrawPinkCharacter (int x, int y, double xSize, double ySize, double faceSize,
                            COLORREF bodyColor, COLORREF contourColor, int moveNose, int leftStep, int rightStep, int leftHand, int rightHand,
                                double leftEyebrow, double rightEyebrow)
    {
    DrawCharacterBase (x, y, bodyColor, contourColor, xSize, ySize, faceSize, rightStep, leftStep, rightHand, leftHand);

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txCircle (x - 18*xSize, y - 29*ySize, 11*faceSize);

    txCircle (x + 27*xSize, y - 29*ySize, 11*faceSize);

    txSetColor (RGB (0, 0, 0), 6*faceSize);

    txLine (x - 22*xSize, y - 47*ySize, x - 36*xSize + rightEyebrow, y - 33*ySize);

    txLine (x + 34*xSize, y - 47*ySize, x + 48*xSize + leftEyebrow, y - 33*ySize);

    txSetColor (RGB (204, 0, 0), 8*faceSize);

    txSetFillColor (RGB (255, 0, 255));

    txCircle (x + 3*xSize, y + 29*ySize, 14*faceSize);

    txSetFillColor (bodyColor);

    txSetColor (contourColor, 6*faceSize);

    txCircle (x + moveNose*faceSize, y, 9*faceSize);
    }


//=============================================================================


void MoveAll()
    {
    int t = 0;

    while (t < 100)
        {
        txSetFillColor (TX_WHITE);

        txClear();

        DrawPinkCharacter (100 + 3 * t, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1);

        DrawYellowCharacter (290 + 3 * t, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, (t % 4) * 5, ((t + 2) % 4) * 5, 1, 1, 1, 1, 1);

        //t = 0 1 2 3 4 5 6 7 8 9

        //    0 1 0 1 0 1 0 1 0 1
        //    1 0 1 0 1 0 1 0 1 0

        t ++ ;

        txSleep (10);
        }
    }


void ScaryMeeting()
    {
    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    txSleep (500);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawBackground();

    DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);
    }


void Punch()
    {
    txSleep (500);

    YellowPunch();

    txSetFillColor (TX_WHITE);

    txClear();

    DrawBackground2();

    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);
    }


void WierdTalk()
    {
    txSleep (500);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawBackground3();

    txSleep (500);

    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 28, 1);

    txTextOut (750, 700, "I NEED THIS");

    DrawJetPack (800, 650, 1, 1, 1);

    txSleep (1000);

    DrawPinkCharacter (400, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, -30, 1);

    txTextOut (390, 700, "???");

    txTextOut (580, 700, "?");

    txSleep (2000);

    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    txSleep (1000);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawBackground4();

    txSleep (1000);

    DrawGreenCharacter (1200, 500, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    txSleep (1000);

    DrawEvilMinion (900 , 800, 1, 1, 1);

    DrawEvilMinion (1050, 800, 1, 1, 1);

    DrawEvilMinion (1200 , 800, 1, 1, 1);

    DrawEvilMinion (1350, 800, 1, 1, 1);

    txSleep (250);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawBackground5();

    DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

    txSleep (2000);
    }


void Explosion()
    {
    int t = 0;

    while (t < 10)
        {
        txSetFillColor (TX_WHITE);

        txClear();

        DrawBackground5();

        DrawPinkCharacter (400, 800, 1 + 1 * t, 1 + 1 * t, 0.5 + 1 * t, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

        t ++ ;

        txSleep (100);

        txSetFillColor (TX_WHITE);

        txClear();

        txSelectFont ("Comic Sans MS", 50);

        txTextOut (650, 500, "ÇÂÓÊ ÂÇÐÛÂÀ");
        }

        {
        txSleep (3000);

        txSetFillColor (TX_WHITE);

        txClear();

        txSelectFont ("Comic Sans MS", 50);

        txTextOut (700, 500, "ÊÎÍÅÖ!");

        DrawBlueCharacter (1000, 500, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), 5, 1, 1, 1, 1);
        }
    }


//-----------------------------------------------------------------------------


void DrawBackground()
    {
    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawBackground2()
    {
    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);
    }


//-----------------------------------------------------------------------------


void YellowPunch()
    {
    txSleep (100);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawPinkGreen();

    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 20, 1, 1, 1, 1);

    txSleep (400);

    txSetFillColor (TX_WHITE);

    txClear();

    DrawPinkGreen();

    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawBackground3()
    {
    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawBackground4()
    {
    DrawPinkCharacter (400, 800, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 1, 1, 1, -30, 1);

    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawBackground5()
    {
    DrawGreenCharacter (1200, 500, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);

    DrawEvilMinion (900 , 800, 1, 1, 1);

    DrawEvilMinion (1050, 800, 1, 1, 1);

    DrawEvilMinion (1200 , 800, 1, 1, 1);

    DrawEvilMinion (1350, 800, 1, 1, 1);

    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawBackground6()
    {
    DrawYellowCharacter (590, 800, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 1, 1, 1, 1, 1, 1);

    DrawGreenCharacter (1200, 500, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);
    }





void DrawPinkGreen()
    {
    DrawPinkCharacter (400, 800, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

    DrawGreenCharacter (800, 800, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 1, 1, 1, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawPinkBackground()
    {
    DrawYellowCharacter (235, 134, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 5, 1, 1, 15, 1, 0.6, 1);

    DrawYellowCharacter (255, 554, 1, 1, 1, RGB (255, 255, 0), (TX_BLACK), 10, 1, 5, 15, 1, 0.6, 1, 1.3);

    DrawGreenCharacter (560, 130, 1, 1, 1, RGB (0, 128, 0), (TX_BLACK), -10, 5, 1, 1, 1, 1, 1);

    DrawGreenCharacter (560, 630, 1, 1, 1, RGB (255, 0, 0), (TX_BLACK), -10, 1, 5, 1, 1, 28, 12);

    DrawBlueCharacter (805, 134, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), 5, 1, 1, 1, 1);

    DrawBlueCharacter (805, 650, 1, 1, 1, RGB (0, 0, 255), (TX_BLACK), 1.5, 5, 1, -5, 5);

    DrawPinkCharacter (1200, 322, 1, 1, 0.5, RGB (255, 0, 255), (TX_BLACK), 10, 15, 15, -15, -15, 1, 1);

    DrawPinkCharacter (1200, 622, 1, 1, 1, RGB (255, 0, 255), (TX_BLACK), 10, 1, 5, 1, 1, -30, 1);

    DrawJetPack (1010, 152, 1, 1, 1);

    DrawCannon (723, 362, 1, 1, 1);

    DrawCannonball (547, 337, 1, (TX_BLACK), (TX_BLACK));

    DrawEvilMinion (980, 320, 1, 1, 1);

    DrawEvilShot (875, 329, 1, 1, 1);

    DrawLaserCannon (808, 440, 1, 1, 1);

    DrawLaser (762, 440, 1, 1, 1);
    }


//-----------------------------------------------------------------------------


void DrawCannonball (int x, int y, double faceSize, COLORREF bodyColor, COLORREF contourColor)
    {
    txSetColor (contourColor);

    txSetFillColor (bodyColor);

    txCircle (x, y, 30*faceSize);
    }


//-----------------------------------------------------------------------------


void DrawCannon (int x, int y, double xSize, double ySize, double faceSize)
    {
    txSetColor (RGB (105, 105, 105));

    txSetFillColor (RGB (105, 105, 105));

    txRectangle (x - 94*xSize, y - 62*ySize, x + 31*xSize, y + 8*ySize);

    txCircle (x + 31*xSize, y - 27*ySize, 35*faceSize);

    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txCircle (x - 94*xSize, y - 27*ySize, 34*faceSize);

    txSetColor (RGB (139, 69, 19));

    txSetFillColor (RGB (139, 69, 19));

    txCircle (x, y, 40*faceSize);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x, y, 12*faceSize);

    txSetColor (RGB (244, 164, 96), 8*faceSize);

    txLine (x + 64*xSize, y - 32*ySize, x + 101*xSize, y - 62*ySize);

    txSetColor (TX_RED);

    txSetFillColor (TX_RED);

    txCircle (x + 101*xSize, y - 62*ySize, 6*faceSize);
    }


//-----------------------------------------------------------------------------


void DrawEvilMinion (int x, int y, double xSize, double ySize, double faceSize)
    {
    txSetColor (RGB (105, 105, 105), 8*faceSize);

    txSetFillColor (RGB (119, 136, 153));

    txRectangle (x - 40*xSize, y - 40*ySize, x + 39*xSize, y + 39*ySize);

    txSetFillColor (TX_RED);

    txRectangle (x - 65*xSize, y + 1*ySize, x - 41*xSize, y + 19*ySize);

    txRectangle (x + 40*xSize, y + 1*ySize, x + 64*xSize, y + 19*ySize);

    txRectangle (x - 30*xSize, y+40*ySize, x - 11*xSize, y + 64*ySize);

    txRectangle (x + 10*xSize, y + 40*ySize, x + 29*xSize, y + 64*ySize);

    txCircle (x - 70*xSize, y + 10*ySize, 10*faceSize);

    txSetColor (TX_RED);

    txRectangle (x - 25*xSize, y - 20*ySize, x - 6*xSize, y - 11*ySize);

    txRectangle (x + 1*xSize, y - 20*ySize, x + 19*xSize, y - 11*ySize);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txRectangle (x - 25*xSize, y + 15*ySize, x + 19*xSize, y + 24*ySize);
    }


//-----------------------------------------------------------------------------


void DrawEvilShot (int x, int y,  double xSize, double ySize, double faceSize)
    {
    txSetColor (RGB (255, 0, 0));

    txSetFillColor (RGB (255, 0, 0));

    txCircle (x + 1*xSize, y+ 1*ySize, 9*faceSize);

    txSetColor (RGB (255, 0, 0), 8*faceSize);

    txLine (x + 1*xSize, y - 5*ySize, x + 18*xSize, y + 1*ySize);

    txLine (x + 18*xSize, y + 1*ySize, x - 1*xSize, y + 5*ySize);
    }


//-----------------------------------------------------------------------------


void DrawLaserCannon (int x, int y, double xSize, double ySize, double faceSize)
    {
    txSetColor (RGB (105, 105, 105), 2*faceSize);

    txSetFillColor (RGB (105, 105, 105));

    txRectangle (x - 37*xSize, y - 20*ySize, x + 36*xSize, y + 19*ySize);

    txSetColor (RGB (105, 105, 105), 9*faceSize);

    txCircle (x + 33*xSize, y - 1*ySize, 17*faceSize);

    txLine (x - 34*xSize, y - 17*ySize, x - 42*xSize, y - 1*ySize);

    txLine (x - 34*xSize, y + 15*ySize, x - 42*xSize, y - 1*ySize);

    txSetColor (RGB (0, 0, 0), 9*faceSize);

    txSetFillColor (TX_RED);

    txCircle (x - 40*xSize, y - 1*ySize, 17*faceSize);
    }

//-----------------------------------------------------------------------------


void DrawCharacterBase (int x, int y, COLORREF bodyColor, COLORREF contourColor,
                        double xScale, double yScale, double faceSize, int leftStep, int rightStep, int leftHand, int rightHand)
    {
    txSetFillColor (bodyColor);

    txSetColor (contourColor, 8*faceSize);

    txRectangle (x - 60*xScale, y - 57*yScale, x + 59*xScale, y + 60*yScale);

    txRectangle (x  - 92*xScale - leftHand, y + 1*yScale, x - 61*xScale - leftHand, y + 40*yScale);

    txRectangle (x  + 60*xScale + rightHand, y  + 1*yScale, x + 90*xScale + rightHand, y + 40*yScale);

    txRectangle (x - 45*xScale, y + 61*yScale - leftStep, x - 11*xScale, y + 90*yScale - leftStep);

    txRectangle (x + 10*xScale, y + 61*yScale - rightStep, x + 44*xScale, y + 90*yScale - rightStep);
    }


//-----------------------------------------------------------------------------


void DrawLaser (int x, int y, double xSize, double ySize, double faceSize)
    {
    txSetColor (RGB (255, 0, 0), 20*faceSize);

    txLine (x + 6*xSize, y - 1*ySize, x - 350*xSize, y - 1*ySize);
    }

