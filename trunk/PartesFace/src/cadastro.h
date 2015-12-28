#ifndef CADASTRO_H_
#define CADASTRO_H_

#define QTD_FOTOS_CADASTRO 10
#define QUANTIDADE_MEDIDAS 16

double facesCadastradasCamera0[QUANTIDADE_MEDIDAS][30][QTD_FOTOS_CADASTRO];
double facesCadastradasCamera1[QUANTIDADE_MEDIDAS][30][QTD_FOTOS_CADASTRO];

int contadorFacesCadastradas = 0;
int numeroFotoCadastro = 0;
bool cadastroAtivado = false;

void cadastrarFoto( int idFace, int numeroFoto, Face face, double facesCadastradas[QUANTIDADE_MEDIDAS][30][QTD_FOTOS_CADASTRO])
{
	facesCadastradas[0][idFace][numeroFoto] = calculaDistancia( face.olhoDireito , face.olhoEsquerdo );
	facesCadastradas[1][idFace][numeroFoto] = calculaDistancia( face.olhoEsquerdo , face.nariz );
	facesCadastradas[2][idFace][numeroFoto] = calculaDistancia( face.olhoDireito , face.nariz );
	facesCadastradas[3][idFace][numeroFoto] = calculaDistancia( face.nariz , face.boca );
	facesCadastradas[4][idFace][numeroFoto] = calculaDistancia( face.olhoDireito , face.boca );
	facesCadastradas[5][idFace][numeroFoto] = calculaDistancia( face.olhoEsquerdo , face.boca );

	facesCadastradas[6][idFace][numeroFoto] = face.olhoDireito.width;
	facesCadastradas[7][idFace][numeroFoto] = face.olhoDireito.height;
	facesCadastradas[8][idFace][numeroFoto] = face.olhoEsquerdo.width;
	facesCadastradas[9][idFace][numeroFoto] = face.olhoEsquerdo.height;
	facesCadastradas[10][idFace][numeroFoto] = face.nariz.width;
	facesCadastradas[11][idFace][numeroFoto] = face.nariz.height;
	facesCadastradas[12][idFace][numeroFoto] = face.boca.width;
	facesCadastradas[13][idFace][numeroFoto] = face.boca.height;
	facesCadastradas[14][idFace][numeroFoto] = face.rosto.width;
	facesCadastradas[15][idFace][numeroFoto] = face.rosto.height;
}

void cadastrarFotoAutenticacao( Face face, double faceAutenticacao[QUANTIDADE_MEDIDAS])
{
	faceAutenticacao[0] = calculaDistancia( face.olhoDireito , face.olhoEsquerdo );
	faceAutenticacao[1] = calculaDistancia( face.olhoEsquerdo , face.nariz );
	faceAutenticacao[2] = calculaDistancia( face.olhoDireito , face.nariz );
	faceAutenticacao[3] = calculaDistancia( face.nariz , face.boca );
	faceAutenticacao[4] = calculaDistancia( face.olhoDireito , face.boca );
	faceAutenticacao[5] = calculaDistancia( face.olhoEsquerdo , face.boca );

	faceAutenticacao[6] = face.olhoDireito.width;
	faceAutenticacao[7] = face.olhoDireito.height;
	faceAutenticacao[8] = face.olhoEsquerdo.width;
	faceAutenticacao[9] = face.olhoEsquerdo.height;
	faceAutenticacao[10] = face.nariz.width;
	faceAutenticacao[11] = face.nariz.height;
	faceAutenticacao[12] = face.boca.width;
	faceAutenticacao[13] = face.boca.height;
	faceAutenticacao[14] = face.rosto.width;
	faceAutenticacao[15] = face.rosto.height;
}

#endif
