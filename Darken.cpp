#include"Darken.h"

Mat darken_image(Mat image, double factor) {
	Mat darkened;

	image.convertTo(darkened, -1, 1, factor);

	return darkened;
}