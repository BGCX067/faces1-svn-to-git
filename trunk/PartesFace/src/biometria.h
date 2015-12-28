#ifndef BIOMETRIA_H_
#define BIOMETRIA_H_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "geometria.h"

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier nose_cascade;
CascadeClassifier mouth_cascade;

Face capturarFace(Mat frame, int idCamera)
{
	Face face;
	face.isCompleta = false;

	Mat frame_gray;
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	std::vector<Rect> faces;
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2,0 | CV_HAAR_SCALE_IMAGE, Size(1, frame_gray.rows * 0.3));

	if( faces.size() > 0 )
	{
		face.rosto = faces[0];
		Mat faceROI = frame_gray(face.rosto);

		std::vector<Rect> narizes;
		nose_cascade.detectMultiScale(faceROI, narizes, 1.1, 2,0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		int index = getIndexPontoMaisProximo( face.rosto.width/2 , face.rosto.height/2 , narizes );

		if( index > -1 )
		{
			face.nariz = narizes[index];

			std::vector<Rect> olhos;
			eyes_cascade.detectMultiScale(faceROI, olhos, 1.1, 2,0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

			index = getIndexPontoMaisProximo( face.rosto.width/4 , face.rosto.height/4, olhos );
			int index2 = getIndexPontoMaisProximo( face.rosto.width * (3.0/4.0) , face.rosto.height/4, olhos );

			if( index != index2 && index > -1 && index2 > -1 )
			{
				face.olhoEsquerdo = olhos[index];
				face.olhoDireito = olhos[index2];

				std::vector<Rect> bocas;
				mouth_cascade.detectMultiScale(faceROI, bocas, 1.1, 2,0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

				index = getIndexPontoMaisProximo( face.rosto.width/2 , face.rosto.height * (3.0/4), bocas );

				if( index > -1 && getY(bocas[index]) > (face.nariz.y+face.nariz.height))
				{
					face.boca = bocas[index];
					face.isCompleta = true;
					return face;
				}
			}
		}
	}
	return face;
}


#endif
