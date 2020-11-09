//data structures to hold important data, and helper functions
#include <stdint.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdint.h>

struct Sprite {
  int w;
  int h;
  int ct;
  uint32_t* list;
};

void drawSprite(Sprite s, int px_x, int px_y, int idx=0);