/*
 * cdgl
 * Contains non-display GL functions and headers
 * Use this to help maintain a clean main file.
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include "ndconst.h"

//base resolution is 1080p
//const int WIN_W = 1920;
//const int WIN_H = 1080;
//float     WIN_S = 1.0;

//constants for image sizes
const int DIM_SPRITE = 32;
const int DIM_IMG = 256;

//test vars
int test[32];


//get current time as long because screw std::chrono
long time() {
  auto dur = std::chrono::system_clock::now().time_since_epoch();
  long ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
  return ms;
}
//time tracking
int elapsed_time = 0;
long old_time = time();
int updateDelta() {
  long new_time = time();
  int delta_ms = new_time-old_time;
  old_time = new_time;
  delta = delta_ms;
  return delta_ms;
}

void init(void)
{
   glPixelStorei (GL_UNPACK_ALIGNMENT, 1);
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnable( GL_BLEND );
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho (0, w, 0, h, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
  key_down[key] = true;
  switch (key) {
    case 27:
      exit(0);
  }
}

void special(int key, int x, int y)
{
  switch(key) {
    case GLUT_KEY_UP:
      break;
    case GLUT_KEY_DOWN:
      break;
    case GLUT_KEY_LEFT:
      break;
    case GLUT_KEY_RIGHT:
      break;
  }
  glutPostRedisplay();
}

/*
 * Forward declarations:
 * Update: should be implemented by user
 * Display: callback for glut
 * drawLayout: implemented below
*/
void update();
void display(void);
void drawLayout(void);

void frame(int frame_ct) {
  updateDelta();
  elapsed_time += delta;
  glutPostRedisplay();
  glutTimerFunc(TARGET_MS, frame, frame_ct+1);
}

/*
 * Draws the outlines for the window format
*/
void drawLayout(void) {
  glBegin(GL_LINES);
    glVertex2f(256*WIN_S, 0);
    glVertex2f(256*WIN_S, 1024*WIN_S);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0, 256*WIN_S);
    glVertex2f(1920*WIN_S, 256*WIN_S);
  glEnd();
  glBegin(GL_LINES);
    glVertex2f(0, 1024*WIN_S);
    glVertex2f(1920*WIN_S, 1024*WIN_S);
  glEnd();
}

/*
 * Starts GL
 * Call with startGL(&argc, argv);
*/
void startGL(int* argc, char* argv[]){
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(WIN_W*WIN_S, WIN_H*WIN_S);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(argv[0]);
  glutFullScreen();
  init();
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(special);
  glutDisplayFunc(display);
  glutTimerFunc(TARGET_MS, frame, 0);
  glutMainLoop();
}