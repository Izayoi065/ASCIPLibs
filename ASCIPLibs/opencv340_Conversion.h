#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void CvtGray(cv::InputArray inputSrc_, cv::OutputArray outputSrc_);
	DllExport void CvtWhiteTop_Hat(cv::InputArray inputSrc_, cv::OutputArray outputSrc_, int Counts);
	DllExport void CvtBlackTop_Hat(cv::InputArray inputSrc_, cv::OutputArray outputSrc_, int Counts);
	DllExport void CvtHighResolution(cv::InputArray inputSrc_, cv::OutputArray outputSrc_);
}