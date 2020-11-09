#include "ndstruct.h"

void drawSprite(Sprite s, int px_x, int px_y, int idx) {
  if(idx >= s.ct) return; //return if idx is too high
  //int u = sizeof(uint32_t); //one unit in list
  int offset = idx*(s.w*s.h);
  //set position
  glRasterPos2i(px_x, px_y);
  //draw sprite
  glDrawPixels(s.w, s.h, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, s.list+offset);
}