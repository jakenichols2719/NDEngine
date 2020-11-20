#include "ndstruct.h"
#include <stdio.h>
#include <iostream>

Sprite subSprite(Sprite s, int bl_x, int bl_y, int tr_x, int tr_y, int idx) {
  Sprite sub;
  sub.w = s.w-bl_x-tr_x;
  sub.h = s.h-bl_y-tr_y;
  sub.ct = 1;
  sub.list = new uint32_t[sub.w*sub.h];
  //populate sub.list
  int y_bound = s.h-tr_y;
  int x_bound = s.w-tr_x;
  int offset_idx = idx*s.w*s.h;
  for(int y=bl_y; y<y_bound; y++) {
    for(int x=bl_x; x<x_bound; x++) {
      int offset_original = x+(y*s.w);
      int offset_sub      = (x-bl_x)+((y-bl_y)*sub.w);
      *(sub.list+offset_idx+offset_sub) = *(s.list+offset_original);
    }
  }

  return sub;
}