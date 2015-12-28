#ifndef UTIL_H_
#define UTIL_H_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

void plotarPontosFace(Mat& frame, Face face);
Point getPoint( Rect ponto, Face face );
int getSegundo();

void plotarPontosFace(Mat& frame, Face face)
{
	line(frame, getPoint(face.olhoEsquerdo,face), getPoint(face.olhoDireito,face), Scalar(255, 255, 0),4, 8, 0 );
	line(frame, getPoint(face.olhoEsquerdo,face), getPoint(face.nariz,face), Scalar(255, 255, 0),4, 8, 0 );
	line(frame, getPoint(face.olhoDireito,face), getPoint(face.nariz,face), Scalar(255, 255, 0),4, 8, 0 );
	line(frame, getPoint(face.boca,face), getPoint(face.nariz,face), Scalar(255, 255, 0),4, 8, 0 );
	line(frame, getPoint(face.boca,face), getPoint(face.olhoEsquerdo,face), Scalar(255, 255, 0),4, 8, 0 );
	line(frame, getPoint(face.boca,face), getPoint(face.olhoDireito,face), Scalar(255, 255, 0),4, 8, 0 );
}

Point getPoint( Rect ponto , Face face){
	Point center(face.rosto.x + getX(ponto) ,face.rosto.y + getY(ponto));
	return center;
}

int getSegundo(){
	time_t now = time(0);
	tm* localtm = localtime(&now);
	return localtm->tm_sec;
}


#endif
