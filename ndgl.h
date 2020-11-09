/*
 * cdgl
 * Contains non-display GL functions and headers
 * Use this to help maintain a clean main file.
*/

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

int player_x = 7;
int player_y = 2;

//base resolution is 1080p
const int WIN_W = 1920;
const int WIN_H = 1080;
float     WIN_S = 1.0;

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
   switch (key) {
      case 27:
         exit(0);
   }
}

void special(int key, int x, int y)
{
  switch(key) {
    case GLUT_KEY_UP:
      player_y++;
      break;
    case GLUT_KEY_DOWN:
      player_y--;
      break;
    case GLUT_KEY_LEFT:
      player_x--;
      break;
    case GLUT_KEY_RIGHT:
      player_x++;
      break;
  }
  glutPostRedisplay();
}

//fwd declare
void display(void);

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
  glutMainLoop();
}