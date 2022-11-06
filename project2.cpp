// 21900262 박경륜
// computer vision (02)

// project 2

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame;
    VideoCapture cap;
    int fps, delay, length, key = 0;
    Ptr<BackgroundSubtractor> bg_model = createBackgroundSubtractorMOG2(); 
    Mat foregroundMask, backgroundImg, foregroundImg;

    // check if file exists. If none program ends
    if (cap.open("Project2.mp4") == 0) {
        cout << "no such file!" << endl;
        waitKey(0);
    }

    fps = cap.get(CAP_PROP_FPS);
    length = int(cap.get(CAP_PROP_FRAME_COUNT));
    delay = 1000 / fps;

    int duration = fps * length;


    // Loop to get each frames in video
    for (int i = 1; i <= duration; ++i) {
        cap >> frame;

        if (frame.empty()) {
            cout << "end of video" << endl;
            break;
        }

        resize(frame, frame, Size(640, 480));
        if (foregroundMask.empty())foregroundMask.create(frame.size(), frame.type());
        // image: Next video frame. Floating point frame will be used without scaling and 
        // should be in range [0,255].
        // foregroundMask: The output foreground mask as an 8-bit binary 
        bg_model->apply(frame, foregroundMask);
        GaussianBlur(foregroundMask, foregroundMask, Size(11, 11), 3.5, 3.5);
        threshold(foregroundMask, foregroundMask, 230, 255, THRESH_BINARY); // 200 넘으면 255
        foregroundImg= Scalar::all(0);
        frame.copyTo(foregroundImg, foregroundMask);
        // backgroundImg: The output background 
        bg_model->getBackgroundImage(backgroundImg);

        int h = frame.rows;
        int w = frame.cols;

        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
                if (foregroundImg.at<Vec3b>(j, k).val[0] != 0 || foregroundImg.at<Vec3b>(j, k).val[1] != 0 || foregroundImg.at<Vec3b>(j, k).val[2] != 0) {
                    putText(frame, format("Alert! Moving object!"), Point(0, 30), FONT_HERSHEY_SIMPLEX, 1.5, Scalar(255, 255, 255), 2);
                    break;
                }

        imshow("Project2 ", frame);

        waitKey(delay);
    }
}