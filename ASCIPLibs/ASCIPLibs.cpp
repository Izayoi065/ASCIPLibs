// ASCIPLibs.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include "ASCIPLibs.h"

void hello() {
	std::cout << "Hello World!" << std::endl;
}

DllExport int add(int a, int b)
{
	return a + b;
}
