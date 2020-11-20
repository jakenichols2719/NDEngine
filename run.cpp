#include "base/load.h"
#include "base/ndconst.h"
#include "base/ndstruct.h"
#include "base/ndgl.h"

Sprite img;
Sprite font;
Text dia;

int _x=0;
int _y=0;
void update() {
  float sec = delta/1000.0;
  _x+=(int)(100*sec);
  _y+=(int)(100*sec);
  Display_drawSprite(img, _x, _y);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (100, 100);
  glPixelZoom(WIN_S,WIN_S);
  drawLayout();
  update();
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  img.w = 598;
  img.h = 598;
  img.ct = 1;
  img.list = loadImage("pack");
  font.w = 12;
  font.h = 16;
  font.ct = 64;
  font.list = loadImage("font");
  dia.ct = 1;
  dia.list = loadDialog("test");
  startGL(&argc, argv);
  return 0;
}
