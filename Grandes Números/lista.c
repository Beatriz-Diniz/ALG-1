#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
#include <string.h>
#include "lista.h"

struct no{
  elem info;
  no_t *prox;
};

struct lista{
  no_t *ini, *fim;
  int tam;
};

/*funcao para ciar lista*/
lista_t *criar(){
  lista_t *l;
  l = (lista_t*)malloc(sizeof(lista_t));
  assert(l != NULL);
  l->ini = NULL;
  l->fim = NULL;
  l->tam = 0;

  return l;
}

/*funcao para liberar a memoria usada pela lista*/
void liberar(lista_t *l){
  if(l != NULL){
    no_t *p = l->ini;
    while(p != NULL){
      l->ini = p->prox;
      free(p);
      p = l->ini;
    }
    free(l);
  }
}

/*funcao para inserir os valores na lista*/
void inserir(lista_t *l, elem x){
  assert(l != NULL);

  no_t *p = (no_t*)malloc(sizeof(no_t));
  p->info = x;
  p->prox = NULL;

  //se lista estiver vazia
  if(l->ini == NULL){
    l->ini = p;
  }else{  //lista com 1 ou mais elementos
    l->fim->prox = p;
  }
  l->fim = p;
  l->tam++;
}

/*funcao para imprimir a lista*/
void imprimir(lista_t *l){
  assert(l != NULL);

  no_t *p = l->ini;
  while(p != NULL){
    printf("%s ", p->info);
    p = p->prox;
  }
  printf("\n");
}

/*funcao para realizar a soma*/
void soma(lista_t *l, char n1[50], char n2[50], char soma[50]){
  int i, j, k, tam_n1, tam_n2, tam_s, aux=0, n1_i=0, n2_i=0, s=0;
  
  tam_n1 = strlen(n1);
  tam_n2 = strlen(n2);
   
  /*tam_s = o tamanho do maior numero+1*/
  if(tam_n1>tam_n2){
    tam_s = tam_n1+1;
  }
  else{
    tam_s = tam_n2+1;
  }

  for(i=tam_n1-1, j=tam_n2-1, k=tam_s-1; k >= 0; i--, j--, k--){
    /*Converter caractere para inteiro
     *se o vetor estiver vazio converte para zero*/
    if(i>=0){
      n1_i= n1[i]-'0';
    }else{
      n1_i=0;
    }

    if(j>=0){
      n2_i= n2[j]-'0';
    }else{
      n2_i=0;
    }

    /*realiza a soma da posicao do vetor*/
    s = n1_i + n2_i + aux;
    /*converte para caractere e guarda somente o ultimo caractere da soma (s)
     *O restantes dos caracteres vai para a variavel aux, para ser somado na proxima posicao do vetor*/
    soma[k] = s % 10 + '0';
    aux = s / 10; //Carrega o que sobrou para somar no próximo ciclo
  }
    
  /*retirar o 0 do inicio*/
  while(soma[0]=='0'){
    if(soma[0] == '0'){
      for(i=0; soma[i]; i++){ 
        soma[i] = soma[i+1];
      }
    }
  } 
}

void expressao(lista_t *l, elem n1, elem n2, char expressao[4]){
  assert(l!=NULL);

  char resultado[50] = {'\0'};

  /*para somar*/
  if(strcmp(expressao, "sum")==0){
    soma(l,n1, n2, resultado);
    inserir(l, resultado);
    printf("%s\n", resultado);
  }
  
  /*para ver se o primeiro eh maior que o segundo*/
  if(strcmp(expressao, "big")==0){
    long int a = atoi(n1), b = atoi(n2);
    if(a>b){
      /*Atribuir o valor 1 para resultado se a>b*/
      *resultado = '1';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }else{
      /*Atribuir o valor 0 para resultado se a<=b*/
      *resultado = '0';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }
  }

  /*para ver se o primeiro eh menor que o segundo*/
  if(strcmp(expressao, "sml")==0){
    long int a = atoi(n1), b = atoi(n2);
    if(a<b){
      /*Atribuir o valor 1 para resultado se a<b*/
      *resultado = '1';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }else{
      /*Atribuir o valor 0 para resultado se a>=b*/
      *resultado = '0';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }
  }

  /*para ver se o primeiro eh igual ao segundo*/
  if(strcmp(expressao, "eql")==0){
    long int a = atoi(n1), b = atoi(n2);
    if(a==b){
      /*Atribuir o valor 1 para resultado se a==b*/
      *resultado = '1';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }else{
      /*Atribuir o valor 0 para resultado se a!=b*/
      *resultado = '0';
      inserir(l, resultado);
      printf("%s\n", resultado);
    }
  }
}