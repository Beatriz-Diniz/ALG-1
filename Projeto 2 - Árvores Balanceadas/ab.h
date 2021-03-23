typedef int elem;
typedef struct no no_t;
typedef struct arvore{
  no_t *raiz;
}arvore_t;

struct no {
  elem info;
  int fb, cor, max, min;
  no_t *esq, *dir;
};


arvore_t *criar();
void finalizar(no_t *raiz);
int inserir(arvore_t *a, elem x);
void pre_ordem(no_t *raiz);
void em_ordem(no_t *raiz);
void pos_ordem(no_t *raiz);
void maximo_t(no_t *raiz, elem x);
void minimo_t(no_t *raiz, elem x);
void sucessor(no_t *no, no_t *pre, no_t *suc, int key);
void predecessor(no_t *no, no_t *pre, no_t *suc, int key);