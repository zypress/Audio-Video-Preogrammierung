#ifndef COLORKEYER_H
#define COLORKEYER_H

#include "videoengine.h"

namespace Ui {
class ColorKeyer;
}

class ColorKeyer : public VideoProcessor
{
    public:
        ColorKeyer();
        void startProcessing(const VideoFormat& format){}
        cv::Mat process(const cv::Mat&source);
        void setOffset(int offset);
    private:
};

#endif // COLORKEYER_H
