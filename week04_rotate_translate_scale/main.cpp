#include <GL/glut.h> ///貼上10行GLUT程式碼
float teapotX = 0.5, teapotY = 0; ///放右邊
float angle = 0; ///旋轉角度
float s = 0.3; ///一開始是原本1倍的大小
void display()
{ ///設定清背景顏色
    glClearColor(1, 1, 0.9, 1); /// R,G,B,A
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 1, 0); ///3f就是R,G,B
    glPushMatrix(); ///備份矩陣
        glRotatef(angle++, 0, 0, 1); ///旋轉
        glTranslatef(teapotX, teapotY, 0); ///移動
        glScalef(s, s, s); ///縮放S倍
        glutSolidTeapot(0.3);
    glPopMatrix(); ///還原矩陣
    glutSwapBuffers();
}
void motion(int x, int y)
{
    s = 1 + (x-150)/150.0; ///變大變小的變數 0~1
    display(); ///重畫畫面
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 rotate translate");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMotionFunc(motion); ///拖動motion的時候
    glutMainLoop();
}
