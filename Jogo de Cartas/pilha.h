#define TamPilha 100
typedef int elem;
typedef struct pilha Pilha_t;

Pilha_t *create();
void destroy(Pilha_t *p);
int isFull(Pilha_t *p);
int isEmpyt(Pilha_t *p);
int push(Pilha_t *p, elem x);
int pop(Pilha_t *p, elem *x);