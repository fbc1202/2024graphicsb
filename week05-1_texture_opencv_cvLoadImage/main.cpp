#include <GL/glut.h>///�ϥ�GLUT�~��
#include <opencv/highgui.h>
 void display()
 {
     glutSolidTeapot(0.3);
     glutSwapBuffers();
 }

int main(int argc, char *argv[])
{
    IplImage * img = cvLoadImage("c:/micky.jpg");
    cvShowImage("opencv", img);
    glutInit(&argc, argv);///��l�� GLUT 140
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///143

    glutCreateWindow("GLUT Shapes");///145
    glutDisplayFunc(display);///148 display�禡
    glutMainLoop();///174 �j��
}
