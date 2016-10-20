/*
 * Tipo Lancamento
 *
 *  Created on: 02/10/2016
 */
#define MAX 200

/* declaracao dos registros */
typedef struct lancamento {
	char nomeEquipe[MAX];
	int tentativas;
	float distanciaAlvo;
	float tempoPropulsao;
	int situacao;
} lancamento;
