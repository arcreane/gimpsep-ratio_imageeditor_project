#include "DrawOnImage.h"

Point center, circumference;

extern void drawOnImage(int event, int x, int y, int, void* imagePointer) {
	String imageWindow = "modified_image";
	Mat& image = (*(Mat*)imagePointer);
	if (event == 1) {
		center = Point(x, y);
	}
	else if(event == 4) {
		circumference = Point(x, y);
		float radius = sqrt(pow(center.x - circumference.x, 2) + pow(center.y - circumference.y, 2));
		circle(image, center, radius, Scalar(255, 0, 255), 4);
		imshow(imageWindow, image);
		waitKey(1);
	}
}