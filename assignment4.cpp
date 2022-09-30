// 21900262 박경륜
// computer vision (02)

// assignment 4
// Read an image “moon.png” as gray scale image•Perform histogram equalization on the input image
// •Display each image with the window name as “before”, “after
// •Display histogram of the inputand the result image•Set the number of bins as 16
// •Set the matrix size for displaying histogram as width : 512, height : 512
// •Display each image with the window name as “h1”, “h2”
// •Compute normalized histogramand display each element of the histogram on the image(‘before’, ‘after’)
// •Set the number of bins as 8
// •You can arbitrarily set the font, fontsize, color, and position of the text
/*
#include "cv.hpp"
#include <iostream>
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

Mat drawHistogram(Mat src) {
    Mat hist, histimage;

    // establish the number of bins
    int i, hist_w, hist_h, bin_w, histSize;

    float range[] = { 0, 256 };
    const float* histRange = { range };

    hist_w = 512;
    hist_h = 512;
    histSize = 16;
    bin_w = cvRound((double)hist_w / histSize);

    // draw the histogram
    histimage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    // compute histograms
    // &src input image, 1: # of src image, 0: # of channels numerated from 0 ~ channels()-1, Mat(): optional mask
    // hist: output histogram, 1: histogram dimension, &histSize: array of histogram size,  &histRange: array of histogram’s boundaries
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // Fit the histogram to [0, histImage.rows]
    // hist: input Mat, hist: output Mat, 0: lower range boundary of range normalization, histImage.rows: upper range boundary
    // NORM_MINMAX: normalization type, -1: when negative, the ouputarray has the same type as src, Mat(): optional mask
    normalize(hist, hist, 0, histimage.rows, NORM_MINMAX, -1, Mat());
    for (i = 0; i < histSize; i++) {
        rectangle(histimage, Point(bin_w * i, hist_h), Point(bin_w * i + hist_w / histSize, hist_h - cvRound(hist.at<float>(i))), Scalar(0, 0, 0), -1);
    }

    return histimage;
}

void printHistogram(Mat src) {
    // establish the number of bins
    int i,histSize;

    float range[] = { 0, 256 };
    const float* histRange = { range };

    histSize = 8;

    // draw the histogram
    Mat hist = src.clone();
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);
    normalize(hist, hist, 0, hist.rows, NORM_MINMAX, -1, Mat());

    for (i = 1; i <= histSize; i++) {
        putText(src, format("bin %d : %f", i, hist.cols - hist.at<float>(i - 1)), Point(0, i * 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 2);
    }
}

int main() {
    Mat before, after;
    Mat hist_before, hist_after;
    Mat out, out2;

    int histSize = 8;

    // read grey scale image
    before = imread("moon.png", 0);
    if (!before.data) exit(1); // Check Image

    // Histogram Equalization
    equalizeHist(before, after);

    hist_before = drawHistogram(before);
    hist_after = drawHistogram(after);

    printHistogram(before);
    printHistogram(after);


    imshow("before", before);
    imshow("after", after);

    imshow("h1", hist_before);
    imshow("h2", hist_after);
    waitKey(0);
    return 0;

}

*/