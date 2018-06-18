// opencv340_Analysis.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//
#include "stdafx.h"
#include "opencv340_Analysis.h"

//****************************************************************************************************
// �t�[���G�ϊ�
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@B_�F�o�͂Ƃ���Mat�^�摜�f�[�^
DllExport void CvtFFTencodeImage(cv::InputArray A_, cv::OutputArray dest_)
{
	cv::Mat A = A_.getMat();	// ���͉摜

	cv::cvtColor(A, A, cv::COLOR_BGR2GRAY);

	cv::Mat Re_img, Im_img, Complex_img, dft_src, dft_dst, dft_dst_p, mag_img;
	std::vector<cv::Mat> mv;

	cv::Size s_size = A.size();
	Re_img = cv::Mat(s_size, CV_64F);
	Im_img = cv::Mat::zeros(s_size, CV_64F);
	Complex_img = cv::Mat(s_size, CV_64FC2);

	A.convertTo(Re_img, CV_64F);
	mv.push_back(Re_img);
	mv.push_back(Im_img);
	merge(mv, Complex_img);

	int dft_rows = cv::getOptimalDFTSize(A.rows);
	int dft_cols = cv::getOptimalDFTSize(A.cols);

	dft_src = cv::Mat::zeros(dft_rows, dft_cols, CV_64FC2);

	cv::Mat roi(dft_src, cv::Rect(0, 0, A.cols, A.rows));
	Complex_img.copyTo(roi);

	cv::dft(dft_src, dft_dst);
	CvtShiftImage(dft_dst, dft_dst);

	dft_dst.copyTo(dest_);
}

//****************************************************************************************************
// �t�t�[���G�ϊ�
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@B_�F�o�͂Ƃ���Mat�^�摜�f�[�^
DllExport void CvtFFTdecodeImage(cv::InputArray A_, cv::OutputArray dest_)
{
	cv::Mat A = A_.getMat();	// ���͉摜

	cv::Mat dft_src, idft_img;
	std::vector<cv::Mat> mv;
	double min, max;

	cv::Mat dft_dst_clone = A.clone();
	CvtShiftImage(dft_dst_clone, dft_dst_clone);

	idft(dft_dst_clone, dft_src);
	split(dft_src, mv);
	minMaxLoc(mv[0], &min, &max);
	idft_img = cv::Mat(mv[0] * 1.0 / max);

	idft_img.copyTo(dest_);
}

//****************************************************************************************************
// �摜�̓���ւ�
// A_�F���͂Ƃ���Mat�^�摜�f�[�^�@dest_�F�o�͂Ƃ���Mat�^�摜�f�[�^
DllExport void CvtShiftImage(cv::InputArray A_, cv::OutputArray dest_)
{
	cv::Mat src_image = A_.getMat();	// ���͉摜
	int cx = src_image.cols / 2, cy = src_image.rows / 2;
	cv::Mat q0(src_image, cv::Rect(0, 0, cx, cy)), q1(src_image, cv::Rect(cx, 0, cx, cy));
	cv::Mat q2(src_image, cv::Rect(0, cy, cx, cy)), q3(src_image, cv::Rect(cx, cy, cx, cy)), temp;

	q0.copyTo(temp);
	q3.copyTo(q0);
	temp.copyTo(q3);
	q1.copyTo(temp);
	q2.copyTo(q1);
	temp.copyTo(q2);

	src_image.copyTo(dest_);
}

DllExport void CvtgenMagImage(cv::InputArray A_, cv::OutputArray dest_)
{
	cv::Mat A = A_.getMat();

	cv::Mat mag_img;
	std::vector<cv::Mat> mv;
	split(A, mv);

	magnitude(mv[0], mv[1], mag_img);
	log(mag_img + 1, mag_img);
	normalize(mag_img, mag_img, 0, 1, CV_MINMAX);

	mag_img.copyTo(dest_);
}
