#include <GL/glut.h> ///貼上10行GLUT程式碼
#include <stdio.h>

void display()
{ ///設定清背景顏色

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    printf("key:%c x:%d y:%d\n", key, x, y);
}   ///小心中文輸入法,要切換成英文

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 keyboard mouse motion");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); ///鍵盤事件的函式
    glutMainLoop();
}
