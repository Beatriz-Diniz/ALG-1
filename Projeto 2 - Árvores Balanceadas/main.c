#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ab.h"

int main() {
  int n = 0, x = 0, comando = 0;
  /*determinar a quantidade de nos a serem inseridos*/
  scanf("%d", &n);

  /*craiar a arvore*/
  arvore_t *a = criar();
  no_t *aux;


  for(int i = 0; i<n; i++){
    scanf("%d", &comando);
    
    /*para inserir*/
    if(comando==1){
      scanf("%d", &x);
      inserir(a, x);
    }
    
    /*para encontrar o suessor*/
    if(comando==2){
      scanf("%d", &x);
      
      /*struct auxiliares para encontra o sucessor*/
      no_t *pre;
      pre = (no_t*)malloc(sizeof(no_t));
      no_t *suc;
      suc = (no_t*)malloc(sizeof(no_t));
      
      sucessor(a->raiz, pre, suc, x);
    }
    
    /*para encontrar o predecessor*/
    if(comando==3){
      scanf("%d", &x);

      /*struct auxiliares para encontra o predecessor*/
      no_t *pre;
      pre = (no_t*)malloc(sizeof(no_t));
      no_t *suc;
      suc = (no_t*)malloc(sizeof(no_t));
      
      predecessor(a->raiz, pre, suc, x);
    }

    /*para encontrar o maior valor da arvore*/
    if(comando==4){
      maximo_t(a->raiz, x);
    }
    
    /*para encontrar o menor valor da arvore*/
    if(comando==5){
      minimo_t(a->raiz, x);
    }
    
    /*para imprimir em pre_ordem*/
    if(comando==6){
      pre_ordem(a->raiz);
      printf("\n");
    }
    
    /*para imprimir em ordem*/
    if(comando==7){
      em_ordem(a->raiz);
      printf("\n");
    }
    
    /*para imprimir em pos_ordem*/
    if(comando==8){
      pos_ordem(a->raiz);
      printf("\n");
    }
  }
   
  /*para excluir a arvore e liberar memoria*/
  finalizar(a->raiz);
  return 0;
}

