#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "skiplist.h"

struct no{
  char *str;
  struct no **prox;
};

struct skiplist{
  signed long int nivel_max;
  /*fracao dos nos*/
  float p;
  signed long int nivel;
  struct no *inicio;
};


/*funcao readline*/
char *readline(FILE *stream) {
  char *string = NULL;
  int pos = 0;    

  do {
    string = (char *) realloc(string, pos+1);
    string[pos] = (char) fgetc(stdin);
    pos++;
  }while (string[pos-1] != '\n' && !feof(stdin));
  string[pos-1] = '\0';
  
  return string;
}


/*funcao para sortear um novo nivel*/
int sorteia_nivel(skiplist *sk){
  signed long int nivel = 0;
  float r = 0;  
  while(r < 0.5 && nivel <sk->nivel_max){
    nivel++;
    r = (float)rand()/RAND_MAX;
  }
  //nivel = sk->nivel++;
  return nivel;
}


/*funcao para criar um novo no*/
struct no* novo_no(char *str, signed long int nivel){
  struct no *novo = malloc(sizeof(struct no));

  /*cria um novo no*/
  if(novo != NULL){
    novo->str = malloc((strlen(str)+100)*sizeof(char*));
    strcpy(novo->str, str);
    novo->prox = malloc((nivel+100)*sizeof(struct no*));
    
    for(signed long int i=0; i<(nivel+1); i++){
      novo->prox[i]=NULL;
    }
  }
  return novo;
}


/*funcao para criar a skiplist*/
skiplist* criar(signed long int nivel_max, float p){
  skiplist *sk = (skiplist*)malloc(sizeof(skiplist));
  if(sk != NULL){
    /*inicialixar os valores da struct*/
    sk->nivel_max = nivel_max;
    sk->p = p;
    sk->nivel = 0;
    sk->inicio = novo_no("null", nivel_max);
  }
  return sk;
}


/*funcao para realizar a busca*/
int busca(skiplist *sk, char *str){
  if(sk==NULL) return 0;

  signed long int i;
  int tam = strlen(str)-1;
  struct no *atual = sk->inicio;

  /*percorrer os nos enquanto a palavra buscada seja
    menor que a palavra do proximo no*/
  for(i = sk->nivel; i>=0; i--){
    while(atual->prox[i]!=NULL && strncmp((atual->prox[i]->str), str, tam)<0)
      atual = atual->prox[i];
  } 

  /*para acessar o nivel 0 do proximo no,
    onde a palavra que deseja inserir nao pode estar*/
  atual = atual->prox[0];
  
  if(atual!= NULL && strncmp((atual->str), str, tam)==0){
    printf("%s\n", atual->str);
  return 1;
  }else{
    printf("OPERACAO INVALIDA\n");
    return 0;
  }
}

/*funcao para inserir novas palavras*/
int inserir(skiplist *sk, char *str){
  if(sk == NULL) return 0;
  
  signed long int i;
  struct no *atual = sk->inicio;

  /*criar um array auxiliar*/
  struct no **aux;
  aux = malloc((sk->nivel_max)*sizeof(struct no*));
  for(i=0; i<= sk->nivel_max; i++)
    aux[i]=NULL;

  /*percorrer os nos enquanto a palavra buscada seja
    menor que a palavra do proximo no*/
  int tam = 0;
  int j = 0;
  while(str[j]!=' '){
    tam++;
    j++;
  }
  for(i = sk->nivel; i>=0; i--){
    while(atual->prox[i]!=NULL && strncmp((atual->prox[i]->str), str, tam)<0)
      atual = atual->prox[i];
    aux[i] = atual;
  } 

  /*para acessar o nivel 0 do proximo no,
    onde a palavra que deseja inserir nao pode estar*/
  atual = atual->prox[0];
  
  /*cria e insere um novo no se a palavra deseja inserir nao existir*/
  if(atual == NULL || strncmp((atual->str), str, tam)!=0){

    /*sorteia um novo nivel*/
    signed long int novo_nivel  = sorteia_nivel(sk);

    /*cria um novo no*/
    struct no *novo = novo_no(str, novo_nivel);
    if(novo == NULL){
      free(aux);
      return 0;
    }

    /*se o novo nivel for maior que o nivel atual da skiplist,
      atualizar os novos niveis do array auxiliar*/
    if(novo_nivel>sk->nivel){
      for(i=sk->nivel+1; i<=novo_nivel; i++){
        aux[i] = sk->inicio;
      }
      sk->nivel = novo_nivel;      
    }

    /*insere o no e arruma os ponteiros*/
    for(i = 0; i<=novo_nivel; i++){
      novo->prox[i] = aux[i]->prox[i];
      aux[i]->prox[i] = novo;
    }
    free(aux);
    return 1;
  }else{
    printf("OPERACAO INVALIDA\n");
  }
  return 0;
}


/*funcao para remover as palavras*/
int remover(skiplist *sk, char *str){
  if(sk == NULL) return 0;

  signed long int i;
  struct no *atual = sk->inicio;
  int tam = strlen(str)-1;

  /*criar um array auxiliar*/
  struct no **aux;
  aux = malloc((sk->nivel_max+1)*sizeof(struct no*));
  for(i=0; i<= sk->nivel_max; i++){
    aux[i] = NULL;
  }

  /*percorrer os nos enquanto a palavra buscada seja
    menor que a palavra do proximo no*/
  for(i = sk->nivel; i>=0; i--){
    while(atual->prox[i]!=0 && strncmp((atual->prox[i]->str), str, tam)<0)
      atual = atual->prox[i];

    aux[i] = atual;
  }

  
  /*para acessar o nivel 0 do proximo no,
    onde a palavra que deseja inserir nao pode estar*/
  atual = atual->prox[0];
  /*aponta para o no que deseja ser removido*/
  if(atual != NULL && strncmp((atual->str), str, tam)==0){
    for(i = 0; i<sk->nivel; i++){
      if(aux[i]->prox[i] != atual)
        break;
      
      aux[i]->prox[i] = atual->prox[i];
    }

    /*exclui os niveis sem elementos*/
    while(sk->nivel >0 && sk->inicio->prox[sk->nivel] == NULL)
      sk->nivel--;

    free(atual->prox);
    free(atual);
    free(aux);
    return 1;
  }else{
    printf("OPERACAO INVALIDA\n");
  }
  free(aux);
  return 0;
}


/*funcao para editar o significado de uma palavra*/
int editar(skiplist *sk, char *str, char *str2){
  if(sk == NULL) return 0;

  signed long int i;
  struct no *atual = sk->inicio;

  /*criar um array auxiliar*/
  struct no **aux;
  aux = malloc((sk->nivel_max+1)*sizeof(struct no*));

  /*percorrer os nos enquanto a palavra buscada seja
    menor que a palavra do proximo no*/
  for(i = sk->nivel; i>=0; i--){

    while(atual->prox[i]!=NULL && strncmp((atual->prox[i]->str), str, strlen(str))<0)
      atual = atual->prox[i];

    aux[i] = atual;
  }

  /*para acessar o nivel 0 do proximo no,
    onde a palavra que deseja inserir nao pode estar*/
  atual = atual->prox[0];
  
  if(atual != NULL && strncmp((atual->str), str, strlen(str))==0){
    /*para comecar a editar somente apos o primeiro ' '*/
    i = strlen(str)+1;
    int j = 0;

    /*para copiar o conteudo de str2 para x->str1*/
    while(j<strlen(str2)+strlen(str+1)){
      atual->str[i] = str2[j];
      j++;
      i++;
    }
  }else{
    printf("OPERACAO INVALIDA\n");
  }
  free(aux);
  return 0;
}

/*funcao para imprimir a lista*/
void imprimir(skiplist* sk, char str){

  struct no *atual = sk->inicio;
  signed long int i, j = 0;

  /*percorrer os nos enquanto a palavra buscada seja
    menor que a palavra do proximo no*/
  for(i=15000; i>0; i--){
    /*para acessar o nivel 0 do proximo no*/
    atual = atual->prox[0]; 
    if(atual->prox[0] == NULL){
      break;
    }
    if(atual->str[0] == str){
      printf("%s\n", atual->str);
      j = 1; 
    } 
  }
  if(j==0)
    printf("NAO HA PALAVRAS INICIADAS POR %c\n",str);
}


