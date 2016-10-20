/*
 * pilhaPodio.h
 *
 *  Created on: 02/10/2016
 *      Author: root
 */
<<<<<<< HEAD
#include "sucesso.h"

/* declaracao do no */
struct rank
{
	struct sucesso dado;   //tipo do elemento da pilha
	struct rank *prox;
};


/*Definicao do tipo de dado pilha */
typedef struct rank* pilhaPodio;

/**
 * Inicia a pilha
 */
void PILHA_INIT(pilhaPodio *topo)
=======
#include "podio.h"

/* declaracao do no */
struct sucesso
{
	struct podio dado;   //tipo do elemento da pilha
	struct sucesso *prox;
};


/*Defini��o do tipo de dado pilha */
typedef struct sucesso* pilhaPodio;


//Fun��o que inicia a pilha
void INIT(pilhaPodio *topo)
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
{
	*topo = NULL;
}


<<<<<<< HEAD
/**
 * Verifica se o no esta vazio
 */
=======
//Verifica se o n� est� vazaio
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
int IsEmpty(pilhaPodio topo){
	return topo == NULL ? 1 : 0;
}

<<<<<<< HEAD
/**
 * Adiciona um novo no na pilha
 */
void PUSH (pilhaPodio *topo, struct sucesso elem)
=======
//Adiciona um novo v� na pilha
void PUSH (pilhaPodio *topo, struct podio elem)
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
{
pilhaPodio novo;
novo = (pilhaPodio) malloc (sizeof(struct sucesso));
if (novo != NULL)
{
	novo->dado=elem;
	novo->prox=*topo;
	*topo = novo;
}
else
	printf("pilha cheia \n");
}


<<<<<<< HEAD
/**
 * Remove um elemento da pilha
 */
int POP (pilhaPodio *topo, struct sucesso *elem)
=======
//Remove um elemento da pilha
int POP (pilhaPodio *topo, struct podio *elem)
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
{
pilhaPodio aux;
aux = *topo;
	if (!IsEmpty(*topo)) {
	     *elem=aux->dado;
	     *topo=aux->prox;
	     free(aux);
	     return(1);
	}
	else
	{
       printf("pilha vazia \n ");
       return(0);
    }
}


<<<<<<< HEAD
/**
 * LE O VALOR DO PRIMERIO ELEMENTO DA PILHA
 */
int TOP(pilhaPodio topo, struct sucesso *elem)
=======
//lE O VALOR DO PRIMERIO ELEMENTO DA PILHA
int TOP(pilhaPodio topo, struct podio *elem)
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
{
	pilhaPodio aux;
	aux = topo;
	if(!IsEmpty(topo)){
<<<<<<< HEAD
		*elem = aux->dado;
=======
		*elem = topo->dado;
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
		return(1);
	}else{
		printf("A pilha vazia ");
		return(0);
	}

}

<<<<<<< HEAD
/**
 * Imprime todos os itens da pilha
 */
//int SHOW(pilhaPodio topo, int cont){
//	int aux, val;
//	if(topo->prox != NULL){
//		printf("%d item da pilha: %d", cont, val) ;
//		SHOW(topo->prox, cont + 1);
//	}
//	return 0;
//}
=======
int SHOW(pilhaPodio topo, int cont){
	int aux, val;
	if(topo->prox != NULL){
		printf("%d item da pilha: %d", cont, val) ;
		SHOW(topo->prox, cont + 1);
	}
	return 0;
}
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92



