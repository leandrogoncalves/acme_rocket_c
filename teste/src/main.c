<<<<<<< HEAD
=======
/*
 * main.c
 *
 *  Created on: 02/10/2016
 */
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
#include <locale.h>
#include "libs/pilhaPodio.h"
#include "libs/filaLancamento.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");

    pilhaPodio pilha;
    sucesso podio, aux;
    PILHA_INIT(&pilha);

	struct lancamento  equipe;
    filaLancamento inicio, fim, aux_fila;
    FILA_INIT(&inicio, &fim);


    int limitador = 2, qtdEquipes = 0,  maxTentativas = 0, colocacao = 0, campeoes[3];
    int i ,x, j, qtdMinEquipe;
=======
#include "libs/equipes.h"
#include "libs/pilhaPodio.h"


int main()
{
    pilhaPodio pilha;
    podio podio, aux;
    INIT(&pilha);
    int qtdEquipes = 0, maxTentativas = 0, colocacao = 0, campeoes[3];
    int i ,x, j;
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
    float menorDistancia = 9999999;
    char situacao;


<<<<<<< HEAD
	printf("  ____                         _           _             \n");
	printf(" |  _ \\                       (_)         | |           \n");
	printf(" | |_) | ___ _ __ ___   __   ___ _ __   __| | ___        \n");
	printf(" |  _ < / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\ \n");
	printf(" | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) |     \n");
	printf(" |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \n");
	printf("               AO SISTEMA ACME ROCKET\n\n\n");
	



	//Pega nomes das equipes
	do{
		// Cria um novo no do tipo lancamento para inserir na lista

		equipe.tentativas = 0;
		equipe.situacao = 0;


    	printf("\n Para cadastrar uma nova equipe digite nome da equipe: ");
    	fflush(stdin);
    	fgets(equipe.nomeEquipe, MAX, stdin);


    	if(strcmp(equipe.nomeEquipe, " ") == 0 || strlen(equipe.nomeEquipe) < 3){
    		printf("\n Insira um nome v�lido para a equipe! \n");
    	}else{
        	//Insere a equipe na lista
        	ENQUEUE(&inicio, &fim, equipe);
        	printf("\n Equipe cadastrada com sucesso \n");
    	}
    	
    	printf("\n Deseja cadastrar uma nova equipe ? 1-SIM ou 2-N�o:");
		fflush(stdin);
		scanf("%d",&limitador);

    	qtdEquipes++;

    }while(limitador == 2);

	aux_fila = inicio;

		//Percorre a lsita de equipes enquanto proximo diferente de null
		 while(aux_fila->prox){
			 //Enquanto houver lancamentos pendentes
			 while(inicio->dado.tentativas <= 2 && inicio->dado.situacao == 0){

				 //M�ximo de 3 tentativas
			 	 for(x = 0 ; x < 3; x++){
			 	 	printf("\n----------------------------------------------------------------------\n");
					printf("\nQual a situacao do %d lancamento da equipe %s?", x+1, aux_fila->dado.nomeEquipe);
					printf("\nInforme (s) Sucesso (f) Falha: ");
					fflush(stdin);
					scanf(" %c", &situacao);

					switch(situacao){
						case 's':
							aux_fila->dado.situacao = 1;

							printf("\nDigite a distancia do alvo: ");
							fflush(stdin);
							scanf("%f", &aux_fila->dado.distanciaAlvo);

							printf("Digite o tempo de propulsao: ");
							fflush(stdin);
							scanf("%f", &aux_fila->dado.tempoPropulsao);

							aux_fila->dado.tentativas++;
							break;

						case 'f':
							printf("Lancamento falhou \n");
							aux_fila->dado.tentativas++;
							if(aux_fila->dado.tentativas > 2){
								aux_fila->dado.situacao = -1;
							}
							break;

						} // END CASE

						if (aux_fila->dado.situacao == 1 || aux_fila->dado.situacao == -1) break;
			 	 } //END FOR

			 } //END WHILE
			//Vai para proximo n� da lista
			aux_fila = aux_fila->prox ;
		 } // End While


	aux_fila = inicio;
	while(aux_fila->prox){
		printf(" \n Equipe: %s \n",aux_fila->dado.nomeEquipe );
		aux_fila = aux_fila->prox ;
	}


/*

	int vencedorTemp;

	qtdMinEquipe = (qtdEquipes > 3)? 3 : qtdEquipes;

	menorDistancia = 999999;

    // Enquanto nao encontrar campeoes
	while(colocacao < qtdMinEquipe){

		campeoes[colocacao] = 0;

		aux_fila = inicio;
//        j = 0;
		// Percorre a lista de equipes
		while(aux_fila->prox){

			//Apenas equipe com lancamento concluido
			if(aux_fila->dado.situacao == 1){
				
				//Sempre a menor distancia do alvo
				if(aux_fila->dado.distanciaAlvo < menorDistancia ){

					menorDistancia = aux_fila->dado.distanciaAlvo;
					//vencedorTemp = j;
				}
				else if (aux_fila->dado.distanciaAlvo == menorDistancia){
//					if(aux_fila->dado.tempoPropulsao > equipe[vencedorTemp].tempoPropulsao){
//						vencedorTemp = j;
//					}
				}
			}
//			j++;
			aux_fila = aux_fila->prox ;
		}
		campeoes[colocacao] = vencedorTemp;
=======
	printf("\n====================================================================");
	printf("\n=============== BEM VINDO AO SISTEMA ACME ROCKETE ===================");
	printf("\n=============== VERSAO: 1.0 ========================================");
	printf("\n====================================================================");
	printf("\n");
	printf("\n");
	printf("\nDigite a quantidade de equipes que deseja cadastrar na competição: ");
	fflush(stdin);
	scanf("%d", &qtdEquipes);

	//Votor de equipes para guardar dados dos lancamentos
	equipes equipe[qtdEquipes];

	//Pega nomes das equipes
	for(i = 0 ; i < qtdEquipes; i++){

		equipe[i].tentativas = 0;
		equipe[i].situacao = 0;

		x = i;

    	printf("\n Digite nome da equipe %d: ",x+1);
    	fflush(stdin);
    	scanf("%s",equipe[i].nomeEquipe);

    }


		//Percorre o array de equipes
		 for(i = 0 ; i < qtdEquipes; i++){
			 //Enquanto houver lancamentos pendentes
			 while(equipe[i].tentativas <= 2 && equipe[i].situacao == 0){

				 //Máximo de 3 tentativas
			 	 for(x = 1 ; x < 3; x++){
						 printf("\n %d° Tentativa de lançamento da equipe %s: ",x,equipe[i].nomeEquipe);

						printf("\nInforme a situação do %d° lançamento da equipe %s: (s = Sucesso ou f = Falha) ",x,equipe[i].nomeEquipe);
						fflush(stdin);
						scanf(" %c", &situacao);

						switch(situacao){
							case 's':
								printf("lancamento ok \n");
								equipe[i].situacao = 1;

								printf("\nSituacao equipe %s : %d \n",equipe[i].nomeEquipe, equipe[i].situacao);

								printf("\nDigite a distancia do alvo: ");
								fflush(stdin);
								scanf("%f", &equipe[i].distanciaAlvo);

								printf("\nDigite o tempo de propulsão: ");
								fflush(stdin);
								scanf("%f", &equipe[i].tempoPropulsao);

								equipe[i].tentativas++;
								break;

							case 'f':
								printf("lancamento falhou \n");
								equipe[i].tentativas++;
								if(equipe[i].tentativas >= 2){
									equipe[i].situacao = -1;
								}
								break;

							} // END CASE

						if (equipe[i].situacao == 1 || equipe[i].situacao == -1) break;
			 	 } //END FOR

			 } //END WHILE

		 } // End for



    // Enquanto nao encontrar campeoes
	while(colocacao < 3){

		campeoes[colocacao] = 0;

		printf("entrou no while, num equipe %d \n", qtdEquipes);

		// Percorre array de equipes
		for(j = 0; j < qtdEquipes; j++){

			printf("entrou no for \n");

			//Apenas equipe com lancamento concluido
			if(equipe[j].situacao == 1){

				printf("\nSituacao equipe %s : %d \n",equipe[j].nomeEquipe, equipe[j].situacao);

				//Sempre a menor distancia do alvo
				if(equipe[j].distanciaAlvo < menorDistancia ){
					//TODO Criar lógica para critério de desempate

					menorDistancia = equipe[j].distanciaAlvo;
//					tempoPropulsao = equipe[j].tempoPropulsao;

					campeoes[colocacao] = j;
				}


			}
		}

>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92
		menorDistancia = 999999;

		equipe[campeoes[colocacao]].situacao = 0;

		colocacao++;
	}

<<<<<<< HEAD
x = colocacao;

//	for(colocacao = 0; colocacao < x; colocacao ++){

	for(colocacao = 0; colocacao < qtdMinEquipe; colocacao ++){

			strcpy(podio.nomeEquipe,equipe[campeoes[colocacao]].nomeEquipe);
			podio.distanciaAlvo = equipe[campeoes[colocacao]].distanciaAlvo;
			podio.tempoPropulsao = equipe[campeoes[colocacao]].tempoPropulsao;
			PUSH(&pilha, podio);
=======


	for(colocacao = 0; colocacao < 3; colocacao ++){

			x = colocacao;

			printf("\nEm %d Lugar: %s \n ",x+1, equipe[campeoes[colocacao]].nomeEquipe);
			strcpy(podio.nomeEquipe,equipe[campeoes[colocacao]].nomeEquipe);
			podio.distanciaAlvo = equipe[campeoes[colocacao]].distanciaAlvo;
			podio.tempoPropulsao = equipe[campeoes[colocacao]].tempoPropulsao;
			PUSH(&pilha,podio);

>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92

	}


<<<<<<< HEAD
    printf("\n######################################################");
    printf("\n#                                                    #");
    printf("\n#              RESULTADOS DA COMPETICAO              #");
    printf("\n#                                                    #");
    printf("\n######################################################\n");

	while (!IsEmpty(pilha)){
    	POP(&pilha, &aux);
       	printf("\nEm %d Lugar: ",colocacao);
    	printf("\nNome da Equipe: %s",aux.nomeEquipe);
       	printf("\nDistancia do alvo: %0.2f \n",aux.distanciaAlvo);
       	printf("\nTempo de propulsao: %0.2f \n",aux.tempoPropulsao);
       	printf("\n");
       	printf("\n");
       	colocacao--;
    }
*/

	printf("\n\nPressione um tecla para sair \n");
=======
    printf("\n======================================================");
    printf("\n=============  Resultados da competição  =============");
    printf("\n======================================================");

	while (!IsEmpty(pilha)){
       POP(&pilha, &aux);
       printf("\nEm %d° Lugar: ",colocacao);
       printf("\nNome da Equipe: %s",aux.nomeEquipe);
       printf("\nDistancia do alvo: %f \n",aux.distanciaAlvo);
       printf("\nTempo de propulsao: %f \n",aux.tempoPropulsao);
       printf("\n");
       printf("\n");
       colocacao--;
    }


	printf("\n\nPressione um tecla para sair \n");
	getchar();
>>>>>>> 7c1578fc4b9e5c519e65db38a68a7961dc5f2a92

system("pause");
return EXIT_SUCCESS;
}
