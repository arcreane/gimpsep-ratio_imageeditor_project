#include "Contrast.h"

Mat Contrast(Mat image, double factor) {
	Mat contrasted;

	image.convertTo(contrasted, -1, factor, 0);

	return contrasted;
}