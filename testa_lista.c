#include <stdio.h>
#include <stdlib.h>
#include "liblista.h"

#define MAX_TAM 10
#define MAX_RANDOM 100

int main(){
	
	printf("\n********** TESTE LISTA **********\n");
	printf("\n");
	int i, elemento, elemento_lido;
	lista_t *lista;
	lista=lista_cria();
	if (lista==NULL){
		printf("FALHA na alocação de memoria\n");
		return 1;
	}
	else
		printf("SUCESSO na alocação de memoria para lista\n");
		
	lista_imprime(lista); /*tenta imprimir a fila recem criada*/ 
	
	printf("\nTESTE DE INSERÇÃO E DE REMOÇÃO DO INICIO DA LISTA\n");
	/* INSERINDO NO INICIO DA FILA */
	for(i=0;i < MAX_TAM; i++){	
		if (lista_insere_inicio(lista,(rand()%MAX_RANDOM)) == 0){
			printf("lista cheia\n");
		}
		lista_imprime(lista);
	}	
	printf("o tamanho da lista é %d\n", lista_tamanho(lista));
	printf("---------------------------------------------------\n");
	/* REMOVENDO DO INICIO DA FILA */
	for(i=0; lista->ini!=NULL; i++){
		if(lista_retira_inicio(lista, &elemento)){
			/* printf("o elemento removido foi: %d\n", elemento); */
		}
		else	
			printf("lista vazia\n");
		lista_imprime(lista);
	}
	printf("o tamanho da lista é %d\n", lista_tamanho(lista));
	printf("\nFIM DO TESTE DE INSERÇÃO E DE REMOÇÃO DO INICIO DA LISTA\n");	
	
	printf("\n********************************************************\n");
	
	/*inserção no final da lista*/
	printf("\nTESTE DE INSERÇÃO E DE REMOÇÃO DO FINAL DA LISTA\n");
	for(i=0;i < MAX_TAM; i++){	
		if (lista_insere_fim(lista,(rand()%MAX_RANDOM)) == 0){
			printf("lista cheia\n");
		}
		lista_imprime(lista);
	}
	printf("o tamanho da lista é %d\n", lista_tamanho(lista));
	printf("--------------------------------------------------\n");
	
	/* removendo do final da lista */
	for(i=0; lista->ini!=NULL; i++){
		lista_imprime(lista);
		if(lista_retira_fim(lista, &elemento)){
			/*printf("o elemento removido foi: %d\n", elemento); */
		}
		else	
			printf("lista vazia\n");
		
	}
	printf("o tamanho da lista é %d\n", lista_tamanho(lista));
	
	printf("\nFIM DO TESTE DE INSERÇÃO E REMOÇÃO DA LISTA\n");	
	
	printf("\n*******************************************\n");
	
	/* inserção ordenada */
	printf("\nTESTE DE INSERÇÃO ORDENADA NA LISTA\n");
	printf("\n1º ENTRADA DESORDENADA\n");
	for(i=0;i < MAX_TAM; i++){	
		lista_imprime(lista);
		if (lista_insere_ordenado(lista,(rand()%MAX_RANDOM)) == 0){
			printf("lista cheia\n");
		}
	}
	/* verificando se o elemento lido pertence a lista  */
	printf("insira um elemento para verificar se ele pertence a lista: ");
	scanf("%d", &elemento_lido);
	if (lista_pertence(lista,elemento_lido)){
		printf("elemento %d encontrado na lista\n", elemento_lido);
	}
	else
		printf("elemento não encontrado\n");
	
	for(i=0; lista->ini!=NULL; i++){
		if(lista_retira_fim(lista, &elemento)){
			/*printf("o elemento removido foi: %d\n", elemento); */
		}
	}
	printf("---------------------------------------------\n");

	/* printf("\nTESTE DE INSERÇÃO ORDENADA  NA LISTA\n"); */
	printf("\n2º ENTRADA ORDENADA CRESCENTE\n");
	for(i=0;i < MAX_TAM; i++){	
		if (lista_insere_ordenado(lista,i) == 0){
			printf("lista cheia\n");
		}
		lista_imprime(lista);
	}
	for(i=0; lista->ini!=NULL; i++){
		if(lista_retira_fim(lista, &elemento)){
			/*printf("o elemento removido foi: %d\n", elemento); */
		}
	}
	printf("---------------------------------------------\n");
	
	printf("\n3º ENTRADA ORDENADA DECRESCENTE\n");
	int k = 10;
	for(i=0;i < MAX_TAM; i++){	
		if (lista_insere_ordenado(lista,k) == 0){
			printf("lista cheia\n");
		}
		k--;
		lista_imprime(lista);
	}
	
	
	/* verificando se o elemento lido pertence a lista, se pertencer o remove  */
	printf("insira um elemento para remove-lo da lista: ");
	scanf("%d", &elemento_lido);
	if (lista_retira_elemento(lista, &elemento_lido)){
		
		lista_imprime(lista);
	}
	else
		printf("elemento não encontrado\n");
	
	
	lista=lista_destroi(lista);
	
	
	
	printf("\n********** FIM TESTE LISTA **********\n");
	printf("\n");
	return 0;
}
