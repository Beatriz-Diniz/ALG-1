#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"

int main() {
  int n = 0, pai = 0, esquerda = 0, direita = 0;
  /*determinar a quantidade de nos a serem inseridos*/
  scanf("%d", &n);

  /*craiar a arvore*/
  arvore_t *a = criar();

  for(int i = 0; i<n; i++){
    if(i==0){
      /*inicializar a arvore*/
      inserir_esq(a, 0, -1);
    }else{
      /*inserir o pai e os seus filhos*/
      scanf("%d", &pai);
      scanf("%d", &esquerda);
      scanf("%d", &direita);
      if(esquerda!=-1){
        inserir_esq(a, esquerda, pai);
      }
      if(direita!=-1){
        inserir_dir(a, direita, pai);
      }
    }
  }
  
  imprimir(a->raiz);
  finalizar(a->raiz);
  return 0;
}