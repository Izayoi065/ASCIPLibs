#include "stdafx.h"
#include "fileOperator.h"

DllExport bool checkFileExistance(const std::string & str)
{
	std::ifstream ifs(str);
	return ifs.is_open();
}
