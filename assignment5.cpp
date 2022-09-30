// 21900262 박경륜
// computer vision (02)

// assignment 5

#include "cv.hpp"
#include <iostream>
#include <vector>
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main() {
    Mat frame;
    VideoCapture cap;
    int fps, delay, length;

    float rho, theta, a, b, x0, y0;
    float total_rho, total_theta;
    Point p1, p2;
    vector<Vec2f> lines_l, lines_r;

	// check if file exists. If none program ends
    if (cap.open("Road.mp4") == 0) {
		cout << "no such file!" << endl;
        waitKey(0);
    }

    // set duration as 20 seconds
    fps = cap.get(CAP_PROP_FPS);
    length = int(cap.get(CAP_PROP_FRAME_COUNT)); 

    delay = 1000 / fps;

    int duration = fps * 20;

    // Loop to get each frames in video
    for (int i = 1; i <= duration; ++i){ 
        cap >> frame;
        if (frame.empty()) {
            cout << "end of video" << endl;
            break;
        }

        // Reset total rho and theta per frames as 0
        total_rho = 0, total_theta = 0;

        Rect rect_l(200, 400, 400, 200); // 600 - 200, 600 - 400);
        Rect rect_r(600, 400, 400, 200); // 1000 - 600, 600 - 400);

        Mat left_roi(frame(rect_l));
        Mat right_roi(frame(rect_r));

        cvtColor(left_roi, left_roi, CV_BGR2GRAY);
        cvtColor(right_roi, right_roi, CV_BGR2GRAY);

        GaussianBlur(left_roi, left_roi, Size(5, 5), 5, 5, BORDER_DEFAULT);
        GaussianBlur(right_roi, right_roi, Size(5, 5), 5, 5, BORDER_DEFAULT);

        Canny(left_roi, left_roi, 10, 60, 3);
        Canny(right_roi, right_roi, 10, 60, 3);

        HoughLines(left_roi, lines_l, 1, CV_PI / 180, 80);
        //HoughLines(left_roi, lines_l, 1, CV_PI / 180, 140, 30 * (CV_PI / 180), 60 * (CV_PI / 180));
        HoughLines(right_roi, lines_r, 1, CV_PI / 180, 80);
        //HoughLines(right_roi, lines_r, 1, CV_PI / 180, 110, 120 * (CV_PI / 180), 150 * (CV_PI / 180));
        
        // Set count number to calculate avg rho and theta
        float count = 0.0;


        // ====================================
        // = LEFT ROI - HOUGH TRANSFORMATION  =
        // ====================================

        for (int i = 0; i < lines_l.size(); i++) {
            rho = lines_l[i][0];
            theta = lines_l[i][1];

            // Set angle between 30 ~ 60
            // Add lines only between selected angles
            if (theta >= 30 * (CV_PI / 180) && theta <= 60 * (CV_PI / 180)) {
                total_rho += rho;
                total_theta += theta;
                count++;
            }
        }

        // Calculate Avg rho and theta, print one line only
        if (count >= 1) {
            float avg_rho = total_rho / count;
            float avg_theta = total_theta / count;

            a = cos(avg_theta);
            b = sin(avg_theta);

            x0 = a * avg_rho + 200;
            y0 = b * avg_rho + 400;

            p1 = Point(cvRound(x0 + 1000 * (-b)), cvRound(y0 + 1000 * a));
            p2 = Point(cvRound(x0 - 1000 * (-b)), cvRound(y0 - 1000 * a));
            line(frame, p1, p2, Scalar(0, 0, 255), 3, 8);
        }



        // ====================================
        // = RIGHT ROI - HOUGH TRANSFORMATION =
        // ====================================

        count = 0.0;
        total_rho = 0, total_theta = 0;

        for (int i = 0; i < lines_r.size(); i++) {
            rho = lines_r[i][0];
            theta = lines_r[i][1];
            
            // Set Angle between 120 ~ 150
            // Add lines only between selected angles
            if (theta >= 120 * (CV_PI / 180) && theta <= 150 * (CV_PI / 180)) {
                total_rho += rho;
                total_theta += theta;
                count++;
            }
        }

        // Calculate Avg rho and theta, print one line only
        if (count >= 1){
            float avg_rho = total_rho / count;
            float avg_theta = total_theta / count;

            a = cos(avg_theta);
            b = sin(avg_theta);

            x0 = a * avg_rho + 600;
            y0 = b * avg_rho + 400;

            p1 = Point(cvRound(x0 + 1000 * (-b)), cvRound(y0 + 1000 * a));
            p2 = Point(cvRound(x0 - 1000 * (-b)), cvRound(y0 - 1000 * a));
            line(frame, p1, p2, Scalar(0, 0, 255), 3, 8);
        }



        namedWindow("Left canny");
        moveWindow("Left canny", 200, 0);
        imshow("Left canny", left_roi);

        namedWindow("Right canny");
        moveWindow("Right canny", 600, 0);
        imshow("Right canny", right_roi);

        namedWindow("Frame");
        moveWindow("Frame", 200, 200);
        imshow("Frame", frame);
        waitKey(delay); 
    }
}