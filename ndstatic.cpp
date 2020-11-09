#include "ndstatic.h"
#include <iostream>

int Display::o_x = 256;
int Display::o_y = 256;

void Display::drawSpriteDisplay(Sprite s, int px_x, int px_y, int idx) {
  drawSprite(s, px_x+o_x, px_y+o_y, idx);
}