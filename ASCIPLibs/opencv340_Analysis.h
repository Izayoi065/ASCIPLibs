#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void CvtDoDFTImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtDoIDFTImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtShiftImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtgenMagImage(cv::InputArray A_, cv::OutputArray dest_);
}