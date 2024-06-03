#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///�W�g�����L, �ХΰŶK��
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * upper = NULL;
GLMmodel * lower = NULL;
GLMmodel * body = NULL;

void drawbody(void)
{
    if (!body) {
        body = glmReadOBJ("body.obj");
        if (!body) exit(0);
        glmUnitize(body);
        glmFacetNormals(body);
        glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawlower(void)
{
    if (!lower) {
        lower = glmReadOBJ("lower.obj");
        if (!lower) exit(0);
        glmUnitize(lower);
        glmFacetNormals(lower);
        glmVertexNormals(lower, 90.0);
    }

    glmDraw(lower, GLM_SMOOTH | GLM_TEXTURE);
}

void drawupper(void)
{
    if (!upper) {
        upper = glmReadOBJ("upper.obj");
        if (!upper) exit(0);
        glmUnitize(upper);
        glmFacetNormals(upper);
        glmVertexNormals(upper, 90.0);
    }

    glmDraw(upper, GLM_SMOOTH | GLM_TEXTURE);
}

void drawpmodel(void)
{
    if (!pmodel) {
        pmodel = glmReadOBJ("pmodel.obj");
        if (!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_TEXTURE);
}

void drawhand1(void)
{
    if (!hand1) {
        hand1 = glmReadOBJ("hand1.obj");
        if (!hand1) exit(0);
        glmUnitize(hand1);
        glmFacetNormals(hand1);
        glmVertexNormals(hand1, 90.0);
    }

    glmDraw(hand1, GLM_SMOOTH | GLM_TEXTURE);
}

void drawhande1(void)
{
    if (!hand2) {
        hand2 = glmReadOBJ("hand2.obj");
        if (!hand2) exit(0);
        glmUnitize(hand2);
        glmFacetNormals(hand2);
        glmVertexNormals(hand2, 90.0);
    }

    glmDraw(hand2, GLM_SMOOTH | GLM_TEXTURE);
}
int angleID = 0;
float angle[20] = { };///float angle=0, da=-1;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glutWireCube(0.6);
    ///glutSolidSphere(0.1,30,30);
    glPushMatrix();
        glRotatef(180,0,1,0);
        drawbody();
        glPushMatrix();
            glTranslatef(-0.15,0,0);
            glRotatef(angle[0],1,0,0);
            glTranslatef(-0.025,-0.05,0);
            glScalef(0.8,0.8,0.8);
            drawupper();
            glPushMatrix();
                glTranslatef(0, -0.1, 0);
                glRotatef(angle[1], 1, 0, 0);
                glTranslatef(-0.02, -0.2, 0);
                glScalef(0.8,0.8,0.8);
                drawlower(); ///glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    ///if(angle<-90) da = 1;
    /// if(angle>0) da = -1;
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };

const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };


const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };

const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };

const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat high_shininess[] = { 100.0f };

void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
}

int oldX = 0, oldY = 0;
void mouse(int button, int state, int x, int y){
    oldX = x;
    oldY = y;
}
void motion(int x, int y){
    angle[angleID] += y - oldY; ///angle[angleID] = y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13-2_many_angle");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    myTexture("Diffuse.jpg");


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);

    glEnable(GL_NORMALIZE);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);



    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);

    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);



    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);

    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);

    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);

    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}