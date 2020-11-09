#include "ndgl.h"
#include "load.h"


uint32_t* img;

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glRasterPos2i (100, 100);
  glPixelZoom(WIN_S,WIN_S);
  //drawLayout();
  glPixelZoom(3.0,3.0);
  glDrawPixels(32, 32, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, img);
  glRasterPos2i(70,100);
  glDrawPixels(32, 32, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, img);
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  img = loadImage("sprite");
  for(int n=0; n<32; n++) {
    printf("0x%08x\n", img[n]);
  }
  //glEnable(GL_ALPHA_TEST);
  //glAlphaFunc(GL_GREATER, 0.5);
  startGL(&argc, argv);
  return 0;
}
