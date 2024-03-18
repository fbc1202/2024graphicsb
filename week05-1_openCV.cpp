///File-New-
#include <opencv/highgui.h> ///使用 openCV 的高級GUI外掛
int main()
{ ///大寫I,小寫pl (Intel performance library)
    IplImage * img = cvLoadImage("c:/micky.jpg");

    cvShowImage("img", img);
    cvWaitKey(0);
}
