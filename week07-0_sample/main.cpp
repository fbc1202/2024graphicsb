#include <GL/glut.h>///�ϥ�GLUT�~��
 void display()
 {
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glutSolidTeapot(0.3);
     glutSwapBuffers();
 }
 int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///��l�� GLUT 140
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143
    glutCreateWindow("week06-1_lighting");///145
    glutDisplayFunc(display);///148 display�禡
    glutMainLoop();///174 �j��
}
