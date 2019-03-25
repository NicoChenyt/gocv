
#include "tools.h"

bool CoverWithTransparentImage(Mat roi, Mat cover, double scale) {
    if (roi->channels() != 3 || cover->channels() != 4) {
        return true;
    }
    if (roi->size() != cover->size()) {
        return false;
    }
    if (scale < 0.01) {
        return false;
    }
    std::vector<cv::Mat> scr_channels;
    std::vector<cv::Mat> dstt_channels;
    split(*cover, scr_channels);
    split(*roi, dstt_channels);

    if (scale < 1) {
        scr_channels[3] *= scale;
        scale = 1;
    }
    for (int i = 0; i < 3; i++) {
        dstt_channels[i] = dstt_channels[i].mul(255.0 / scale - scr_channels[3], scale / 255.0);
        dstt_channels[i] += scr_channels[i].mul(scr_channels[3], scale / 255.0);
    }
    merge(dstt_channels, *roi);

    return true;
}
