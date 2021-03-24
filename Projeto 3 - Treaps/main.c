#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treap.h"

int main() { 
  
    no_t *raiz = NULL; 
    fila_t *fila = NULL;
    fila = (fila_t*)malloc(sizeof(fila_t));
    int n = 0, i = 0, chave = 0, prioridade = 0;
    char *op;

    scanf("%d", &n);
    for(i = 0; i<n; i++){
      
        op = (char*)calloc(25, sizeof(char));
        scanf("%s", op);

        /*para inserir uma chave e sua prioridade*/
        if(strcmp(op, "insercao") == 0){
            scanf("%d", &chave);
            scanf("%d", &prioridade);
            
            /*verificar se a chave nao foi inserida*/
            no_t *res = buscar(raiz, chave);
            if(res == NULL)
                raiz = inserir(raiz, chave, prioridade);
            else
                printf("Elemento ja existente\n");
        }

        /*para remover uma chave*/
        if(strcmp(op, "remocao") == 0){
            scanf("%d", &chave);
            
            /*verificar se a chave existe*/
            no_t *res = buscar(raiz, chave);
            if(res == NULL)
                printf("Chave nao localizada\n");
            else
                raiz =  deletar(raiz, chave);
        }

        /*para buscar uma chave*/
        if(strcmp(op, "buscar") == 0){
            scanf("%d", &chave);
            
            no_t *res = buscar(raiz, chave); 
            if(res==NULL)
                printf("0\n");
            else
                printf("1\n");
        }

        /*para imprimir a arvore*/
        if(strcmp(op, "impressao") == 0){
            char *imp;
            imp = (char*)calloc(25, sizeof(char));
            scanf("%s", imp);
            
            if(strcmp(imp, "ordem") == 0){
                em_ordem(raiz);
                printf("\n");
            }

            if(strcmp(imp, "posordem") == 0){
                pos_ordem(raiz);
                printf("\n");
            }

            if(strcmp(imp, "preordem") == 0){
                pre_ordem(raiz);
                printf("\n");
            }

            if(strcmp(imp, "largura") == 0){
                /*copiar os dados de no_t para fila_t*/
                memcpy(fila, raiz, sizeof(*raiz));
                largura(fila);
                printf("\n");
            }
        }
    }   
    return 0; 
}