#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
  int i = 0, t = 0;
  char n1[50] = {'\0'}, n2[50] = {'\0'};
  char op[4]={'\0'};
  /*t =  numero de operacoes
   *n1 = numero de pessoas
   *n2 = indice de sorteio
   *op = operacao a ser realizada*/
  scanf("%d", &t);
  lista_t *l = criar();
  /*para encontrar o sobrevivente de cada acao*/
  for(i = 1; i<=t; i++){
    
    scanf("%s", op);
    scanf("%s", n1);
    inserir(l, n1);
    scanf("%s", n2);
    inserir(l, n2);
    printf("Resultado %d: ", i);
    expressao(l, n1, n2, op);
  }
  return 0;
}