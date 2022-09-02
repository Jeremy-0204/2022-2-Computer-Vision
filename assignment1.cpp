// 21900262 박경륜
// Computer Vision (02)

// Assignment 1
// Read a video "background.mp4"
// display video for the first 3 seconds
// Find out the proper input parameter for waitKey()
// Print out the number of the current frame and the total number of frames

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat frame;
    int fps;
    int delay;
    int length;
    VideoCapture cap;

    int seconds;
    int totalFrame;

    // check if file exists. If none program ends
    if (cap.open("background.mp4") == 0) {
        cout << "no such file!" << endl;
        waitKey(0);
    }


    // fps는 1초당 들어있는 프레임의 갯수이다.
    // length는 영상 속 들어있는 총 프레임의 갯수이다.
    // fps * 3을 하면, 3초당 들어가게 되는 총 프레임의 갯수가 저장되겠지?

    fps = cap.get(CAP_PROP_FPS);
    length = int(cap.get(CAP_PROP_FRAME_COUNT));
    seconds = 3;
    totalFrame = fps * seconds; 

    delay = 500 / fps; // 프레임과 프레임 사이의 딜레이를 지정해준다. 
    // 여기서는 영상을 2배속 해보았다. 


    for (int i = 1; i <= totalFrame; ++i){ 


        // i는 여기서 프레임을 의미하게 된다. 
        // 프레임을 한번 읽을 때마다 i는 증가한다. 
        // 3초의 시간동안 들어갈 수 있는 프레임의 갯수를 다다르면 동영상을 끝낸다.

        cap >> frame;
        if (frame.empty()) {
            cout << "end of video" << endl;
            break;
        }


        // waitKey는 멈춰주는 함수이다.
        // 1000 / fps 하면 원래 속도 그대로 재생된다.
        // 이는 waitKey의 패러미터가 millisecoond 기준이기 때문이다.

        cout << "Frames: " << i << " / " << length << endl;
        imshow("video", frame);
        waitKey(delay); 

    }
}