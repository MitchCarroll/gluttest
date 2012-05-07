#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_LIBGL
#include <GL/gl.h>
#endif
#ifdef HAVE_LIBGLU
#include <GL/glu.h>
#endif
#ifdef HAVE_LIBGLUT
#include <GL/glut.h>
#endif

GLint angle=0;
GLuint texture=0;

GLubyte tex[]=
  {255,0,0,   128,128,0, 128,0,128, 255,0,0,
   128,128,0, 0,255,0,   0,128,128, 0, 255,0,
   128,0,128, 0,128,128, 0,0,255,   0,0,255,
   255,0,0,   0,255,0,   0,0,255,   255,255,255};

GLfloat mat_spe[] = {0,0,0,0};

GLfloat light_pos[] = {1.0, 1.0, 1.0, 0.0};
GLfloat light_amb[] = {0.2, 0.2, 0.2, 1.0};
GLfloat light_dif[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_spe[] = {1.0, 1.0, 1.0, 1.0};

void display(void)
{
  glLoadIdentity();
  angle++;
  if(angle>=360)
    angle-=360;
  glPushMatrix();
  glTranslatef(0,0,-3);
  glRotatef(23,1,0,0);
  glRotatef(angle,0,1,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glBindTexture(GL_TEXTURE_2D, texture);
  glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,.5);
  glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR, mat_spe);
  glutSolidTeapot(1);
  glPopMatrix();
  glutSwapBuffers();
}

void timer(int t)
{
  glutPostRedisplay();
  glutTimerFunc(t, timer, t);
}

void keyboard(unsigned char key, int x, int y)
{
  if(key==27)
    exit(0);
}

void init(void)
{
  glutInitWindowSize(512,512);
  glutInitWindowPosition(10,10);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutCreateWindow(PACKAGE_STRING);
  glClearColor(0,0,0,1);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
  glLightfv(GL_LIGHT0,GL_AMBIENT,light_amb);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,light_dif);
  glLightfv(GL_LIGHT0,GL_SPECULAR,light_spe);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, 4, 4, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60,1.5,0.01,1000);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  init();
  glutDisplayFunc(display);
  glutTimerFunc(50,timer,50);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
