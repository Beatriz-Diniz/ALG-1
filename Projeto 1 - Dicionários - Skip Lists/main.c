#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "skiplist.h"


int main() {
  skiplist *sk = criar(20, 0.5);
  char *str1, *str2;
  char *comando;
  char *arquivo;

  do{
    arquivo=readline(stdin); 
    char aux1 = 0; 
    int l = 0, k = 0;

    /*alocar memoria*/
    str1 = (char*)calloc(200, sizeof(char));
    str2 = (char*)calloc(200, sizeof(char));
    comando = (char*)calloc(20, sizeof(char));
    /*Verificar se o comando digitado eh o inserir*/
    if(strncmp(arquivo, "in", 2) == 0){
      /*para salvar o comando em uma variavel*/
      if(aux1 == 0){
        while(arquivo[k]!=' '){
          comando[l] = arquivo[k];
          k++;
          aux1 = 1;
          l++;
        }
      }

      /*para salvar a palavra str1 e a definicao str2 numa unica variavel*/
      if(aux1 == 1){
        k++;
        l = 0;
        while(k<strlen(arquivo)){
          str1[l] = arquivo[k];
          k++;
          l++;
        }
        inserir(sk, str1);  
      }
    }
    
    /*para verificar se o comando escolhido eh o remover*/
    if(strncmp(arquivo, "r", 1) == 0){
      if(aux1 == 0){
        while(arquivo[k]!=' '){
          comando[l] = arquivo[k];
          k++;
          aux1 = 1;
          l++;
        }
      }

      /*para salvar o nome da variavel que deseja remover*/
      if(aux1 == 1){
        k++;
        l = 0;
        while(k<strlen(arquivo)){
          str1[l] = arquivo[k];
          k++;
          l++;
        }
        remover(sk, str1);
      }        
    }  

    /*para verificar se o comando escolhido eh o editar str2*/
    if(strncmp(arquivo, "a", 1) == 0){
      if(aux1 == 0){
        while(arquivo[k]!=' '){
          comando[l] = arquivo[k];
          k++;
          aux1 = 1;
          l++;
        }
      }

      /*para salvar o nome da variavel que deseja alterar*/
      if(aux1 == 1){
        k++;
        l = 0;
        while(arquivo[k]!=' '){
          str1[l] = arquivo[k];
          k++;
          l++;
          aux1 = 2;
        }
      }

      /*para salvar a nova definicao de str1*/
      if(aux1 == 2){
        k++;
        l = 0;
        while(k<strlen(arquivo)){
          str2[l] = arquivo[k];
          k++;
          l++;
        }
      }
      editar(sk, str1, str2);
    }

    /*para verificar se o comando escolhido eh o buscar*/
    if(strncmp(arquivo, "b", 1) == 0){
      if(aux1 == 0){
        while(arquivo[k]!=' '){
          comando[l] = arquivo[k];
          k++;
          aux1 = 1;
          l++;
        }
      }
      /*para salvar o nome da variavel que deseja buscar*/
      if(aux1 == 1){
        k++;
        l = 0;
        while(k<strlen(arquivo)){
          str1[l] = arquivo[k];
          k++;
          l++;
        }
        busca(sk, str1);
      } 
    }

    /*para verificar se o comando escolhido eh o imprimir*/
    if(strncmp(arquivo, "im", 2) == 0){
    /*para salvar somenete o o caractere que deseja imprimir*/
      while(arquivo[k] != ' ')
        k++;
      char caractere = arquivo[k+1]; 
      imprimir(sk, caractere);
    }  
  } while (!feof(stdin)); //para a readline terimanar qaundo a leitura do arquivo chegar no fim

  free(str2);  
  free(str1);
  free(comando);
  
  return 0;
}