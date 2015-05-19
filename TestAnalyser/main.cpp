#include "testanalyser.h"
#include <QtWidgets/QApplication>

#ifndef OPENCV_LIB
#define OPENCV_LIB

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\imgproc\imgproc_c.h>
#include <opencv2\core\core_c.h>
#include <opencv2\highgui\highgui_c.h>

#endif	/*OPENCV_LIB*/

#include "license.h"
#include "utils.h"

#define LIC 36240826

std::string error_log;
bool notification;

int main(int argc, char *argv[])
{
	if (argc == 2) {
		error_log = "error.log";
		if (strcmp(argv[1], "true") == 0)
			notification = true;
	}
	else if (argc > 2) {
		if (strcmp(argv[1], "true") == 0)
			notification = true;
		error_log = argv[2];
	}
	else {
		error_log = "error.log";
		notification = false;
	}

	QApplication a(argc, argv);
	TestAnalyser w;
	w.show();
	if (!enableKey(LIC, OS_64BIT)) {
		errorHandler("Erro", "Erro ao validar licensa do programa.", &w);
		return -1;
	}
	return a.exec();
}
