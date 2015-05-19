#include "utils.h"

void errorHandler(std::string functionName, std::string errorInfo, TestAnalyser *parent) {
	std::ofstream file;

	if (!error_log.empty()) {
		file.open(error_log, std::ofstream::out | std::ofstream::app);

		char timeString[50];

		struct tm actual_time;
		time_t raw_time;

		time(&raw_time);

		localtime_s(&actual_time, &raw_time);

		strftime(timeString, 50, "%d/%m/%Y - %X\n", &actual_time);

		file << timeString << "\t" << functionName << std::endl << "\t\t" << errorInfo << std::endl << std::endl;

		file.close();
	}

	notificationHandler(functionName, "O programa encerrou com erro.");

	/* Printar warning e sair do programa */
	QMessageBox *erro = new QMessageBox;
	erro->warning(parent, "Erro Fatal", QString(errorInfo.c_str()), QMessageBox::Ok | QMessageBox::Default);
	delete erro;

	emit parent->close();
}

void notificationHandler(std::string functionName, std::string notificationInfo) {
	if(notification) {
		std::ofstream file(NOTIFICATION_FILE, std::ofstream::out | std::ofstream::app);

		char timeString[50];

		struct tm actual_time;
		time_t raw_time;

		time(&raw_time);

		localtime_s(&actual_time, &raw_time);

		strftime(timeString,50,"%d/%m/%Y - %X\n",&actual_time);

		file << timeString << "\t" << functionName << std::endl << "\t\t" << notificationInfo << std::endl << std::endl;

		file.close();
	}
}
