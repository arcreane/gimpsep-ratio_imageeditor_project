#include"CannyEdgeVideo.h"

VideoWriter cannyEdgeVideo(VideoCapture video) {

	Mat frame;
	int frameWidth = video.get(CAP_PROP_FRAME_WIDTH);
	int frameHeight = video.get(CAP_PROP_FRAME_HEIGHT);
	int fps = video.get(CAP_PROP_FPS);

	VideoWriter modifiedVideo("output_video_canny_edge.avi", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, Size(frameWidth, frameHeight));

	while (video.read(frame)) {
		video >> frame;
	
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		Canny(frame, frame, 100, 300, 3);
		cvtColor(frame, frame, COLOR_GRAY2BGR);

		imshow("Modified video (press enter to exit)", frame);
		if (waitKey(1000.0 / fps) == 30) {
			break;
		}
		modifiedVideo << frame;
	}
	return modifiedVideo;
}