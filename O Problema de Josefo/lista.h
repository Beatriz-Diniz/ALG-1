typedef int elem;
typedef struct lista lista_t;
typedef struct no no_t;

lista_t *criar();
void liberar(lista_t *l);
void inserir(lista_t *l, elem x);
void imprimir(lista_t *l);
void remover(lista_t *l, elem n, elem k);