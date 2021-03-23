#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"
#define red 1
#define BLACK 0

/*funcao para criar a arvore*/
arvore_t *criar(){
  arvore_t *a = (arvore_t*)malloc(sizeof(arvore_t));
  a->raiz = NULL;
  return a;
}

/*funcao para liberar a memoria*/
void finalizar(no_t *raiz){
  if(raiz!=NULL){
    finalizar(raiz->esq);
    finalizar(raiz->dir);
    free(raiz);
  }
}

/*funcao para acessar a cor de um no*/
int cor(no_t *raiz){
  if(raiz==NULL){
    return BLACK;
  }else{
    return raiz->cor;
  }
}

/*funcao para inverter a cor do pai e de seus filhos*/
void troca_cor(no_t *raiz){
  raiz->cor = !raiz->cor;
  if(raiz->esq != NULL)
    raiz->esq->cor = !raiz->esq->cor;

  if(raiz->dir != NULL)
    raiz->dir->cor = !raiz->dir->cor;
}

/*funcao para realizar a rotacao para a esquerda*/
no_t *rotacao_esq(no_t *desb){
  no_t *aux = desb->dir;
  desb->dir = aux->esq;
  aux->esq = desb;
  aux->cor = desb->cor;
  desb->cor = red;
  return aux;
}

/*funcao para realizar a rotacao para a direita*/
no_t *rotacao_dir(no_t *desb){
  no_t *aux = desb->esq;
  desb->esq = aux->dir;
  aux->dir = desb;
  aux->cor = desb->cor;
  desb->cor = red;
  return aux;
}

/*move o no vermelho para a esquerda*/
no_t *move_esq_red(no_t *raiz){
  troca_cor(raiz);
  if(cor(raiz->dir->esq) == red){
    raiz->dir = rotacao_dir(raiz->dir);
    raiz = rotacao_esq(raiz);
    troca_cor(raiz);
  }
  return raiz;
}

/*move o no vermelho para a direita*/
no_t *move_dir_red(no_t *raiz){
  troca_cor(raiz);
  if(cor(raiz->esq->esq) == red){
    raiz = rotacao_dir(raiz);
    troca_cor(raiz);
  }
  return raiz;
}

/*funcao para fazer o balanceamento*/
no_t *balancear(no_t *raiz){

  /*no vermelho sempre na esquerda*/
  if(cor(raiz->dir)==red)
    raiz = rotacao_esq(raiz);

  /*filho da direita e neto da esquerda sao vermelhos*/
  if(raiz->esq != NULL && cor(raiz->dir) == red && cor(raiz->esq->esq) == red)
    raiz = rotacao_dir(raiz);

  /*se dois filhos tiverem a mesma cor, troca a cor*/
  if(cor(raiz->esq) == red && cor(raiz->dir) == red)
    troca_cor(raiz);

  return raiz;
}


/*funcao para inserir um novo no*/
no_t *insere_no(no_t *raiz, elem x, int *flag){
  struct a *a;
  if(raiz==NULL){
    no_t *novo;
    novo = (no_t*)malloc(sizeof(no_t));
    if(novo == NULL){
      *flag = 0;
      return NULL;
    }

    /*inicializar as possicoes*/
    novo->info = x;
    novo->cor = red;
    novo->dir = NULL;
    novo->esq = NULL;
    *flag = 1;
    return novo;
  }
  
  if(x == raiz->info)
    *flag = 0;
  else{
    /*inserir o novo no*/
    if(x < raiz->info)
      raiz->esq = insere_no(raiz->esq, x, flag);
    else
      raiz->dir = insere_no(raiz->dir, x, flag); 
  }

  /*verificar se algum lado esta maior que o outro, e se sim, fazer a rotacao*/
  if(cor(raiz->dir) == red && cor(raiz->esq) == BLACK)
    raiz = rotacao_esq(raiz);

  if(cor(raiz->esq) == red && cor(raiz->esq->esq) == red)
    raiz =  rotacao_dir(raiz);
  
  if(cor(raiz->esq) == red && cor(raiz->dir) == red)
    troca_cor(raiz);

  return raiz;  
}

/*funcao para inserir os valores na arvore*/
int inserir(arvore_t *a, elem x){
  int flag = 0;
  a->raiz = insere_no(a->raiz, x, &flag);
  if((a->raiz) != NULL)
    a->raiz->cor = BLACK;

  return flag;
}

/*imprimir os valores sem ser ordenado*/
void pre_ordem(no_t *raiz){
  if(raiz!=NULL){
    printf("%d ", raiz->info);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

/*imprimir os valores ordenadamente*/
void em_ordem(no_t *raiz){
  if(raiz!=NULL){
    em_ordem(raiz->esq);
    printf("%d ", raiz->info);
    em_ordem(raiz->dir);
  }
}

/*imprimir os valores em pos_ordem*/
void pos_ordem(no_t *raiz){
  if(raiz!=NULL){
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->info);
  }
}


/*encontrar o valor maximo da arvore*/
void maximo_t(no_t *raiz, elem x){
  raiz->max = 0;
  /*para andar na arvore ate chegar no maior elemento*/
  if(raiz->dir->dir != NULL){
    maximo_t(raiz->dir, x);
  }else{
    printf("%d\n", raiz->dir->info);
  }
}

/*encontrar o valor minimo da arvore*/
void minimo_t(no_t *raiz, elem x){
  raiz->min = 0;
  /*para andar na arvore ate chegar no menor elemento*/
  if(raiz->esq->esq != NULL){
    minimo_t(raiz->esq, x);
  }else{
    printf("%d\n", raiz->esq->info);
  }
}


void sucessor(no_t *no, no_t *pre, no_t *suc, int key){
  if (no == NULL)  return; 
  
  /*se o valor atual da arvore for igual a key*/
  if (no->info == key){ 
    /*o maior valor da esquerda eh o predecessor*/
    if (no->esq != NULL) { 
      no_t *tmp = no->esq; 
      while (tmp->dir) 
        tmp = tmp->dir; 
      pre = tmp;        
    } 
  
    /*o menor valor da direita eh o sucessor*/
    if (no->dir != NULL){ 
      no_t* tmp = no->dir; 
      while (tmp->esq) 
        tmp = tmp->esq; 
      suc = tmp;    
    } 

    /*para imprimir erro se nehum valor for encontrado*/        
    if(suc->info != 0)
      printf("%d\n", suc->info); 
    else
      printf("erro\n");
    return ; 
  } 


  /*se o valor atual da arvore for maior que a key*/ 
  if (no->info > key){ 
    suc = no;
    sucessor(no->esq, pre, suc, key); 
  
  /*se o valor atual da arvore for menor que a key*/ 
  }else { 
    pre = no;
    sucessor(no->dir, pre, suc, key); 
  }
}

void predecessor(no_t *no, no_t *pre, no_t *suc, int key){
  if (no == NULL)  return ; 
  
  /*se o valor atual da arvore for igual a key*/ 
  if (no->info == key) { 
    /*o maior valor da esquerda eh o predecessor*/
    if (no->esq != NULL) { 
      no_t *tmp = no->esq; 
      while (tmp->dir) 
        tmp = tmp->dir; 
      pre = tmp;     
    } 
  
    /*o menor valor da direita eh o sucessor*/
    if (no->dir != NULL) { 
      no_t* tmp = no->dir; 
      while (tmp->esq) 
        tmp = tmp->esq; 
      suc = tmp; 
    } 
    
    /*para imprimir erro se nehum valor for encontrado*/
    if(pre->info != 0)
      printf("%d\n", pre->info); 
    else
      printf("erro\n");
    return ; 
  } 
    
  /*se o valor atual da arvore for maior que a key*/  
  if (no->info > key) { 
    suc = no;
    predecessor(no->esq, pre, suc, key); 

  /*se o valor atual da arvore for menor que a key*/ 
  }else{ 
    pre = no;
    predecessor(no->dir, pre, suc, key); 
  }
}