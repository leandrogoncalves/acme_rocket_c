
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    float menorDistancia = 9999999;
    char situacao;


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
    		printf("\n Insira um nome válido para a equipe! \n");
    	}else{
        	//Insere a equipe na lista
        	ENQUEUE(&inicio, &fim, equipe);
        	printf("\n Equipe cadastrada com sucesso \n");
    	}
    	
    	printf("\n Deseja cadastrar uma nova equipe ? 1-SIM ou 2-Não:");
		fflush(stdin);
		scanf("%d",&limitador);

    	qtdEquipes++;

    }while(limitador == 2);

	aux_fila = inicio;

		//Percorre a lsita de equipes enquanto proximo diferente de null
		 while(aux_fila->prox){
			 //Enquanto houver lancamentos pendentes
			 while(inicio->dado.tentativas <= 2 && inicio->dado.situacao == 0){

				 //Máximo de 3 tentativas
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
			//Vai para proximo nó da lista
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
		menorDistancia = 999999;

		equipe[campeoes[colocacao]].situacao = 0;

		colocacao++;
	}

x = colocacao;

//	for(colocacao = 0; colocacao < x; colocacao ++){

	for(colocacao = 0; colocacao < qtdMinEquipe; colocacao ++){

			strcpy(podio.nomeEquipe,equipe[campeoes[colocacao]].nomeEquipe);
			podio.distanciaAlvo = equipe[campeoes[colocacao]].distanciaAlvo;
			podio.tempoPropulsao = equipe[campeoes[colocacao]].tempoPropulsao;
			PUSH(&pilha, podio);

	}


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

system("pause");
return EXIT_SUCCESS;
}
