// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーから使用されていない部分を除外します。
// Windows ヘッダー ファイル:
#include <windows.h>

#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif
#pragma comment(lib, "opencv_world340" CV_EXT)

// TODO: プログラムに必要な追加ヘッダーをここで参照してください
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <direct.h>

/* OpenCV関連 */
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>