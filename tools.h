#ifndef _OPENCV3_TOOLS_H_
#define _OPENCV3_TOOLS_H_

#ifdef __cplusplus
#include <opencv2/opencv.hpp>


extern "C" {
#endif

#include "./core.h"

bool CoverWithTransparentImage(Mat roi, Mat cover, double scale);

#ifdef __cplusplus
}
#endif

#endif //_OPENCV3_TOOLS_H
