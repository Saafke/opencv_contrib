// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#ifndef _OPENCV_DNN_SUPERRES_DNNSUPERRESIMPL_HPP_
#define _OPENCV_DNN_SUPERRES_DNNSUPERRESIMPL_HPP_

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/dnn.hpp"

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
            class CV_EXPORTS DnnSuperResImpl
            {   
                private:
                    Net net;
                
                public:
                    DnnSuperResImpl();
                    DnnSuperResImpl(std::string algo);
                    void setModel(std::string algo);
                    Mat upsample(Mat img, int scale);
                    Mat upsampleBilinear(Mat img, int scale);
                    Mat upsampleBicubic(Mat img, int scale);
            };
            //! @}
        }
    }
}
#endif