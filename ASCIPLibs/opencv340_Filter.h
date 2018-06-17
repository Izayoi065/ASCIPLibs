#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void BGR_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void Gray_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void BGR_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void Gray_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void BGR_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold);
	DllExport void Gray_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold);
};