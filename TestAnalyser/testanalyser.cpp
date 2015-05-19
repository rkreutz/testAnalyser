#include "testanalyser.h"
#include "license.h"
#include "utils.h"
#include "callbacks.h"

TestAnalyser::TestAnalyser(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	createDeviceMenu();

	timer = new QTimer(this);
	shape.setBordersAspect(cv::Scalar(-255, 255, -255), 3);
}

TestAnalyser::~TestAnalyser()
{
	delete devices, deviceMenu, cameraOn, cameraOff, timer;
	if (device1)
		delete device1;
	if (device2)
		delete device2;
	if (device3)
		delete device3;
	if (device4)
		delete device4;
	if (device5)
		delete device5;
	camera.release();
	cv::destroyAllWindows();
}

void TestAnalyser::createDeviceMenu()
{
	std::vector<std::string> devicesName = camera.listDevices();
	devices = new QActionGroup(this);
	deviceMenu = menuBar()->addMenu(tr("Cameras"));

	device1 = device2 = device3 = device4 = device5 = NULL;
	
	if (devicesName.size() > 0) {
		device1 = new QAction(tr(devicesName[0].c_str()), this);
		device1->setCheckable(true);
		device1->setChecked(false);
		connect(device1, SIGNAL(changed()), this, SLOT(setDevice1()));
		devices->addAction(device1);
	}
	
	if (devicesName.size() > 1) {
		device2 = new QAction(tr(devicesName[1].c_str()), this);
		device2->setCheckable(true);
		device2->setChecked(false);
		connect(device2, SIGNAL(changed()), this, SLOT(setDevice2()));
		devices->addAction(device2);
	}

	if (devicesName.size() > 2) {
		device3 = new QAction(tr(devicesName[2].c_str()), this);
		device3->setCheckable(true);
		device3->setChecked(false);
		connect(device3, SIGNAL(changed()), this, SLOT(setDevice3()));
		devices->addAction(device3);
	}
	
	if (devicesName.size() > 3) {
		device4 = new QAction(tr(devicesName[3].c_str()), this);
		device4->setCheckable(true);
		device4->setChecked(false);
		connect(device4, SIGNAL(changed()), this, SLOT(setDevice4()));
		devices->addAction(device4);
	}

	if (devicesName.size() > 4) {
		device5 = new QAction(tr(devicesName[4].c_str()), this);
		device5->setCheckable(true);
		device5->setChecked(false);
		connect(device5, SIGNAL(changed()), this, SLOT(setDevice5()));
		devices->addAction(device5);
	}
	deviceMenu->addActions(devices->actions());
	
	deviceMenu->addSeparator();

	cameraOn = new QAction(tr("Visualizar"), this);
	cameraOn->setIcon(QIcon(QString(":/Images/cameraIcon.png")));
	cameraOn->setStatusTip(QString("Visualizar camera selecionada."));
	connect(cameraOn, SIGNAL(triggered()), this, SLOT(showCamera()));
	deviceMenu->addAction(cameraOn);

	cameraOff = new QAction(tr("Desligar Camera"), this);
	cameraOff->setIcon(QIcon(QString(":/Images/closeIcon.jpg")));
	cameraOff->setStatusTip(QString("Fecha a camera que esta sendo utilizada."));
	connect(cameraOff, SIGNAL(triggered()), this, SLOT(closeCamera()));
	deviceMenu->addAction(cameraOff);
}

void TestAnalyser::setDevice1()
{
	if (device1->isChecked())
		camera.open(0);
}

void TestAnalyser::setDevice2()
{
	if (device2->isChecked())
		camera.open(1);
}

void TestAnalyser::setDevice3()
{
	if (device3->isChecked())
		camera.open(2);
}

void TestAnalyser::setDevice4()
{
	if (device4->isChecked()) 
		camera.open(3);
}

void TestAnalyser::setDevice5()
{
	if (device5->isChecked())
		camera.open(4);
}

void TestAnalyser::showCamera()
{
	if (camera.isOpened()) {
		cv::namedWindow("Teste", CV_GUI_NORMAL);
		while (windowOpen("Teste") && camera.isOpened()) {
			camera >> img;
			cv::imshow("Teste", img);
			cv::waitKey(10);
		}
	}
	else {
		QMessageBox *erro = new QMessageBox;
		erro->warning(this, "Erro", "Por favor, selecione uma\ncamera antes de visualiza-la.", QMessageBox::Ok | QMessageBox::Default);
		delete erro;
	}
}

void TestAnalyser::closeCamera()
{
	if (camera.isOpened()) {
		if (devices->checkedAction())
			devices->checkedAction()->setChecked(false);
		cv::destroyAllWindows();

		disconnect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
		ui.label->clear();
		ui.label->show();
		camera.release();
	}
}

void TestAnalyser::startRec()
{
	if (camera.isOpened()) {
		connect(timer, SIGNAL(timeout()), this, SLOT(showFrame()));
		timer->start(1);
		camera >> img;
		shape.prepareImage(img);
	}
	else {
		QMessageBox *erro = new QMessageBox;
		erro->warning(this, "Erro", "Por favor, selecione uma\ncamera antes de visualiza-la.", QMessageBox::Ok | QMessageBox::Default);
		delete erro;
	}
}

void TestAnalyser::showFrame() 
{
	if (camera.isOpened())
		camera >> img;
	shape.printBorders(img, img_display);
	cv::cvtColor(img_display, img_display, CV_BGR2RGB);
	ui.label->setPixmap(QPixmap::fromImage(QImage(img_display.data, img_display.cols, img_display.rows, img_display.step, QImage::Format_RGB888)));
	ui.label->show();
}

void TestAnalyser::selectRegions()
{
	if (camera.isOpened()) {
		cv::namedWindow("Regioes", CV_GUI_NORMAL | CV_WINDOW_FREERATIO);
		camera >> img;
		cv::Mat show = cv::Mat::zeros(img.rows, img.cols, img.type());
		shape.prepareImage(img);
		cv::setMouseCallback("Regioes", drawingRegion, (void*)&shape);
		cv::displayOverlay("Regioes", "Click esquerdo - indica um ponto do contorno.\nClick direito - finaliza o contorno e conecta ao inicio.");
		while (shape.isEmpty() && camera.isOpened()) {
			cv::add(img, shape.mask, show);
			cv::imshow("Regioes", show);
			cv::waitKey(10);
			camera >> img;
		}
		shape.prepareImage(img);
		shape.printBorders(img, img_display);
		cv::imshow("Regioes", img);
		cv::waitKey(500);
		cv::destroyAllWindows();
	}
	else if (img.cols != 0 && img.rows != 0) {
		cv::namedWindow("Regioes", CV_GUI_NORMAL | CV_WINDOW_FREERATIO);
		cv::Mat show = cv::Mat::zeros(img.rows, img.cols, img.type());
		shape.prepareImage(img);
		cv::setMouseCallback("Regioes", drawingRegion, (void*)&shape);
		cv::displayOverlay("Regioes", "Click esquerdo - indica um ponto do contorno.\nClick direito - finaliza o contorno e conecta ao inicio.\nPrimeiro contorno -> controle         Segundo contorno -> teste");
		while (shape.isEmpty()) {
			cv::add(img, shape.mask, show);
			cv::imshow("Regioes", show);
			cv::waitKey(10);
		}
		shape.prepareImage(img);
		shape.printBorders(img, img_display);
		cv::imshow("Regioes", img_display);
		cv::waitKey(500);
		cv::destroyAllWindows();
		cv::cvtColor(img_display, img_display, CV_BGR2RGB);
		ui.label->setPixmap(QPixmap::fromImage(QImage(img_display.data, img_display.cols, img_display.rows, img_display.step, QImage::Format_RGB888)));
		ui.label->show();
	}
	else {
		QMessageBox *erro = new QMessageBox;
		erro->warning(this, "Erro", "Por favor, selecione uma camera\nou imagem antes de marcar as regioes.", QMessageBox::Ok | QMessageBox::Default);
		delete erro;
	}
}

void TestAnalyser::resetRegions()
{
	shape.deleteRegions();
	shape.prepareImage(img);
	shape.printBorders(img, img_display);
	cv::cvtColor(img_display, img_display, CV_BGR2RGB);
	ui.label->setPixmap(QPixmap::fromImage(QImage(img_display.data, img_display.cols, img_display.rows, img_display.step, QImage::Format_RGB888)));
	ui.label->show();
}

void TestAnalyser::analyseRegions()
{
	if (shape.isEmpty() || (!camera.isOpened() && img.cols == 0 && img.rows == 0)) {
		QMessageBox *erro = new QMessageBox;
		erro->warning(this, "Erro", "Por favor, certifique-se de que uma camera ou imagem\nfoi selecionada corretamente e as regioes criadas.", QMessageBox::Ok | QMessageBox::Default);
		delete erro;
		return;
	}

	timer->stop();

	std::vector<cv::Mat> control, test, pictures;
	int PICTURES_TAKEN = 1;

	if (camera.isOpened()) {
		for (int x = 0; x < PICTURES_TAKEN; x++) {
			pictures.push_back(img.clone());
			Sleep(20);
			camera >> img;
		}

		for (int x = 0; x < PICTURES_TAKEN; x++) {
			control.push_back(pictures[x].colRange(shape.getControlRegion().x, shape.getControlRegion().br().x));
			control[x] = control[x].rowRange(shape.getControlRegion().y, shape.getControlRegion().br().y);
			test.push_back(pictures[x].colRange(shape.getTestRegion().x, shape.getTestRegion().br().x));
			test[x] = test[x].rowRange(shape.getTestRegion().y, shape.getTestRegion().br().y);
		}

	}
	else {
		PICTURES_TAKEN = 1;

		control.push_back(img.colRange(shape.getControlRegion().x, shape.getControlRegion().br().x));
		control[0] = control[0].rowRange(shape.getControlRegion().y, shape.getControlRegion().br().y);
		test.push_back(img.colRange(shape.getTestRegion().x, shape.getTestRegion().br().x));
		test[0] = test[0].rowRange(shape.getTestRegion().y, shape.getTestRegion().br().y);
	}

	if ((control.empty() || test.empty()) && (control.size() < PICTURES_TAKEN || test.size() < PICTURES_TAKEN)) {
		notificationHandler(var2str(command()), "Imagens carregadas da camera estao vazias ou ha menos do que deveria.");
		QMessageBox *erro = new QMessageBox;
		erro->warning(this, "Erro", "Imagens carregadas da camera estao\nvazias ou ha menos do que deveria.", QMessageBox::Ok | QMessageBox::Default);
		delete erro;
		return;
	}

	cv::Mat binC, binT;
	binC = 255 * cv::Mat::zeros(control[0].rows, control[0].cols, CV_8UC1);
	binT = 255 * cv::Mat::zeros(test[0].rows, test[0].cols, CV_8UC1);
	std::vector<cv::Point> match;
	match.push_back(cv::Point(0, 0));
	match.push_back(cv::Point(0, 15));
	match.push_back(cv::Point(5, 15));
	match.push_back(cv::Point(5, 0));
	match.push_back(cv::Point(0, 0));

	for (int x = 0; x < PICTURES_TAKEN; x++) {
		std::vector<int> values = { minH, minS, minV, maxH, maxS, maxV };//{152, 20, 153, 182, 48, 217};
		cv::Mat tempColor, tempGray, tempReg;
		filter_strip(control[x], tempColor, 5, 9);
		cv::cvtColor(tempColor, tempColor, CV_BGR2HSV);
		region_custom(tempColor, tempReg, values, 10, 5);
		cv::bitwise_or(tempReg, binC, binC);
		filter_strip(test[x], tempColor, 5, 9);
		cv::cvtColor(tempColor, tempColor, CV_BGR2HSV);
		region_custom(tempColor, tempReg, values, 10, 5);
		cv::bitwise_or(tempReg, binT, binT);
	}
	cv::Mat temp1, temp2;
	cv::cvtColor(binT, temp1, CV_GRAY2BGR);
	cv::cvtColor(binC, temp2, CV_GRAY2BGR);
	cv::add(temp1, test[0], temp1);
	cv::add(temp2, control[0], temp2);
	imshow("Controle", temp2);
	imshow("Teste", temp1);

	std::vector<double> rel, mean_cv;
	for (int x = 0; x < PICTURES_TAKEN; x++)
		rel.push_back(relation(control[x], binC, test[x], binT));
	mean_cv = meanAndCv(rel);
	std::stringstream stream;
	if (mean_cv[1] < (double)4)
		//cout << Ax*mean_cv[0] + Bx << endl;
		stream << mean_cv[0] << std::endl;
	else
		stream << "O teste nao foi bem sucedido, tire uma nova foto.\n";

	QMessageBox *erro = new QMessageBox;
	erro->warning(this, "Analise", stream.str().c_str(), QMessageBox::Ok | QMessageBox::Default);
	delete erro;

	rel.clear();
	mean_cv.clear();
	control.clear();
	test.clear();
	pictures.clear();

	timer->start();
}

void TestAnalyser::loadImage()
{
	std::string file = QFileDialog::getOpenFileName(this, tr("Abrir Imagem"), QString(), tr("Image Files (*.png *.jpg *.bmp)")).toLocal8Bit().constData();

	img = cv::imread(file, CV_LOAD_IMAGE_UNCHANGED);

	shape.prepareImage(img);
	shape.printBorders(img, img_display);
	cv::cvtColor(img_display, img_display, CV_BGR2RGB);
	ui.label->setPixmap(QPixmap::fromImage(QImage(img_display.data, img_display.cols, img_display.rows, img_display.step, QImage::Format_RGB888)));
	ui.label->show();
}

void TestAnalyser::TESTE() 
{
	cv::namedWindow("Comando");
	cv::createTrackbar("minH", "Comando", &minH, 255);
	cv::createTrackbar("maxH", "Comando", &maxH, 255);
	cv::createTrackbar("minS", "Comando", &minS, 255);
	cv::createTrackbar("maxS", "Comando", &maxS, 255);
	cv::createTrackbar("minV", "Comando", &minV, 255);	
	cv::createTrackbar("maxV", "Comando", &maxV, 255);
	cv::Mat	dummy = cv::Mat::zeros(1, 50, CV_8UC1);
	cv::imshow("Comando", dummy);

	filter_strip(img, img_HSV, 5, 9);
	cv::cvtColor(img_HSV, img_HSV, CV_BGR2HSV);
	cv::Mat bin;

	while (windowOpen("Comando")) {
		cv::inRange(img_HSV, cv::Scalar(minH, minS, minV), cv::Scalar(maxH, maxS, maxV), bin);
		if (bin.type() == CV_8UC1)
			cv::cvtColor(bin, bin, CV_GRAY2BGR);
		cv::addWeighted(img, 0.6, bin, 0.4, 0, img_display);
		shape.prepareImage(img_display);
		cv::Mat img_display2;
		shape.printBorders(img_display, img_display2);
		cv::cvtColor(img_display2, img_display2, CV_BGR2RGB);
		ui.label->setPixmap(QPixmap::fromImage(QImage(img_display2.data, img_display2.cols, img_display2.rows, img_display2.step, QImage::Format_RGB888)));
		ui.label->show();
		cv::waitKey(30);
	}

	cv::destroyAllWindows();
}