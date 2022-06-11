#include "CannyEdge.h"

Mat cannyEdge(Mat image) {
        Mat contours;
        Canny(image, contours, 100, 100);
        return contours;
}