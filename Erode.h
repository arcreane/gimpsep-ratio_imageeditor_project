#include <opencv2/opencv.hpp>
using namespace cv;

#ifndef ERODE_H
#define ERODE_H

Mat erode(Mat image, double factor1, double factor2, MorphShapes morph_shape);

#endif // !ERODE_H

