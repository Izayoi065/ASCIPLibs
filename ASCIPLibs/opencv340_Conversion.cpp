// opencv340-Conversion.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//
#include "stdafx.h"
#include "opencv340_Conversion.h"

/* グレースケール変換 */
DllExport void CvtGray(cv::InputArray inputSrc_, cv::OutputArray outputSrc_)
{
	cv::Mat inputSrc = inputSrc_.getMat();
	cv::Mat outputSrc = outputSrc_.getMat();
	cv::cvtColor(inputSrc, outputSrc, CV_RGBA2GRAY);

	outputSrc.copyTo(outputSrc_);
}

/* ホワイトトップハット処理 */
DllExport void CvtWhiteTop_Hat(cv::InputArray inputSrc_, cv::OutputArray outputSrc_, int Counts)
{
	cv::Mat inputSrc = inputSrc_.getMat();
	cv::Mat outputSrc = outputSrc_.getMat();
	cv::Mat temp, temp2;

	cv::erode(inputSrc, temp, cv::Mat(), cv::Point(-1, -1), Counts);
	cv::dilate(temp, temp2, cv::Mat(), cv::Point(-1, -1), Counts);
	cv::absdiff(inputSrc, temp2, outputSrc);

	outputSrc.copyTo(outputSrc_);
}

DllExport void CvtBlackTop_Hat(cv::InputArray inputSrc_, cv::OutputArray outputSrc_, int Counts)
{
	cv::Mat inputSrc = inputSrc_.getMat();
	cv::Mat outputSrc = outputSrc_.getMat();
	cv::Mat temp, temp2;

	cv::dilate(inputSrc, temp, cv::Mat(), cv::Point(-1, -1), Counts);
	cv::erode(temp, temp2, cv::Mat(), cv::Point(-1, -1), Counts);
	cv::absdiff(inputSrc, temp2, outputSrc);

	outputSrc.copyTo(outputSrc_);
}

DllExport void CvtHighResolution(cv::InputArray inputSrc_, cv::OutputArray outputSrc_)
{
	cv::Mat inputSrc = inputSrc_.getMat();
	cv::Mat outputSrc = outputSrc_.getMat();

	// 入力画像がカラー画像の場合，グレースケール画像に変換する
	if (!inputSrc.type() == CV_RGB2GRAY) {
		cv::cvtColor(inputSrc, inputSrc, CV_RGB2GRAY);
	}


	outputSrc.copyTo(outputSrc_);
}
