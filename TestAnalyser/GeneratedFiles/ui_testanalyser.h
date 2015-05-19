/********************************************************************************
** Form generated from reading UI file 'testanalyser.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTANALYSER_H
#define UI_TESTANALYSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestAnalyserClass
{
public:
    QAction *actionFile;
    QAction *actionCarregar_Foto;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *analyseBtn;
    QPushButton *regionBtn;
    QPushButton *resetReg;
    QPushButton *recBtn;
    QPushButton *testeBtn;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestAnalyserClass)
    {
        if (TestAnalyserClass->objectName().isEmpty())
            TestAnalyserClass->setObjectName(QStringLiteral("TestAnalyserClass"));
        TestAnalyserClass->setWindowModality(Qt::WindowModal);
        TestAnalyserClass->resize(618, 483);
        TestAnalyserClass->setUnifiedTitleAndToolBarOnMac(true);
        actionFile = new QAction(TestAnalyserClass);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        actionCarregar_Foto = new QAction(TestAnalyserClass);
        actionCarregar_Foto->setObjectName(QStringLiteral("actionCarregar_Foto"));
        centralWidget = new QWidget(TestAnalyserClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 5);

        analyseBtn = new QPushButton(centralWidget);
        analyseBtn->setObjectName(QStringLiteral("analyseBtn"));

        gridLayout->addWidget(analyseBtn, 1, 3, 1, 1);

        regionBtn = new QPushButton(centralWidget);
        regionBtn->setObjectName(QStringLiteral("regionBtn"));

        gridLayout->addWidget(regionBtn, 1, 1, 1, 1);

        resetReg = new QPushButton(centralWidget);
        resetReg->setObjectName(QStringLiteral("resetReg"));

        gridLayout->addWidget(resetReg, 1, 2, 1, 1);

        recBtn = new QPushButton(centralWidget);
        recBtn->setObjectName(QStringLiteral("recBtn"));

        gridLayout->addWidget(recBtn, 1, 0, 1, 1);

        testeBtn = new QPushButton(centralWidget);
        testeBtn->setObjectName(QStringLiteral("testeBtn"));

        gridLayout->addWidget(testeBtn, 1, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        TestAnalyserClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestAnalyserClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 618, 21));
        menuBar->setStyleSheet(QLatin1String("background-color: rgb(240, 240, 240);\n"
"selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(215, 229, 243);"));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QStringLiteral("menuArquivo"));
        TestAnalyserClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(TestAnalyserClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestAnalyserClass->setStatusBar(statusBar);
        QWidget::setTabOrder(recBtn, regionBtn);

        menuBar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionCarregar_Foto);

        retranslateUi(TestAnalyserClass);
        QObject::connect(actionCarregar_Foto, SIGNAL(triggered()), TestAnalyserClass, SLOT(loadImage()));
        QObject::connect(testeBtn, SIGNAL(clicked()), TestAnalyserClass, SLOT(TESTE()));
        QObject::connect(analyseBtn, SIGNAL(clicked()), TestAnalyserClass, SLOT(analyseRegions()));
        QObject::connect(recBtn, SIGNAL(clicked()), TestAnalyserClass, SLOT(startRec()));
        QObject::connect(resetReg, SIGNAL(clicked()), TestAnalyserClass, SLOT(resetRegions()));
        QObject::connect(regionBtn, SIGNAL(clicked()), TestAnalyserClass, SLOT(selectRegions()));

        QMetaObject::connectSlotsByName(TestAnalyserClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestAnalyserClass)
    {
        TestAnalyserClass->setWindowTitle(QApplication::translate("TestAnalyserClass", "Analisador de Testes Rapidos", 0));
        actionFile->setText(QApplication::translate("TestAnalyserClass", "File", 0));
        actionCarregar_Foto->setText(QApplication::translate("TestAnalyserClass", "Carregar Foto", 0));
        label->setText(QString());
        analyseBtn->setText(QApplication::translate("TestAnalyserClass", "Analizar", 0));
        regionBtn->setText(QApplication::translate("TestAnalyserClass", "Regioes", 0));
        resetReg->setText(QApplication::translate("TestAnalyserClass", "Resetar Regioes", 0));
        recBtn->setText(QApplication::translate("TestAnalyserClass", "Filmar", 0));
        testeBtn->setText(QApplication::translate("TestAnalyserClass", "Ajuste Manual", 0));
        menuArquivo->setTitle(QApplication::translate("TestAnalyserClass", "Arquivo", 0));
    } // retranslateUi

};

namespace Ui {
    class TestAnalyserClass: public Ui_TestAnalyserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTANALYSER_H
