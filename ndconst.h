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
void Display_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);

extern const int O_DIA_X, O_DIA_Y, D_DIA_W, D_DIA_H;
void Dialog_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Dialog_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);

extern const int O_MEN_X, O_MEN_Y, D_MEN_W, D_MEN_H;
void Menu_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Menu_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);

extern const int O_IMG_X, O_IMG_Y, D_IMG_W, D_IMG_H;
void Image_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Image_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);

extern const int O_BAR_X, O_BAR_Y, D_BAR_W, D_BAR_H;
void Bar_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Bar_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);

#endif
