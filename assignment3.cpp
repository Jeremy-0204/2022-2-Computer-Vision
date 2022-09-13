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

    // create ROI
    Rect rect(0, 0, w / 2, h);
    Mat roi(moon_filtered(rect));


    // perform unsharp masking
    // 1. create the blurred copy
    // 2. create gaussian filtered image
    Mat blurred;
    GaussianBlur(roi, roi, Size(3, 3), 0, 0, BORDER_DEFAULT);

    // 3. subtract gaussian filtered image from original
    Mat sub;
    subtract(moon, moon_filtered, sub);

    // 4. add subtracted image to original
    add(moon, sub, moon_filtered);

    // display results
    imshow("moon", moon);
    imshow("moon_filtered", moon_filtered);

    waitKey(0);
    return 0;

}