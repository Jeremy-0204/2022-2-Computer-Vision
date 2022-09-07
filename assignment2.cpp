// 21900262 �ڰ��
// Computer Vision (02)

// Assignment 2
// Perform the following operations
//	- Generate a 90 - degree rotated image
//	- On the generated image, perform negative transformation if the pixel
//	- value is smaller than 127. Otherwise, perform gamma transformation
//	- with gamma as 10
// 
// Display the input and the result on two windows
//  -��gray image�� for input
//  - ��result�� for result

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image;
    image = imread("lena.png", 0);

    int h = image.rows;
    int w = image.cols;

    Mat rotated_img = image.clone();
    Mat gamma_img;
    Mat negative_img;

    int value;
    float gamma = 10.0;
    unsigned char pix[256];

    for (int i = 0; i < 256; i++) {
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
    }

    // ������ �޾ƿ���

    // 90�� ȸ����Ű��

    // check if file exists. If none program ends
    //if (image.open("lena.png") == 0) {
    //    cout << "no such file!" << endl;
    //    waitKey(0);
    //}

    for (int j = 0; j < h; j++){
        for (int i = 0; i < w; i++) {
            // Rotate 90 degree left
            rotated_img.at<uchar>(i, j) = image.at<uchar>(j, i);
            
            // Rotate Upside Down
            //rotated_img.at<uchar>(h-j-1, i) = image.at<uchar>(j, i);
            
            // Rotate 90 degree right
            //rotated_img.at<uchar>(i, h-j-1) = image.at<uchar>(j, i);

            value = rotated_img.at<uchar>(j, i);

            if (value < 127) rotated_img.at<uchar>(j, i) = 255 - value;
            else rotated_img.at<uchar>(j, i) = pix[rotated_img.at<uchar>(j, i)];
            // ���� �ȼ��� 127���� ������ negative
            // ���� �ȼ��� �� �ܸ� gamma
            // gamma�� 10���� ����
        }
    }

    // Print results and input image
    imshow("gray image", image);
    imshow("result", rotated_img);

    waitKey(0);
    return 0;

}