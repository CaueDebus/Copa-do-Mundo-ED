// maximo 50 times
#define MAX 50

typedef struct {
    int v[MAX];
    int topo;
} Pilha;

Pilha *cria_pilha() {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

void push(Pilha *p, int x) {
    p->topo++;
    p->v[p->topo] = x;
}

int pop(Pilha *p) {
    int t = p->v[p->topo];
    p->topo--;
    return t;
}