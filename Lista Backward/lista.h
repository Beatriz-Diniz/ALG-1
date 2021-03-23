typedef struct no no_t;

no_t * criar_lista(int valor);
no_t* adicionar_lista(int v, int i, int j, int back);
void imprimir_lista();
int lista_vazia();
no_t * buscar_elemento(int v, no_t **anterior);
int remover_elemento(int v);
void receber_comandos();