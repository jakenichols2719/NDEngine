#include "ndconst.h"

const int WIN_W = 1920;
const int WIN_H = 1080;
const float WIN_S = 1.0;

/*
 * Primitive function definitions
*/
//draw sprite s[idx] at origin px_x, px_y
void drawSprite(Sprite s, int px_x, int px_y, int idx) {
  if(idx >= s.ct) return; //return if idx is too high
  idx = s.ct-(idx+1); //invert index
  int offset = idx*(s.w*s.h);
  //set position
  glRasterPos2i(px_x*WIN_S, px_y*WIN_S);
  //draw sprite
  glDrawPixels(s.w, s.h, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, s.list+offset);
}

//draw text d[idx] with font at origin px_x, px_y
void drawText(Text d, Sprite font, int px_x, int px_y, int idx) {
  if(idx >= d.ct) return; //return if idx is too high
  std::string line = d.list[idx];
  for(int n=0; n<line.length(); n++) {
    if(line[n] == ' ') {
      px_x += font.h; //increment by font HEIGHT
      continue;
    }
    int letter_idx = line[n]-65;
    drawSprite(font, px_x, px_y, letter_idx);
    px_x += font.h; //incrememnt by font HEIGHT
  }
}

const int O_DISP_X=256, O_DISP_Y=256, D_DISP_W=1664, O_DISP_H=824;
void Display_drawSprite(Sprite x, int px_x, int px_y, int idx) {
  drawSprite(x, px_x+O_DISP_X, px_y+O_DISP_Y, idx);
}