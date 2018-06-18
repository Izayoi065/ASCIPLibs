#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void CvtBGR_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void CvtGray_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void CvtBGR_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void CvtGray_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void CvtBGR_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void CvtGray_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold);
};