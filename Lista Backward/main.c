#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include "lista.h"

int main(){
  
  /*realizar a insercao e remocao dos elementos*/
  receber_comandos();

	/*para imprimir a lista*/
	imprimir_lista();

  /*para imprimir -1 se a lista estiver vazia*/
	if(lista_vazia() != 0){
    	printf("-1\n");
  	}

	return 0;
}