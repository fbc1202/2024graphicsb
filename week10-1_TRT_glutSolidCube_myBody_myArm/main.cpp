#include <GL/glut.h>

void myBody(){

    glColor3f(1, 0, 0);
    glutSolidCube(0.3);
}

void myArm(){

    glColor3f(0, 1, 0);
    glScalef(1.5, 0.5, 0.5);
    glutSolidCube(0.3);

}


void display() ///¦Û¤v¼g
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(-0.6, +0.3, 0);
        myBody();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(+0.0, +0.3, 0);
        myArm();
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
