#include "TXLib.h"

//-----------------------------------------------------------------------------

void DrawXwing();

void MoveHero();

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (1500, 1000);

    txSetFillColor (TX_WHITE);

    txClear();

    //MoveHero();

    DrawXwing();

    return 0;
    }

//-----------------------------------------------------------------------------

void MoveHero()
    {
    DrawXwing();
    }

//-----------------------------------------------------------------------------

void DrawXwing()
    {
    txSetColor (TX_BLACK, 3);

    txSetFillColor (TX_WHITE);

    txRectangle (91, 306, 97, 316);

    txRectangle (97, 307, 127, 313);

    txRectangle (106, 301, 130, 307);

    txRectangle (127, 306, 133, 316);

    txRectangle (113, 328, 118, 337);

    txRectangle (116, 322, 130, 331);

    txSetFillColor (TX_BLACK);

    txRectangle (133, 309, 157, 312);

    txLine (158, 310, 205, 310);

    txLine (179, 304, 179, 316);

    txLine (103, 313, 95, 348);

    txLine (130, 316, 130, 348);

    txLine (100, 328, 106, 328);

    txLine (74, 349, 74, 355);

    txSetFillColor (TX_WHITE);

    txRectangle (88, 348, 104, 357);

    txRectangle (82, 357, 88, 348);

    txRectangle (77, 348, 82, 357);

    txRectangle (104, 343, 116, 361);

    txRectangle (116, 352, 128, 361);

    txRectangle (116, 352, 128, 343);

    txRectangle (128, 343, 139, 361);

    txRectangle (139, 346, 144, 358);

    txLine (130, 361, 130, 372);

    txLine (130, 372, 88, 372);

    txLine (91, 357, 86, 376);

    txLine (86, 376, 86, 399);

    txLine (130, 372, 232, 382);

    txLine (232, 381, 232, 396);

    txLine (232, 381, 260, 384);

    txLine (260, 384, 262, 385);

    txLine (262, 385, 263, 387);

    txLine (263, 387, 263, 389);

    txLine (263, 389, 262, 391);

    txLine (262, 391, 260, 393);

    txLine (260, 393, 232, 396);

    txLine (232, 395, 130, 405);

    txLine (130, 405, 130, 415);

    txLine (130, 405, 88, 405);

    txLine (86, 399, 91, 420);

    txRectangle (88, 420, 104, 429);

    txRectangle (88, 420, 82, 429);

    txRectangle (82, 429, 77, 420);

    txLine (74, 421, 74, 427);

    txRectangle (104, 433, 116, 415);

    txRectangle (116, 415, 128, 424);

    txRectangle (116, 433, 128, 424);

    txRectangle (128, 415, 139, 433);

    txRectangle (139, 430, 144, 418);

    txLine (95, 430, 103, 463);

    txLine (130, 433, 130, 462);

    txRectangle (113, 439, 118, 448);

    txRectangle (130, 454, 116, 444);

    txLine (100, 448, 106, 448);

    txRectangle (91, 462, 97, 471);

    txRectangle (97, 463, 127, 469);

    txRectangle (127, 462, 133, 471);

    txRectangle (106, 469, 130, 475);

    txSetFillColor (TX_BLACK);

    txRectangle (133, 465, 157, 468);

    txLine (158, 466, 205, 466);

    txLine (179, 460, 179, 472);

    txRectangle (86, 391, 130, 385);

    txLine (98, 372, 98, 405);

    txLine (122, 372, 122, 405);

    txCircle (141, 388, 4);

    txLine (152, 382, 152, 394);

    txLine (152, 382, 158, 376);

    txLine (152, 394, 158, 400);

    txRectangle (158, 385, 178, 392);

    txLine (178, 388, 226, 388);

    txLine (178, 389, 226, 389);

    txLine (239, 388, 254, 388);

    txLine (239, 389, 239, 389);

    txLine (190, 379, 190, 398);

    txLine (209, 381, 209, 396);

    txSetColor (TX_BLACK, 2);

    txLine (100, 334, 105, 334);

    txLine (100, 453, 105, 453);

    txSetColor (TX_BLACK, 1);

    txLine (100, 323, 108, 323);

    txLine (100, 443, 108, 443);
    }
