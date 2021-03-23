#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
  int i = 0, t = 0, n = 0, k = 0;
  /*t =  numero de operacoes
   *n = numero de pessoas
   *k = indice de sorteio*/
  scanf("%d", &t);

  /*para encontrar o sobrevivente de cada acao*/
  for(i = 1; i<=t; i++){
    lista_t *l = criar();
    scanf("%d", &n);
    scanf("%d", &k);
    remover(l, n, k);
    printf("Caso %d: ",i);
    imprimir(l);
    liberar(l);
  }
  return 0;
}