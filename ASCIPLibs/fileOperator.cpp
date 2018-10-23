#include "stdafx.h"
#include "fileOperator.h"

#define LOG_FILE     "LOG/log.txt"        /* ���O�f�B���N�g��(�ʏ�)  */
#define ERR_LOG_FILE "LOG/err_log.txt"    /* ���O�f�B���N�g��(�G���[)*/
#define FPSCOUNTER_QUERYPER_COUNTER        true
#define FPSCOUNTER_TIMEGETTIME             false

DllExport bool checkExistanceOfFile(const std::string & str)
{
	std::ifstream ifs(str);
	return ifs.is_open();
}

DllExport bool checkExistanceOfFolder(const std::string & str)
{
	if (_mkdir(str.c_str()) == 0)
		return true;
	else
		return false;
}

DllExport bool writeCSVfromMat(std::string filename, cv::InputArray inputSrc_)
{
	cv::Mat src_image = inputSrc_.getMat();	// ���͉摜

	std::ofstream ofs(filename);
	ofs << cv::format(src_image, cv::Formatter::FMT_CSV) << std::endl;

	return true;
}

DllExport void printLog(const char log_txt[256], ...)
{
	FILE *log_file;        /* �ʏ탍�O */
	char str[256];

	time_t timer;
	struct tm date;
	errno_t error;

	checkExistanceOfFolder("LOG");
	if (!checkExistanceOfFile(LOG_FILE))
	{
		std::ofstream stream(LOG_FILE);
		stream.close();
	}

	/* ���Ԏ擾 */
	timer = time(NULL);
	error = localtime_s(&date, &timer);
	strftime(str, sizeof(str), "[%Y/%x %H:%M:%S]\n", &date);

	/* �����񌋍� */
	strcat_s(str, log_txt);
	strcat_s(str, "\n");

	if (fopen_s(&log_file, LOG_FILE, "a+"))
	{
		std::cout << "�t�@�C�����I�[�v���ł��܂���D" << std::endl;
		printErrorLog("file open error!!\n");
		//exit(-1);
	}
	else
	{
		std::cout << "���݂̓��t�E�����������o���܂����D" << std::endl;
		fputs(str, log_file);

		fclose(log_file);
	}

	return;
}

DllExport void printErrorLog(const char err_txt[256], ...)
{
	FILE *err_log_file;    /* �ُ탍�O */
	char str[256];

	time_t timer;
	struct tm date;
	errno_t error;

	checkExistanceOfFolder("LOG");
	if (!checkExistanceOfFile(ERR_LOG_FILE))
	{
		std::ofstream stream(ERR_LOG_FILE);
		stream.close();
	}

	/* ���Ԏ擾 */
	timer = time(NULL);
	error = localtime_s(&date, &timer);
	strftime(str, sizeof(str), "[%Y/%x %H:%M:%S]\n", &date);

	/* �����񌋍� */
	strcat_s(str, err_txt);
	strcat_s(str, "\n");

	if (fopen_s(&err_log_file, ERR_LOG_FILE, "a"))
	{
		std::cout << "ERROR!" << std::endl;
		//exit(-1);
	}

	fputs(str, err_log_file);

	fclose(err_log_file);

	return;
}
