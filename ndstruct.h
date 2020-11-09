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

void drawSprite(Sprite s, int px_x, int px_y, int idx=0);

struct Dialog {
  int ct;
  //int* dia_lens;
  std::string* list;
};

void drawDialog(Dialog d, Sprite font, int px_x, int px_y, int idx=0);