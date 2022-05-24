#include <opencv2/opencv.hpp>
using namespace cv;

Mat resize_image(Mat image, double factor) {
	Mat resized_image;

	resize(image, resized_image, Size(), factor, factor, INTER_LINEAR);

	return resized_image;
}

Mat darken_image(Mat image, double factor) {
	Mat darkened;

	image.convertTo(darkened, -1, 1, 0);

	return darkened;
}


Mat erode(Mat image, double factor1, double factor2, MorphShapes morph_shape) {
    Mat element = getStructuringElement(
        morph_shape, Size(factor1, factor2),
        Point(-1, -1));
    Mat erod;

    // For Erosion
    erode(image, erod, element,
        Point(-1, -1), 1);

    return erod;
}

Mat dilate(Mat image, double factor1, double factor2, MorphShapes morph_shape) {
    Mat element = getStructuringElement(
        MORPH_RECT, Size(factor1, factor2),
        Point(-1, -1));
    Mat dill;


    // For Dilation
    dilate(image, dill, element,
        Point(-1, -1), 1);

    return dill;
}