#include <GL/glut.h>///使用GLUT外掛
#include "glm.h"
GLMmodel * pmodel = NULL;
void drawmodel(void)
{
    if(!pmodel){
    pmodel = glmReadOBJ("data/porsche.obj");
    if(!pmodel) exit(0);
    glmUnitize(pmodel);
    glmFacetNormals(pmodel);
    glmVertexNormals(pmodel, 90.0);
    }
    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
 void display()
 {
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     drawmodel();
     glutSwapBuffers();
 }
 int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///初始化 GLUT 140
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///143
    glutCreateWindow("week06-1_lighting");///145
    glutDisplayFunc(display);///148 display函式
    glutMainLoop();///174 迴圈
}
