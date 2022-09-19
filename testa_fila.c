#include <stdio.h>
#include <stdlib.h>
#include "libfila.h"

#define MAX_TAM 10

#define MAX_RANDOM 500

int main(){
	
	printf("\n**************** TESTE DA FILA ****************\n");	
	printf("\n");
	int i;
	int elemento;
	fila_t *fila;
	fila = fila_cria();
	if (fila == NULL){
		printf("FALHA, fila não foi criada\n");
		fila= fila_destroi(fila);
		return 0;
	}
	else
		printf("Fila criada com SUCESSO\n");
	
	fila_imprime(fila); /*tenta imprimir a fila recem criada*/ 
	
	/* preenche a fila com MAX_TAM valores*/
	printf("preenchendo fila\n");	
	for(i=0;i < MAX_TAM; i++){	
		if (queue(fila,(rand()%MAX_RANDOM)) == 0){
			printf("fila cheia\n");
		}
	}
	fila_imprime(fila);
	/* verifica se a fila esta vazia, se não estiver nos diz o tamanho dela */ 	
	if(fila_vazia(fila)){
		printf("fila vazia\n");
	}
	else{
		printf("fila com %d elementos\n", fila_tamanho(fila));
	}
	
	/* remoção de elemento se possivel */
	if (dequeue(fila, &elemento)){
		printf("removido com sucesso\n");
	}
	else
		printf("falha ao remover elemento\n");
	printf("o elemento removido foi: %d\n", elemento);
	fila_imprime(fila);
	
	/* tenta inserir algum elemento na fila, se estiver cheia retorna 0 */
	if (queue(fila,(rand()%MAX_RANDOM)) == 0){
		printf("fila cheia\n");
		fila= fila_destroi(fila);
		return 0;
	}
	printf("apos inserção temos a seguinte ");
	fila_imprime(fila);
	printf("fila com %d elementos\n", fila_tamanho(fila));
	
	/* tentando inserir elemento em fila ja cheia */
	if (queue(fila,(rand()%MAX_RANDOM)) == 0){
		printf("fila cheia\n");
	}
	
	/* remove todos os elementos da fila */
	
	for(i=0; fila->ini!=NULL; i++){
		if(dequeue(fila, &elemento)){
			printf("o elemento removido foi: %d\n", elemento);
		}
		else	
			printf("fila vazia\n");
	}
	fila_imprime(fila);
	
	fila = fila_destroi(fila);	
	printf("\n********** FIM TESTE DA FILA **********\n");	
	printf("\n");
	return 0;
}
