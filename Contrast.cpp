#include "Contrast.h"

Mat contrast(Mat image, double factor) {
	Mat contrasted;

	image.convertTo(contrasted, -1, factor, 0);

	return contrasted;
}