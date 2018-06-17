// opencv340-Filter.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//
#include "stdafx.h"
#include "opencv340_Filter.h"

//****************************************************************************************************
// BGR�x�[�X�̃\�[�x���t�B���^
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@B_�F�o�͂Ƃ���Mat�^�摜�f�[�^�@threshold�FBGR�̍ő�l��臒l
DllExport void BGR_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜

	cv::Mat sobel_x, sobel_y;
	cv::Mat sobel_b, sobel_g, sobel_r, sobel;

	//------------------------------B, G, R�ɕ���------------------------------
	cv::Mat channels[3];
	cv::split(src_image, channels);
	//-----------------------------B��Sobel���g�p-----------------------------
	cv::Sobel(channels[0], sobel_x, CV_32F, 1, 0);
	cv::Sobel(channels[0], sobel_y, CV_32F, 0, 1);
	sobel_b = (abs(sobel_x) + abs(sobel_y)) / 2.0;
	//-----------------------------G��Sobel���g�p-----------------------------
	cv::Sobel(channels[1], sobel_x, CV_32F, 1, 0);
	cv::Sobel(channels[1], sobel_y, CV_32F, 0, 1);
	sobel_g = (abs(sobel_x) + abs(sobel_y)) / 2.0;
	//-----------------------------R��Sobel���g�p-----------------------------
	cv::Sobel(channels[2], sobel_x, CV_32F, 1, 0);
	cv::Sobel(channels[2], sobel_y, CV_32F, 0, 1);
	sobel_r = (abs(sobel_x) + abs(sobel_y)) / 2.0;
	//--------------------------B, G, R�̍ő�l���̂�--------------------------
	sobel = max(max(sobel_b, sobel_g), sobel_r);
	cv::threshold(sobel, sobel, threshold, 255, CV_THRESH_BINARY_INV);

	sobel.copyTo(dest_);
}

DllExport void Gray_Sobel(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜

	//-----------------------------�O���[�X�P�[����-----------------------------
	cv::Mat gray_image;					// �O���[�X�P�[���摜
	cv::cvtColor(src_image, gray_image, cv::COLOR_BGR2GRAY);	// ���͉摜�̃O���[�X�P�[����

	cv::Mat sobel_x, sobel_y;
	cv::Mat sobel;

	//-------------------------------Sobel���g�p-------------------------------
	cv::Sobel(gray_image, sobel_x, CV_32F, 1, 0);
	cv::Sobel(gray_image, sobel_y, CV_32F, 0, 1);
	sobel = (abs(sobel_x) + abs(sobel_y)) / 2.0;
	cv::threshold(sobel, sobel, threshold, 255, CV_THRESH_BINARY_INV);

	sobel.copyTo(dest_);
}

DllExport void BGR_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜
	cv::GaussianBlur(src_image, src_image, cv::Size(5, 5), 0);

	//------------------------------B, G, R�ɕ���------------------------------
	cv::Mat channels[3];
	cv::split(src_image, channels);
	//-----------------------------Laplacian���g�p-----------------------------
	cv::Mat lap_b, lap_g, lap_r;
	cv::Laplacian(channels[0], lap_b, CV_32F, 3);	// B channel
	cv::Laplacian(channels[1], lap_g, CV_32F, 3);	// G channel
	cv::Laplacian(channels[2], lap_r, CV_32F, 3);	// R channel
	//--------------------------B, G, R�̍ő�l���̂�--------------------------
	cv::Mat lap_ba, lap_ga, lap_ra;
	lap_ba = abs(lap_b);
	lap_ga = abs(lap_g);
	lap_ra = abs(lap_r);
	cv::Mat lap_image = max(max(lap_ba, lap_ga), lap_ra);
	cv::threshold(lap_image, lap_image, threshold, 255, CV_THRESH_BINARY_INV);

	lap_image.copyTo(dest_);
}

DllExport void Gray_Laplacian(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜
	cv::GaussianBlur(src_image, src_image, cv::Size(5, 5), 0);

	//-----------------------------�O���[�X�P�[����-----------------------------
	cv::Mat gray_image;					// �O���[�X�P�[���摜
	cv::cvtColor(src_image, gray_image, cv::COLOR_BGR2GRAY);	// ���͉摜�̃O���[�X�P�[����

	//-------------------------------Sobel���g�p-------------------------------
	cv::Mat lap_image;
	cv::Laplacian(gray_image, lap_image, CV_32F, 3);
	abs(lap_image);
	cv::threshold(lap_image, lap_image, threshold, 255, CV_THRESH_BINARY_INV);

	lap_image.copyTo(dest_);
}

DllExport void BGR_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜
	cv:: Mat canny_image;

	//------------------------------B, G, R�ɕ���------------------------------
	cv::Mat channels[3];
	cv::split(src_image, channels);
	//------------------------------Canny���g�p-------------------------------
	cv::Mat canny_b, canny_g, canny_r;
	cv::Canny(channels[0], canny_b, threshold, 180.0, 3);
	cv::Canny(channels[1], canny_g, threshold, 180.0, 3);
	cv::Canny(channels[2], canny_r, threshold, 180.0, 3);
	//--------------------------B, G, R�̍ő�l���̂�--------------------------
	cv::bitwise_or(canny_b, canny_g, canny_image);
	cv::bitwise_or(canny_image, canny_r, canny_image);
	canny_image = canny_image;	// �����𔽓]

	canny_image.copyTo(dest_);
}

DllExport void Gray_Canny(cv::InputArray A_, cv::OutputArray dest_, int threshold)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜
	cv::Mat canny_image;

	//-----------------------------�O���[�X�P�[����-----------------------------
	cv::Mat gray_image;					// �O���[�X�P�[���摜
	cv::cvtColor(src_image, gray_image, cv::COLOR_BGR2GRAY);	// ���͉摜�̃O���[�X�P�[����
	//------------------------------Canny���g�p-------------------------------
	cv::Canny(gray_image, canny_image, threshold, 180.0, 3);
	canny_image = canny_image;	// �����𔽓]

	canny_image.copyTo(dest_);
}

