#include "Menu.h"
#include "Darken.h"
#include "Dilate.h"
#include "Erode.h"
#include "Size.h"
#include "FaceDetection.h"
#include "CannyEdge.h"
#include "PanoramaStitching.h"
#include <iostream>

using namespace std;

Mat Menu() {

	String editOrStitch;

	cout << "What do you want to do ? (Edit or Stitch)" << endl;
	cin >> editOrStitch;

	bool keep = true;

	while (editOrStitch.compare("Edit") != 0 || editOrStitch.compare("Stitch") != 0) {

		if (editOrStitch.compare("Stitch") == 0) {
			Mat stitchImage;
			stitchImage = panoramaStitching();
			keep = false;
			cout << "do you want to save your image ? (Yes or No) : " << endl;
			String save;
			cin >> save;
			while (save.compare("Yes") != 0 || save.compare("No") != 0) {
				if (save.compare("Yes") == 0) {
					imwrite("rendu.jpg", stitchImage);
					waitKey(0);
				}
				else if (save.compare("No") == 0) {
					break;
				}
				else {
					cout << "wrong input, chose Yes or No : " << endl;
					cin >> save;
				}
			}
			keep = false;
		}
		else if (editOrStitch.compare("Edit") == 0) {
			String urlImage;
			cout << "Please write the path to your file : " << endl;
			cin >> urlImage;

			while (keep != false) {
				Mat image;
				std::string image_path = samples::findFile(urlImage);
				image = imread(image_path);



				Mat modified_image;
				MorphShapes morphshape;
				double factor;
				String Stringmorphshape;
				cout << "What do you want to do" << endl;
				cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl << "6 : Face Detection" << endl << "7 : CannyEdge" << endl;
				int choice = 0;
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "chose the factor (2 = 2 times bigger, 0.5, divide the size by two)" << endl;
					cin >> factor;
					modified_image = resize_image(image, factor);
					break;
				case 2:
					cout << "chose the factor :" << endl;
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
					cout << "chose the factor (between 1 and 20) :" << endl;
					cin >> factor;
					while (factor < 1 || factor > 20) {
						cout << "out of range, chose between (1 and 20) : " << endl;
						cin >> factor;
					}
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
				case 6:
					modified_image = faceDetection(image);
					break;
				case 7:
					modified_image = cannyEdge(image);
					break;
				default:
					cout << "Wrong input, please choose between : " << endl;
					cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl << "6 : Face Detection" << endl << "7 : CannyEdge" << endl;
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
					cout << "do you want to save your image ? (Yes or No) : " << endl;
					String save;
					cin >> save;
					while (save.compare("Yes") != 0 || save.compare("No") != 0) {
						if (save.compare("Yes") == 0) {
							imwrite("rendu.jpg", modified_image);
							waitKey(0);
						}
						else if (save.compare("No") == 0) {
							break;
						}
						else {
							cout << "wrong input, chose Yes or No : " << endl;
							cin >> save;
						}
					}
				}
				else {
					cout << "Wrong input !" << endl << "Chose Yes of No" << endl;
					cin >> finalChoice;
				}
			}

		}
		else {
			cout << "Wrong input, chose between Edit or Stitch" << endl;
			cin >> editOrStitch;
		}
	}
}