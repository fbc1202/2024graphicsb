#include <GL/glut.h> ///�K�W10��GLUT�{���X
#include <stdio.h>

void display()
{ ///�]�w�M�I���C��

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    printf("key:%c x:%d y:%d\n", key, x, y);
}   ///�p�ߤ����J�k,�n�������^��

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 keyboard mouse motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///��L�ƥ󪺨禡
    glutMainLoop();
}
