#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"

/*realizar a rotacao para a direita*/   
no_t *rotacao_dir(no_t *y){ 
    no_t *x = y->esq,  *T2 = x->dir; 
    x->dir = y; 
    y->esq = T2; 
    
    return x; 
} 
  
/*realizar a rotacao para a esquerda*/
no_t *rotacao_esq(no_t *x) { 
    no_t *y = x->dir, *T2 = y->esq; 
    y->esq = x; 
    x->dir = T2; 
  
    return y; 
} 
  
/*funcao para criar um novo no*/
no_t* novo_no(int chave, int prioridade){ 
    no_t* temp = (no_t*)malloc(sizeof(no_t)); 
    
    temp->chave = chave; 
    temp->prioridade = prioridade; 
    temp->esq = temp->dir = NULL; 
    
    return temp; 
} 
  
/*funcao para realizar a busca*/
no_t* buscar(no_t* raiz, int chave){ 
    
    /*se a posicao atual for NULL ou igual a chave*/
    if (raiz == NULL || raiz->chave == chave) 
       return raiz; 
  
    /*se o valor atual for menor que a chave*/ 
    if (raiz->chave < chave) 
       return buscar(raiz->dir, chave); 
  
    /*se o valor ataul for maior que a chave*/
    return buscar(raiz->esq, chave); 
} 
  
/*funcao para inserir os valores na arvore*/
no_t* inserir(no_t* raiz, int chave, int prioridade){ 
    /*se a raiz for NULL, cria um novo no*/ 
    if (!raiz) 
        return novo_no(chave, prioridade); 
  
    /*se a chave for menor que a raiz*/
    if (chave <= raiz->chave) { 
        /*insere no filho esquerdo*/
        raiz->esq = inserir(raiz->esq, chave, prioridade); 
  
        /*se o lado esquerdo ficar maio, faz a rotacao para a direita*/ 
        if (raiz->esq->prioridade > raiz->prioridade) 
            raiz = rotacao_dir(raiz);
    
    /*se a chave for maio*/
    }else{ 
        /*insere no filho direito*/
        raiz->dir = inserir(raiz->dir, chave, prioridade); 
  
        /*se o lado direito ficar maio, faz a rotacao para a esquerda*/
        if (raiz->dir->prioridade > raiz->prioridade) 
            raiz = rotacao_esq(raiz); 
    } 
    return raiz; 
} 
  
/*funcao para deletar uma chave*/
no_t* deletar(no_t* raiz, int chave){ 
    if (raiz == NULL) 
        return raiz; 
  
    if (chave < raiz->chave) 
        raiz->esq = deletar(raiz->esq, chave); 
    else if (chave > raiz->chave) 
        raiz->dir = deletar(raiz->dir, chave); 
  
  
    /*se o filo esquerdo for NULL*/ 
    else if (raiz->esq == NULL) { 
        no_t *temp = raiz->dir; 
        /*transforma o filho direito numa raiz*/
        raiz = temp;  
    } 
  
    /*se o filo direito for NULL*/  
    else if (raiz->dir == NULL) { 
        no_t *temp = raiz->esq; 
        /*transforma o filho esquerdo numa raiz*/
        raiz = temp;
    } 
  
    /*se a chave estiver na raiz e os filhos nao forem NULL*/
    else if (raiz->esq->prioridade > raiz->dir->prioridade){ 
        raiz = rotacao_esq(raiz); 
        raiz->esq = deletar(raiz->esq, chave); 
    } 
    else{ 
        raiz = rotacao_dir(raiz); 
        raiz->dir = deletar(raiz->dir, chave); 
    } 
  
    return raiz; 
} 

/*imprimir os valores sem ser ordenado*/
void pre_ordem(no_t* raiz){
    if(raiz!=NULL){
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}


/*imprimir os valores ordenadamente*/
void em_ordem(no_t* raiz){
    if(raiz!=NULL){
        em_ordem(raiz->esq);
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
        em_ordem(raiz->dir);
    }
}

/*imprimir os valores em pos_ordem*/
void pos_ordem(no_t* raiz){
    if(raiz!=NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("(%d, %d) ", raiz->chave, raiz->prioridade);
    }
}


/*imprimir os valores em ordem de largura*/
void largura (fila_t *h) {

    fila_t *fila;
    int i, f;

    fila = calloc(200, sizeof(no_t));
    fila[0] = *h; 
    i = 0; f = 1;
  
    while (f > i) {
       *h = fila[i++];
       printf("(%d, %d) ", h->chave, h->prioridade);
       if (h->esq != NULL) fila[f++] = *h->esq;
       if (h->dir != NULL) fila[f++] = *h->dir;
    }  
}
