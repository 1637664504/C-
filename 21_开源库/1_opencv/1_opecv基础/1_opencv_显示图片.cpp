#include <opencv2/opencv.hpp>
#include <string>
#include <stdio.h>
#include <unistd.h>
using namespace std;

#define KEY_Esc 0x1b

int main(int argc, char** argv)
{
    string file = "/home/liuj/1_Data/5_python_example/res/113.jpg";
    cv::Mat img = cv::imread(file);
    cv::imshow("[img1]", img);
    int key = 0;
    while (key != KEY_Esc) {
        key = cv::waitKey(0) & 0xff;
        printf("key=%x\n", key);
        sleep(1);
    }
    return 0;
}