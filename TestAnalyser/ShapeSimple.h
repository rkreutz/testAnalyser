#pragma once
#ifndef SHAPESIMPLE_H
#define SHAPESIMPLE_H

#include <iostream>

#ifndef OPENCV_LIB
#define OPENCV_LIB

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui_c.h"

#endif	/*OPENCV_LIB*/

#define TEXT_FONT 5
#define TEXT_SCALE 2.3
#define TEXT_THICKNESS 2
#define LETTER_HEIGHT 35
#define LETTER_WIDTH 34
#define LETTER_DIST_BORDER 7

class ShapeSimple
{
private:
	// Regiao de controle e teste.
	cv::Rect control, test;
	// Cor das bordas.
	cv::Scalar bordersColor;
	// Tamanho das bordas.
	int bordersSize;
	// Imagem das bordas.
	cv::Mat borders;
	// Ponto em que a letra C ou T serao escritos.
	cv::Point C,T;
public:
	//Constructors and Destructor
	ShapeSimple(void);
	ShapeSimple(std::vector<cv::Point> _cr, std::vector<cv::Point> _tr);	//_cr = control region; _tr = test region;
	ShapeSimple(const ShapeSimple &src);

	virtual ~ShapeSimple(void);

	// Operacoes diversas.
	ShapeSimple &operator= (ShapeSimple &src);
	friend std::ostream& operator<< (std::ostream& out,const ShapeSimple &src);
	cv::Point meanPoint(std::vector<cv::Point> point);
	inline bool isEmpty() { return (control.area() == 0 || test.area() == 0); };

	// Manipulacao de regioes.
	bool createRegions(std::vector<cv::Point> _cr, std::vector<cv::Point> _tr);	//_cr = control region; _tr = test region;
	bool createRegions(std::vector<cv::Point> region);
	void deleteRegions();
	void swapRegions();

	// Funcoes para imprimir a borda.
	bool prepareImage(const cv::Mat &image, bool withText = true);
	bool printBorders(cv::Mat &image, cv::Mat &dst);
	
	// Funcoes 'get'
	inline const cv::Scalar getBorderColor() {return bordersColor;};
	inline const int getBorderSize() {return bordersSize;};
	inline const cv::Rect getTestRegion() {return test;};
	inline const cv::Rect getControlRegion() {return control;};
	inline const cv::Mat getBordersImage() {return borders;};

	// Funcoes de customizacao.
	void setBordersAspect(cv::Scalar color, int size);
	
	// Variaveis para cariacao de regioes.
	std::vector<cv::Point> region;
	cv::Mat mask, auxiliar;
};

#endif //SHAPESIMPLE_H