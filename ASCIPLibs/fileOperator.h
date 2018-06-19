#pragma once

#define DllExport   __declspec( dllexport )

#include<string>

extern "C" {
	DllExport bool checkFileExistance(const std::string& str);

}