#include "cdstruct.h"

struct Sprite {
  int w;
  int h;
  int ct;
  uint32_t* list;
};

uint32_t* getSprite(Sprite s, int idx) {
  if(idx >= s.ct) return nullptr; //return null if idx is too high
  int u = sizeof(uint32_t); //one unit in list
  int offset = idx*(s.w*s.h);
  return s.list + offset;
}