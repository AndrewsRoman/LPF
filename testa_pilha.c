#include <stdio.h>
#include <stdlib.h>
#include "libpilha.h"

#define MAX_TAM 1000
#define MAX_RANDOM 10

/* status de saida */
/* -2 -> pop falhou, solicitou remoção maior que o numero maximo de elementos da pilha */
/* -1 -> pop falhou, pilha vazia */
/*  1 -> push falhou, pilha cheia */
/*  2 -> push falhou, sem espaço suficiente para inserir os elementos solicitados */
/*  3 -> FALHA na alocação de memoria para pilha */
/*  0 -> Sucesso */

int main(){
	printf("\n********** TESTE PILHA **********\n");
	pilha_t *pilha;
	int i, elemento, qtd_insere, qtd_remove, inserir;
	
	pilha=pilha_cria(MAX_TAM);
	if (pilha == NULL){
		printf("criação da pilha FALHOU\n");
		return 3;
	}
	else{
		printf("criação da pilha realizada com SUCESSO\n");
	}
	/* insersão de elementos pseudo-aleatorios na pilha variando entre 0 e MAX_RANDOM */ 
	for(i=0;i < MAX_TAM; i++){
		if (push(pilha,(rand()%MAX_RANDOM)) == -1){
			printf("pilha cheia\n");
		}
	}
	pilha_imprime(pilha);
	printf("o elemento do topo é: %d\n", pilha_topo(pilha));
	printf("a quantidade de elementos na pilha é: %d\n", pilha_tamanho(pilha));
	printf("\n");
	
	/* remoção de n elementos */	
	printf("/* REMOÇÃO DOS N ELEMENTOS */\n");
	printf("quantos elementos deseja remover: ");
	scanf("%d", &qtd_remove);
	if (pilha_vazia(pilha)){
		pilha = pilha_destroi(pilha);
		return -1;
	}
	if (qtd_remove > pilha->nelem){
		pilha = pilha_destroi(pilha);
		return -2;
	}
	for (i=0; i< qtd_remove; i++){
		elemento = pop(pilha);
	}
	printf("pilha apos remoção de %d elementos\n", qtd_remove);
	pilha_imprime(pilha);
	printf("o elemento do topo é: %d\n", pilha_topo(pilha));
	printf("a quantidade de elementos na pilha é: %d\n", pilha_tamanho(pilha));
	printf("\n");
	
	/*inserção de n elementos*/
	printf("/* INSERÇÃO DOS N ELEMENTOS */\n");
	printf("quantos elementos deseja inserir: ");
	scanf("%d", &qtd_insere);
	if (pilha_tamanho(pilha) == 200){
		pilha = pilha_destroi(pilha);
		return 1;
	}
	if (qtd_insere > (MAX_TAM - pilha->nelem)){
		printf("espaço insuficiente na pilha\n");
		printf("destruindo pilha\n");
		pilha = pilha_destroi(pilha);
		return 2;
	}
	for (i=0; i< qtd_insere; i++){
		printf("insira um elemento: ");
		scanf("%d",&inserir);
		push(pilha,inserir);
	}
	printf("pilha apos inserção de %d elementos\n", qtd_insere);
	pilha_imprime(pilha);
	printf("o elemento do topo é: %d\n", pilha_topo(pilha));
	printf("a quantidade de elementos na pilha é: %d\n", pilha_tamanho(pilha));
	printf("\n");
	
	printf("/* ESVAZIANDO PILHA E IMPRIMINDO ELEMENTO REMOVIDO */\n");
	while(pilha_vazia(pilha) != 1){
		elemento = pop(pilha);
		printf("%d ", elemento); 
	}

	/* liberando memoria da pilha */
	pilha = pilha_destroi(pilha);
	printf("\n********** FIM TESTE PILHA **********\n");

	return 0;
}
