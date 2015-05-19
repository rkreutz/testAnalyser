#ifndef TESTANALYSER_H
#define TESTANALYSER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtCore/qtimer.h>
#include <qfiledialog.h>
#include "ui_testanalyser.h"

#include "opencv.h"
#include "ShapeSimple.h"
#include <sstream>

class TestAnalyser : public QMainWindow
{
	Q_OBJECT

public:
	TestAnalyser(QWidget *parent = 0);
	~TestAnalyser();
signals:
	

private slots:
	void setDevice1();
	void setDevice2();
	void setDevice3();
	void setDevice4();
	void setDevice5();

	void showCamera();
	void closeCamera();

	void startRec();
	void showFrame();
	void selectRegions();
	void resetRegions();
	void analyseRegions();

	void loadImage();

	void TESTE();

private:
	Ui::TestAnalyserClass ui;

	void createDeviceMenu();

	QMenu *deviceMenu;
	QActionGroup *devices;
	QAction *device1;
	QAction *device2;
	QAction *device3;
	QAction *device4;
	QAction *device5;
	QAction *cameraOn;
	QAction *cameraOff;

	cv::VideoCapture camera;
	cv::Mat img;
	cv::Mat img_HSV;
	cv::Mat img_display;

	QTimer *timer;

	ShapeSimple shape;

	int maxH = 255, minH = 0, maxS = 255, minS = 0, maxV = 255, minV = 0;

public:
	const cv::VideoCapture *getCamera() { return &camera; }
};

#endif // TESTANALYSER_H
