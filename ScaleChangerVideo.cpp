#include"ScaleChangerVideo.h"

VideoWriter scaleChangerVideo(VideoCapture video, double factor) {

	Mat frame;
	double newFrameWidth = ceil(video.get(cv::CAP_PROP_FRAME_WIDTH)*factor);
	int newFrameHeight = ceil(video.get(cv::CAP_PROP_FRAME_HEIGHT)*factor);
	int fps = video.get(CAP_PROP_FPS);

	VideoWriter modifiedVideo("output_video_scale" + to_string(factor) + ".avi", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, Size(newFrameWidth, newFrameHeight));

	while (video.read(frame)) {
		video >> frame;

		resize(frame, frame, Size(), factor, factor, INTER_LINEAR);
		imshow("Modified video (press enter to exit)", frame);
		if (waitKey(1000.0 / fps) == 27) {
			break;
		}
		modifiedVideo << frame;
	}
	return modifiedVideo;
}