#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///上週有做過, 請用剪貼的
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
float angleX[10] = { };///float angle=0, da=-1;
float angleY[10] = { };
void display()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    ///glutWireCube(0.6);
    ///glutSolidSphere(0.1,30,30);
    glPushMatrix();
        glRotatef(180,0,1,0);
        glRotatef(angleX[0], 1, 0, 0);
        glRotatef(angleY[0], 0, 1, 0);
        drawbody();
        glPushMatrix();
            glTranslatef(-0.15,0,0);
            glRotatef(angleX[1], 1, 0, 0);
            glRotatef(angleY[1], 0, 1, 0);
            glTranslatef(-0.025,-0.05,0);
           /// glScalef(0.8,0.8,0.8);
            drawupper();
            glPushMatrix();
                glTranslatef(0, -0.1, 0);
                glRotatef(angleX[2], 1, 0, 0);
                glRotatef(angleY[2], 0, 1, 0);
                glTranslatef(-0.02, -0.2, 0);
                ///glScalef(0.8,0.8,0.8);
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


#include <stdio.h>

FILE * fout = NULL;
FILE * fin = NULL;
void timer(int t);

void keyboard(unsigned char key, int x, int y){

    if(key=='p'){
        glutTimerFunc(0, timer, 0);
    }

    if(key=='r'){
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<10; i++){
            fscanf(fin, "%f", & angleX[i]);
            fscanf(fin, "%f", & angleY[i]);
        }
        glutPostRedisplay();
    }

    if(key=='s'){
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<10; i++){
            printf("%.1f ", angleX[i]);
            fprintf(fout,"%.1f ", angleX[i]);
            printf("%.1f ", angleY[i]);
            fprintf(fout,"%.1f ", angleY[i]);
        }
        printf("\n");
        fprintf(fout,"\n");
    }

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
    angleX[angleID] += y - oldY;
    angleY[angleID] += x - oldX; ///angle[angleID] = y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}

float oldAngleX[10] = {};
float oldAngleY[10] = {};
float newAngleX[10] = {};
float newAngleY[10] = {};

void timer(int t){
    glutTimerFunc(50, timer, t+1);
    if(fin==NULL) fin = fopen("angle.txt", "r");
    if(t%20==0){
        for(int i=0; i<10; i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];
            fscanf(fin, "%f", &newAngleX[i]);
            fscanf(fin, "%f", &newAngleY[i]);
        }
    }
    float alpha = (t%20) / 20.0;
    for(int i=0; i<10; i++ ){
        angleX[i] = alpha * newAngleX[i] + (1-alpha) * oldAngleX[i];
        angleY[i] = alpha * newAngleY[i] + (1-alpha) * oldAngleY[i];
    }
    glutPostRedisplay();
    printf("你呼叫了 timer(%d)\n", t);
}

int main(int argc, char* argv[])
{
    printf("程式開始執行\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14-2_alpha_blending");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    ///glutTimerFunc(0, timer, 0);


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
