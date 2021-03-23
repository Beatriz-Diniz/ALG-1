#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

struct no{
  elem info;
  no_t *prox;
};

struct lista{
  no_t *ini, *fim;
  int tam;
};

/*funcao para ciar lista*/
lista_t *criar(){
  lista_t *l;
  l = (lista_t*)malloc(sizeof(lista_t));
  assert(l != NULL);
  l->ini = NULL;
  l->fim = NULL;
  l->tam = 0;

  return l;
}

/*funcao para liberar a memoria usada pela lista*/
void liberar(lista_t *l){
  if(l != NULL){
    no_t *p = l->ini;
    while(p != NULL){
      l->ini = p->prox;
      free(p);
      p = l->ini;
    }
    free(l);
  }
}

/*funcao para inserir as pessoas na lista*/
void inserir(lista_t *l, elem x){
  assert(l != NULL);

  no_t *p = (no_t*)malloc(sizeof(no_t));
  p->info = x;
  p->prox = NULL;

  //se lista estiver vazia
  if(l->ini == NULL){
    l->ini = p;
  }else{  //lista com 1 ou mais elementos
    l->fim->prox = p;
  }
  l->fim = p;
  l->tam++;
}

/*funcao para imprimir a lista*/
void imprimir(lista_t *l){
  assert(l != NULL);

  no_t *p = l->ini;
  while(p != NULL){
    printf("%d ", p->info);
    p = p->prox;
  }
  printf("\n");
}

/*funcao para remover as pessoas e encontrar o sobrevivente*/
void remover(lista_t *l, elem N, elem k){
  /*N = numero de pessoas
   *K = indice de sorteio*/
  int i;

  no_t *tmp;
  no_t *x;
  no_t *t = (no_t*) malloc(sizeof(no_t));
  assert(t!=NULL);
  x = t;

  /*atribuir o primeiro elemento da lista*/
  t->info = 1;
  t->prox = t;

  /*inserir as pessoas na lista*/
  for(i = 2; i <= N; i++) {
    x = x->prox = (no_t *) malloc(sizeof(no_t));
    assert(x!=NULL);
    x->info = i;
    x->prox = t;
  }

  /*Remover pessoas*/
  while(x != x->prox) {
    for(i = 1; i < k; i++)
    x = x->prox;
    tmp = x->prox;
    x->prox = tmp->prox;
    free(tmp);
  }
  i = x->info;
  inserir(l, i);
}