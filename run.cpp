#include "ndgl.h"
#include "load.h"
#include "ndstruct.h"

Sprite img;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (100, 100);
  glPixelZoom(WIN_S,WIN_S);
  drawLayout();
  drawSprite(img, 100, 100, 2);
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  img.w = 32;
  img.h = 32;
  img.ct = 3;
  img.list = loadImage("character");
  //glEnable(GL_ALPHA_TEST);
  //glAlphaFunc(GL_GREATER, 0.5);
  startGL(&argc, argv);
  return 0;
}
