#include <opencv2/opencv.hpp>
#include <iostream>
#include "resize.cpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	String urlImage;
	cin >> urlImage;
	cout << typeid(urlImage).name();

	Mat image;
	std::string image_path = samples::findFile(urlImage);
	image = imread(image_path);

	
	String imageWindow = "image1";
	namedWindow(imageWindow);
	imshow(imageWindow, image);

	double scale_down = 0.2;
	Mat scaled_f_down;
	scaled_f_down = resize_image(image, scale_down);

	String Scaled_Down_Window = "Scaled_Down";
	namedWindow(Scaled_Down_Window);
	imshow(Scaled_Down_Window, scaled_f_down);


	double darken_factor = 50;
	Mat darkened_image;
	darkened_image = darken_image(image, darken_factor);
	
	String imageDarkened = "imageDarkened";
	namedWindow(imageDarkened);
	imshow(imageDarkened, darkened_image);

	Mat eroded_image;
	eroded_image = erode(image, 50, 50, MORPH_ELLIPSE);
	String eroded_name = "eroded image";
	namedWindow(eroded_name);
	imshow(eroded_name, eroded_image);

	Mat eroded_image_cross;
	eroded_image_cross = erode(image, 50, 50, MORPH_ELLIPSE);
	String eroded_name_cross = "eroded image cross";
	namedWindow(eroded_name_cross);
	imshow(eroded_name_cross, eroded_image_cross);


	Mat dilated_image;
	dilated_image = dilate(image, 50, 50, MORPH_ELLIPSE);
	String dilated_name = "dilated image";
	namedWindow(dilated_name);
	imshow(dilated_name, dilated_image);

	waitKey(0);
	return 0;
}