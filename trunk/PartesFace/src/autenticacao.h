#ifndef AUTENTICACAO_H_
#define AUTENTICACAO_H_

#include "cadastro.h"

double faceAutenticacaoCamera0[QUANTIDADE_MEDIDAS];
double faceAutenticacaoCamera1[QUANTIDADE_MEDIDAS];

int idFaceAutorizada=-1;

bool autenticarFace( double faceAutenticacao[QUANTIDADE_MEDIDAS], double facesCadastradas[QUANTIDADE_MEDIDAS][30][QTD_FOTOS_CADASTRO], int idFace, int numeroFoto )
{
	double proporcaoZero = faceAutenticacao[0] / facesCadastradas[0][idFace][numeroFoto];

	for(int idMedida=1; idMedida < QUANTIDADE_MEDIDAS ; idMedida++)
	{
		double proporcao = faceAutenticacao[idMedida] / facesCadastradas[idMedida][idFace][numeroFoto];
		double dif = abs(proporcao - proporcaoZero);


		if( idMedida <= 5 && dif > 0.09 ){
			return false;
		}
		else if( dif > 0.9 ){
			return false;
		}
	}

	return true;
}

int getIdFaceValida( int idsFacesCadastradas )
{
	for( int idFace=0 ; idFace < idsFacesCadastradas ; idFace++ )
	{
		for( int numeroFoto=0 ; numeroFoto < QTD_FOTOS_CADASTRO ; numeroFoto++ )
		{
			bool isFaceValidaCamera0 = autenticarFace( faceAutenticacaoCamera0, facesCadastradasCamera0, idFace, numeroFoto );

			if( isFaceValidaCamera0 )
			{
				bool isFaceValidaCamera1 = autenticarFace( faceAutenticacaoCamera1, facesCadastradasCamera1, idFace, numeroFoto );

				if( isFaceValidaCamera1 ){
					return idFace;
				}
			}
		}
	}

	return -1;
}

#endif
