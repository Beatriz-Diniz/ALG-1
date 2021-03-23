#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pilha.h"

int main(){

  int qtd_cartas = 0, i = 0, x = 0, aux = 0;
  Pilha_t *p;
  p = create();

  /*determinar a quantidade de cartas que tera a pilha*/
  scanf("%d", &qtd_cartas);
  
  /*preencher a pilha*/
  for(i=0; i<qtd_cartas; i++){
    push(p, (elem)i);
  }

  i = 0;
  /*para procurar a carta 1 na pilha*/
  while(!isEmpyt(p)){
    /*passar para x o valor da ultima posicao percorrida*/
    pop(p, &x);

    /*para contar quantas jogadas haverao no total apos encontrar a carta 1*/
    if(x==1){
      aux = 1;
    }
    if(aux == 1){
      i++;
    }
  }
  printf("%d",i);
  return 0;
}