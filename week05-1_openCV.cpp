///File-New-
#include <opencv/highgui.h> ///�ϥ� openCV ������GUI�~��
int main()
{ ///�j�gI,�p�gpl (Intel performance library)
    IplImage * img = cvLoadImage("c:/micky.jpg");

    cvShowImage("img", img);
    cvWaitKey(0);
}
