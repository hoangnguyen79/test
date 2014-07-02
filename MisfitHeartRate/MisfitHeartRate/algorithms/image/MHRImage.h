//
//  MHRImage.h
//  MisfitHeartRate
//
//  Created by Bao Nguyen on 6/24/14.
//  Copyright (c) 2014 misfit. All rights reserved.
//

#ifndef __MisfitHeartRate__MHRImage__
#define __MisfitHeartRate__MHRImage__

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/types_c.h>
#include "MHRMatrix.h"


namespace cv {
    // print a frame to file
    bool frameToFile(const Mat& frame, const String& outFile);
    
	// convert a RGB Mat to a TSL Mat
	Mat rgb2tsl(const Mat& srcRGBmap);
    
	// convert a RGB Mat to a NTSC Mat
    // ref: http://en.wikipedia.org/wiki/YIQ
	Mat rgb2ntsc(const Mat& rgbFrame);
    
	// convert a RGB Mat to a NTSC Mat
    // ref: http://en.wikipedia.org/wiki/YIQ
	Mat ntsc2rgb(const Mat& ntscFrame);
    
    // Blur and downsample an image.  The blurring is done with
    // filter kernel specified by FILT (default = 'binom5')
    Mat blurDnClr(const Mat& src, int level);

    // Compute correlation of matrices IM with FILT, followed by
    // downsampling.  These arguments should be 1D or 2D matrices, and IM
    // must be larger (in both dimensions) than FILT.  The origin of filt
    // is assumed to be floor(size(filt)/2)+1.
    Mat corrDn(const Mat &src, const Mat &filter, int rectRow, int rectCol);
    
	// Apply Gaussian pyramid decomposition on VID_FILE from START_INDEX to END_INDEX
	// and select a specific band indicated by LEVEL.
	// GDOWN_STACK: stack of one band of Gaussian pyramid of each frame
	// the first dimension is the time axis
	// the second dimension is the y axis of the video
	// the third dimension is the x axis of the video
	// the forth dimension is the color channel
	Mat buildGDownStack(const vector<Mat>& vid, int startIndex, int endIndex, int level);
}

#endif /* defined(__MisfitHeartRate__MHRImage__) */


