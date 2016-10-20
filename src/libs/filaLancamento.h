#include "lancamento.h"

struct noLancamento {
       struct lancamento dado;
       struct noLancamento *prox;
};

typedef struct noLancamento* filaLancamento;

/**
 * Inicia a fila
 */
void FILA_INIT (filaLancamento *inicio,filaLancamento *fim)
{
	*inicio=NULL;
	*fim=NULL;
}

/**
 * Retorna 1 caso a lista esteja vazia
 */
int IS_EMPTY(filaLancamento *inicio, filaLancamento *fim){
	return (*inicio != 0 && *fim != 0) ? 1 : 0;
}

/**
 * Insere novo item na lista
 */
void ENQUEUE(filaLancamento *inicio, filaLancamento *fim, struct lancamento elemento)
{
	filaLancamento novo;
	// Aloca memoria par ao novo nó
	novo=(filaLancamento) malloc(sizeof(struct noLancamento));

	if (novo==NULL)
		 printf("overflow \n");
	else{
		 novo->dado=elemento;
		 novo->prox=NULL;

		if (IS_EMPTY(inicio,fim)){
			//Se a fila estiver vazia o inicio aponta para novo nó
			 *inicio = novo;
		}
		else
		{
			//Caso não esteja vazia fim->prox recebe o novo nó
			 //(*fim)->prox=novo;
		}
		//Fim aponta para novo nó
		*fim=novo;
	}
}

/**
 * Retira item da lista
 */
int DEQUEUE(filaLancamento *inicio, filaLancamento *fim, struct lancamento *elemento){
	filaLancamento aux;
	aux = *inicio;
	if (!IS_EMPTY(inicio,fim)){
		//Caso a fila nao esteja vazia pega o valor do inicio da fila
		*elemento = (*inicio)->dado;
		//O inicio apnta para o proximo item da lista
		*inicio=(*inicio)->prox;
		//se inicio for null o fim recebe null
		if(*inicio == NULL) *fim = NULL;
		free(aux);
		return(1);
	}else{
		printf("fila vazia \n");
		return(0);
	}

}



