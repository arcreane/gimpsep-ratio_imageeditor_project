#include "Menu.h"
#include "Darken.h"
#include "Dilate.h"
#include "Erode.h"
#include "Size.h"
#include "FaceDetection.h"
#include "CannyEdge.h"
#include "PanoramaStitching.h"
#include "GreyConverterVideo.h"
#include "CannyEdgeVideo.h"
#include "SpeedChangerVideo.h"
#include "ScaleChangerVideo.h"
#include "Contrast.h"
#include "DrawOnImage.h"
#include <iostream>

using namespace std;

int Menu() {
	cout << "------------ Welcome on the image / video Editor ------------" << endl << endl;
	int choiceStartMenu;
	bool loopStartMenu = true;
	while (loopStartMenu != false) {
		cout << "On which type of file do you want to work ?" << endl << "1 : An image" << endl << "2 : A video" << endl << "0 : Leave" << endl;
		int choiceStartMenu = 0;
		cin >> choiceStartMenu;
		if (choiceStartMenu == 1) {
			String editOrStitch;
			cout << "What do you want to do ? (Edit or Stitch)" << endl;
			cin >> editOrStitch;

			bool loopImageMenu = true;


			while (loopImageMenu != false) {
				if (editOrStitch.compare("Stitch") == 0) {
					panoramaStitching();
					loopImageMenu = false;
				}
				else if (editOrStitch.compare("Edit") == 0) {
					String urlImage;
					cout << "Please write the path to your image file : " << endl;
					cin >> urlImage;
					Mat image;
					std::string image_path = samples::findFile(urlImage);
					image = imread(image_path);
					bool keepEditing = true;
					while (keepEditing) {
						Mat modified_image;
						MorphShapes morphshape;
						double factor;
						String Stringmorphshape;
						cout << "What do you want to do" << endl;
						cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl << "6 : Face Detection" << endl << "7 : CannyEdge" << endl << "8 : Contrast" << endl << "9 : Draw" << endl;
						int choiceMenuImage = 0;
						cin >> choiceMenuImage;

						switch (choiceMenuImage) {
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
							cout << "chose the factor : (between 1 and 50)" << endl;
							cin >> factor;
							while (factor < 1 || factor > 50) {
								cout << "Wrong input select between 1 and 50 !" << endl;
								cin >> factor;
							}
							cout << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
							cin >> Stringmorphshape;
							while (Stringmorphshape.compare("CROSS") != 0 && Stringmorphshape.compare("ELLIPSE") != 0 && Stringmorphshape.compare("RECT") != 0) {
								cout << "Wrong input !" << endl << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
								cin >> Stringmorphshape;
							}
							if (Stringmorphshape.compare("CROSS") == 0) {
								morphshape = MORPH_CROSS;
							}
							else if (Stringmorphshape.compare("ELLIPSE") == 0) {
								morphshape = MORPH_ELLIPSE;
							}
							else if (Stringmorphshape.compare("RECT") == 0) {
								morphshape = MORPH_RECT;
							}
							modified_image = erode(image, factor, factor, morphshape);
							break;
						case 5:
							cout << "chose the factor : (between 1 and 50)" << endl;
							cin >> factor;
							while (factor < 1 || factor > 50) {
								cout << "Wrong input select between 1 and 50 !" << endl;
								cin >> factor;
							}
							cout << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
							cin >> Stringmorphshape;
							while (Stringmorphshape.compare("CROSS") != 0 && Stringmorphshape.compare("ELLIPSE") != 0 && Stringmorphshape.compare("RECT") != 0) {
								cout << "Wrong input !" << endl << "chose the shape (between CROSS, ELLIPSE, RECT) : " << endl;
								cin >> Stringmorphshape;
							}
							if (Stringmorphshape.compare("CROSS") == 0) {
								morphshape = MORPH_CROSS;
							}
							else if (Stringmorphshape.compare("ELLIPSE") == 0) {
								morphshape = MORPH_ELLIPSE;
							}
							else if (Stringmorphshape.compare("RECT") == 0) {
								morphshape = MORPH_RECT;
							}
							modified_image = dilate(image, factor, factor, morphshape);
							break;
						case 6:
							modified_image = faceDetection(image);
							break;
						case 7:
							modified_image = cannyEdge(image);
							break;
						case 8:
							cout << "chose the factor : (Over 1 increases contrast, between 0 and 1 decreases)" << endl;
							cin >> factor;
							modified_image = contrast(image, factor);
							break;
						case 9:
							namedWindow("modified_image", 0);
							setMouseCallback("modified_image", drawOnImage, &image);
							waitKey(0);
							modified_image = image;
							break;
						default:
							cout << "Wrong input, please choose between : " << endl;
							cout << "1 : resize image" << endl << "2 : Darken image" << endl << "3 : Ligthen image" << endl << "4 : Erode image" << endl << "5 : Dilate image" << endl << "6 : Face Detection" << endl << "7 : CannyEdge" << endl << "8 : Contrast" << endl << "9 : Draw" << endl;
							cin >> choiceMenuImage;
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

						cout << "Do you want to keep editing your image ? (Yes or No)" << endl;
						String finalChoice;
						cin >> finalChoice;

						if (finalChoice.compare("Yes") == 0) {
							loopImageMenu = true;
						}
						else if (finalChoice.compare("No") == 0) {
							String saveChoice;
							cout << "Do you want to save your new image ? (Yes or No) " << endl;
							cin >> saveChoice;
							while (saveChoice.compare("Yes") !=0 || saveChoice.compare("No") != 0) {
							if (saveChoice.compare("Yes") == 0) {
								bool isSuccess = imwrite("saveImage.jpg", image);
								if (isSuccess) {
									cout << "Image Saved successfully !" << endl;
									waitKey(0);
									return 1;
								}
								else {
									cout << "failed saving image" << endl;
								}
							} else if (saveChoice.compare("No") != 0){
								cout << "Wrong input ! (Yes or No)" << endl;
								cin >> saveChoice;
							} else {
								return 0;
							}
							}

							keepEditing = false;
							loopImageMenu = false;
						}
						else {
							cout << "Wrong input !" << endl << "Chose Yes of No" << endl;
							cin >> finalChoice;
						}
					}
				}
				else {
					cout << "Wrong input, chose between Edit and Stitch" << endl;
					cin >> editOrStitch;
				}

			}

		}
		else if (choiceStartMenu == 2) {
			String urlVideo;
			cout << "Please write the path to your video file : " << endl;
			cin >> urlVideo;
			VideoCapture cap(urlVideo);

			while (!cap.isOpened()) {
				std::cout << "Unable to open the video, please enter a valide file" << endl;
				cin >> urlVideo;
				VideoCapture cap(urlVideo);
			}

			bool loopVideoMenu = true;
			while (loopVideoMenu != false) {
				cout << "What do you want to do" << endl;
				cout << "1 : Convert to black and white" << endl << "2 : Use Canny Edge on video" << endl << "3 : Change the speed of the video" << endl << "4 : Change the scale of the video" << endl;

				int choiceMenuVideo = 0;
				cin >> choiceMenuVideo;

				VideoWriter modifiedVideo;

				switch (choiceMenuVideo) {
				case 1:
					modifiedVideo = greyConverter(cap);
					break;
				case 2:
					modifiedVideo = cannyEdgeVideo(cap);
					break;
				case 3:
					double speedFactor;
					cout << "Give a factor to change the speed of the video" << endl;
					cin >> speedFactor;
					if (speedFactor < 0.1 || speedFactor > 20.0) {
						cout << "You factor must be between 0.1 and 20.0, enter it a new time :" << endl;
						cin >> speedFactor;
					}
					modifiedVideo = speedChangerVideo(cap, speedFactor);
					break;
				case 4:
					double scaleFactor;
					cout << "Give a factor to change the scale of the video" << endl;
					cin >> scaleFactor;
					if (scaleFactor < 0.1 || scaleFactor > 4.0) {
						cout << "You factor must be between 0.1 and 4.0, enter it a new time :" << endl;
						cin >> scaleFactor;
					}
					modifiedVideo = scaleChangerVideo(cap, scaleFactor);
				default:
					cout << "Wrong input, please choose between : " << endl;
					cout << "1 : Convert to black and white" << endl << "2 : Use Canny Edge on video" << endl << "3 : Change the speed of the video" << endl << "4 : Change the scale of the video" << endl;
					cin >> choiceMenuVideo;
				}

				waitKey(0);
				destroyAllWindows();

				cout << "Do you want to save this new video ? (Yes or No)" << endl;

				String saveTheNewVideo;
				cin >> saveTheNewVideo;

				if (saveTheNewVideo == "Yes") {
					modifiedVideo.release();
					cout << "\nFinished wirting, you can check the result in the project repository" << endl;
					loopVideoMenu = false;
				}
				else if (saveTheNewVideo == "No") {
					loopVideoMenu = false;
				}
				else {
					cout << "Wrong input, write Yes or No" << endl;
					cin >> saveTheNewVideo;
				}
			}
		}
		else if (choiceStartMenu == 0) {
			loopStartMenu = false;
		}
		else {
			cout << "Wrong input, please choose between : " << endl;
			cout << "1 : An image" << endl << "2 : A video" << endl << "0 : Leave";
			cin >> choiceStartMenu;
		}
	}
	return 0;
}