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

struct Text {
  int ct;
  std::string* list;
};

#endif