// maximo 50 times
#define MAX 50

typedef struct {
    int v[MAX];
    int topo;
} Estrutura;

Estrutura *cria_pilha() 
{
    Estrutura *p = (Estrutura*)malloc(sizeof(Estrutura));
    p->topo = -1;
    return p;
}

void push(Estrutura *p, int x) 
{
    p->topo++;
    p->v[p->topo] = x;
}

int pop(Estrutura *p) 
{
    int t = p->v[p->topo];
    p->topo--;
    return t;
}