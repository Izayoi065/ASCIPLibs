#pragma once

#define DllExport   __declspec( dllexport )

extern "C" {
	DllExport void hello();
	DllExport int add(int a, int b);
}