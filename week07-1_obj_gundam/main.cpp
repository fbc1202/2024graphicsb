#include <GL/glut.h>
#include "glm.h"

GLMmodel * pmodel = NULL;

void drawmodel(void)
{
    if(!pmodel){
        pmodel = glmReadOBJ("gundam.obj");
        ///上週的模型檔放在奇怪的目錄裡 桌面\freeglut\bin
        ///本周要換更好的地方
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
     drawmodel(); ///glutSolidTeapot(0.3);
     glutSwapBuffers();
 }

 int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week07-1_obj_gundam");
    glutDisplayFunc(display);

    glutMainLoop();
}
