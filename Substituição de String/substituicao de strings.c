#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *substituir_palavras(char *texto,char *erro, char *correcao){
  
  char *texto_corrigido= (char*)malloc(100*sizeof(char)); //para alocar memoria
  int i = 0;

  while (*texto!='\0'){ 
    /*para localizar o erro*/
    if (strstr(texto, erro) == texto){
      /*fazer a substituicao*/
      strcpy(&texto_corrigido[i], correcao);
      
      /*para deixar o espaco ocupado pela correcao igual ao tamanho dela*/
      i += strlen(correcao);
      texto += strlen(erro);
    }
    texto_corrigido[i++] = *texto++;
  }
  return texto_corrigido;
}
 
int main(){

  /*alocar memoria*/
  char *texto=(char*)malloc(100*sizeof(char));
  char *erro=(char*)malloc(20*sizeof(char));
  char *correcao=(char*)malloc(20*sizeof(char));
  char *texto_corrigido=(char*)malloc(100*sizeof(char));;
  int j = 0;

  while(j<3){ 
    scanf(" %[^\n]s",texto);
    scanf(" %[^\n]s",erro);
    scanf(" %[^\n]s",correcao);

    /*para considerar apenas os 100 primeiros caracteres*/
    if(strlen(texto)>100){
      for(int i = 0; i<strlen(texto); i++){
        if(i>99){
          texto[i]='\0';
        }
      }
    }
  
    /*chamar a funcao que realiza a correcao*/
    texto_corrigido = substituir_palavras(texto, erro,correcao);
    printf("%s\n", texto_corrigido);
    j++;
  }

  /*liberar memoria*/
  free(texto);
  free(erro);
  free(correcao);
  free(texto_corrigido);
  return 0; 
}