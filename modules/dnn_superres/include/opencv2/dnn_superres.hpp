// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#ifndef _OPENCV_DNN_SUPERRES_DNN_SUPERRESIMP_HPP_
#define _OPENCV_DNN_SUPERRES_DNN_SUPERRESIMP_HPP_

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

/** @defgroup dnn_superres DNN used for super resolution
*/

namespace cv
{
    namespace dnn
    {
        namespace dnn_superres
        {
            //! @addtogroup dnn_superres
            //! @{
            class CV_EXPORTS Dnn_SuperResImp
            {
                public:
                    Dnn_SuperResImp();
                    Mat upsample(Mat img, std::string algo, int scale);
            };
            //! @}
        }
    }
}
#endif