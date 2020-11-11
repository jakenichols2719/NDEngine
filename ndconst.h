/*
 * ndconst.h
 * Declares constants used across the engine, defined in ndconst.cpp
*/

#ifndef NDCONST_H_
#define NDCONST_H_

#include "ndstruct.h"

//resolution and scale
extern const int WIN_W;
extern const int WIN_H;
extern const float WIN_S;

/*
 * "Primitive" functions not tied to a particular component
*/
void drawSprite(Sprite s, int px_x, int px_y, int idx=0);
void drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);


/*
 * Pixel origin and dimensions of each component, followed by relevant fucntions
*/
extern const int O_DISP_X, O_DISP_Y, D_DISP_W, D_DISP_H;
void Display_drawSprite(Sprite x, int px_x, int px_y, int idx=0);

#endif
