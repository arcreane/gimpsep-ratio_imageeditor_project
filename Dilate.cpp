#include "Dilate.h"

Mat dilate(Mat image, double factor1, double factor2, MorphShapes morph_shape) {
    Mat element = getStructuringElement(
        MORPH_RECT, Size(factor1, factor2),
        Point(-1, -1));
    Mat dill;

    dilate(image, dill, element,
        Point(-1, -1), 1);

    return dill;
}