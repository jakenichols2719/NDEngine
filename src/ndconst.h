/*
 * ndconst.h
 * Declares constants used across the engine, defined in ndconst.cpp
*/

#ifndef NDCONST_H_
#define NDCONST_H_

#include "ndstruct.h"
#include <chrono> //for time tracking

//resolution and scale
extern const int WIN_W;
extern const int WIN_H;
extern const float WIN_S;

//delta tracking
extern const int TARGET_FPS; //target frames per second
extern const int TARGET_MS; //target ms per frame
extern int delta; //previous delta value

//key tracking
extern bool* key_down;
bool getKey(char key, bool just_pressed=false);

/*
 * "Primitive" functions not tied to a particular component
*/
//draw sprites/text
void drawSprite(Sprite s, int px_x, int px_y, int idx=0);
void drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void drawText(std::string d, Sprite font, int px_x, int px_y);


/*
 * Pixel origin and dimensions of each component, followed by relevant fucntions
*/
extern const int O_DISP_X, O_DISP_Y, D_DISP_W, D_DISP_H;
void Display_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Display_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void Display_drawText(std::string d, Sprite font, int px_x, int px_y);

extern const int O_DIA_X, O_DIA_Y, D_DIA_W, D_DIA_H;
void Dialog_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Dialog_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void Dialog_drawText(std::string d, Sprite font, int px_x, int px_y);

extern const int O_MEN_X, O_MEN_Y, D_MEN_W, D_MEN_H;
void Menu_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Menu_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void Menu_drawText(std::string d, Sprite font, int px_x, int px_y);

extern const int O_IMG_X, O_IMG_Y, D_IMG_W, D_IMG_H;
void Image_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Image_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void Image_drawText(std::string d, Sprite font, int px_x, int px_y);

extern const int O_BAR_X, O_BAR_Y, D_BAR_W, D_BAR_H;
void Bar_drawSprite(Sprite x, int px_x, int px_y, int idx=0);
void Bar_drawText(Text d, Sprite font, int px_x, int px_y, int idx=0);
void Bar_drawText(std::string d, Sprite font, int px_x, int px_y);

#endif
