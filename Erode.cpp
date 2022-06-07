#include"Erode.h"

Mat erode(Mat image, double factor1, double factor2, MorphShapes morph_shape) {
    Mat element = getStructuringElement(
        morph_shape, Size(factor1, factor2),
        Point(-1, -1));
    Mat erod;
    erode(image, erod, element,
        Point(-1, -1), 1);

    return erod;
}