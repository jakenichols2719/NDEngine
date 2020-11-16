//include guards
#ifndef NDSTRUCT_H_
#define NDSTRUCT_H_

//data structures to hold important data, and helper functions
#include <stdint.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdint.h>
#include <string>

struct Sprite {
  int w;
  int h;
  int ct;
  uint32_t* list;
};

/*
 * Get a sprite with dimensional restraints based on distance
 * from bottom left (origin) and top right (end) of sprite.
 * For now, assumes that the restraints are valid.
*/
Sprite subSprite(Sprite s, int bl_x, int bl_y, int tr_x, int tr_y, int idx=0);

struct Text {
  int ct;
  std::string* list;
};

#endif