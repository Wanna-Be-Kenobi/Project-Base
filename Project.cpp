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

    txRectangle (x-(235-143), y-(134-135), x-(235-174), y-(134-174));

    txRectangle (x-(235-295), y-(134-135), x-(235-325), y-(134-174));

    txRectangle (x-(235-190), y-(134-195), x-(235-224), y-(134-224));

    txRectangle (x-(235-245), y-(134-195), x-(235-279), y-(134-224));

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x-(235-262), y-(134-106), 11);

    txCircle (x-(235-216), y-(134-106), 11);

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-(235-219), y-(134-141), x-(235-205), y-(134-154));

    txLine (x-(235-214), y-(134-149), x-(235-227), y-(134-161));

    txLine (x-(235-227), y-(134-161), x-(235-251), y-(134-161));
    }


//-----------------------------------------------------------------------------


void DrawGreenCharacter (int x, int y)
    {
    txSetFillColor (RGB (0, 128, 0));

    txSetColor (RGB (84, 84, 84), 8);

    txRectangle (x-(560-500), y-(130-71), x-(560-619), y-(130-188));

    txRectangle (x-(560-515), y-(130-191), x-(560-549), y-(130-220));

    txRectangle (x-(560-570), y-(130-191), x-(560-604), y-(130-220));

    txRectangle (x-(560-468), y-(130-131), x-(560-499), y-(130-170));

    txRectangle (x-(560-620), y-(130-131), x-(560-651), y-(130-170));

    txSetFillColor (TX_BLACK);

    txSetColor (TX_BLACK);

    txRectangle (x-(560-520), y-(130-94), x-(560-544), y-(130-109));

    txRectangle (x-(560-565), y-(130-94), x-(560-589), y-(130-109));

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-(560-523), y-(130-173), x-(560-536), y-(130-159));

    txLine (x-(560-536), y-(130-159), x-(560-584), y-(130-159));

    txLine (x-(560-584), y-(130-159), x-(560-597), y-(130-173));

    txLine (x-(560-538), y-(130-83), x-(560-552), y-(130-92));

    txLine (x-(560-573), y-(130-83), x-(560-559), y-(130-92));
    }



//-----------------------------------------------------------------------------


void DrawBlueCharacter (int x, int y)
    {
    txSetColor (RGB (84, 84, 84), 8);

    txSetFillColor (RGB (0, 0, 255));

    txCircle (x, y, 52);

    txCircle (x-(805-779), y-(134-205), 20);

    txCircle (x-(805-829), y-(134-205), 20);

    txCircle (x-(805-875), y-(134-156), 20);

    txCircle (x-(805-735), y-(134-156), 20);

    txSetColor (RGB (0, 0, 0));

    txSetFillColor (TX_BLACK);

    txRectangle (x-(805-769), y-(134-109), x-(805-793), y-(134-124));

    txRectangle (x-(805-809), y-(134-109), x-(805-833), y-(134-124));

    txSetColor (RGB (0, 0, 0), 8);

    txLine (x-(805-779), y-(134-100), x-(805-793), y-(134-100));

    txLine (x-(805-809), y-(134-100), x-(805-825), y-(134-100));

    txLine (x-(805-797), y-(134-165), x-(805-819), y-(134-165));

    txLine (x-(805-819), y-(134-165), x-(805-815), y-(134-150));

    txSetColor (RGB (160, 82, 45), 8);

    txSetFillColor (RGB (160, 82, 45));

    txCircle (x-(805-725), 163, 10);

    txLine (x-(805-725), y-(134-170), x-(805-725), y-(134-234));

    txSetColor (RGB (210, 105, 30), 6);

    txLine (x-(805-810), y-(134-155), x-(805-822), y-(134-168));

    txSetColor (TX_GREY);

    txSetFillColor (TX_GREY);

    txCircle (x-(805-822), y-(134-168), 4);

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (TX_BLACK);

    txLine (x-(805-815), y-(134-150), x-(805-797), y-(134-161));

    txSetColor (RGB (84, 84, 84));

    txSetFillColor (RGB (84, 84, 84));

    txRectangle (x-(805-772), y-(134-75), x-(805-837), y-(134-85));

    txRectangle (x-(805-790), y-(134-33), x-(805-820), y-(134-75));
    }


//-----------------------------------------------------------------------------


void DrawJetPack (int x, int y)
    {
    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txRectangle (x-(1010-970), y-(152-109), x-(1010-989), y-(152-193));

    txRectangle (x-(1010-1030), y-(152-109), x-(1010-1049), y-(152-193));

    txRectangle (x-(1010-974), y-(152-95), x-(1010-984), y-(152-110));

    txRectangle (x-(1010-1035), y-(152-95), x-(1010-1045), y-(152-110));

    txSetColor (RGB (218, 165, 32));

    txSetFillColor (RGB (218, 165, 32));

    txRectangle (x-(1010-975), y-(152-115), x-(1010-1044), y-(152-189));

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (TX_BLACK);

    txLine (x-(1010-987), y-(152-120), x-(1010-987), y-(152-184));

    txLine (x-(1010-1032), y-(152-120), x-(1010-1032), y-(152-184));
    }


//-----------------------------------------------------------------------------


void DrawPinkCharacter (int x, int y)
    {
    txSetColor (RGB (84, 84, 84), 8);

    txSetFillColor (RGB (255, 0, 255));

    txRectangle (x-(233-173), y-(322-262), x-(233-292), y-(322-381));

    txRectangle (x-(233-141), y-(322-322), x-(233-172), y-(322-361));

    txRectangle (x-(233-293), y-(322-322), x-(233-323), y-(322-361));

    txRectangle (x-(233-188), y-(322-382), x-(233-222), y-(322-411));

    txRectangle (x-(233-243), y-(322-382), x-(233-277), y-(322-411));

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x-(233-215), y-(322-293), 11);

    txCircle (x-(233-260), y-(322-293), 11);

    txSetColor (RGB (0, 0, 0), 6);

    txLine (x-(233-211), y-(322-275), x-(233-197), y-(322-289));

    txLine (x-(233-267), y-(322-275), x-(233-281), y-(322-289));

    txSetColor (RGB (0, 0, 0), 8);

    txSetFillColor (RGB (255, 0, 255));

    txCircle (x-(233-236), y-(322-349), 14);
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

    txRectangle (629, 300, 754, 370);

    txCircle (x-(723-754), y-(362-335), 35);

    txSetColor (TX_GRAY);

    txSetFillColor (TX_GRAY);

    txCircle (x-(723-629), y-(362-335), 34);

    txSetColor (RGB (139, 69, 19));

    txSetFillColor (RGB (139, 69, 19));

    txCircle (x, y, 40);

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txCircle (x, y, 12);

    txSetColor (RGB (244, 164, 96), 8);

    txLine (x-(723-787), y-(362-330), x-(723-824), y-(362-300));

    txSetColor (TX_RED);

    txSetFillColor (TX_RED);

    txCircle (x-(723-824), y-(362-300), 6);
    }


//-----------------------------------------------------------------------------


void DrawEvilMinion (int x, int y)
    {
    txSetColor (RGB (105, 105, 105), 8);

    txSetFillColor (RGB (119, 136, 153));

    txRectangle (x-(980-940), y-(320-280), x-(980-1019), y-(320-359));

    txSetFillColor (TX_RED);

    txRectangle (x-(980-915), y-(320-320), x-(980-939), y-(320-339));

    txRectangle (x-(980-1020), y-(320-320), x-(980-1044), y-(320-339));

    txRectangle (x-(980-950), y-(320-360), x-(980-969), y-(320-384));

    txRectangle (x-(980-990), y-(320-360), x-(980-1009), y-(320-384));

    txCircle (x-(980-910), y-(320-329), 10);

    txSetColor (TX_RED);

    txRectangle (x-(980-955), y-(320-300), x-(980-974), y-(320-309));

    txRectangle (x-(980-980), y-(320-300), x-(980-999), y-(320-309));

    txSetColor (TX_BLACK);

    txSetFillColor (TX_BLACK);

    txRectangle (x-(980-955), y-(320-335), x-(980-999), y-(320-344));

    txSetColor (RGB (255, 0, 0));

    txSetFillColor (RGB (255, 0, 0));

    txCircle (x-(980-875), y-(320-329), 9);

    txSetColor (RGB (255, 0, 0), 8);

    txLine (x-(980-875), y-(320-324), x-(980-893), y-(320-329));

    txLine (x-(980-893), y-(320-329), x-(980-875), y-(320-334));
    }


//-----------------------------------------------------------------------------


void DrawLaser (int x, int y)
    {
    txSetColor (RGB (105, 105, 105));

    txSetFillColor (RGB (105, 105, 105));

    txRectangle (x-(808-771), y-(440-420), x-(808-844), y-(440-459));

    txSetColor (RGB (105, 105, 105), 8);

    txLine (x-(808-774), y-(440-423), x-(808-766), y-(440-439));

    txLine (x-(808-774), y-(440-455), x-(808-766), y-(440-439));

    txSetColor (RGB (128, 0, 0), 8);

    txLine (x-(808-762), y-(440-439), x-(808-590), y-(440-440));
    }



