#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"

struct no {
  elem info, pai;
  no_t *esq, *dir;
};

arvore_t *criar(){
  arvore_t *a = (arvore_t*)malloc(sizeof(arvore_t));
  a->raiz = NULL;
  return a;
}

/*funcao para liberar memoria*/
void finalizar(no_t *raiz){
  if(raiz!=NULL){
    finalizar(raiz->esq);
    finalizar(raiz->dir);
    free(raiz);
  }
}

/*funcao para calcular a altura*/
int altura(no_t *raiz){
  if(raiz == NULL)
    return 0;

  int alt_esq  = 1+altura(raiz->esq);
  int alt_dir  = 1+altura(raiz->dir);

  if(alt_esq>alt_dir)
    return alt_esq;
  else
    return alt_dir;
}

/*funcao para realizar a busca do elemento*/
no_t *busca(no_t *raiz, elem x){
  if(raiz == NULL)
    return NULL;

  if(raiz->info == x)
    return raiz;
  
  no_t *p = busca(raiz->esq, x);
  if(p==NULL)
    p = busca(raiz->dir, x);

  return p;
}

/*se pai == -1 insere na raiz
 *caso contrario insere na esquerda de pai */
/*para salvar o filho esquerdo*/
int inserir_esq(arvore_t *a, elem x, elem pai){
  no_t *p = (no_t*)malloc(sizeof(no_t));
  p->esq = NULL;
  p->dir = NULL;
  p->info = x;
  p->pai = pai;
  if(pai==-1){
    if(a->raiz == NULL){
      a->raiz=p;
    }else{
      free(p);
      return 0;
    }
  }else{
    no_t *aux = busca(a->raiz, pai);
    if(aux != NULL && aux->esq == NULL){
      /*salvar o elemento no filho esquerdo*/
      aux->esq = p;
    }else{
      free(p);
      return 0;
    }
  }
  return 1;
}

/*funcao para salvar o filho direito*/
int inserir_dir(arvore_t *a, elem x, elem pai){
  no_t *p = (no_t*)malloc(sizeof(no_t));
  p->esq = NULL;
  p->dir = NULL;
  /*salvar o elemento*/
  p->info = x;
  /*salvar o pai*/
  p->pai = pai;
  if(pai==-1){
    if(a->raiz == NULL){
      a->raiz=p;
    }else{
      free(p);
      return 0;
    }
  }else{
    no_t *aux = busca(a->raiz, pai);
    if(aux != NULL && aux->dir == NULL){
      /*salvar o elemento no filho direito*/
      aux->dir = p;
    }else{
      free(p);
      return 0;
    }
  }
  return 1;
}

/*funcao para imprimir as informacoes*/
void imprimir(no_t *raiz){
  if(raiz!=NULL){
    int grau = 0;
    /*para imprimiro valor do no e o pai*/
    printf("no %d: pai = ", raiz->info);
    printf("%d, ", raiz->pai);
    /*para encontarar a altura*/
    printf("altura = %d, ",altura(raiz));

    /*para encontrar o grau*/
    if(raiz->esq!=NULL || raiz->dir!=NULL) 
      grau = 1;
    if(raiz->esq!=NULL && raiz->dir!=NULL)
      grau = 2;
    printf("grau = %d, ", grau);

    /*para encontrar o filho esquerdo*/
    if(raiz->esq!=NULL){
      printf("filhos = (%d,",raiz->esq->info);
    }else{
      printf("filhos = (-1,");
    }

    /*para encontrar o filho direito*/
    if(raiz->dir!=NULL){
      printf("%d), ",raiz->dir->info);
    }else{
      printf("-1), ");
    }

    /*para encontrar o tipo*/ 
    if(raiz->pai == -1)
      printf("tipo = raiz\n");
    if(raiz->esq==NULL && raiz->dir==NULL && raiz->pai >-1)
      printf("tipo = folha\n");
    if((raiz->esq!=NULL || raiz->dir!=NULL) && raiz->pai > -1) 
      printf("tipo = interno\n");
    
    imprimir(raiz->esq);
    imprimir(raiz->dir);
  }
}