#ifndef GEOMETRIA_H_
#define GEOMETRIA_H_

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int getIndexPontoMaisProximo(double xIdeal, double yIdeal, std::vector<Rect> pontosSugeridos );
double calculaDistancia( double x1, double y1, double x2, double y2);
double calculaDistancia( Rect ponto1 , Rect ponto2 );
double getX( Rect ponto );
double getY( Rect ponto );

int getIndexPontoMaisProximo(double xIdeal, double yIdeal, std::vector<Rect> pontosSugeridos )
{
	int indexMenorPonto = -1;

	if( pontosSugeridos.size() == 1 ){
		indexMenorPonto = 0;
	}
	else if( pontosSugeridos.size() > 1 ){
		int menorDistancia = INT_MAX;

		for( int i=0; i < pontosSugeridos.size() ; i++ ){
			int modulo = calculaDistancia(xIdeal , yIdeal , getX(pontosSugeridos[i]) , getY(pontosSugeridos[i]));

			if( modulo < menorDistancia ){
				menorDistancia = modulo;
				indexMenorPonto = i;
			}
		}
	}
	return indexMenorPonto;
}

double calculaDistancia( Rect ponto1 , Rect ponto2 ){
	return calculaDistancia(getX(ponto1), getY(ponto1), getX(ponto2), getY(ponto2));
}

double calculaDistancia( double x1, double y1, double x2, double y2){
	return pow( pow(x2-x1, 2) + pow(y2-y1,2) , 0.5);
}

double getX( Rect ponto ){
	return ponto.x + (ponto.width/2);
}

double getY( Rect ponto ){
	return ponto.y + (ponto.height/2);
}

#endif
