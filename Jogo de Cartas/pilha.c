#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"

struct pilha {
int topo;
elem itens[TamPilha];
};


/*funcao para criar a pilha*/
Pilha_t *create(){
  Pilha_t *p = (Pilha_t*)malloc(sizeof(Pilha_t));
  assert(p!=NULL);

  p->topo = -1;
  return p;
}


/*funcao para destruir a pilha*/
void destroy(Pilha_t *p){
  if(p!=NULL)
    free(p);
  
  p=NULL;
}

/*funcao para verificar se a pilha esta cheia*/
int isFull(Pilha_t *p){
  assert(p!=NULL);
  if(p->topo == TamPilha-1)
    return 1;
  else
    return 0;
}

/*funcao para verificar se a pilha esta vazia*/
int isEmpyt(Pilha_t *p){
  assert(p!=NULL);
  if(p->topo == -1)
    return 1;
  else  
    return 0;
}

/*funcao para inserir os valores na pilha*/
int push(Pilha_t *p, elem x){
  assert(p!=NULL);
  if(isFull(p)==1){
    return -1;
  }
  p->topo = p->topo+1;
  scanf("%d", &x);
  p->itens[p->topo] = x;
  return 1;
}

/*funcao para retirar o ultimo elemento*/
int pop(Pilha_t *p, elem *x){
  assert(p!=NULL);
  if(isEmpyt(p)==1){
    return -1;
  }
  *x = p->itens[p->topo];
  p->topo -= 1;
  return 1;
}

/*funcao para consultar o valor do ultimo elemento*/
int top(Pilha_t *p, elem *x){
  assert(p!=NULL);
  if(isEmpyt(p)==1){
    return -1;
  }
  *x = p->itens[p->topo];
  return 1;
}