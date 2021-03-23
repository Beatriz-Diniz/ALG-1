typedef char *elem;
typedef struct lista lista_t;
typedef struct no no_t;

lista_t *criar();
void liberar(lista_t *l);
void inserir(lista_t *l, elem x);
void imprimir(lista_t *l);
void soma(lista_t *l,char n1[50], char n2[50], char soma[50]);
void expressao(lista_t *l, elem n1, elem n2, char expressao[4]);