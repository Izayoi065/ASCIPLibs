#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void CvtFFTencodeImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtFFTdecodeImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtShiftImage(cv::InputArray A_, cv::OutputArray dest_);
	DllExport void CvtgenMagImage(cv::InputArray A_, cv::OutputArray dest_);
}