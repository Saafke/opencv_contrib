// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.

#include "precomp.hpp"

#include "opencv2/dnn_superres.hpp"

namespace cv
{
    namespace dnn
    {
        namespace dnn_superres
        {   
            Dnn_SuperResImp::Dnn_SuperResImp()
            {
                //constructor
            }

            Mat Dnn_SuperResImp::upsample(Mat img, std::string algo, int scale)
            {   
                Mat new_img;
                
                if(algo == "bilinear")
                {
                    cv::resize(img, new_img, Size(), scale, scale, 2);
                }
                else if(algo == "bicubic")
                {
                    cv::resize(img, new_img, Size(), scale, scale, 3);
                }
                else if(algo == "espcn" || algo == "lapsrn" || algo == "fsrcnn" || algo == "edsr") //neural nets
                {   
                    std::string filename_pb;
                    std::string filename_pbtxt;
                    
                    //fetch appropriate model
                    if(algo == "espcn")
                    {
                        //filename_b = ...
                        //filename_pbtxt = ...
                    }
                    else if(algo == "lapsrn")
                    {
                        
                    }
                    else if(algo == "fsrcnn")
                    {

                    }
                    else if(algo == "edsr")
                    {

                    }
                    //get blob
                    Mat blob = blobFromImage (img, 1.0);
                    //const Size &size=Size(), const Scalar &mean=Scalar(), bool swapRB=false, bool crop=false, int ddepth=CV_32F)
                    std::cout << "Made a blob. \n";
                    
                    //load net
                    Net net = readNetFromTensorflow(filename_pb, filename_pbtxt);
                    std::cout << "Made a Net. \n";
                    
                    //get prediction
                    net.setInput(blob);
                    new_img = net.forward();
                    std::cout << "Made a Prediction. \n";
                }
                else
                {
                    std::cerr << "Algorithm is not recognized. \n";
                }
                return new_img;
            }
        }
    }
}
        