#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "fila.h"

int main(){
  Fila_t *f;
  int i = 0, n_acoes;
  char acao[6] = {'\0'};

  /*determinar a qunatidade de acoes*/
  scanf("%d", &n_acoes);
  f = criar();
  for(i=0; i<n_acoes; i++){

    /*definir a acao*/
    scanf("%s", acao);
    if(strcmp(acao, "ENTRA")==0){
      /*inserir uma nova pessoa na fila*/
      inserir(f);
    }
    if(strcmp(acao, "SAI")==0){
      if(isEmpety(f)==0){
        /*imprimir a proxima pessoa a ser atendida*/
        ordem_atendimento(f);
      }
      else{
        /*se nao tiver mais ninguem na fila*/
        printf("FILA VAZIA\n");
      }
      
    }
  } 
  return 0;
}