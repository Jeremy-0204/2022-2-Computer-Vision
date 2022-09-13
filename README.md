# 2022-2-Computer-Vision
2022년 2학기 컴퓨터비전 과목의 과제 코드 저장용도 레포입니다.

# 과제 설명
## Assignment 1
### TODO
- Read a video "background.mp4"  
- Display video for the first 3 seconds  
- Find out the proper input parameter for waitKey()  
- Print out the number of the current frame and the total number of frames

### Result
![Assignment1](https://github.com/Jeremy-0204/2022-2-Computer-Vision/blob/main/Results_Screenshots/Assignment1_result1.png)
![Assignment1](https://github.com/Jeremy-0204/2022-2-Computer-Vision/blob/main/Results_Screenshots/Assignment1_result2.png)

## Assignment 2
### TODO
#### Read an image “lena.png” as a gray-scale image
> - Perform the following operations  
> - Generate a 90-degree rotated image
> - On the generated image, perform negative transformation if the pixel 

#### value is smaller than 127. Otherwise, perform gamma transformation with gamma as 10
> - Display the input and the result on two windows
> - ‘gray image’ for input
> - ‘result’ for result

### Result
![Assignment2](https://github.com/Jeremy-0204/2022-2-Computer-Vision/blob/main/Results_Screenshots/Assignment2_result.png)

## Assignment 3
### TODO
#### Read an image “moon.png” as gray scale image
> - Perform sharpening on the right-half of the image
> - Perform sharpening using unsharp masking  

#### Read an image “saltnpepper.png” as gray scale image
> - Perform median filtering on left-half of the the image
> - Set aperture size as 9 
> - medianBlur(in, out, val);
> - Blurs an image using the median filter
> - in: src, out: dst, val: aperture size(must be odd and greater than 1)

### Result
![Assignment3](https://github.com/Jeremy-0204/2022-2-Computer-Vision/blob/main/Results_Screenshots/Assignment3_result.png)
