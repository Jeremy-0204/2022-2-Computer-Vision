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
    Mat moon, moon_filtered;
    Mat saltnpepper, saltnpepper_filtered;

    // read grey scale image
    moon = imread("moon.png", 0);
    saltnpepper = imread("saltnpepper.png", 0);

    // copy original images
    moon_filtered = moon.clone();
    saltnpepper_filtered = saltnpepper.clone();

    // calculate width, height
    int h = moon.rows;
    int w = moon.cols;

    int hs = saltnpepper.rows;
    int ws = saltnpepper.cols;

    // create ROI
    Rect rect(0, 0, w / 2, h);
    Rect rect2(0, 0, ws / 2, hs);
    Mat roi_m(moon_filtered(rect));
    Mat roi_s(saltnpepper_filtered(rect2));

    // 1.PERFORM UNSHARP MASKING
    // 1) create the blurred copy
    // 2) create gaussian filtered image
    Mat blurred;
    GaussianBlur(roi_m, roi_m, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // 3) subtract gaussian filtered image from original
    Mat sub;
    subtract(moon, moon_filtered, sub);

    // 4) add subtracted image to original
    add(moon, sub, moon_filtered);


    // 2.PERFORM MEDIAN FILTER
    medianBlur(roi_s, roi_s, 9);

    // display results
    imshow("moon", moon);
    imshow("moon_filtered", moon_filtered);

    imshow("saltnpepper", saltnpepper);
    imshow("saltnpepper_filtered", saltnpepper_filtered);

    waitKey(0);
    return 0;

}