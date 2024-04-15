#include <GL/glut.h>

void display() ///¦Û¤v¼g
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(-0.6, +0.3, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(+0.0, +0.3, 0);
        glutSolidCube(0.3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(+0.6, +0.3, 0);
        glutSolidSphere(0.3,30,30);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.6, -0.3, 0);
        glutWireTeapot(0.3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(+0.0, -0.3, 0);
        glutWireCube(0.3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(+0.6, -0.3, 0);
        glutWireSphere(0.3,30,30);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///138
{
    glutInit(&argc, argv); ///140
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); ///143

    glutCreateWindow("GLUT Shapes"); ///145

    glutDisplayFunc(display); ///148

    glutMainLoop(); ///174
}
