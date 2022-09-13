// 21900262 박경륜
// Computer Vision (02)

// Assignment 3
//• Read an image “moon.png” as gray scale image
//  • Perform sharpening on the right - half of the image
//  • Perform sharpening using unsharp masking
// 
//• Read an image “saltnpepper.png” as gray scale image
//  • Perform median filtering on left - half of the the image
//      • Set aperture size as 9
//      • medianBlur(in, out, val);
//          • Blurs an image using the median filter
//          • in : src, out : dst, val : aperture size(must be oddand greater than 1)

#include "cv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat img1;
    Mat img2;
    // 흑백사진 받아오기
    // ROI 사진 절반 입력하기
    // Unsharp Masking 적용하기

    // 흑백사진 받아오기
    // ROI 사진 절반 입력하기
    // Median Filtering 하기
    img1 = imread("moon.png", 0);
    img2 = imread("saltnpepper.png", 0);


    int h = img1.rows;
    int w = img1.cols;

    Mat rotated_img = img1.clone();
    Mat gamma_img;
    Mat negative_img;

    int value;
    float gamma = 10.0;
    unsigned char pix[256];

    for (int i = 0; i < 256; i++) {
        pix[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
    }

    // 흑백사진 받아오기

    // 90도 회전시키기

    // check if file exists. If none program ends
    //if (image.open("lena.png") == 0) {
    //    cout << "no such file!" << endl;
    //    waitKey(0);
    //}

    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            // Rotate 90 degree left
            rotated_img.at<uchar>(i, j) = img1.at<uchar>(j, i);

            // Rotate Upside Down
            //rotated_img.at<uchar>(h-j-1, i) = image.at<uchar>(j, i);

            // Rotate 90 degree right
            //rotated_img.at<uchar>(i, h-j-1) = image.at<uchar>(j, i);

            value = rotated_img.at<uchar>(i, j);

            if (value < 127) rotated_img.at<uchar>(i, j) = 255 - value;
            else rotated_img.at<uchar>(i, j) = pix[rotated_img.at<uchar>(j, i)];
            // 만약 픽셀이 127보다 작으면 negative
            // 만약 픽셀이 그 외면 gamma
            // gamma는 10으로 고정
        }
    }

    // Print results and input image
    imshow("gray image", img1);
    imshow("result", rotated_img);

    waitKey(0);
    return 0;

}