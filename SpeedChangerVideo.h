#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


#ifndef SPEEDCHANGERVIDEO_H
#define SPEEDCHANGERVIDEO_H

VideoWriter speedChangerVideo(VideoCapture video, double factor);

#endif