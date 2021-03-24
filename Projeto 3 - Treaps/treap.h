typedef struct no no_t;
typedef struct fila fila_t;

struct no { 
    int chave, prioridade; 
    no_t *esq, *dir; 
}; 

struct fila{
  int chave, prioridade; 
  fila_t *esq, *dir; 
};

no_t *rotacao_dir(no_t *y);
no_t *rotacao_esq(no_t *x);
no_t* novo_no(int chave, int prioridade);
no_t* buscar(no_t* raiz, int chave);
no_t* inserir(no_t* raiz, int chave, int prioridade);
no_t* deletar(no_t* raiz, int chave);
void pre_ordem(no_t* raiz);
void em_ordem(no_t* raiz);
void pos_ordem(no_t* raiz);
void largura (fila_t *h);
