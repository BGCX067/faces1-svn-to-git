#ifndef FACE_H_
#define FACE_H_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

struct Face {
	Rect rosto;
	Rect olhoEsquerdo;
	Rect olhoDireito;
	Rect nariz;
	Rect boca;
	bool isCompleta;
};

#endif
