#include <GL/glut.h> ///�K�W10��GLUT�{���X
float teapotX = 0.5, teapotY = 0; ///��k��
float angle = 0; ///���ਤ��
float s = 0.3; ///�@�}�l�O�쥻1�����j�p
void display()
{ ///�]�w�M�I���C��
    glClearColor(1, 1, 0.9, 1); /// R,G,B,A
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 1, 0); ///3f�N�OR,G,B
    glPushMatrix(); ///�ƥ��x�}
        glTranslatef(teapotX, teapotY, 0); ///����
        glRotatef(angle++, 0, 0, 1); ///����
        glScalef(s, s, s); ///�Y��S��
        glutSolidTeapot(0.3);
    glPopMatrix(); ///�٭�x�}
    glutSwapBuffers();
}
void motion(int x, int y)
{
    s = 1 + (x-150)/150.0; ///�ܤj�ܤp���ܼ� 0~1
    display(); ///���e�e��
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 translate rotate");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMotionFunc(motion); ///���motion���ɭ�
    glutMainLoop();
}