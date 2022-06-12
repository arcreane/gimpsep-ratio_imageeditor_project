#include"ScaleChangerVideo.h"

VideoWriter scaleChangerVideo(VideoCapture video, double factor) {

	Mat frame;
	double newFrameWidth = ceil(video.get(CAP_PROP_FRAME_WIDTH)*factor);
	int newFrameHeight = ceil(video.get(CAP_PROP_FRAME_HEIGHT)*factor);
	int fps = video.get(CAP_PROP_FPS);

	Size newSize = Size(newFrameWidth, newFrameHeight);

	VideoWriter modifiedVideo("output_video_scale" + to_string(factor) + ".avi", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, newSize);

	while (video.read(frame)) {
		video >> frame;

		Mat resizedFrame;
		resize(frame, resizedFrame, newSize, factor, factor, INTER_LINEAR);
		imshow("Modified video (press enter to exit)", resizedFrame);
		if (waitKey(1000.0 / fps) == 30) {
			break;
		}
		modifiedVideo << resizedFrame;
	}
	return modifiedVideo;
}