#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;

int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";

/**
 * @function CannyThreshold
 * @brief Trackbar callback - Canny thresholds input with a ratio 1:3
 */
static void CannyThreshold(int, void*)
{
    /// Reduce noise with a kernel 3x3
    blur(src_gray, detected_edges, Size(3, 3));

    /// Canny detector
    Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernel_size);

    /// Using Canny's output as a mask, we display our result
    //![fill]
    dst = Scalar::all(0);

    //![copyto]
    src.copyTo(dst, detected_edges);

    //![display]
    imshow(window_name, dst);
}


/**
 * @function main
 */
int main(int argc, char** argv)
{
    CommandLineParser parser(argc, argv, "{@input | img.jpg | input image}");
    src = imread("C:\\Users\\salomegrille\\Desktop\\img.jpg"); // Load an image

    if (src.empty())
    {
        std::cout << "Could not open or find the image selected...\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }

    ///Create a matrix of the same type and size as src
    dst.create(src.size(), src.type());

    //convert to gray
    cvtColor(src, src_gray, COLOR_BGR2GRAY);

    //create window
    namedWindow(window_name, WINDOW_AUTOSIZE);

    ///Trackbar for user to enter threshold
    createTrackbar("Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

    /// Show the image
    CannyThreshold(0, 0);

    /// Wait until user exit program by pressing a key
    waitKey(0);

    return 0;
}
