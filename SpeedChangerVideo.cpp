#include"CannyEdgeVideo.h"

VideoWriter speedChangerVideo(VideoCapture video, double factor) {

	Mat frame;
	int frameWidth = video.get(CAP_PROP_FRAME_WIDTH);
	int frameHeight = video.get(CAP_PROP_FRAME_HEIGHT);
	int fps = video.get(CAP_PROP_FPS);
	double newFrameRate = ceil(fps * factor);

	VideoWriter modifiedVideo("output_video_x" + to_string(factor) + ".avi", VideoWriter::fourcc('m', 'p', '4', 'v'), newFrameRate, Size(frameWidth, frameHeight));

	while (video.read(frame)) {
		video >> frame;

		imshow("Modified video (press enter to exit)", frame);
		if (waitKey(1000.0 / newFrameRate) == 30) {
			break;
		}
		modifiedVideo << frame;
	}
	cout << "framerate of the new video is : " << newFrameRate << endl;
	return modifiedVideo;
}