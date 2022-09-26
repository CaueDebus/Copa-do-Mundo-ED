#include <stdlib.h>

typedef struct nodo {
    nodo *topo;
} Pilha;

Pilha *cria_pilha() 
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int vazia(Pilha *p) 
{
    return p->topo == NULL ? 1 : 0;
}

void push(Pilha *p, int x) 
{
    p->topo = insere(p->topo, x);
}

int pop(Pilha *p) 
{
    nodo *aux = p->topo->prox;
    free(p->topo);
    p->topo = aux;
}