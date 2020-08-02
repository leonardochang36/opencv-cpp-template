#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
    VideoCapture cap;
    cap.open(0);

    if(!cap.isOpened()) {
        cout << "ERROR opening camera..." << endl;
        return -1;
    }
    
    Mat frame;
    for (;;) {
        cap >> frame;        
        if(frame.empty())
            break;

        Mat neg = Mat(frame.size(), frame.type());
        neg.setTo(255);
        neg = neg - frame;

        imshow("Video", frame);
        imshow("Negative", neg);

        int key = waitKey(5);
        if (key == 27) {
            return 0;
        }        
    }
    
    return 0;
}