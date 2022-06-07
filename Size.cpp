#include "Size.h"

Mat resize_image(Mat image, double factor) {
	Mat resized_image;

	resize(image, resized_image, Size(), factor, factor, INTER_LINEAR);

	return resized_image;
}