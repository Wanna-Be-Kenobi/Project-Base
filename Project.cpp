#include "TXLib.h"

//-----------------------------------------------------------------------------


void DrawYellowCharacter (int x, int y);

void DrawGreenCharacter (int x, int y);

void DrawBlueCharacter (int x, int y);

void DrawJetPack (int x, int y);

void DrawPinkCharacter (int x, int y);

void DrawCannonball (int x, int y);

void DrawCannon (int x, int y);

void DrawEvilMinion (int x, int y);

void DrawLaser (int x, int y);


//-----------------------------------------------------------------------------


int main()
    {
    txCreateWindow (1200, 800);

    DrawYellowCharacter (235, 134);

    DrawGreenCharacter (560, 130);

    DrawBlueCharacter (805, 134);

    DrawPinkCharacter (233, 322);

    DrawJetPack (1010, 152);

    DrawCannonball (547, 337);

    DrawCannon (723, 362);

    DrawEvilMinion (980, 320);

    DrawLaser (808, 440);

    return 0;
    }


//-----------------------------------------------------------------------------


void DrawYellowCharacter (int x, int y)
    {
    txSetFillColor (RGB (255, 255, 0));

    txSetColor (RGB (84, 84, 84), 8);

    txRectangle (x-60, y-57, x+59, y+60);

    txRectangle (x-92, y+1, x-61, y+40);

    txRectangle (x+60, y+1, x+90, y+40);

    txRectangle (x-45, y+61, x-11, y+90);

    txRectangle (x+10, y+61, x+44, y+90);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x+27, y-28, 11);

    txCircle (x-19, y-28, 11);

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-16, y+7, x-35, y+20);

    txLine (x-21, y+15, x-8, y+27);

    txLine (x-8, y+27, x+16, y+27);
    }


//-----------------------------------------------------------------------------


void DrawGreenCharacter (int x, int y)
    {
    txSetFillColor (RGB (0, 128, 0));

    txSetColor (RGB (84, 84, 84), 8);

    txRectangle (x-60, y-59, x+59, y+58);

    txRectangle (x-45, y+61, x-11, y+90);

    txRectangle (x+10, y+61, x+44, y+90);

    txRectangle (x-92, y+1, x-61, y+40);

    txRectangle (x+60, y+1, x+91, y+40);

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txRectangle (x-40, y-36, x-16, y-21);

    txRectangle (x+5, y-36, x+29, y-21);

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-37, y+43, x-24, y+29);

    txLine (x-24, y+29, x+24, y+29);

    txLine (x+24, y+29, x+37, y+43);

    txLine (x-22, y-47, x-8, y-38);

    txLine (x+13, y-47, x-1, y-38);
    }



//-----------------------------------------------------------------------------


void DrawBlueCharacter (int x, int y)
    {
    txSetColor (RGB (84, 84, 84), 8);

    txSetFillColor (RGB (0, 0, 255));

    txCircle (x, y, 52);

    txCircle (x-26, y+71, 20);

    txCircle (x+24, y+71, 20);

    txCircle (x+70, y+22, 20);

    txCircle (x-70, y+22, 20);

    txSetColor (RGB (0, 0, 0));

    txSetFillColor (TX_BLACK);

    txRectangle (x-36, y-25, x-12, y-10);

    txRectangle (x+4, y-25, x+28, y-10);

    txSetColor (RGB (0, 0, 0), 8);

    txLine (x-26, y-34, x-12, y-34);

    txLine (x+4, y-34, x+20, y-34);

    txLine (x-8, y+31, x+14, y+31);

    txLine (x+14, y+31, x+10, y+16);

    txSetColor (RGB (160, 82, 45), 8);

    txSetFillColor (RGB (160, 82, 45));

    txCircle (x-80, y+29, 10);

    txLine (x-80, y+36, x-80, y+100);

    txSetColor (RGB (210, 105, 30), 6);

    txLine (x+5, y+21, x+17, y+34);

    txSetColor (TX_GREY);

    txSetFillColor (TX_GREY);

    txCircle (x+17, y+34, 4);

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (TX_BLACK);

    txLine (x+10, y+16, x-8, y+27);

    txSetColor (RGB (84, 84, 84));

    txSetFillColor (RGB (84, 84, 84));

    txRectangle (x-33, y-59, x+32, y-49);

    txRectangle (x-15, y-101, x+15, y-59);
    }


//-----------------------------------------------------------------------------


void DrawJetPack (int x, int y)
    {
    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txRectangle (x-40, y-43, x-21, y+41);

    txRectangle (x+20, y-43, x+39, y+41);

    txRectangle (x-36, y-57, x-26, y-42);

    txRectangle (x+25, y-57, x+35, y-42);

    txSetColor (RGB (218, 165, 32));

    txSetFillColor (RGB (218, 165, 32));

    txRectangle (x-35, y-37, x+34, y+37);

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (TX_BLACK);

    txLine (x-23, y-32, x-23, y+32);

    txLine (x+22, y-32, x+22, y+32);
    }


//-----------------------------------------------------------------------------


void DrawPinkCharacter (int x, int y)
    {
    txSetColor (RGB (84, 84, 84), 8);

    txSetFillColor (RGB (255, 0, 255));

    txRectangle (x-60, y-60, x+59, y+59);

    txRectangle (x-92, y, x-61, y+39);

    txRectangle (x+60, y, x+90, y+39);

    txRectangle (x-45, y+60, x-11, y+89);

    txRectangle (x+10, y+60, x+44, y+89);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x-18, y-29, 11);

    txCircle (x+27, y-29, 11);

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-22, y-47, x-36, y-33);

    txLine (x+34, y-47, x+48, y-33);

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (RGB (255, 0, 255));

    txCircle (x+3, y+27, 14);
    }


//-----------------------------------------------------------------------------


void DrawCannonball (int x, int y)
    {
    txSetColor (RGB (105, 105, 105));

    txSetFillColor (RGB (105, 105, 105));

    txCircle (x, y, 30);
    }


//-----------------------------------------------------------------------------


void DrawCannon (int x, int y)
    {
    txSetColor (RGB (105, 105, 105));

    txSetFillColor (RGB (105, 105, 105));

    txRectangle (x-94, y-62, x+31, y+8);

    txCircle (x+31, y-27, 35);

    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txCircle (x-94, y-27, 34);

    txSetColor (RGB (139, 69, 19));

    txSetFillColor (RGB (139, 69, 19));

    txCircle (x, y, 40);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x, y, 12);

    txSetColor (RGB (244, 164, 96), 8);

    txLine (x+64, y-32, x+101, y-62);

    txSetColor (TX_RED);

    txSetFillColor (TX_RED);

    txCircle (x+101, y-62, 6);
    }


//-----------------------------------------------------------------------------


void DrawEvilMinion (int x, int y)
    {
    txSetColor (RGB (105, 105, 105), 8);

    txSetFillColor (RGB (119, 136, 153));

    txRectangle (x-40, y-40, x+39, y+39);

    txSetFillColor (TX_RED);

    txRectangle (x-65, y, x-41, y+19);

    txRectangle (x+40, y, x+64, y+19);

    txRectangle (x-30, y+40, x-11, y+64);

    txRectangle (x+10, y+40, x+29, y+64);

    txCircle (x-70, y+9, 10);

    txSetColor (TX_RED);

    txRectangle (x-25, y-20, x-6, y-11);

    txRectangle (x, y-20, x+19, y-11);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txRectangle (x-25, y+15, x+19, y+24);

    txSetColor (RGB (255, 0, 0));

    txSetFillColor (RGB (255, 0, 0));

    txCircle (x-105, y+9, 9);

    txSetColor (RGB (255, 0, 0), 8);

    txLine (x-105, y+4, x-87, y+9);

    txLine (x-87, y+9, x-105, y+14);
    }


//-----------------------------------------------------------------------------


void DrawLaser (int x, int y)
    {
    txSetColor (RGB (105, 105, 105));

    txSetFillColor (RGB (105, 105, 105));

    txRectangle (x-37, y-20, x+36, y+19);

    txSetColor (RGB (105, 105, 105), 8);

    txLine (x-34, y-17, x-42, y-1);

    txLine (x-34, y+15, x-42, y-1);

    txSetColor (RGB (128, 0, 0), 8);

    txLine (x-46, y-1, x-218, y);
    }



