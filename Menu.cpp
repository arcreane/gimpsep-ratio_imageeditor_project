#include "Menu.h"
#include "Darken.h"
#include "Dilate.h"
#include "Erode.h"
#include "Size.h"
#include <iostream>

using namespace std;

Mat Menu() {
	String urlImage;
	cout << "Please write the path to your file : " << endl;
	cin >> urlImage;
	cout << typeid(urlImage).name();


	Mat image;
	std::string image_path = samples::findFile(urlImage);
	image = imread(image_path);


	bool keep = true;
	while (keep != false) {
		Mat modified_image;
		MorphShapes morphshape;
		double factor;
		String Stringmorphshape;
		cout << "What do you want to do" << endl;
		cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl;
		int choice = 0;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "chose the factor (2 = 2 times bigger, 0.5, divide the size by two)" << endl;
			cin >> factor;
			modified_image = resize_image(image, factor);
			break;
		case 2:
			cout << "chose the factor :" <<endl;
			cin >> factor;
			if (factor > 0) {
				factor = 0 - factor;
			}
			modified_image = darken_image(image, factor);
			break;
		case 3:
			cout << "chose the factor :" << endl;
			cin >> factor;
			if (factor < 0) {
				factor = 0 - factor;
			}
			modified_image = darken_image(image, factor);
			break;		
		case 4:
			cout << "chose the factor :" << endl;
			cin >> factor;
			cout << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
			cin >> Stringmorphshape;
			if (Stringmorphshape.compare("CROSS") == 0) {
				morphshape = MORPH_CROSS;
			}
			else if (Stringmorphshape.compare("ELLIPSE") == 0) {
				morphshape = MORPH_ELLIPSE;
			}
			else if (Stringmorphshape.compare("RECT") == 0) {
				morphshape = MORPH_RECT;
			}
			else {
				cout << "Wrong input !" << endl << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
				cin >> Stringmorphshape;
			}
			modified_image = erode(image, factor, factor, morphshape);
			break;
		case 5:
			cout << "chose the factor :" << endl;
			cin >> factor;
			cout << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
			cin >> Stringmorphshape;
			if (Stringmorphshape.compare("CROSS") == 0) {
				morphshape = MORPH_CROSS;
			}
			else if (Stringmorphshape.compare("ELLIPSE") == 0) {
				morphshape = MORPH_ELLIPSE;
			}
			else if (Stringmorphshape.compare("RECT") == 0) {
				morphshape = MORPH_RECT;
			}
			else {
				cout << "Wrong input !" << endl << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
				cin >> Stringmorphshape;
			}
			modified_image = dilate(image, factor, factor, morphshape);
			break;
		default:
			cout << "Wrong input, please choose between : " << endl;
			cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl;
			cin >> choice;
		}
		String imageWindow = "modified_image";
		namedWindow(imageWindow);
		imshow(imageWindow, modified_image);

		waitKey(0);
		destroyAllWindows();
		

		cout << "Do you want to keep this modification ? (Yes or No)" << endl;
		String keepTheNewImage;
		cin >> keepTheNewImage;

		if (keepTheNewImage == "Yes") {
			image = modified_image;
		}
		else if (keepTheNewImage == "No") {
			image = image;
		}
		else {
			cout << "Wrong input, write Yes or No" << endl;
			cin >> keepTheNewImage;
		}

		cout << "Do you want to keep editing your image ? Yes or No" << endl;
		String finalChoice;
		cin >> finalChoice;

		if (finalChoice.compare("Yes") == 0) {
			keep = true;
		}
		else if (finalChoice.compare("No") == 0) {
			keep = false;
		}
		else {
			cout << "Wrong input !" << endl << "Chose Yes of No" << endl;
			cin >> finalChoice;
		}

	}
}