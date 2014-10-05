#include "colorkeyer.h"

using namespace cv;

ColorKeyer::ColorKeyer()
{
}
Mat ColorKeyer::process(const Mat &input){
    Mat output(input.rows, input.cols, input.type());
    Vec3b outputPixel;
    for(int x = 0; x < input.cols; x++){
        for(int y = 0; y < input.rows; y++){
            Vec3b inputPixel = input.at<Vec3b>(y,x);
            int r = inputPixel[2];
            int g = inputPixel[1];
            int b = inputPixel[0];
            int distance = pow((r-98),2) + pow((g-41),2) + pow((b-41),2);
            if (distance < 40){
                outputPixel = (255, 255, 255);
            } else {
                outputPixel = (0, 0, 0);
            }
            output.at<Vec3b>(y,x) = outputPixel;
        }
    }
    return output;
}
