// 21900262 �ڰ��
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


    // fps�� 1�ʴ� ����ִ� �������� �����̴�.
    // length�� ���� �� ����ִ� �� �������� �����̴�.
    // fps * 3�� �ϸ�, 3�ʴ� ���� �Ǵ� �� �������� ������ ����ǰ���?

    fps = cap.get(CAP_PROP_FPS);
    length = int(cap.get(CAP_PROP_FRAME_COUNT));
    seconds = 3;
    totalFrame = fps * seconds; 

    delay = 500 / fps; // �����Ӱ� ������ ������ �����̸� �������ش�. 
    // ���⼭�� ������ 2��� �غ��Ҵ�. 


    for (int i = 1; i <= totalFrame; ++i){ 


        // i�� ���⼭ �������� �ǹ��ϰ� �ȴ�. 
        // �������� �ѹ� ���� ������ i�� �����Ѵ�. 
        // 3���� �ð����� �� �� �ִ� �������� ������ �ٴٸ��� �������� ������.

        cap >> frame;
        if (frame.empty()) {
            cout << "end of video" << endl;
            break;
        }


        // waitKey�� �����ִ� �Լ��̴�.
        // 1000 / fps �ϸ� ���� �ӵ� �״�� ����ȴ�.
        // �̴� waitKey�� �з����Ͱ� millisecoond �����̱� �����̴�.

        cout << "Frames: " << i << " / " << length << endl;
        imshow("video", frame);
        waitKey(delay); 

    }
}