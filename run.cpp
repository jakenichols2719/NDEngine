#include "ndgl.h"
#include "load.h"
#include "ndstatic.h"

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
  //Display_drawSprite(img, 0, 0);
  Display_drawText(dia, font, 288, 192, 0);
  Display_drawText(dia, font, 288, 144, 1);
  Display_drawSprite(font, 0, 0, 40);
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  img.w = DIM_IMG;
  img.h = DIM_IMG;
  img.ct = 1;
  //img.list = loadImage("portrait");
  font.w = 12;
  font.h = 16;
  font.ct = 64;
  font.list = loadImage("font");
  dia.ct = 2;
  dia.list = loadDialog("test");
  startGL(&argc, argv);
  return 0;
}
