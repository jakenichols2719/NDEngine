#include "ndgl.h"
#include "load.h"

Sprite img;
Sprite font;
Text dia;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (100, 100);
  glPixelZoom(WIN_S,WIN_S);
  drawLayout();
  Display_drawSprite(img, 1600, 700, 0);
  //drawSprite(subSprite(img,20,20,0,0), 256,256);
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  img.w = 256;
  img.h = 256;
  img.ct = 1;
  img.list = loadImage("portrait");
  font.w = 12;
  font.h = 16;
  font.ct = 64;
  font.list = loadImage("font");
  dia.ct = 1;
  dia.list = loadDialog("test");
  startGL(&argc, argv);
  return 0;
}
