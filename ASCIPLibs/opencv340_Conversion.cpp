// opencv340-Conversion.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//
#include "stdafx.h"
#include "opencv340_Conversion.h"

//****************************************************************************************************
// �O���[�X�P�[���ɕϊ�
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@B_�F�o�͂Ƃ���Mat�^�摜�f�[�^
DllExport void CvtGray(cv::InputArray inputSrc_, cv::OutputArray outputSrc_)
{
	cv::Mat inputSrc = inputSrc_.getMat();
	cv::Mat outputSrc = outputSrc_.getMat();
	cv::cvtColor(inputSrc, outputSrc, CV_RGBA2GRAY);

	outputSrc.copyTo(outputSrc_);
}

//****************************************************************************************************
// �z���C�g�g�b�v�n�b�g�ϊ�
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@B_�F�o�͂Ƃ���Mat�^�摜�f�[�^�@Counts�F�c���E���k�̎��s��
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

	// ���͉摜���J���[�摜�̏ꍇ�C�O���[�X�P�[���摜�ɕϊ�����
	if (!inputSrc.type() == CV_RGB2GRAY) {
		cv::cvtColor(inputSrc, inputSrc, CV_RGB2GRAY);
	}


	outputSrc.copyTo(outputSrc_);
}
