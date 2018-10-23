#pragma once

#define DllExport   __declspec( dllexport )

#include <string>
#include <fstream>

extern "C" {
	DllExport bool checkExistanceOfFile(const std::string& str);
	DllExport bool checkExistanceOfFolder(const std::string& str);
	DllExport bool writeCSVfromMat(std::string filename, cv::InputArray inputSrc_);
	DllExport void printLog(const char log_txt[256], ...);			/* 通常ログ出力関数  */
	DllExport void printErrorLog(const char err_txt[256], ...);		/* エラーログ出力関数*/
}