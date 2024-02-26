#include<GL/glut.h>
void display()
{
    glColor3f(95/255.0,160/255.0,124/255.0);
    glutSolidTeapot( 0.3 );

    glColor3f(31/255.0,115/255.0,21/255.0);
    glutSolidTeapot( 0.2 );

    glColor3f(45/255.0,70/255.0,43/255.0);
    glutSolidTeapot( 0.1 );
    glutSwapBuffers();
}

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("week02_glut");
    glutDisplayFunc(display);
    glutMainLoop();
}
