#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "usb.h"
#include "face.h"
#include "biometria.h"
#include "autenticacao.h"
#include "util.h"

using namespace std;
using namespace cv;

RNG rng(12345);

Face faceCamera0, faceCamera1;

int segundoAutorizacao = 0;

int main(int argc, const char** argv)
{
	face_cascade.load("/home/rafael/programas/openCV-2.4.3/OpenCV/OpenCV-2.4.3/data/haarcascades/haarcascade_frontalface_default.xml");
	eyes_cascade.load("/home/rafael/programas/openCV-2.4.3/OpenCV/OpenCV-2.4.3/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml");
	nose_cascade.load("/home/rafael/programas/openCV-2.4.3/OpenCV/OpenCV-2.4.3/data/haarcascades/haarcascade_mcs_nose.xml");
	mouth_cascade.load("/home/rafael/programas/openCV-2.4.3/OpenCV/OpenCV-2.4.3/data/haarcascades/haarcascade_mcs_mouth.xml");

	CvCapture* camera0 = cvCaptureFromCAM(-1);

	while(true){

		Mat fotoCamera0 = cvQueryFrame(camera0);
		faceCamera0 = capturarFace(fotoCamera0,0);

		if( faceCamera0.isCompleta ){

			int segundoAtual = getSegundo();

			if( segundoAtual < segundoAutorizacao || (segundoAtual-segundoAutorizacao) >= 10 ){
				segundoAutorizacao=segundoAtual;
				abrirPorta();
			}
		}
	}

//	CvCapture* camera0 = cvCaptureFromCAM(0);
//	CvCapture* camera1 = cvCaptureFromCAM(1);
//
//	while (true)
//	{
//		char key = (char) waitKey(20);
//
//		if( key == 'c' ){
//			cadastroAtivado = true;
//		}
//		else if( key == 'z' ){
//			idFaceAutorizada=-1;
//			contadorFacesCadastradas=0;
//			numeroFotoCadastro = 0;
//		}
//		else if( key == 'l' ){
//			idFaceAutorizada=-1;
//		}
//		else if( key == 's' ){
//			break;
//		}
//
//		Mat fotoCamera0 = cvQueryFrame(camera0);
//		Mat fotoCamera1 = cvQueryFrame(camera1);
//
//		faceCamera0 = capturarFace(fotoCamera0,0);
//		faceCamera1 = capturarFace(fotoCamera1,1);
//
//		if( faceCamera0.isCompleta && faceCamera1.isCompleta )
//		{
//			if( cadastroAtivado )
//			{
//				cadastrarFoto(contadorFacesCadastradas, numeroFotoCadastro, faceCamera0, facesCadastradasCamera0);
//				cadastrarFoto(contadorFacesCadastradas, numeroFotoCadastro, faceCamera1, facesCadastradasCamera1);
//
//				plotarPontosFace(fotoCamera0, faceCamera0);
//				plotarPontosFace(fotoCamera1, faceCamera1);
//
//				numeroFotoCadastro++;
//
//				if( numeroFotoCadastro >= QTD_FOTOS_CADASTRO){
//					numeroFotoCadastro = 0;
//					cadastroAtivado = false;
//					contadorFacesCadastradas++;
//				}
//			}
//			else
//			{
//				cadastrarFotoAutenticacao(faceCamera0, faceAutenticacaoCamera0);
//				cadastrarFotoAutenticacao(faceCamera1, faceAutenticacaoCamera1);
//
//				idFaceAutorizada = getIdFaceValida( contadorFacesCadastradas );
//			}
//		}
//
//		if( idFaceAutorizada > -1 ){
//			putText(fotoCamera0, format("Face Autorizada = %d", idFaceAutorizada) , Point(25, 25), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
//			putText(fotoCamera1, format("Face Autorizada = %d", idFaceAutorizada) , Point(25, 25), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
//
//			int segundoAtual = getSegundo();
//
//			if( segundoAtual < segundoAutorizacao || (segundoAtual-segundoAutorizacao) >= 10 ){
//				segundoAutorizacao=segundoAtual;
//				abrirPorta();
//			}
//		}
//
//		imshow("Capture - Face detection 0", fotoCamera0);
//		imshow("Capture - Face detection 1", fotoCamera1);
//	}
	return 0;
}





