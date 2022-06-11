#include "FaceDetection.h"

Mat faceDetection(Mat image) {
	CascadeClassifier faceCascade, eyesCascade;
	
	eyesCascade.load("Dataset/haarcascade_eye_tree_eyeglasses.xml");
	faceCascade.load("Dataset/haarcascade_frontalface_alt.xml");

	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);
	equalizeHist(grayImage, grayImage);

	vector<Rect> faces;
	faceCascade.detectMultiScale(grayImage, faces);
	
	for (size_t i = 0; i < faces.size(); i++) {
		Point faceCenter(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(image, faceCenter, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);

		Mat faceRegionOfInterest = grayImage(faces[i]);

		vector<Rect> eyes;
		eyesCascade.detectMultiScale(faceRegionOfInterest, eyes);

		for (size_t j = 0; j < eyes.size(); j++) {
			Point eyeCenter(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
			int radius = cvRound((eyes[j].width + eyes[j].height) * 0.25);
			circle(image, eyeCenter, radius, Scalar(255, 0, 0), 4);
		}
	}

	return image;
}