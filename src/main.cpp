#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
    // Initialize camera
    VideoCapture cap;
    cap.open(0);

    if(!cap.isOpened()) {
        cout << "ERROR opening camera..." << endl;
        return -1;
    }
    
    Mat frame;
    for (;;) {
        // Get frame from camera
        cap >> frame;        
        if(frame.empty())
            break;

        // Compute negative image, i.e., 255 - pixel_val
        Mat neg = Mat(frame.size(), frame.type());
        neg = Scalar(255, 255, 255) - frame;

        // Resize input frame
        Mat frame_rz;
        resize(frame, frame_rz, Size(), 0.2, 0.2);

        // Set image region of interest (ROI) to resized frame
        Rect roi = Rect(10, 10, frame_rz.cols, frame_rz.rows);
        frame_rz.copyTo(neg(roi));

        // Draw frame around ROI
        rectangle(neg, roi, Scalar(200, 200, 200), 3);

        // Show image
        imshow("Negative", neg);

        int key = waitKey(5);
        if (key == 27) {
            return 0;
        }        
    }
    
    return 0;
}