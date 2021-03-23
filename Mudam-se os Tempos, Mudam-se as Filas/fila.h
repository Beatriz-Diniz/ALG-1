#define TamFila 100
typedef struct fila Fila_t;

Fila_t *criar();
int isEmpety(Fila_t *f);
int isFull(Fila_t *f);
int inserir(Fila_t *f);
void destruir(Fila_t *f);
int ordem_atendimento(Fila_t *f);