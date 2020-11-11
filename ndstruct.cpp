#include "ndstruct.h"
#include <stdio.h>
#include <iostream>

/*
struct Sprite {
  int w;
  int h;
  int ct;
  uint32_t* list;
};

struct Text {
  int ct;
  std::string* list;
};

/*
void drawSprite(Sprite s, int px_x, int px_y, int idx) {
  if(idx >= s.ct) return; //return if idx is too high
  idx = s.ct-(idx+1); //invert index
  int offset = idx*(s.w*s.h);
  //set position
  glRasterPos2i(px_x, px_y);
  //draw sprite
  glDrawPixels(s.w, s.h, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, s.list+offset);
}


void drawDialog(Dialog d, Sprite font, int px_x, int px_y, int idx) {
  if(idx >= d.ct) return; //return if idx is too high
  std::string line = d.list[idx];
  for(int n=0; n<line.length(); n++) {
    if(line[n] == ' ') {
      px_x += 32;
      continue;
    }
    int letter_idx = line[n]-65;
    drawSprite(font, px_x, px_y, letter_idx);
    px_x += 32;
  }
}
*/