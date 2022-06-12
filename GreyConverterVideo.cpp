#include"GreyConverterVideo.h"

VideoWriter greyConverter(VideoCapture video) {
	
	Mat frame;
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeight = video.get(cv::CAP_PROP_FRAME_HEIGHT);
	int fps = video.get(CAP_PROP_FPS);

	VideoWriter modifiedVideo("output_video_black_white.avi", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, Size(frameWidth, frameHeight));

	while (video.read(frame)) {
		video >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		cvtColor(frame, frame, COLOR_GRAY2BGR);
		
		imshow("Modified video (press enter to exit)", frame);
		if (waitKey(1000.0 / fps) == 27) {
			break;
		}
		modifiedVideo << frame;
	}
	return modifiedVideo;
}