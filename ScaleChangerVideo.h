#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;


#ifndef SCLAECHANGERVIDEO_H
#define SCALECHANGERVIDEO_H

VideoWriter scaleChangerVideo(VideoCapture video, double factor);

#endif
