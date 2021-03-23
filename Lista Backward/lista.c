#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "lista.h"

typedef struct no{
	int valor; 
  int i;
  int j;
  int m;
	struct no *prox; 
  struct no *back; 
} no_t;

/*variaveis que vao guardar o inio e o no*/
no_t *inicio = NULL;
no_t *no = NULL;

/*funcao para criar uma lista*/
no_t * criar_lista(int valor){
	/*alocar memória*/
	no_t * p = (no_t*)malloc(sizeof(no_t));
  assert(p != NULL);

	/*adicionar o elemento inicial da lista e inicializar a variavel prox*/
	p->valor = valor; 
	p->prox = NULL; 
  p->i = 0;
  
	/*o inicio e o no aponta para p*/
	inicio = no = p;
	return p;
}

/*funcao para adicionar os elementos na lista*/
no_t* adicionar_lista(int v, int i, int j, int back){
  /*verificar se a lista esta vazia*/
	if(inicio == NULL){
		return criar_lista(v);
	}

  /*alocar memoria*/
	no_t * p = (no_t*)malloc(sizeof(no_t));
  assert(p != NULL);

	/*atribuir o novo valor e o novo no*/
	p->valor = v;
  p->i = i;
  p->j = j;
  p->m = back;
	p->prox = NULL;
	no->prox = p;
	no = p;
  
  /*para os ponteiros igual a zero aponte para NULL*/
  if(back == 0 || (p->i == p->m && p->i == p->j)){
    no->back = NULL;
  }else{
    no->back = no;
  }
	return p;
}

/*funcao para imprimir a lista*/
void imprimir_lista(){
  
  /*k = variavel para guradar a posicao que back aponta
   *l = variavel auxiliar*/
  int i = 0;
  int l = 0;
  int k = 0;
  /*variavel para percorrer a lista*/
	no_t *aux = inicio;

  /*percorrer a lista se ela nao estiver vazia*/
	if(inicio != NULL){
    while(aux != NULL){
      /*Se o ponteiro back apontar para NULL*/
      if(aux->back == NULL){
        printf("[%d,%d] ", aux->valor, aux->i);
        i++;
      }
      /*Para encontrar a posicao que o ponteiro back aponta*/
      else{
        l = 0;
        k = aux->j;
        while(l<aux->m){
          k--;
          l++;
        }
        if(k<0){
          k = 0;
        }
        if(i==1){
          k = k-1;
        }
        printf("[%d,%d,%d] ", aux->valor, aux->i, k);
      }
		  aux = aux->prox;
	  }
    printf("\n");
  }
  
}

/*funcao para verificar se a lista esta vazia*/
int lista_vazia(){
	if(inicio == NULL)
		return 1;

	return 0;
}

/*funcao para realizar a busca do elemento*/
no_t * buscar_elemento(int v, no_t **anterior){

	if(lista_vazia() == 1)
		return NULL;

	no_t *p = inicio;

	/*variável aux para guardar o elemento anterior*/
	no_t *aux = NULL;

	/*flag encontrou que indica se achou o elemento*/
	int encontrou = 0;

	while(p != NULL){
		if(p->valor == v){
			encontrou = 1;
			break;
		}
		aux = p;
		p = p->prox;
	}

	if(encontrou == 1){
		if(anterior)
			*anterior = aux;
		return p;
	}
	return NULL;
}

/*funcao para remover o elemento desejado*/
int remover_elemento(int v){

	no_t *anterior = NULL;
	no_t * elem = buscar_elemento(v, &anterior);
  no_t *a;

	if(elem == NULL)
		return 0;

  /*para reorganizar as posicoes dos elementos*/
	if(anterior != NULL)
		anterior->prox = elem->prox;

  /*para mudar a posicao do no*/
	if(elem == no)
		no = anterior;    

  /*para mudar a posicao do primeiro elemento, caso o elemento removido seja o primeiro*/
	if(elem == inicio)
		inicio = elem->prox;

  /*para o ponteiro back que aponta para o elemento deletado seja igual a NULL*/
  if(elem->prox!=NULL){
    a=elem->prox;
    if(a->m==1){
      a->back = NULL;
    }else{
      if(a->prox!=NULL){
        a = a->prox;
        a->back = NULL;
      }
    }
  }
  
	free(elem);
	elem = NULL;
	return 1;
}

/*funcao para inserir ou remover elementos
i =  inserir novo elemento
r = remover elemento
f =  finalizar*/
void receber_comandos(){
  char entrada;
  int valor = 0, i = 0, j = 0, back = 0, aux = 0;

  while(entrada!='f'){
    scanf("%c", &entrada);
    
    /*para inserir*/
    if(entrada=='i'){
      back = 0;
      scanf("%d", &valor);
      scanf("%d", &back);
      if(i == 0){
        criar_lista(valor);
      }else{
        if(back>0){
          j++;
          aux = j;
        }else{
          aux = j;
          j = 0;
        }
        adicionar_lista(valor, i, j, back);
        j = aux;
      }
      i++;
    }
    
    /*para remover*/
    if(entrada=='r'){
      scanf("%d", &valor);
      remover_elemento(valor);
      i++;
    }
    
  }
}