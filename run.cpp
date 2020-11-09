#include "ndgl.h"

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (20, 20);
  glPixelZoom(WIN_S,WIN_S);
  drawLayout();
  //Display::drawMap(m, WIN_S);
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  startGL(&argc, argv);
  return 0;
}
