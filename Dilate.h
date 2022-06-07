#include<opencv2/opencv.hpp>
using namespace cv;

#ifndef DILATE_H
#define DILATE_H

Mat dilate(Mat image, double factor1, double factor2, MorphShapes morph_shape);

#endif // !DILATE_H

