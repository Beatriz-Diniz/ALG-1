#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fila.h"

struct fila {
  int total;
  char nome[TamFila][TamFila];
  int idade[TamFila], saude[TamFila];
};

/*criar a fila*/
Fila_t *criar(){
  Fila_t *f;
  f = (Fila_t*)malloc(sizeof(Fila_t));
  assert(f != NULL);
  f -> total = 0;
  return f;
}

/*verificar se a fila estiver vazia*/
int isEmpety(Fila_t *f){
  assert(f != NULL);
  if(f->total == 0)
    return 1;
  return 0;
}

/*verificar se a fila estiver cheia*/
int isFull(Fila_t *f){
  assert(f != NULL);
  if(f->total == TamFila)
    return 1;
  return 0;
}

/*inserir os dados da pessoa que entra na fila*/
int inserir(Fila_t *f){
  if(isFull(f)==1)
    return 0;
  
  scanf("%s", f->nome[f->total]);
  scanf("%d", &f->idade[f->total]);
  scanf("%d", &f->saude[f->total]);
  f->total++;
  return 1;
}

/*funcao para chamar a proxima pessoa em ordem de prioridade*/
int ordem_atendimento(Fila_t *f){
  /*chamar a proxima pessoa da fila que tiver mais de 60 anos e algum problema de saude*/
  for(int i=0; i<f->total; i++){
    if(f->idade[i]>=60 && f->saude[i]==1){
      printf("%s %d %d\n", f->nome[i], f->idade[i], f->saude[i]);

      /*atualizar fila*/
      for(int j = i; j<f->total; j++){
        strcpy(f->nome[j], f->nome[j+1]);
        f->idade[j] = f->idade[j+1];
        f->saude[j] = f->saude[j+1];
      }
      f->total--;
      return 0;
    }
  }

  /*chamar a proxima pessoa da fila que tiver menos de 60 anos e algum problema de saude*/
  for(int i=0; i<f->total; i++){
    if(f->idade[i]<60 && f->saude[i]==1){
      printf("%s %d %d\n", f->nome[i], f->idade[i], f->saude[i]);

      /*atualizar fila*/
      for(int j = i; j<f->total; j++){
        strcpy(f->nome[j], f->nome[j+1]);
        f->idade[j] = f->idade[j+1];
        f->saude[j] = f->saude[j+1];
      }
      f->total--;
      return 0;
    }
  }

  /*chamar a proxima pessoa da fila que tiver mais de 60 anos e nem problema de saude*/
  for(int i=0; i<f->total; i++){
    if(f->idade[i]>=60 && f->saude[i]==0){
      printf("%s %d %d\n", f->nome[i], f->idade[i], f->saude[i]);

      /*atualizar a fila*/
      for(int j = i; j<f->total; j++){
        strcpy(f->nome[j], f->nome[j+1]);
        f->idade[j] = f->idade[j+1];
        f->saude[j] = f->saude[j+1];
      }
      f->total--;
      return 0;
    }
  }

  /*chamar a proxima pessoa da fila em ordem de chegada*/
  for(int i=0; i<f->total; i++){
    if(f->idade[i]<60 && f->saude[i]==0){
      printf("%s %d %d\n", f->nome[i], f->idade[i], f->saude[i]);

      /*atualizar a fila*/
      for(int j = i; j<f->total; j++){
        strcpy(f->nome[j], f->nome[j+1]);
        f->idade[j] = f->idade[j+1];
        f->saude[j] = f->saude[j+1];
      }
      f->total--;
      return 0;
    }
  }
  return 1;
}


/*destruir a fila*/
void destruir(Fila_t *f){
  if(f!=NULL){
    free(f);
  }
}